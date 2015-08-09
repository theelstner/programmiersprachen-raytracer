#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape
{
public:
	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max);
	Box(Box const& b);
	Box(std::string const& name);
	Box(Material const& material);
	Box(std::string const& name, Material const& material);
	Box(glm::vec3 const& min, glm::vec3 const& max, 
		std::string const& name, Material const& material);
	Box(std::string const& name, glm::vec3 const& min, glm::vec3 const& max, Material const& material);
	glm::vec3 getmin() const;
	glm::vec3 getmax() const;
	double area() const override;
	double volume() const override;
	std::ostream& print(std::ostream& os) const override;
	bool intersect(Ray const& ray, float& t) override;
private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif