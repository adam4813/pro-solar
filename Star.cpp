#include "Star.h"


Star::Star(void)
{
}


Star::~Star(void)
{
}

void Star::Generate( int seed )
{
	// determine the class of star we have using the frequency array starclasspercent
	int r = static_cast<STARCLASS>(rand() % 10000);
	for (int i = 0; i < STARCLASSMAX; ++i) {
		if (r < starclasspercent[i]) {
			this->props.sc = static_cast<STARCLASS>(STARCLASSMAX - i - 1);
			break;
		}
	}

	// Using the star's class determine the physical properties
	if (this->props.sc != O_BLUE) {
		this->props.radius = fmod(rand(), (SCpropsrange[this->props.sc - 1].radius - SCpropsrange[this->props.sc].radius)) + SCpropsrange[this->props.sc].radius;
		this->props.mass = fmod(rand(), (SCpropsrange[this->props.sc - 1].mass - SCpropsrange[this->props.sc].mass)) + SCpropsrange[this->props.sc].mass;
		this->props.temp = fmod(rand(), (SCpropsrange[this->props.sc - 1].temp - SCpropsrange[this->props.sc].temp)) + SCpropsrange[this->props.sc].temp;
		this->props.luminosity = fmod(rand(), (SCpropsrange[this->props.sc - 1].luminosity - SCpropsrange[this->props.sc].luminosity)) + SCpropsrange[this->props.sc].luminosity;
		this->props.luminosity *= 383900000000000000000000000.0f;
	} else {
		this->props.radius = rand() + SCpropsrange[this->props.sc].radius;
		this->props.mass = rand() + SCpropsrange[this->props.sc].mass;
		this->props.temp = rand() + SCpropsrange[this->props.sc].temp;
		this->props.luminosity = rand() + SCpropsrange[this->props.sc].luminosity;
		this->props.luminosity *= 383900000000000000000000000.0f;
	}

	// determine the star's age as a function of luminosity and mass
	float lifespan = pow(this->props.mass, -2.5f) * 10000000000;
	float age = ((rand() % 100) / 100.0f) * lifespan;
}

float Star::HotRadius()
{
	return 0.0f;
}

float Star::WarmRadius()
{
	return 0.0f;
}

// Distance needs to be in meters for the equation to work correctly
// check http://www.shatters.net/forum/viewtopic.php?f=4&t=2999&start=5 for equation
float Star::PlanetTemp( float distance )
{
	float bottom = 16.0f * 3.14159265f * 0.000000056704f * pow(distance, 2);
	float temp = pow((this->props.luminosity * 0.7f)/ bottom, 0.25f);
	return temp;
}

float Star::Radius()
{
	return this->props.radius;
}
float Star::Mass()
{
	return this->props.mass;
}
