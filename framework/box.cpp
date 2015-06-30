#include "box.hpp"
#include <glm/vec3.hpp>
#include <cmath>

Box::Box() :
Shape(),
min_{0.0, 0.0, 0.0},
max_{1.0, 1.0, 1.0} {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
Shape(),
min_{min},
max_{max} {}

Box::Box(Box const& b) :
Shape(),
min_{b.min_},
max_{b.max_} {}

Box::Box(std::string const& name) :
Shape(name),
min_{0.0, 0.0, 0.0},
max_{1.0, 1.0, 1.0} {}

Box::Box(Material const& material) :
Shape(material),
min_{0.0, 0.0, 0.0},
max_{1.0, 1.0, 1.0} {}

Box::Box(std::string const& name, Material const& material) :
Shape(name, material),
min_{0.0, 0.0, 0.0},
max_{1.0, 1.0, 1.0} {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Material const& material) :
Shape(name, material),
min_{min},
max_{max} {}


glm::vec3 Box::getmin() const
{
	return min_;
}

glm::vec3 Box::getmax() const
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

std::ostream& Box::print(std::ostream& os) const
{
	os << "Name: " << getname() << "; " << "\n" << "Material: " << getmaterial() << "; " 
	    << "Min: " << "(" << min_.x << ", " << min_.y << ", " 
	     << min_.z << ")" << "; " << "Max: " << "(" << max_.x << ", " 
	     << max_.y << ", "  << max_.z << ")" << "; " << "\n";
	return os;
}







