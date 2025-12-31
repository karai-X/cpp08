#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class NotFindException : public std::exception {
public:
  const char *what() const throw() { return "Not Find"; }
};

template <typename T>
typename T::const_iterator easyfind(const T &a, const int &find_value) {
  typename T::const_iterator it = std::find(a.begin(), a.end(), find_value);
  if (it == a.end()) {
    throw NotFindException();
  }
  return it;
}

#endif
