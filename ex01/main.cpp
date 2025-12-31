#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main() {
  {
    std::cout << "=== Test for standard ===" << std::endl;
    try {
      Span sp = Span(5);
      sp.addNumber(6);
      sp.addNumber(3);
      sp.addNumber(17);
      sp.addNumber(9);
      sp.addNumber(11);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }
  {
    std::cout << "=== Test for Exception over max size ===" << std::endl;
    try {
      Span sp = Span(5);
      sp.addNumber(6);
      sp.addNumber(3);
      sp.addNumber(17);
      sp.addNumber(9);
      sp.addNumber(11);
      sp.addNumber(10); // Exception occur
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }
  {
    std::cout << "=== Test for Exception No Span ===" << std::endl;
    try {
      Span sp = Span(5);
      sp.addNumber(6);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }
  {
    std::cout << "=== Test for corner case(Span(1)) ===" << std::endl;
    try {
      Span sp = Span(1);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }
  {
    std::cout << "=== Test for corner case(Span(0)) ===" << std::endl;
    try {
      Span sp = Span(0);
      sp.addNumber(19);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }
  {
    std::cout << "=== Test for more than 10,000 numbers ===" << std::endl;
    try {
      Span sp = Span(50000);
      sp.addNumber_all();
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }
}
