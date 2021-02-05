#pragma once
#include <iostream>

// Astronomical Unit in meters
#define AU 149598000000.0f

class Star;
class Planet;

class SolarSystem
{
public:
	SolarSystem(void);
	~SolarSystem(void);

	void Create(int);
private:
	Star* suns[3];
	Planet* planets[10];
	int seed;
};

