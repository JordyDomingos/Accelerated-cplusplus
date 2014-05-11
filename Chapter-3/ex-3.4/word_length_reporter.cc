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

bool compare_func(string a, string b) { return a.size() <= b.size(); }

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

  sort(word_set.begin(), word_set.end(), compare_func);
  int last_value = word_set.size() - 1;

  cout << "The shortest word is [" << word_set[0] << "] with a length of " << word_set[0].size() << " letter(s)" << endl;
  cout << "The longest word is [" << word_set[last_value] << "] with a length of " << word_set[last_value].size() << " letter(s)" << endl;
  
  return 0;
}
