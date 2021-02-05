#pragma once
#include <iostream>

// Check reference to http://en.wikipedia.org/wiki/Stellar_classification for classification
enum STARCLASS { O_BLUE = 0, B_BLUEWHITE, A_WHITE, F_YELLLOWWHITE, G_YELLOW, K_ORANGE, M_RED, STARCLASSMAX};

struct StarProps {
	float radius;
	float mass;
	float temp;
	float luminosity;
	STARCLASS sc;
};

// Minimum values for each properties for a given class of star
static StarProps SCpropsrange[STARCLASSMAX] = {
	{33000.f,	16.0f,	6.60f,	30000.f, O_BLUE},
	{10000.f,	2.10f,	1.80f,	25.000f, B_BLUEWHITE},
	{7500.0f,	1.40f,	1.40f,	5.0000f, A_WHITE},
	{6000.0f,	1.04f,	1.15f,	1.5000f, F_YELLLOWWHITE},
	{5200.0f,	0.80f,	0.96f,	0.6000f, G_YELLOW},
	{3700.0f,	0.45f,	0.70f,	0.0800f, K_ORANGE},
	{0.0f,		0.00f,	0.00f,	0.0000f, M_RED},
};

// Frequency of the main sequence stars from M to B, anything beyond B is a very small fraction ad will be considered with a special rule
static int starclasspercent[STARCLASSMAX] = {7645, 8855, 9615, 9915, 9975, 9988, 10000};

class Star
{
public:
	Star(void);
	~Star(void);
	void Generate( int seed );
	float HotRadius();
	float WarmRadius();
	float PlanetTemp(float);
	float Radius();
	float Mass();
private:
	StarProps props;
};

