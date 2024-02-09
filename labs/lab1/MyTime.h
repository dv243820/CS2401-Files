// Add documentation for each function

#include <iostream>

class MyTime
{
public:
  // CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES
  // DEFAULT ARGUMENTS
  // MyTime();
  MyTime(int h = 0, int m = 0);

  // Member functions
  void Reset(int h, int m);

  void input(std::istream &ins);

  void output(std::ostream &outs) const;

  int get_hours() const { return hours; }

  int get_minutes() const { return minutes; }

  MyTime operator+(const MyTime &t2) const;

  MyTime operator-(const MyTime &t2) const;

  MyTime operator*(int num);

  MyTime operator/(int num);

  bool operator==(const MyTime &t2) const;

  bool operator<(const MyTime &t2) const;

  bool operator<=(const MyTime &t2) const;

private:
  void simplify();
  int hours;   // hours can be > 24
  int minutes; // 0 <= minutes <= 59
};

std::istream &operator>>(std::istream &ins, MyTime &t);

std::ostream &operator<<(std::ostream &outs, const MyTime &t);
