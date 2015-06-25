#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <cmath> //PI

Sphere::Sphere() :
Shape(),
center_{0.0, 0.0, 0.0},
radius_{1.0} {std::cout << "Sphere konstruiert" << std::endl;}

Sphere::Sphere(glm::vec3 const& center, double radius) :
Shape(),
center_{center},
radius_{radius} {std::cout << "Sphere konstruiert" << std::endl;}

Sphere::Sphere(Sphere const& x) :
Shape(),
center_{x.center_},
radius_{x.radius_} {std::cout << "Sphere konstruiert" << std::endl;}

Sphere::Sphere(std::string const& name) :
Shape(name),
center_{0.0, 0.0, 0.0},
radius_{1.0} {std::cout << "Sphere konstruiert" << std::endl;}

Sphere::Sphere(Color const& color) :
Shape(color),
center_{0.0, 0.0, 0.0},
radius_{1.0} {std::cout << "Sphere konstruiert" << std::endl;}

Sphere::Sphere(std::string const& name, Color const& color) :
Shape(name, color),
center_{0.0, 0.0, 0.0},
radius_{1.0} {std::cout << "Sphere konstruiert" << std::endl;}

Sphere::Sphere(glm::vec3 const& center, double radius, std::string const& name, Color const& color) :
Shape(name, color),
center_{center},
radius_{radius} {std::cout << "Sphere konstruiert" << std::endl;}

Sphere::~Sphere()
{
	std::cout << "Sphere gelöscht" << std::endl;
}

double Sphere::getradius() const
{
	return radius_;
}

glm::vec3 Sphere::getcenter() const
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

std::ostream& Sphere::print(std::ostream& os) const
{
	os << "Name: " << name_ << "; " << "Color: " << color_ << "; " 
	    << "Center: " << "(" << center_.x << ", " << center_.y << ", " 
	     << center_.z << ")" << "; " << "Radius: " << radius_ << "\n";
	return os;
}

bool Sphere::intersect(Ray & r) const
{
	auto v = glm::normalize(r.direction);
	float distance(0.0);
	auto result = glm::intersectRaySphere(r.origin, v, center_ , radius_, distance);
	return result;
}


