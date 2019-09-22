#include <iostream>
#include <vector> // for std::vector

class DisjointSets {
public:
	int s[256];
	int roots[256];

	DisjointSets() { for (int i = 0; i < 256; i++) s[i] = -1; }

	int find(int i);
private:
  std::vector<int> to_update_;
};

/* Modify the find() method below
 * to implement path compression
 * so that element i and all of
 * its ancestors in the up-tree
 * point to directly to the root
 * after find() completes.
 */

int DisjointSets::find(int i) {
  std::cout << "i is: " << i << std::endl; 
  if ( s[i] < 0 ) {
    if (!to_update_.empty()) {
      for ( auto& num : to_update_ ) {
        s[num] = i;
      }
    }
    return i;
  } else {
    to_update_.push_back(i);
    return find(s[i]);
  }
}

int main() {
  DisjointSets d;

  d.s[1] = 3;
  d.s[3] = 5;
  d.s[5] = 7;
  d.s[7] = -1;

  std::cout << "d.s(4) = " << d.s[4] << ". Should be -1" << std::endl;

  std::cout << "d.find(1) = " << d.find(1) << std::endl;
  std::cout << "d.s(1) = " << d.s[1] << ". Should be 7" << std::endl;
  std::cout << "d.s(3) = " << d.s[3] << ". Should be 7" << std::endl;
  std::cout << "d.s(5) = " << d.s[5] << ". Should be 7" << std::endl;
  std::cout << "d.s(7) = " << d.s[7] << ". Should be -1" << std::endl;

  return 0;
}