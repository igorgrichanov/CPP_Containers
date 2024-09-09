#include "test_entry.h"

namespace containers {

TEST(SetConstructorTest, EmptyConstructor) {
  set<int> mySet;
  EXPECT_TRUE(mySet.empty());
}

TEST(SetConstructorTest, InitializerListConstructor) {
  set<int> mySet = {1, 2, 3, 4, 5};
  EXPECT_EQ(mySet.size(), (size_t)5);
}

TEST(SetConstructorTest, CopyConstructor) {
  set<int> originalSet = {1, 2, 3};
  set<int> copiedSet(originalSet);
  EXPECT_EQ(originalSet.size(), (size_t)copiedSet.size());
}

TEST(SetConstructorTest, MoveConstructor) {
  set<int> originalSet = {1, 2, 3};
  set<int> movedSet(std::move(originalSet));
  EXPECT_EQ(originalSet.size(), (size_t)0);
  EXPECT_EQ(movedSet.size(), (size_t)3);
}

TEST(SetConstructorTest, InitializerListConstructorEmpty) {
  set<int> emptySet = {};
  EXPECT_TRUE(emptySet.empty());
}

TEST(SetConstructorTest, DefaultMaxSizeConstructor) {
  set<int> mySet;
  EXPECT_EQ(mySet.max_size(), std::numeric_limits<size_t>::max() / 32);
}

TEST(SetConstructorTest, InsertConstructor) {
  set<int> mySet = {1, 2, 3};
  mySet.insert(4);
  EXPECT_EQ(mySet.size(), (size_t)4);
}

TEST(SetConstructorTest, ClearConstructor) {
  set<int> mySet = {1, 2, 3};
  mySet.clear();
  EXPECT_TRUE(mySet.empty());
}

TEST(SetClearTest, ClearEmptySet) {
  set<int> mySet;
  mySet.clear();
  EXPECT_TRUE(mySet.empty());
}

TEST(SetClearTest, ClearNonEmptySet) {
  set<int> mySet;
  mySet.insert(10);
  mySet.insert(5);
  mySet.insert(15);
  mySet.clear();
  EXPECT_TRUE(mySet.empty());
}

TEST(SetClearTest, ClearNonEmptySetCheckSize) {
  set<int> mySet;
  mySet.insert(10);
  mySet.insert(5);
  mySet.insert(15);
  mySet.clear();
  EXPECT_EQ(mySet.size(), (size_t)0);
}

TEST(SetInsertTest, InsertSingleElement) {
  set<int> mySet;
  mySet.insert(10);
  EXPECT_EQ(mySet.size(), (size_t)1);
  EXPECT_TRUE(mySet.contains(10));
}

TEST(SetInsertTest, InsertMultipleElements) {
  set<int> mySet;
  mySet.insert(10);
  mySet.insert(5);
  mySet.insert(15);
  EXPECT_EQ(mySet.size(), (size_t)3);
  EXPECT_TRUE(mySet.contains(10));
  EXPECT_TRUE(mySet.contains(5));
  EXPECT_TRUE(mySet.contains(15));
}

TEST(SetInsertTest, InsertDuplicateElement) {
  set<int> mySet;
  mySet.insert(10);
  mySet.insert(10);  // Повторное добавление
  EXPECT_EQ(mySet.size(),
            (size_t)1);  // Размер остается 1, так как дубликаты не добавляются
  EXPECT_TRUE(mySet.contains(10));
}
TEST(SetInsertTest, InsertEmptySet) {
  set<std::string> mySet;
  mySet.insert("apple");
  EXPECT_EQ(mySet.size(), (size_t)1);
  EXPECT_TRUE(mySet.contains("apple"));
}

TEST(SetInsertTest, InsertUniqueElements) {
  set<char> mySet;
  mySet.insert('a');
  mySet.insert('b');
  mySet.insert('c');
  EXPECT_EQ(mySet.size(), (size_t)3);
  EXPECT_TRUE(mySet.contains('a'));
  EXPECT_TRUE(mySet.contains('b'));
  EXPECT_TRUE(mySet.contains('c'));
}

TEST(SetInsertTest, InsertCustomObjects) {
  struct Person {
    std::string name;
    int age{};
    // Оператор меньше для сравнения объектов Person
    bool operator<(const Person& other) const { return age < other.age; }

    bool operator==(const Person& other) const {
      return name == other.name && age == other.age;
    }
  };

  set<Person> mySet;
  Person p1{"Alice", 25};
  Person p2{"Bob", 30};
  mySet.insert(p1);
  mySet.insert(p2);
  EXPECT_EQ(mySet.size(), (size_t)2);
  EXPECT_TRUE(mySet.contains(p1));
  EXPECT_TRUE(mySet.contains(p2));
}

TEST(SetInsertReturnValueTest, InsertReturnValueSingleElement) {
  set<int> mySet;
  EXPECT_TRUE(
      mySet.insert(10).second);  // Проверяем, что вставка прошла успешно
  EXPECT_EQ(mySet.size(), (size_t)1);
  EXPECT_TRUE(mySet.contains(10));
}

TEST(SetInsertReturnValueTest, InsertReturnValueExistingElement) {
  set<int> mySet;
  mySet.insert(10);
  EXPECT_FALSE(
      mySet.insert(10)
          .second);  // Проверяем, что повторная вставка не добавляет элемент
  EXPECT_EQ(mySet.size(), (size_t)1);
}

TEST(SetInsertReturnValueTest, InsertReturnValueMultipleElements) {
  set<int> mySet;
  EXPECT_TRUE(mySet.insert(10).second);
  EXPECT_TRUE(mySet.insert(5).second);
  EXPECT_TRUE(mySet.insert(15).second);
  EXPECT_EQ(mySet.size(), (size_t)3);
}

TEST(SetInsertReturnValueTest, InsertReturnValueOverwriteElement) {
  set<int> mySet;
  mySet.insert(10);
  auto result = mySet.insert(10);  // Пытаемся вставить существующий элемент
  EXPECT_FALSE(result.second);  // Вставка не произошла
  EXPECT_EQ(*(result.first), 10);  // Проверяем, что возвращенный итератор
                                   // указывает на существующий элемент
}

TEST(SetEraseTest, EraseSingleElement) {
  set<int> mySet;
  mySet.insert(10);
  mySet.erase(mySet.find(10));
  EXPECT_TRUE(mySet.empty());
}

TEST(SetEraseTest, EraseNonExistingElement) {
  set<int> mySet;
  mySet.insert(10);
  mySet.erase(mySet.find(5));
  EXPECT_EQ(mySet.size(), (size_t)1);
}

TEST(SetEraseTest, EraseMultipleElements) {
  set<int> mySet;
  mySet.insert(10);
  mySet.insert(5);
  mySet.insert(15);
  mySet.erase(mySet.find(5));
  EXPECT_EQ(mySet.size(), (size_t)2);
}

TEST(SetEraseTest, EraseLastElement) {
  set<int> mySet;
  mySet.insert(4);
  mySet.insert(10);
  mySet.erase(mySet.find(10));
  EXPECT_EQ(mySet.size(), (size_t)1);
}

TEST(SetSwapTest, SwapEmptySets) {
  set<int> set1;
  set<int> set2;

  set1.swap(set2);

  EXPECT_TRUE(set1.empty());
  EXPECT_TRUE(set2.empty());
}

TEST(SetSwapTest, SwapNonEmptyWithEmptySet) {
  set<int> set1 = {1, 2, 3};
  set<int> set2;

  set1.swap(set2);

  EXPECT_TRUE(set1.empty());
  EXPECT_EQ(set2.size(), (size_t)3);
}

TEST(SetSwapTest, SwapNonEmptySets) {
  set<int> set1 = {1, 2, 3};
  set<int> set2 = {4, 5, 6};

  set1.swap(set2);

  EXPECT_EQ(set1.size(), (size_t)3);
  EXPECT_EQ(set2.size(), (size_t)3);
  EXPECT_TRUE(set1.contains(4));
  EXPECT_FALSE(set1.contains(1));
}

TEST(SetSwapTest, SwapSetsOfDifferentSizes) {
  set<int> set1 = {1, 2, 3};
  set<int> set2 = {4, 5};

  set1.swap(set2);

  EXPECT_EQ(set1.size(), (size_t)2);
  EXPECT_EQ(set2.size(), (size_t)3);
  EXPECT_TRUE(set1.contains(4));
  EXPECT_FALSE(set1.contains(1));
}

TEST(SetMergeTest, MergeEmptySets) {
  set<int> set1;
  set<int> set2;

  set1.merge(set2);

  EXPECT_TRUE(set1.empty());
  EXPECT_TRUE(set2.empty());
}

TEST(SetMergeTest, MergeNonEmptyWithEmptySet) {
  set<int> set1 = {1, 2, 3};
  set<int> set2;

  set1.merge(set2);

  EXPECT_EQ(set1.size(), (size_t)3);
  EXPECT_TRUE(set2.empty());
}

TEST(SetMergeTest, MergeEmptyWithNonEmptySet) {
  set<int> set1;
  set<int> set2 = {4, 5, 6};

  set1.merge(set2);

  EXPECT_EQ(set1.size(), (size_t)3);
  EXPECT_EQ(set2.size(), (size_t)3);
}

TEST(SetMergeTest, MergeNonEmptySets) {
  set<int> set1 = {1, 2, 3};
  set<int> set2 = {4, 5, 6};

  set1.merge(set2);

  EXPECT_EQ(set1.size(), (size_t)6);
  EXPECT_TRUE(set1.contains(4));
  EXPECT_TRUE(set1.contains(6));
}

TEST(SetMergeTest, MergeSetsWithCommonElements) {
  set<int> set1 = {1, 2, 3};
  set<int> set2 = {3, 4, 5};

  set1.merge(set2);

  EXPECT_EQ(set1.size(), (size_t)5);
  EXPECT_TRUE(set1.contains(3));
}

TEST(SetMergeTest, MergeSetsWithDuplicateElements) {
  set<int> set1 = {1, 2, 3};
  set<int> set2 = {3, 4, 4};

  set1.merge(set2);

  EXPECT_EQ(set1.size(), (size_t)4);
  EXPECT_TRUE(set1.contains(4));
}

TEST(SetMergeTest, MergeLargerSetIntoSmallerSet) {
  set<int> set1 = {1, 2};
  set<int> set2 = {3, 4, 5, 6};

  set1.merge(set2);

  EXPECT_EQ(set1.size(), (size_t)6);
  EXPECT_TRUE(set1.contains(6));
}

TEST(SetMergeTest, MergeSmallerSetIntoLargerSet) {
  set<int> set1 = {1, 2, 3, 4, 5};
  set<int> set2 = {6};

  set1.merge(set2);

  EXPECT_EQ(set1.size(), (size_t)6);
  EXPECT_TRUE(set1.contains(6));
}

TEST(SetMergeTest, MergeSetsWithZeroElements) {
  set<int> set1;
  set<int> set2;

  set1.merge(set2);

  EXPECT_TRUE(set1.empty());
  EXPECT_TRUE(set2.empty());
}

TEST(SetFindTest, FindInEmptySet) {
  set<int> set;

  auto it = set.find(5);

  EXPECT_EQ(it, set.end());
}

TEST(SetFindTest, FindInNonEmptySetSingleElement) {
  set<int> set = {1};

  auto it = set.find(1);

  EXPECT_NE(it, set.end());
  EXPECT_EQ(*it, 1);
}

TEST(SetFindTest, FindInNonEmptySetMultipleElements) {
  set<int> set = {1, 2, 3, 4, 5};

  auto it = set.find(3);

  EXPECT_NE(it, set.end());
  EXPECT_EQ(*it, 3);
}

TEST(SetFindTest, FindNonExistentElement) {
  set<int> set = {1, 2, 3, 4, 5};

  auto it = set.find(6);

  EXPECT_EQ(it, set.end());
}

TEST(SetFindTest, FindInSetWithDuplicates) {
  set<int> set = {1, 2, 2, 3, 4};

  auto it = set.find(2);

  EXPECT_NE(it, set.end());
  EXPECT_EQ(*it, 2);
}

TEST(SetFindTest, FindInSetOfStrings) {
  set<std::string> set = {"apple", "banana", "cherry"};

  auto it = set.find("banana");

  EXPECT_NE(it, set.end());
  EXPECT_EQ(*it, "banana");
}

TEST(SetFindTest, FindInSetWithCustomObjects) {
  struct Person {
    std::string name;
    int age{};

    bool operator==(const Person& other) const {
      return name == other.name && age == other.age;
    }

    bool operator<(const Person& other) const { return age < other.age; }
  };

  set<Person> set = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 40}};
  Person target = {"Bob", 30};

  auto it = set.find(target);

  EXPECT_NE(it, set.end());
  EXPECT_EQ((*it).name, "Bob");
  EXPECT_EQ((*it).age, 30);
}

TEST(SetFindTest, FindInSetOfPointers) {
  set<int*> set;
  int a = 10;
  int b = 20;
  int c = 30;

  set.insert(&a);
  set.insert(&b);
  set.insert(&c);

  auto it = set.find(&b);

  EXPECT_NE(it, set.end());
  EXPECT_EQ(*it, &b);
}

TEST(SetFindTest, FindInLargeSet) {
  set<int> set;
  for (int i = 0; i < 1000; ++i) {
    set.insert(i);
  }

  auto it = set.find(500);

  EXPECT_NE(it, set.end());
  EXPECT_EQ(*it, 500);
}

TEST(SetFindTest, FindRangeCheck) {
  set<int> set = {1, 2, 3, 4, 5};

  auto it = set.find(6);

  EXPECT_EQ(it, set.end());
}

TEST(SetContainsTest, ContainsInEmptySet) {
  set<int> set;

  bool result = set.contains(5);

  EXPECT_FALSE(result);
}

TEST(SetContainsTest, ContainsInNonEmptySetSingleElement) {
  set<int> set = {1};

  bool result = set.contains(1);

  EXPECT_TRUE(result);
}

TEST(SetContainsTest, ContainsInNonEmptySetMultipleElements) {
  set<int> set = {1, 2, 3, 4, 5};

  bool result = set.contains(3);

  EXPECT_TRUE(result);
}

TEST(SetContainsTest, ContainsNonExistentElement) {
  set<int> set = {1, 2, 3, 4, 5};

  bool result = set.contains(6);

  EXPECT_FALSE(result);
}

TEST(SetContainsTest, ContainsInSetWithDuplicates) {
  set<int> set = {1, 2, 2, 3, 4};

  bool result = set.contains(2);

  EXPECT_TRUE(result);
}

TEST(SetContainsTest, ContainsInSetOfStrings) {
  set<std::string> set = {"apple", "banana", "cherry"};

  bool result = set.contains("banana");

  EXPECT_TRUE(result);
}

TEST(SetContainsTest, ContainsInSetWithCustomObjects) {
  struct Person {
    std::string name;
    int age{};

    bool operator==(const Person& other) const {
      return name == other.name && age == other.age;
    }

    bool operator<(const Person& other) const { return age < other.age; }
  };

  set<Person> set = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 40}};
  Person target = {"Bob", 30};

  bool result = set.contains(target);

  EXPECT_TRUE(result);
}

TEST(SetContainsTest, ContainsInSetOfPointers) {
  set<int*> set;
  int a = 10;
  int b = 20;
  int c = 30;

  set.insert(&a);
  set.insert(&b);
  set.insert(&c);

  bool result = set.contains(&b);

  EXPECT_TRUE(result);
}

TEST(SetContainsTest, ContainsInLargeSet) {
  set<int> set;
  for (int i = 0; i < 1000; ++i) {
    set.insert(i);
  }

  bool result = set.contains(500);

  EXPECT_TRUE(result);
}

TEST(SetContainsTest, ContainsRangeCheck) {
  set<int> set = {1, 2, 3, 4, 5};

  bool result = set.contains(6);

  EXPECT_FALSE(result);
}

TEST(SetInsertManyTest, InsertManyEmptySet) {
  set<int> set;
  auto result = set.insert_many(1, 2, 3);

  EXPECT_EQ(result.size(), (size_t)3);
  EXPECT_TRUE(result[0].second);
  EXPECT_TRUE(result[1].second);
  EXPECT_TRUE(result[2].second);
}

TEST(SetInsertManyTest, InsertManyExistingElements) {
  set<int> set = {1, 2, 3};

  auto result = set.insert_many(1, 2, 3);

  EXPECT_EQ(result.size(), (size_t)3);
  EXPECT_FALSE(result[0].second);
  EXPECT_FALSE(result[1].second);
  EXPECT_FALSE(result[2].second);
}

TEST(SetInsertManyTest, InsertManyNewAndExistingElements) {
  set<int> set = {1, 2};

  auto result = set.insert_many(2, 3, 4);

  EXPECT_EQ(result.size(), (size_t)3);
  EXPECT_FALSE(result[0].second);  // Existing element
  EXPECT_TRUE(result[1].second);   // New element
  EXPECT_TRUE(result[2].second);   // New element
}

TEST(SetInsertManyTest, InsertManyRangeCheck) {
  set<int> set;

  auto result = set.insert_many(1, 2, 3);

  EXPECT_EQ(result.size(), (size_t)3);
  EXPECT_TRUE(result[0].second);
  EXPECT_TRUE(result[1].second);
  EXPECT_TRUE(result[2].second);
}

TEST(SetInsertManyTest, InsertManyLargeSet) {
  set<int> set;

  auto result = set.insert_many(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  EXPECT_EQ(result.size(), (size_t)10);
  for (const auto& pair : result) {
    EXPECT_TRUE(pair.second);
  }
}

TEST(SetInsertManyTest, InsertManyDuplicateArguments) {
  set<int> set;

  auto result = set.insert_many(1, 1, 1, 1, 1);

  EXPECT_EQ(result.size(), (size_t)5);
  EXPECT_TRUE(result[0].second);
  for (int i = 1; i < 5; ++i) {
    EXPECT_FALSE(result[i].second);
  }
}

}  // namespace containers
