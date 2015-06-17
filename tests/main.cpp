#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.cpp"

TEST_CASE("aufgabe22", "[2_center_radius_sphere]")
{
	Sphere s{{0.0, 1.0, 2.0}, {3.0}};
	glm::vec3 v3{0.0, 1.0, 2.0};
	REQUIRE(s.getcenter() == v3);
	REQUIRE(s.getradius() == 3.0);
}

TEST_CASE("aufgabe2", "[2_area_volume_sphere]")
{
	Sphere s{};
	REQUIRE(s.area() == Approx(12.56).epsilon(0.001));
	REQUIRE(s.volume() == Approx(4.19).epsilon(0.001));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
