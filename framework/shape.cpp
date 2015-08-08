#include "shape.hpp"

Shape::Shape() :
name_{},
material_{} {}
//{std::cout << "Shape konstruiert" << std::endl;}

Shape::Shape(Material const& material) :
name_{},
material_{material} {}
//{std::cout << "Shape konstruiert" << std::endl;}

Shape::Shape(std::string const& name) :
name_{name},
material_{} {}
//{std::cout << "Shape konstruiert" << std::endl;}

Shape::Shape(std::string const& name, Material const& material) :
name_{name},
material_{material} {}
//{std::cout << "Shape konstruiert" << std::endl;}

Shape::~Shape()
{
	std::cout << "Shape gelöscht" << std::endl; 
}

std::string const& Shape::getname() const
{
	return name_;
}

Material const& Shape::getmaterial() const
{
	return material_;
}

std::ostream& Shape::print(std::ostream& os) const
{
	os << "Name: " << name_ << "; \n" << "---------\n" << "Material: \n" << material_ << "\n---------\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	s.print(os);
	return os;
}