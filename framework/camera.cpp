#include "camera.hpp"

Camera::Camera() :
name_{},
position_{0, 0, 0},
fov_x_{45}
{}

Camera::Camera(std::string const& name, double fov_x) :
name_{name},
position_{0, 0, 0},
fov_x_{fov_x}
{}

std::string const& Camera::getname() const
{
	return name_;
}

glm::vec3 const& Camera::getpostion() const
{
	return position_;
}
	
double const& Camera::getfov_x() const
{
	return fov_x_;
}