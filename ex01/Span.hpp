#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

class NotSpanFound : public std::exception {
public:
  const char *what() const throw() {
    return "Element of vector is less than 2";
  }
};

class OverMaxSize : public std::exception {
public:
  const char *what() const throw() {
    return "Attempted to add number over Max Size";
  }
};

class Span {
private:
  unsigned int max_N_;
  std::vector<int> vec_;

public:
  Span(unsigned int max_N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();
  void addNumber(int num);
  void addNumber_all();
  long shortestSpan();
  long longestSpan();
};

#endif
