#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.cpp"
#include "box.cpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE("aufgabe8", "[aufgabe8]")
{
	std::cout << "hier gehts los" << std::endl;

	Color red(255, 0, 0);
	glm::vec3 position(0.0);

	Sphere* s1 = new Sphere(position, 1.2, "sphere0", red);
	Shape* s2 = new Sphere(position, 1.2, "sphere1", red);

	s1->print(std::cout);
	s2->print(std::cout);

	delete s1;
	delete s2;

	std::cout << "hier endets" << std::endl;
}

TEST_CASE("aufgabe61_intersectSphere", "[intersectSphere]")
{
	Ray r1{{0.0, 0.0, 0.0}, {0.0, 1.0, 2.0}};
	Sphere s1{};
	bool intersection = s1.intersect(r1);
	REQUIRE(intersection == true);
}

TEST_CASE("aufgabe6_intersectRaySphere", "[intersect]")
{
	//Ray
	glm::vec3 ray_origin(0.0, 0.0, 0.0);
	// ray direction has to be normalized!
	// you can use:
	// v= glm::normalize(some_vector)
	glm::vec3 ray_direction(0.0, 0.0, 1.0);

	//Sphere
	glm::vec3 sphere_center(0.0, 0.0, 5.0);
	float sphere_radius(1.0);

	float distance(0.0);
	auto result = glm::intersectRaySphere(ray_origin, ray_direction, sphere_center, sphere_radius, distance);
	REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("aufgabe51", "[5_aufgabe]")
{
    Box bp(glm::vec3{0.0, 0.0, 1.0}, glm::vec3{2.0, 3.0, 4.0}, 
		"Testbox", Color{0.0, 1.0, 1.0});
    std::cout << bp << std::endl;
}

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
