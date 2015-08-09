// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andre Schollmeyer and Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Pixel
// -----------------------------------------------------------------------------

#include "pixel.hpp"
#include <ostream>

Pixel::Pixel(unsigned int a, unsigned int b)
  : x(a),
    y(b),
    color(0,0,0)
{}

/*Pixel::Pixel(unsigned int a, unsigned int b, Color c)
  : x(a),
    y(b),
    color(c)
{}*/

void Pixel::print(std::ostream& os) const
{
  os << "Pixel[" << (int)x << ',' << (int)y << "]("
     << color.r << ','
     << color.g << ','
     << color.b << ')';
}

std::ostream& operator<<(std::ostream& os, const Pixel& a)
{
  std::ostream::sentry cerberus (os);
  if (cerberus)
    a.print(os);
  return os;
}
