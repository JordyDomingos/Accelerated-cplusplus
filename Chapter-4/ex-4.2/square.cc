#include <iomanip>
#include <iostream>
#include <istream>

int main()
{
  int first_column = 10;
  int second_column = 10;

  std::cout << std::setw(first_column) 
	    << "Value" << std::setw(second_column) 
	    << "Square" << std::endl;
  for (int i = 0; i <= 100; ++i) {
    std::cout << std::setw(first_column) << i 
	      << std::setw(second_column) << i * i << std::endl;
  }  
}
