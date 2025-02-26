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
