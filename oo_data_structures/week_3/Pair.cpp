#include <iostream>

Pair::Pair(int first, int second) {
  pa = new int(first);
  pb = new int(second);
}

Pair::Pair(const Pair & pair) {
  std::cout << "Copy ct: Memory location of first pa is: " << (&pair.pa) << std::endl;
  pa = new int;
  *pa = *pair.pa; 
  std::cout << "Copy ct: Memory location of second pa is: " << &pa << std::endl;
  
  pb = new int;
  *pb = *pair.pb; 
}

Pair::~Pair() {
  delete pa;
  delete pb;
  
  pa = nullptr;
  pb = nullptr;
}

