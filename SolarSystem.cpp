#include "SolarSystem.h"
#include "Star.h"
#include "Planet.h"


SolarSystem::SolarSystem(void)
{
	for (int i = 0; i < 3; ++i) {
		this->suns[i] = nullptr;
	}
	for (int i = 0; i < 10; ++i) {
		this->planets[i] = nullptr;
	}
}


SolarSystem::~SolarSystem(void)
{
	for (int i = 0; i < 3; ++i) {
		if (this->suns[i] != nullptr) {
			delete this->suns[i];
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (this->planets[i] != nullptr) {
			delete this->planets[i];
		}
	}
}

void SolarSystem::Create(int s)
{
	float size = AU;
	// Seed RNG
	srand(this->seed = s);

	// Step 1 create the stars
	int numstars = rand() % 3 + 1; // How many stars min 1 max 3
	Star* sun;
	for (int i = 0; i < numstars; ++i) {
		sun = new Star();
		this->suns[i] = sun;
		sun->Generate(seed); // Generate properties of the star
	}

	// Step 3 determine number of planets max 10
	int maxplanetstuff = rand() + 1;
	int planetstuff = rand() % maxplanetstuff;
	int numplanets = planetstuff / (maxplanetstuff / 10);

	if (numplanets > 0) {
		// Step 4 determine amount of stuff based on percent of distance from the star (0.0) to edge of star's gravity (1.0)
		float* stuffproportion = new float[numplanets]; // float stuffproportion[]: new
		float totalproportion = 0.0f;
		int range = static_cast<int>(1.0f / (float)numplanets * 100.0f);
		for (int i = 0; i < numplanets; ++i) {
			float start = (float)i / (float)numplanets * 100.0f; // start of the range of percents for this planet, all planets are about equally spaced
			float percent = (start) + (rand() % range);

			// Use http://en.wikipedia.org/wiki/Gaussian_function to determine the percent of stuff, value can be skewed with a change in b (default: a = 100 / numplanets, b = 50, c = 2(50^2) or 5000)
			totalproportion += stuffproportion[i] = pow((100.0f / (float)(numplanets)) * 2.718281828f, (-1.0f * pow((percent - 50.0f), 2.0f) / 5000.0f));
		}

		// Step 4b determine distance to the star
		float* distances = new float[numplanets]; // float distances[]: new
		for (int i = 0; i < numplanets; ++i) {
			float scale = 4.0f * this->suns[0]->Mass();
			distances[i]= (scale * cosh(((float)i + 1.0f) / scale) - scale) * AU; // using http://en.wikipedia.org/wiki/Catenary with an a value of 4
		}


		// Step 5 create planets
		for (int i = 0; i < numplanets; ++i) {
			this->planets[i] = new Planet();
			float stuff = stuffproportion[i] / totalproportion * (float)planetstuff;
			this->planets[i]->Generate(distances[i], stuff, this->suns[0]->PlanetTemp(distances[i])); // Shape and polarize them, also create moons
		}
		delete[] stuffproportion; // float stuffproportion[]: delete
		delete[] distances; // float distances[]: delete
	}
}
