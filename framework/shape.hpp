#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <string>
#include "color.hpp"


class Shape
{
	public:
		Shape();
		Shape(Color const& color);
		Shape(std::string const& name);
		Shape(std::string const& name, Color const& color);
		std::string getname();
		Color getcolor();
		virtual double area() const = 0;
		virtual double volume() const = 0;
	protected:
		std::string name_;
		Color color_;
};
#endif