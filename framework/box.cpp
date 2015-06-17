#include "box.hpp"
#include <glm/vec3.hpp>
#include <cmath>

Box::Box() :
min_{0.0, 0.0, 0.0},
max_{1.0, 1.0, 1.0} {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
min_{min},
max_{max} {}

Box::Box(Box const& b) :
min_{b.min_},
max_{b.max_} {}

glm::vec3 Box::getmin()
{
	return min_;
}

glm::vec3 Box::getmax()
{
	return max_;
}

double Box::area() const
{
	double a = 2*(((max_.x - min_.x)*(max_.y - min_.y))
		+((max_.x - min_.x)*(max_.z - min_.z))+((max_.y - min_.y)*(max_.z - min_.z)));
	return a;

}

double Box::volume() const
{
	double v = (max_.x - min_.x)*(max_.y - min_.y)*(max_.z - min_.z);
	return v;

}