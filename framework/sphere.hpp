#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "ray.hpp"

//NUR von cpp auf Hpp verlinkung "" sonst <>

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(glm::vec3 const& center, double radius);
	Sphere(Sphere const& x);
	Sphere(std::string const& name);
	Sphere(Material const& material);
	Sphere(std::string const& name, Material const& material);
	Sphere(glm::vec3 const& center, double radius, std::string const& name, Material const& material);
	Sphere(std::string const& name, glm::vec3 const& center, double radius, Material const& material); //added for sdf loade
	// ~Sphere();
	double getradius() const;
	glm::vec3 getcenter() const;
	double area() const override;
	double volume() const override;
	std::ostream& print(std::ostream& os) const override;
	bool intersect(Ray const& r, float& t);
private:
	glm::vec3 center_;
	double radius_;
};
#endif