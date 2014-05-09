#include <iostream>

int main()
{
  int i = 1;
  int result = 1;
  while (i < 10) {
    result *= i;
    ++i;
  }
  std::cout << "The result is : " << result << std::endl;
}
