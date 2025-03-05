#include "gtest.h"
#include "monom.h"

TEST(Monom, can_create_monom1)
{
	ASSERT_NO_THROW(Monom a);
}
TEST(Monom, can_create_monom2)
{
	ASSERT_NO_THROW(Monom a(111,2));
}
TEST(Monom, cant_create_monom3)
{
	ASSERT_ANY_THROW(Monom a(1001, 56));
}
TEST(Monom, can_get_x_deg)
{
	Monom a(111, 2);
	EXPECT_EQ(1, a.x_deg());
}
TEST(Monom, can_get_y_deg)
{
	Monom a(151, 2);
	EXPECT_EQ(5, a.y_deg());
}
TEST(Monom, can_get_z_deg)
{
	Monom a(119, 2);
	EXPECT_EQ(9, a.z_deg());
}
TEST(Monom, can_check_correct_degree)
{
	Monom a(999, 2);
	EXPECT_EQ(1, a.is_deg_correct());
}
TEST(Monom, can_add_monoms)
{
	Monom a(111, 2); // 2xyz
	Monom b(111, 94); // 94xyz
	ASSERT_NO_THROW(a + b);
	Monom c = a + b;
	EXPECT_EQ(1, c.is_deg_correct());
	EXPECT_EQ(96, c.get_k());
}
TEST(Monom, can_sub_monoms)
{
	Monom a(111, 2); // 2xyz
	Monom b(111, 94); // 94xyz
	ASSERT_NO_THROW(a - b);
	Monom c = a - b;
	EXPECT_EQ(1, c.is_deg_correct());
	EXPECT_EQ(-92, c.get_k());
}
TEST(Monom, cant_add_monoms)
{
	Monom a(111, 2); // 2xyz
	Monom b(234, 94); // 94*x^2*y^3*z^4
	ASSERT_ANY_THROW(a+b);
}
TEST(Monom, cant_sub_monoms)
{
	Monom a(111, 2); // 2xyz
	Monom b(234, 94); // 94*x^2*y^3*z^4
	ASSERT_ANY_THROW(a - b);
}
TEST(Monom, can_mul_monoms)
{
	Monom a(111, 2); // 2xyz
	Monom b(234, 94); // 94*x^2*y^3*z^4
	ASSERT_NO_THROW(a * b);
	Monom c = a * b; // 188*x^3*y^4*z^5;
	EXPECT_EQ(1, c.is_deg_correct());
	EXPECT_EQ(345, c.get_deg());
	EXPECT_EQ(188, c.get_k());
}
TEST(Monom, can_mul_monom_const)
{
	Monom a(111, 2); // 2xyz
	Monom c = a*3; // 6xyz;
	EXPECT_EQ(1, c.is_deg_correct());
	EXPECT_EQ(6, c.get_k());
}
TEST(Monom, cant_mul_monoms1)
{
	Monom a(766, 2); // 2*x^7*y^6*z^6
	Monom b(234, 94); // 94*x^2*y^3*z^4
	ASSERT_ANY_THROW(a * b);
}
TEST(Monom, cant_mul_monoms2)
{
	Monom a(111, 2); // 2xyz
	Monom b(999, 94); // 94*x^9*y^9*z^9
	ASSERT_ANY_THROW(a * b);
}