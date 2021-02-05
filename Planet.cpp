#include "Planet.h"


Planet::Planet(void)
{
	for (int i = 0; i < 10; ++i) {
		this->moons[i] = nullptr;
	}
}


Planet::~Planet(void)
{
	for (int i = 0; i < 10; ++i) {
		if (this->moons[i] != nullptr) {
			delete this->moons[i];
		}
	}
}

/*
	1. Choose number of moons
	2. Determine the orbits of the moons relative to the planet
	3. Determine the planet type (rocky, earth like, gas giant, barren, etc)
	4. Generate a surface if not gas giant passing in Goldilocks and type
	5. Create an atmosphere, make the full planet an atmosphere for a gas giant
	6. Destroy a moon(s) to create rings
*/
void Planet::Generate( float orbit, float stuff, float temp, Star* sun, Planet* parent )
{
	this->props.orbit = orbit;
	this->props.mass = stuff;
	this->props.temp = temp;

	this->sun = sun;
	this->parent = parent;

	if (!this->parent) { // Only the primary planet can have moons if this is a moon than skip
		int nummoons = rand() % 10;

		if (nummoons > 0) {
			int* orbits = new int[nummoons]; // int orbits[]: new
			int range = static_cast<int>(1.0f / (float)nummoons * 100.0f);
			for (int i = 0; i < nummoons; ++i) {
				int start = static_cast<int>((float)i / (float)nummoons * 100.0f);
				orbits[i] = (start) + (rand() % range);
			}

			for (int i = 0; i < nummoons; ++i) {
				this->moons[i] = new Planet();
			}

			delete[] orbits; // int orbits[]: delete
		}
	}


}

float Planet::DistanceToSun()
{
	return this->props.distance;
}
