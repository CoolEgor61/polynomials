#include "gtest.h"
#include "polynom.h"

TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom a);
}

TEST(Polynom, can_create_polynom_from_list)
{
	TList<Monom>b;
	Monom c(100, 2), d(111, 1);
	b.push_back(c); b.push_back(d);
	ASSERT_NO_THROW(Polynom a(b));
}
TEST(Polynom, can_add_polynoms)
{
	TList<Monom>b, b1;
	Monom c(100, 2), d(111, 1); Monom ans1(100, 4), ans2(111, 2), fst;
	b.push_back(c); b.push_back(d);
	b1.push_back(c); b1.push_back(d);
	Polynom a1(b), a2(b1); // 0+2x+xyz, 0+2x+xyz
	Polynom q(a1 + a2); // 0+4x+2xyz
	EXPECT_EQ(fst.get_deg(), q.Plnm.first->value.get_deg());
	EXPECT_EQ(fst.get_k(), q.Plnm.first->value.get_k());
	TNode<Monom>* next_n = q.Plnm.first->next;
	EXPECT_EQ(ans1.get_deg(), next_n->value.get_deg());
	EXPECT_EQ(ans1.get_k(), next_n->value.get_k());
	next_n = next_n->next;
	EXPECT_EQ(ans2.get_deg(), next_n->value.get_deg());
	EXPECT_EQ(ans2.get_k(), next_n->value.get_k());
}
TEST(Polynom, can_sub_polynoms)
{
	TList<Monom>b, b1;
	Monom c(100, 2), d(111, 1); Monom ans1(100, 4), ans2(111, 2), fst;
	b.push_back(c); b.push_back(d);
	b1.push_back(c); b1.push_back(d);
	Polynom a1(b), a2(b1); // 0+2x+xyz, 0+2x+xyz
	Polynom q(a1 - a2); // 0
	EXPECT_EQ(fst.get_deg(), q.Plnm.first->value.get_deg());
	EXPECT_EQ(fst.get_k(), q.Plnm.first->value.get_k());
}
TEST(Polynom, can_mul_scalar)
{
	TList<Monom>b, b1;
	Monom c(100, 2), d(111, 1); Monom ans1(100, 8), ans2(111, 4), fst;
	b.push_back(c); b.push_back(d);
	Polynom a1(b); // 0+2x+xyz
	Polynom q(a1 * 4); // 0+8x+4xyz
	EXPECT_EQ(fst.get_deg(), q.Plnm.first->value.get_deg());
	EXPECT_EQ(fst.get_k(), q.Plnm.first->value.get_k());
	TNode<Monom>* next_n = q.Plnm.first->next;
	EXPECT_EQ(ans1.get_deg(), next_n->value.get_deg());
	EXPECT_EQ(ans1.get_k(), next_n->value.get_k());
	next_n = next_n->next;
	EXPECT_EQ(ans2.get_deg(), next_n->value.get_deg());
	EXPECT_EQ(ans2.get_k(), next_n->value.get_k());
}
TEST(Polynom, can_mul_polynoms)
{
	TList<Monom>b, b1;
	Monom c(100, 2), d(111, 1); Monom ans1(200, 4), ans2(211, 2), ans3(222,1), fst;
	b.push_back(c); b.push_back(d);
	b1.push_back(c); b1.push_back(d);
	Polynom a1(b), a2(b1); // 0+2x+xyz, 0+2x+xyz
	Polynom q(a1 * a2); // 0 + 4*x^2 + 2*x^2*y*z + 2*x^2*y*z + x^2*y^2*z^2
	EXPECT_EQ(fst.get_deg(), q.Plnm.first->value.get_deg());
	EXPECT_EQ(fst.get_k(), q.Plnm.first->value.get_k());
	TNode<Monom>* next_n = q.Plnm.first->next;
	EXPECT_EQ(ans1.get_deg(), next_n->value.get_deg());
	EXPECT_EQ(ans1.get_k(), next_n->value.get_k());
	next_n = next_n->next;
	EXPECT_EQ(ans2.get_deg(), next_n->value.get_deg());
	EXPECT_EQ(ans2.get_k(), next_n->value.get_k());
	next_n = next_n->next;
	EXPECT_EQ(ans2.get_deg(), next_n->value.get_deg());
	EXPECT_EQ(ans2.get_k(), next_n->value.get_k());
	next_n = next_n->next;
	EXPECT_EQ(ans3.get_deg(), next_n->value.get_deg());
	EXPECT_EQ(ans3.get_k(), next_n->value.get_k());
}