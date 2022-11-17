#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "bstmap.h"

int main(void) {
  BstMap<int, int> map;
  map.add(60, 1);
  map.add(19, 2);
  map.add(93, 3);
  map.add(4, 4);
  map.add(25, 5);
  map.add(84, 6);
  map.add(1, 7);
  map.add(11, 8);
  map.add(21, 9);
  int ans1 = map.lookup(60);
  int ans2 = map.lookup(4);
  std::cout << "\n";
  std::cout << "expected1 = 1; ans1 =" << ans1 << "\n";
  std::cout << "expected2 = 4; ans2 =" << ans2 << "\n";
  map.remove(19);
  std::cout << "\n";
  return EXIT_SUCCESS;
}
