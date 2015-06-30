#ifndef BUW_SDFLOADER_HPP
#define BUW_SDFLOADER_HPP
#include <material.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <utility>


std::vector<Material> loadSDF(std::string const& file);

#endif