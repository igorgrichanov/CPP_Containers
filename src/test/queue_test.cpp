#include "test_entry.h"

namespace containers {

TEST(QueueContainer, test_default_constructor) {
  queue<int> q;
  EXPECT_TRUE(q.empty());
  EXPECT_EQ(q.size(), (size_t)0);
}

TEST(QueueContainer, test_constructor_init_list_one_element) {
  queue<int> q{8};
  EXPECT_FALSE(q.empty());
  EXPECT_EQ(q.size(), (size_t)1);
}

TEST(QueueContainer, test_constructor_init_list_many_elements) {
  queue<int> q{8, 128, 15};
  EXPECT_FALSE(q.empty());
  EXPECT_EQ(q.size(), (size_t)3);
}

TEST(QueueContainer, test_constructor_copy) {
  queue<int> list1{1, 2, 3, 4, 5};
  EXPECT_FALSE(list1.empty());
  EXPECT_EQ(list1.size(), (size_t)5);
  queue<int> list2(list1);
  EXPECT_FALSE(list2.empty());
  EXPECT_EQ(list2.size(), (size_t)5);
  EXPECT_FALSE(list1.empty());
  EXPECT_EQ(list1.size(), (size_t)5);
  EXPECT_EQ(list1.front(), list2.front());
}

TEST(QueueContainer, test_constructor_move) {
  queue<int> list1{1, 2, 3, 4, 5};
  EXPECT_FALSE(list1.empty());
  EXPECT_EQ(list1.size(), (size_t)5);
  queue<int> list2(std::move(list1));
  EXPECT_TRUE(list1.empty());
  EXPECT_EQ(list1.size(), (size_t)0);
  EXPECT_FALSE(list2.empty());
  EXPECT_EQ(list2.size(), (size_t)5);
  EXPECT_EQ(list2.front(), 1);
}

TEST(QueueContainer, test_front_back) {
  queue<int> q{8, 128, 15};
  EXPECT_EQ(q.front(), 8);
  EXPECT_EQ(q.back(), 15);
}

TEST(QueueContainer, test_push_pop) {
  queue<int> q;
  EXPECT_TRUE(q.empty());
  EXPECT_EQ(q.size(), (size_t)0);
  q.push(1);
  EXPECT_FALSE(q.empty());
  EXPECT_EQ(q.size(), (size_t)1);
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(), 1);
  q.pop();
  EXPECT_TRUE(q.empty());
  EXPECT_EQ(q.size(), (size_t)0);
  q.push(2);
  q.push(3);
  EXPECT_FALSE(q.empty());
  EXPECT_EQ(q.size(), (size_t)2);
  EXPECT_EQ(q.front(), 2);
  EXPECT_EQ(q.back(), 3);
  q.push(4);
  EXPECT_EQ(q.front(), 2);
  EXPECT_EQ(q.back(), 4);
  q.pop();
  q.pop();
  EXPECT_EQ(q.size(), (size_t)1);
  EXPECT_EQ(q.front(), 4);
  EXPECT_EQ(q.back(), 4);
}

TEST(QueueContainer, test_swap) {
  queue<int> q1{1, 2, 3}, q2{4, 5};
  EXPECT_EQ(q1.size(), (size_t)3);
  EXPECT_EQ(q2.size(), (size_t)2);
  q1.swap(q2);
  EXPECT_EQ(q1.size(), (size_t)2);
  EXPECT_EQ(q2.size(), (size_t)3);
  EXPECT_EQ(q1.front(), 4);
  EXPECT_EQ(q2.front(), 1);
}

TEST(QueueContainer, test_insert_many_back) {
  queue<int> q{4, 5};
  q.insert_many_back(1, 2, 3);
  EXPECT_EQ(q.size(), (size_t)5);
  EXPECT_EQ(q.front(), 4);
  EXPECT_EQ(q.back(), 3);
}

}  // namespace containers
