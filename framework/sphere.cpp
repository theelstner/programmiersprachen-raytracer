#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <cmath> //PI

Sphere::Sphere() :
Shape(),
center_{0.0, 0.0, 0.0},
radius_{1.0} {}

Sphere::Sphere(glm::vec3 const& center, double radius) :
Shape(),
center_{center},
radius_{radius} {}

Sphere::Sphere(Sphere const& x) :
Shape(),
center_{x.center_},
radius_{x.radius_} {}

Sphere::Sphere(std::string const& name) :
Shape(name),
center_{0.0, 0.0, 0.0},
radius_{1.0} {}

Sphere::Sphere(Color const& color) :
Shape(color),
center_{0.0, 0.0, 0.0},
radius_{1.0} {}

Sphere::Sphere(std::string const& name, Color const& color) :
Shape(name, color),
center_{0.0, 0.0, 0.0},
radius_{1.0} {}

Sphere::Sphere(glm::vec3 const& center, double radius, std::string const& name, Color const& color) :
Shape(name, color),
center_{center},
radius_{radius} {}

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
