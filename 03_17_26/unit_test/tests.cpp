#include <gtest/gtest.h>
#include <cmath>
#include "../donut.h"
using namespace std;
// extern "C" int __wrap_main();

// int startTest() __attribute__ ((constructor));
TEST(donutTest, constructorAndGetterTest)
{
	donut cube("Chocolate", "Peanuts", "Peanut Butter");
	ASSERT_EQ(cube.getIcing(), CHOCOLATEICING);
	ASSERT_EQ(cube.getTopping(), donut::PEANUTS);
	ASSERT_EQ(cube.getDrizzle(), drizzleType::PEANUTBUTTER);
	donut cube2("coco", "nut", "stuff");
	ASSERT_EQ(cube2.getIcing(), NOICE);
	ASSERT_EQ(cube2.getDrizzle(), drizzleType::NODRIZZLE);
	ASSERT_EQ(cube2.getTopping(), donut::NOTOP);
}
TEST(donutTest, icingSetterTest)
{
	donut cube;
	// cube.setIcing("coco");
	ASSERT_EQ(cube.getIcing(), NOICE);
	cube.setIcing("Maple");
	ASSERT_EQ(cube.getIcing(), MAPLE);
}
TEST(donutTest, toppingSetterTest)
{
	donut cube;
	// cube.setTopping("coco");
	ASSERT_EQ(cube.getTopping(), donut::NOTOP);
	cube.setTopping("Chocolate Chips");
	ASSERT_EQ(cube.getTopping(), donut::CHOCOLATECHIPS);
}
TEST(donutTest, drizzleSetterTest)
{
	donut cube;
	cube.setDrizzle("coco");
	ASSERT_EQ(cube.getDrizzle(), drizzleType::NODRIZZLE);
	cube.setDrizzle("Raspberry");
	ASSERT_EQ(cube.getDrizzle(), drizzleType::RASPBERRY);
}

extern "C" int startTest(int x, char **y)
{
	// cout << "begin" << endl;
	// int x = 0;
	// char ** y = NULL;
	testing::InitGoogleTest(&x, y);
	// cout << "Init Complete"<< endl;
	int code = RUN_ALL_TESTS();
	// exit(code);
	return code;
}
// int i = startTest();
extern "C" int __wrap_main(int x, char **y)
{
	return startTest(x, y);
}