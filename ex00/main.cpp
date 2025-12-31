#include "easyfind.hpp"

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d(arr, arr + 10);
  std::list<int> l(arr, arr + 10);
  std::vector<int> v(arr, arr + 10);

  std::cout << "=== Test for deque ===" << std::endl;
  try {
    std::cout << *easyfind(d, 6) << std::endl;
  } catch (const NotFindException &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "=== Test for list ===" << std::endl;
    std::cout << *easyfind(l, 1) << std::endl;
  } catch (const NotFindException &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "=== Test for vector ===" << std::endl;
    std::cout << *easyfind(v, 10) << std::endl;
  } catch (const NotFindException &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "=== Test for NOT FIND ===" << std::endl;
    std::cout << *easyfind(v, 11) << std::endl;
  } catch (const NotFindException &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
