#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <stack>
#include <vector>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
private:
public:
  MutantStack() : std::stack<T, Container>() {}
  ~MutantStack(){};
  MutantStack(const MutantStack &other) : std::stack<T,Container>(){
	*this = other;
  }
  MutantStack &operator=(const MutantStack &other){
	this->c = other->c;
	return *this;
  }
  typedef typename MutantStack::container_type::iterator iterator;
  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
};

#endif
