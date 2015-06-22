#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(glm::vec3 const& center, double radius);
	Sphere(Sphere const& x);
	Sphere(std::string const& name);
	Sphere(Color const& color);
	Sphere(std::string const& name, Color const& color);
	Sphere(glm::vec3 const& center, double radius, std::string const& name, Color const& color);
	double getradius();
	glm::vec3 getcenter();
	double area() const override;
	double volume() const override;
private:
	glm::vec3 center_;
	double radius_;
};
#endif