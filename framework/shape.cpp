#include "shape.hpp"

Shape::Shape() :
name_{},
color_{0.0, 0.0, 0.0}
{}

Shape::Shape(Color const& color) :
name_{},
color_{color}
{}

Shape::Shape(std::string const& name) :
name_{name},
color_{0.0, 0.0, 0.0}
{}

Shape::Shape(std::string const& name, Color const& color) :
name_{name},
color_{color}
{}

std::string Shape::getname()
{
	return name_;
}

Color Shape::getcolor()
{
	return color_;
}