#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

bool compare_func(int a, int b) { return a <= b; }

int main()
{
  cout << "Please enter a set of number, followed by end-of-file:  ";
  int x;
  vector<int> number_set;
  while (cin >> x)
    number_set.push_back(x);

  vector<int>::size_type vec_size = number_set.size();
  if (!vec_size) {
    cout << "You must enter numbers" << endl;
    return 1;
  }

  sort(number_set.begin(), number_set.end(), compare_func);    
  int mid = vec_size / 2;
  double median = vec_size % 2 ? number_set[mid]
    : (number_set[mid] + number_set[mid - 1]) / 2.0;

  double q1, q2, q3;

  int q1_size = mid;
  int q1_mid = 1.0 / 4.0 * vec_size;
  cout << "Q1 mid est " << q1_mid << endl;
  q1 = mid % 2 ? number_set[q1_mid]
    : (number_set[q1_mid] + number_set[q1_mid - 1]) / 2.0;

  q2 = median;
  
  int q3_size = mid;
  int q3_mid = 3.0 / 4.0 * vec_size;
  q3 = q3_size % 2 ? number_set[q3_mid]
    : (number_set[q3_mid] + number_set[q3_mid - 1]) / 2.0;
  
  streamsize prec = cout.precision();
  cout << setprecision(3) << "Q1 = " << q1 << endl
       << "Q2 = " << q2 << endl
       << "Q3 = " << q3 << setprecision(prec) << endl;
  
  return 0;
}
