#include <iostream>
#include <string>

void create_rectangle(unsigned int width, unsigned int height) {
  std::string first_n_last_line(width, '*');
  std::string middle_lines = '*' +
    std::string(width > 2 ? width - 2 : 0, ' ') + '*';

  // invariant: we wrote i lines so far
  for (unsigned int i = 0; i < height; ++i) {
    if (i == 0 || i == height -1)
      std::cout << first_n_last_line << std::endl;
    else
      std::cout << middle_lines << std::endl;
  }
}

// Works with odd numbers
void create_triangle(unsigned int base_size) {
  std::string current_line(base_size, ' ');
  unsigned int left_star = base_size / 2;
  unsigned int right_star = base_size / 2;

  current_line[base_size / 2] = '*';
  // invariant: we wrote i lines so far
  for (unsigned int i = 0; i < base_size / 2; ++i) {
    if (i != 0) {
      current_line[left_star--] = ' ';
      current_line[right_star++] = ' ';
      current_line[left_star] = '*';
      current_line[right_star] = '*';
    }
    std::cout << current_line << std::endl;
  }
  std::cout << std::string(base_size, '*') << std::endl;
}

void create_square(unsigned int side_size) {
  std::string first_n_last_line(side_size, '*');
  std::string middle_lines = '*' +
    std::string(side_size > 2 ? side_size - 2 : 0, ' ') + '*';

  // invariant: we wrote i lines so far
  for (unsigned int i = 0; i < side_size; ++i) {
    if (i == 0 || i == side_size - 1)
      std::cout << first_n_last_line << std::endl;
    else
      std::cout << middle_lines << std::endl;
  }
}

int main()
{
  std::cout << std::endl;
  create_square(15);
  std::cout << std::endl;
  create_rectangle(12,15);
  std::cout << std::endl;
  create_triangle(15);
}
