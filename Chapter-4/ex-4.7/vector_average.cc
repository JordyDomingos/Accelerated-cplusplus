#include <iostream>
#include <numeric>
#include <vector>

int main()
{
  int x;
  std::vector<int> storage;

  while (std::cin >> x) {
    storage.push_back(x);
  }
  std::cout << std::endl;
  std::cout << "The average is "
	    << std::accumulate(storage.begin(), storage.end(), 0) / storage.size()
	    << std::endl;
}
