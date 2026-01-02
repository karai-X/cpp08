#include "Span.hpp"

Span::Span(unsigned int max_N) : max_N_(max_N) {}
Span::~Span() {}
Span::Span(const Span &other) { *this = other; }
Span &Span::operator=(const Span &other) {
  this->max_N_ = other.max_N_;
  this->vec_ = other.vec_;
  return *this;
}

void Span::addNumber(int num) {
  if (vec_.size() == max_N_) {
    throw OverMaxSize();
  }
  this->vec_.push_back(num);
}

void Span::addNumber_multi(std::vector<int> input_vec) {
  if (vec_.size() + input_vec.size() > max_N_) {
    throw OverMaxSize();
  }
  vec_.insert(vec_.end(), input_vec.begin(), input_vec.end());
}

long Span::shortestSpan() {
  if (vec_.size() < 2) {
    throw NotSpanFound();
  }
  long ans = std::numeric_limits<long>::max();
  long diff;
  sort(vec_.begin(), vec_.end());
  for (std::vector<int>::iterator it = vec_.begin(); it != vec_.end() - 1;
       it++) {
    diff = *(it + 1) - *it;
    ans = std::min(ans, diff);
  }
  return ans;
}

long Span::longestSpan() {
  if (vec_.size() < 2) {
    throw NotSpanFound();
  }
  sort(vec_.begin(), vec_.end());
  return *(vec_.end() - 1) - *vec_.begin();
}
