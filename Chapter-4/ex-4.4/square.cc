#include <iomanip>
#include <iostream>
#include <istream>

int count_digit(int value)
{
  if (value < 10)
    return 1;
  return 1 + count_digit(value / 10);
}

// compute the square value of value in range [0, last_value) (last value exclude)
// The output should a value and the square of that value.
int main()
{
  int upper_value = 1000;
  int digits_in_upper_value = count_digit(upper_value);

  // At least five character to align the word Value
  int first_column = std::max(digits_in_upper_value, 5);
  
  // According to the formula : max_number_of_digit = 2 * digit_in_upper_value
  int second_column = 2 * digits_in_upper_value;

  std::cout << std::setw(first_column) 
	    << "Value" << std::setw(second_column) 
	    << "Square" << std::endl;
  for (int i = 0; i < upper_value; ++i) {
    std::cout << std::setw(first_column) << i 
	      << std::setw(second_column) << i * i << std::endl;
  }  
}
