#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.cpp"
#include "box.cpp"

TEST_CASE("aufgabe5", "[5_aufgabe]")
{
	Sphere sp{glm::vec3{0.0, 0.0, 0.0}, {1.0}, "Testsphere", Color{0.0, 1.0, 1.0}};
	std::cout << sp << std::endl;
}

/*TEST_CASE("aufgabe4", "[4_print]")
{
	Sphere sp{"TaskSphere", Color{0.0, 1.0, 1.0}};
	std::cout << sp << std::endl;
}*/

TEST_CASE("aufgabe31", "[3_konstruktor_box]")
{
	Box b1{glm::vec3{0.0, 0.0, 0.0}, glm::vec3{2.0, 2.0, 2.0}, "TestBox", Color{1.0, 0.0, 0.0}};
	glm::vec3 min{0.0, 0.0, 0.0};
	glm::vec3 max{2.0, 2.0, 2.0};
	Color color{1.0, 0.0, 0.0};
	std::string name = "TestBox";
	REQUIRE(b1.getname() == name);
	REQUIRE(b1.getcolor().r == color.r);
	REQUIRE(b1.getcolor().g == color.g);
	REQUIRE(b1.getcolor().b == color.b);
	REQUIRE(b1.getmin() == min);
	REQUIRE(b1.getmax() ==max);
}

TEST_CASE("aufgabe3", "[3_konstruktor_sphere]")
{
	Sphere s1{glm::vec3{0.0, 1.0, 0.0}, {2.0}, "TestSphere", Color{0.0, 1.0, 0.0}};
	glm::vec3 center{0.0, 1.0, 0.0};
	double radius = 2.0;
	std::string name = "TestSphere";
	Color color{0.0, 1.0, 0.0};
	REQUIRE(s1.getname() == name);
	REQUIRE(s1.getcolor().r == color.r);
	REQUIRE(s1.getcolor().g == color.g);
	REQUIRE(s1.getcolor().b == color.b);
	REQUIRE(s1.getradius() == radius);
	REQUIRE(s1.getcenter() == center);
}

TEST_CASE("aufgabe24", "[2_min_max_box]")
{
	Box b{glm::vec3{0.0, 3.0, 4.0}, glm::vec3{3.0, 5.0, 6.0}};
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
