#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.cpp"
#include "box.cpp"

TEST_CASE("aufgabe24", "[2_min_max_box]")
{
	Box b{{0.0, 3.0, 4.0}, {3.0, 5.0, 6.0}};
	glm::vec3 minimum{0.0, 3.0, 4.0};
	glm::vec3 maximum{3.0, 5.0, 6.0};
	REQUIRE(b.getmin() == minimum);
	REQUIRE(b.getmax() == maximum);
}

TEST_CASE("aufgabe23", "[2_area_volume_box]")
{
	Box b{};
	REQUIRE(b.area() == Approx(6.0).epsilon(0.001));
	REQUIRE(b.volume() == Approx(1.0).epsilon(0.001));
}

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
