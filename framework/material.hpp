#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP
#include <color.hpp>
#include <string>
#include <iostream>

class Material
{
public:
	Material();
	Material(std::string const& usrname);
	Material(std::string const& usrname, Color const& usrka, Color const& usrkd, Color const& usrks, float const usrm);
	std::string const& getname() const;
	Color const& getka() const;
	Color const& getkd() const;
	Color const& getks() const;
	float const getm() const;
	Material const& getmaterial() const;


private:
	std::string name;
	Color ka;
	Color kd;
	Color ks;
	float m;
};
std::ostream& operator<<(std::ostream& os, Material const& mat);
#endif