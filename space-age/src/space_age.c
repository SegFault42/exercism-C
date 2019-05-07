#include "space_age.h"

double	convert_planet_age(double planet, double nb_second)
{
	double	age = 0.0;

	age = nb_second / planet;
	age = (int)((age * 100) + 0.5);
	age = age / 100;

	return (age);
}
