// source file for Student_info=related functions
#include "Student_info.h"

using std::istream;		using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
}

istream& read(istream& in, Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  in >> s.name >> s.midterm >> s.final;

  read_hw(in, s.homework); // read and store all the student's homeword grades
  return in;
}

istream& read_hw(istream& in, vector <double>& hw)
{
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);
    
    // clear the stream so that input will work for the next student
    in.clear();
  }
  return in;
}
