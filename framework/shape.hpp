#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <string>
#include "color.hpp"
#include <iostream>


class Shape
{
	public:
		Shape();
		Shape(Color const& color);
		Shape(std::string const& name);
		virtual ~Shape();
		Shape(std::string const& name, Color const& color);
		std::string getname() const;
		Color getcolor() const;
		virtual double area() const = 0;
		virtual double volume() const = 0;
		virtual std::ostream& print(std::ostream& os) const;
	private:
		std::string name_;
		Color color_;
};
std::ostream& operator<<(std::ostream& os, Shape const& s);
#endif