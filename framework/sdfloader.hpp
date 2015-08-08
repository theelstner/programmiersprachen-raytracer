#ifndef BUW_SDFLOADER_HPP
#define BUW_SDFLOADER_HPP
#include "scene.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <utility>


Scene* loadSDF(std::string const& file);

#endif