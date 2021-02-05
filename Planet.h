#pragma once
#include <iostream>

enum PLANETCLASS {ROCKY, EARTH, GASGIANT, STAR, OHTER, PLANETCLASSMAX};

struct PlanetProps {
	float radius;
	float mass; // In Earth masses
	float temp;
	float orbit;
	float distance;
	PLANETCLASS pc;
};

// Minimum values for each properties for a given class of planet
static PlanetProps PCpropsranges[PLANETCLASSMAX] = {
	{0.0f, 0.1f, 0.0f, 0.0f, 0.0f, ROCKY},
	{0.0f, 1.0f, 0.0f, 0.0f, 0.0f, EARTH},
	{0.0f, 15.0f, 0.0f, 0.0f, 0.0f, GASGIANT},
	{0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, STAR},
	{0.0f, 0.1f, 0.0f, 0.0f, 0.0f, OHTER},
};

class Star;

class Planet
{
public:
	Planet(void);
	~Planet(void);
	void Generate( float, float, float, Star*, Planet* = nullptr );
	float DistanceToSun();
private:
	Planet* moons[10];
	Planet* parent;
	Star* sun;
	PlanetProps props;
};

