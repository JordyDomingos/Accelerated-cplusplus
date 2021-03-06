#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;			using std::setprecision;
using std::cout;       		using std::sort;
using std::domain_error;       	using std::streamsize;
using std::endl;       		using std::string;
using std::max;			using std::vector;

int main()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;		// the length of the longest name

  // read and store all the students' data.
  // invariant: |students| contains all the student records read so far
  //		|maxlen| contains the length of the longest name in |students|
  
  
  try {
    while (read(cin, record)) {
      // find length of longest name
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
    }
  } catch (const domain_error& e) {
    e.what();
  }
  
  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  cout << endl;

  // write the names and grades
  for (vector<Student_info>::size_type i = 0;
       i != students.size(); ++i) {
    cout << students[i].name
	 << string(maxlen + 1 - students[i].name.size(), ' ');
    
    streamsize prec = cout.precision();
    cout << setprecision(3) << students[i].grade
	   << setprecision(prec);
    cout << endl;
  }
  return 0;
}
