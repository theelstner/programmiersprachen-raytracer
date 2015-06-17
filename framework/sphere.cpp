#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <cmath> //PI

Sphere::Sphere() :
center_{0.0, 0.0, 0.0},
radius_{1.0} {}

Sphere::Sphere(glm::vec3 center, double radius) :
center_{center},
radius_{radius} {}

Sphere::Sphere(Sphere const& x) :
center_{x.center_},
radius_{x.radius_} {}

double Sphere::getradius()
{
	return radius_;
}

glm::vec3 Sphere::getcenter()
{
	return center_;
}

double Sphere::area() const
{
	double a = 4*M_PI*radius_*radius_;
	return a;
}

double Sphere::volume() const
{
	double v = (4.0/3.0)*M_PI*radius_*radius_*radius_;
	return v;
}
