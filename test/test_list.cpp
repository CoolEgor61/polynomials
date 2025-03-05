#include "gtest.h"
#include "list.h"

TEST(List, can_create_node)
{
	ASSERT_NO_THROW(TNode<int> a(25,NULL));
}
TEST(List, can_get_value)
{
	TNode<int> a(25, NULL);
	EXPECT_EQ(25, a.value);
}
TEST(List, can_create_list1)
{
	ASSERT_NO_THROW(TList<int> a);

}
TEST(List, can_create_list2)
{
	TNode<int>* a = new TNode<int>(25, NULL);
	ASSERT_NO_THROW(TList<int> c(a));

}
TEST(List, can_push_front)
{
	TNode<int>* a = new TNode<int>(25, NULL);
	TList<int> c(a);
	c.push_front(24);
	EXPECT_EQ(24, c.get_first()->value);
}
TEST(List, can_push_back)
{
	TNode<int>* a = new TNode<int>(25, NULL);
	TList<int> c(a);
	c.push_back(244);
	TNode<int>* q = c.get_last();
	EXPECT_EQ(244, q->value);
}
TEST(List, can_pop_front)
{
	TNode<int>* a = new TNode<int>(25, NULL);
	TList<int> c(a);
	c.push_front(24);
	c.pop_front();
	EXPECT_EQ(25, c.get_first()->value);
}
TEST(List, can_pop_back)
{
	TNode<int>* a = new TNode<int>(25, NULL);
	TList<int> c(a);
	c.push_back(244);
	c.pop_back();
	TNode<int>* q = c.get_last();
	EXPECT_EQ(25, q->value);
}
TEST(List, can_insert)
{
	TNode<int>* a = new TNode<int>(25, NULL);
	TList<int> c(a);
	c.push_front(24);
	c.insert(14, c.get_last());
	TNode<int>* q = c.get_last();
	EXPECT_EQ(14, q->value);
}
TEST(List, can_erase)
{
	TNode<int>* a = new TNode<int>(25, NULL);
	TList<int> c(a);
	c.push_front(24);
	c.insert(14, c.get_last());
	c.erase(c.get_first());
	TNode<int>* q = c.get_first();
	EXPECT_EQ(24, q->value);
}
