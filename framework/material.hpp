#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP
#include <color.hpp>
#include <string>
#include <iostream>

class Material
{
public:
	Material();
	Material(std::string usrname, Color usrka, Color usrkd, Color usrks, float usrm);
	std::string const& getname();
	Color const& getka();
	Color const& getkd();
	Color const& getks();
	float const getm();


private:
	std::string name;
	Color ka;
	Color kd;
	Color ks;
	float m;
};
std::ostream& operator<<(std::ostream& os, Material const& mat);
#endif