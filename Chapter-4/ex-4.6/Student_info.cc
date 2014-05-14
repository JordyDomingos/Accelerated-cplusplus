// source file for Student_info=related functions
#include "Student_info.h"
#include "grade.h"

using std::istream;		using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
}

istream& read(istream& in, Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  double midterm;
  double final;

  in >> s.name >> midterm >> final;

  std::vector<double> homework;
  read_hw(in, homework); // read and store all the student's homeword grades
  s.grade = grade(midterm, final, homework);
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
