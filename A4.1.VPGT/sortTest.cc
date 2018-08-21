#include "gtest/gtest.h"
#include "sort.h"

template <class T>
class TypedFixture : public ::testing::TestWithParam<T>
{
public:
  void SetUp()
  {
    parent = new T;
  }
  void TearDown()
  {
    delete parent;
  }
  T* parent;
};

typedef ::testing::Types<BubbleSort, InsertionSort, SelectionSort> implementations;

TYPED_TEST_CASE(TypedFixture, implementations);

int arr[] = {64, 34, 25, 12, 22, 11, 90}, arrOrdenado[] = {11, 12, 22, 25, 34, 64, 90};
int n = sizeof(arr)/sizeof(arr[0]);

TYPED_TEST(TypedFixture, implementations)
{
  this->parent->sort(arr, n);
  if (equal(begin(arr), end(arr), begin(arrOrdenado)))
    cout << "Arrays are equal." << endl;
}
