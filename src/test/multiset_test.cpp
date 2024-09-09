#include <iterator>

#include "test_entry.h"

namespace containers {

TEST(MultiSetConstructorTest, DefaultConstructor) {
  multiset<int> multiset;

  EXPECT_TRUE(multiset.empty());
}

TEST(MultiSetConstructorTest, CopyConstructor) {
  multiset<int> original = {1, 2, 3};
  multiset<int> copied(original);

  EXPECT_EQ(original.size(), copied.size());
  for (auto it = original.begin(); it != original.end(); ++it) {
    EXPECT_TRUE(copied.contains(*it));
  }
}

TEST(MultiSetConstructorTest, MoveConstructor) {
  multiset<int> original = {1, 2, 3};
  multiset<int> moved(std::move(original));

  EXPECT_EQ(original.size(), (size_t)0);
  EXPECT_EQ(moved.size(), (size_t)3);
}

TEST(MultiSetConstructorTest, InitializerListConstructor) {
  multiset<int> multiset = {1, 2, 3};

  EXPECT_EQ(multiset.size(), (size_t)3);
}

TEST(MultiSetConstructorTest, EmptyInitializerListConstructor) {
  multiset<int> multiset = {};

  EXPECT_TRUE(multiset.empty());
}

TEST(MultiSetConstructorTest, DuplicateElementsInitializerListConstructor) {
  multiset<int> multiset = {1, 2, 2, 3, 3};

  EXPECT_EQ(multiset.size(), (size_t)5);
}

TEST(MultiSetConstructorTest, StringConstructor) {
  multiset<std::string> multiset = {"apple", "banana", "cherry"};

  EXPECT_EQ(multiset.size(), (size_t)3);
}

TEST(MultiSetConstructorTest, LargeMultiSetConstructor) {
  multiset<int> multiset;

  for (int i = 0; i < 1000; ++i) {
    multiset.insert(i);
  }

  EXPECT_EQ(multiset.size(), (size_t)1000);
}

TEST(MultiSetInsertTest, InsertSingleElement) {
  multiset<int> multiset;
  multiset.insert(5);

  EXPECT_EQ(multiset.size(), (size_t)1);
}

TEST(MultiSetInsertTest, InsertDuplicateElements) {
  multiset<int> multiset;
  multiset.insert(5);
  multiset.insert(5);

  EXPECT_EQ(multiset.size(), (size_t)2);
}

TEST(MultiSetInsertTest, InsertMultipleElements) {
  multiset<int> multiset;
  multiset.insert(5);
  multiset.insert(10);
  multiset.insert(5);

  EXPECT_EQ(multiset.size(), (size_t)3);
}

TEST(MultiSetInsertTest, InsertLargeNumberOfElements) {
  multiset<int> multiset;

  for (int i = 0; i < 1000; ++i) {
    multiset.insert(i);
  }

  EXPECT_EQ(multiset.size(), (size_t)1000);
}

TEST(MultiSetInsertTest, InsertStringElements) {
  multiset<std::string> multiset;
  multiset.insert("apple");
  multiset.insert("banana");
  multiset.insert("apple");

  EXPECT_EQ(multiset.size(), (size_t)3);
}

TEST(MultiSetInsertTest, InsertMixedElements) {
  multiset<int> multiset;
  multiset.insert(5);
  multiset.insert(3);
  multiset.insert(7);

  EXPECT_EQ(multiset.size(), (size_t)3);
}

TEST(MultiSetInsertTest, InsertMultipleDuplicates) {
  multiset<int> multiset;
  multiset.insert(5);
  multiset.insert(5);
  multiset.insert(5);

  EXPECT_EQ(multiset.size(), (size_t)3);
}

TEST(MultiSetInsertTest, InsertLargeNumberOfElementsWithDuplicates) {
  multiset<int> multiset;

  for (int i = 0; i < 1000; ++i) {
    multiset.insert(i);
    multiset.insert(i);  // Insert duplicates
  }

  EXPECT_EQ(multiset.size(), (size_t)2000);
}

TEST(MultiSetEraseTest, EraseExistingElement) {
  multiset<int> multiset = {1, 2, 2, 3, 4};
  auto it = multiset.find(2);
  multiset.erase(it);

  EXPECT_EQ(multiset.size(), (size_t)4);
  EXPECT_EQ(multiset.count(2), (size_t)1);
}

TEST(MultiSetEraseTest, EraseNonExistingElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.find(5);
  multiset.erase(it);

  EXPECT_EQ(multiset.size(), (size_t)4);
}

TEST(MultiSetEraseTest, EraseEmptySet) {
  multiset<int> multiset;
  multiset.erase(multiset.end());

  EXPECT_TRUE(multiset.empty());
}

TEST(MultiSetEraseTest, EraseLastElement) {
  multiset<int> multiset = {1, 2, 3};
  multiset.erase(multiset.find(3));

  EXPECT_EQ(multiset.size(), (size_t)2);
  EXPECT_EQ(multiset.count(3), (size_t)0);
}

TEST(MultiSetFindTest, FindExistingElement) {
  multiset<int> multiset = {1, 2, 2, 3, 4};
  auto it = multiset.find(2);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 2);
}

TEST(MultiSetFindTest, FindNonExistingElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.find(5);

  EXPECT_EQ(it, multiset.end());
}

TEST(MultiSetFindTest, FindFirstElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.find(1);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 1);
}

TEST(MultiSetFindTest, FindLastElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.find(4);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 4);
}

TEST(MultiSetFindTest, FindMiddleElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.find(2);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 2);
}

TEST(MultiSetContainsTest, ContainsExistingElement) {
  multiset<int> multiset = {1, 2, 3, 4};

  EXPECT_TRUE(multiset.contains(2));
}

TEST(MultiSetContainsTest, ContainsNonExistingElement) {
  multiset<int> multiset = {1, 2, 3, 4};

  EXPECT_FALSE(multiset.contains(5));
}

TEST(MultiSetContainsTest, ContainsFirstElement) {
  multiset<int> multiset = {1, 2, 3, 4};

  EXPECT_TRUE(multiset.contains(1));
}

TEST(MultiSetContainsTest, ContainsLastElement) {
  multiset<int> multiset = {1, 2, 3, 4};

  EXPECT_TRUE(multiset.contains(4));
}

TEST(MultiSetContainsTest, ContainsMiddleElement) {
  multiset<int> multiset = {1, 2, 3, 4};

  EXPECT_TRUE(multiset.contains(2));
}

TEST(MultiSetContainsTest, ContainsElementFromEmptySet) {
  multiset<int> multiset;

  EXPECT_FALSE(multiset.contains(2));
}

class CustomClass {
 public:
  int value;

  CustomClass() : value(0) {}

  CustomClass(int val) : value(val) {}

  CustomClass(const CustomClass &other) : value(other.value){};

  bool operator<(const CustomClass &other) const { return value < other.value; }

  bool operator>=(const CustomClass &other) const {
    return value >= other.value;
  }
  bool operator>(const CustomClass &other) const { return value > other.value; }

  bool operator==(const CustomClass &other) const {
    return value == other.value;
  }

  CustomClass &operator=(const CustomClass &other) {
    if (this != &other) {
      value = other.value;
    }
    return *this;
  }
};

TEST(MultiSetEqualRangeTest, EqualRangeExistingElement) {
  multiset<int> multiset = {1, 2, 2, 3, 4};
  auto range = multiset.equal_range(2);

  EXPECT_EQ(++range.first, range.second);
}

TEST(MultiSetEqualRangeTest, EqualRangeNonExistingElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto range = multiset.equal_range(5);

  EXPECT_EQ(range.first, range.second);
}

TEST(MultiSetEqualRangeTest, EqualRangeCustomClass) {
  multiset<CustomClass> multiset = {CustomClass(1), CustomClass(2),
                                    CustomClass(2), CustomClass(3)};
  CustomClass target(2);
  auto range = multiset.equal_range(target);

  EXPECT_EQ(*range.first, target);
  EXPECT_EQ(*range.second, target);
  EXPECT_EQ(++range.first, range.second);
}

TEST(MultiSetEqualRangeTest, EqualRangeCustomClassNonExisting) {
  multiset<CustomClass> multiset = {CustomClass(1), CustomClass(2),
                                    CustomClass(3)};
  CustomClass target(4);
  auto range = multiset.equal_range(target);

  EXPECT_EQ(range.first, multiset.end());
  EXPECT_EQ(range.second, multiset.end());
}

TEST(MultiSetEqualRangeTest, EqualRangeEmptySet) {
  multiset<int> multiset;
  auto range = multiset.equal_range(1);

  EXPECT_EQ(range.first, multiset.end());
  EXPECT_EQ(range.second, multiset.end());
}

TEST(MultiSetEqualRangeTest, EqualRangeFirstElement) {
  multiset<int> multiset = {1, 2, 2, 3, 4};
  auto range = multiset.equal_range(1);

  EXPECT_EQ(range.first, range.second);
  EXPECT_EQ(*range.first, 1);
  EXPECT_EQ(*range.second, 1);
}

TEST(MultiSetEqualRangeTest, EqualRangeLastElement) {
  multiset<int> multiset = {1, 2, 2, 3, 4};
  auto range = multiset.equal_range(4);

  EXPECT_EQ(range.first, range.second);
  EXPECT_EQ(*range.first, 4);
  EXPECT_EQ(*range.second, 4);
}

TEST(MultiSetEqualRangeTest, EqualRangeRangeWithMultipleElements) {
  multiset<int> multiset = {1, 2, 1, 2, 3, 4};
  auto range = multiset.equal_range(2);

  EXPECT_EQ(*range.first, 2);
  EXPECT_EQ(*range.second, 2);
  EXPECT_EQ(++range.first, range.second);
}

TEST(MultiSetLowerBoundTest, LowerBoundExistingElement) {
  multiset<int> multiset = {1, 2, 2, 3, 4};
  auto it = multiset.lower_bound(2);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 2);
}

TEST(MultiSetLowerBoundTest, LowerBoundNonExistingElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.lower_bound(5);

  EXPECT_EQ(it, multiset.end());
}

TEST(MultiSetLowerBoundTest, LowerBoundCustomClass) {
  multiset<CustomClass> multiset = {CustomClass(1), CustomClass(2),
                                    CustomClass(3)};
  CustomClass target(2);
  auto it = multiset.lower_bound(target);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ((*it).value, 2);
}

TEST(MultiSetLowerBoundTest, LowerBoundEmptySet) {
  multiset<int> multiset;
  auto it = multiset.lower_bound(1);

  EXPECT_EQ(it, multiset.end());
}

TEST(MultiSetLowerBoundTest, LowerBoundFirstElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.lower_bound(1);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 1);
}

TEST(MultiSetUpperBoundTest, UpperBoundExistingElement) {
  multiset<int> multiset = {1, 2, 2, 3, 4};
  auto it = multiset.upper_bound(2);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 3);
}

TEST(MultiSetUpperBoundTest, UpperBoundNonExistingElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.upper_bound(2);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ(*it, 3);
}

TEST(MultiSetUpperBoundTest, UpperBoundCustomClass) {
  multiset<CustomClass> multiset = {CustomClass(1), CustomClass(2),
                                    CustomClass(2), CustomClass(3)};
  CustomClass target(2);
  auto it = multiset.upper_bound(target);

  EXPECT_NE(it, multiset.end());
  EXPECT_EQ((*it).value, 3);
}

TEST(MultiSetUpperBoundTest, UpperBoundEmptySet) {
  multiset<int> multiset;
  auto it = multiset.upper_bound(1);

  EXPECT_EQ(it, multiset.end());
}

TEST(MultiSetUpperBoundTest, UpperBoundLastElement) {
  multiset<int> multiset = {1, 2, 3, 4};
  auto it = multiset.upper_bound(4);

  EXPECT_EQ(it, multiset.end());
}

TEST(MultiSetInsertManyTest, InsertManyIntegers) {
  multiset<int> multiset;
  auto result = multiset.insert_many(1, 2, 3, 4, 5);

  EXPECT_EQ(result.size(), (size_t)5);
  for (const auto &pair : result) {
    EXPECT_TRUE(pair.second);  // Ensure all elements were inserted
  }

  EXPECT_EQ(multiset.size(), (size_t)5);
}

TEST(MultiSetInsertManyTest, InsertManyStrings) {
  multiset<std::string> multiset;
  auto result = multiset.insert_many("apple", "banana", "cherry");

  EXPECT_EQ(result.size(), (size_t)3);
  for (const auto &pair : result) {
    EXPECT_TRUE(pair.second);  // Ensure all elements were inserted
  }

  EXPECT_EQ(multiset.size(), (size_t)3);
}

TEST(MultiSetInsertManyTest, InsertManyCustomClass) {
  multiset<std::pair<int, std::string>> multiset;
  auto result =
      multiset.insert_many(std::make_pair(1, "one"), std::make_pair(2, "two"));

  EXPECT_EQ(result.size(), (size_t)2);
  for (const auto &pair : result) {
    EXPECT_TRUE(pair.second);  // Ensure all elements were inserted
  }

  EXPECT_EQ(multiset.size(), (size_t)2);
}

TEST(MultiSetInsertManyTest, InsertManyDuplicates) {
  multiset<int> multiset;
  auto result = multiset.insert_many(1, 2, 3, 3, 4, 4, 4);

  EXPECT_EQ(result.size(),
            (size_t)7);  // All elements should be considered inserted
  EXPECT_EQ(multiset.size(), (size_t)7);  // Size should reflect all elements
  for (const auto &pair : result) {
    EXPECT_TRUE(pair.second);  // Ensure all elements were inserted
  }
}

}  // namespace containers