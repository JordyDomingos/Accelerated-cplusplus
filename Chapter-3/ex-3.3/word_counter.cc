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

// Implementation of a word counter using only vectors and strings
int main()
{
  cout << "Please enter a set of word, followed by end-of-file:  ";
  string current_word;
  vector<string> word_set;
  while (cin >> current_word)
    word_set.push_back(current_word);

  vector<string>::size_type vec_size = word_set.size();
  if (!vec_size) {
    cout << "You must enter at least one word" << endl;
    return 1;
  }

  sort(word_set.begin(), word_set.end());
  current_word.clear();
  unsigned int counter = 0;
  for (vector<string>::size_type i = 0; i < word_set.size(); ++i) {
    if (word_set[i] != current_word) {
      if (!current_word.empty())
	cout << "The word " << current_word << " appeared " << counter << " time(s)" << endl;
      current_word = word_set[i];
      counter = 1;
    }
    else
      ++counter;
  }
  if (!current_word.empty())
    cout << "The word " << current_word << " appeared " << counter << " time(s)" << endl;
  
  return 0;
}
