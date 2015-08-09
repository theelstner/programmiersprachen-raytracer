#include "material.hpp"

Material::Material() :
name{},
ka{0, 0, 0},
kd{0, 0, 0},
ks{0, 0, 0},
m{0} {} 

Material::Material(std::string const& usrname) :
name{usrname},
ka{0, 0, 0},
kd{0, 0, 0},
ks{0, 0, 0},
m{0} {}

Material::Material(std::string const& usrname, Color const& usrka, Color const& usrkd, Color const& usrks, float const usrm) :
name{usrname},
ka{usrka},
kd{usrkd},
ks{usrks},
m{usrm} {}

std::string const& Material::getname() const
{
    return name;
}
	
Color const& Material::getka() const
{
	return ka;
}

Color const& Material::getkd() const
{
	return kd;
}

Color const& Material::getks() const
{
	return ks;
}

float const Material::getm() const
{
	return m;
}

std::ostream& operator<<(std::ostream& os, Material const& mat) // in die hpp
{
	os << "Name: " << mat.getname() << "\n" << "Color: " << mat.getka() << mat.getkd() << mat.getks() << "m: " << mat.getm();
	return os;
}