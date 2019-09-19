#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>

int insert(int value, std::vector<int> &table) {
  int last_sig_digits = 0;
  int tries = 0;
  
  if (value < 100) {
    last_sig_digits = value % 10;
  }
  if (value >= 100) {
    last_sig_digits = value % 100;
  }
  if (value >= 1000) {
    last_sig_digits = value % 1000;
  }
  while (table[last_sig_digits] != -1) {
    last_sig_digits++;
    last_sig_digits = last_sig_digits < 1000 ? last_sig_digits : 0;
    tries++;
  }
  table[last_sig_digits] = value;
  return tries;
}

int main() {
  int i, j, hit, max_hit = 0, max_value = -1;

  std::vector<int> value(500);
  
  int old_value = 0;
  for (i = 0; i < 500; i++) {
    old_value += rand()%100;
    value[i] = old_value;
  }

  // create hash table of size 1000 initialized with -1
  std::vector<int> table(1000,-1);

  for (i = 0; i < 500; i++) {
    hit = insert(value[i],table);
    if (hit > max_hit) {
      max_hit = hit;  
      max_value = value[i];
    }
  }

  std::cout << "Hashing value " << max_value << " experienced " << max_hit << " collisions." << std::endl <<std::endl;

  for (j = 0; j < 1000; j += 10) {
    std::cout << std::setw(3) << j << ":";
    for (i = 0; i < 10; i++) {
      if (table[j+i] == -1)
        std::cout << "      ";
      else
        std::cout << std::setw(6) << table[j+i];
    }
    std::cout << std::endl;
  }

  return 0;
}