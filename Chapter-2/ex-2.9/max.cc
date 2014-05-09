#include <iostream>

int main() 
{
  int n1, n2;

  std::cout << "Enter two number : ";
  std::cin >> n1 >> n2;
  std::cout << "The larger number is: " << std::max(n1, n2) << std::endl;
}
