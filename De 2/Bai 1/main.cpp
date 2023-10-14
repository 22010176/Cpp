#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
public:
  int start, end;

  Interval(int start, int end) : start{ start }, end{ end } {}
  int getTime() { return end - start; }
  friend ostream& operator<< (ostream& out, Interval& e);
};

ostream& operator<< (ostream& out, Interval& e) {
  out << e.start << " " << e.end << endl;
  return out;
}

bool _util(const Interval& a, const Interval& b) { return a.start < b.start; }
vector<Interval> check(vector<Interval>& a) {
  sort(a.begin(), a.end(), _util);

  vector<Interval> res;
  int min = a.begin()->start, max = a.begin()->end;

  for (const Interval& i : a) {
    if (i.start > max) {
      res.push_back(Interval(min, max));
      min = i.start, max = i.end;
      continue;
    }

    if (i.start < min) min = i.start;
    if (max < i.end) max = i.end;
  }
  res.push_back(Interval(min, max));

  return res;
}

int main() {
  int start[] = { 1,3,0,8,8 };
  int end[] = { 5,4,3,10,9 };

  vector<Interval> interval;

  for (int i = 0; i < size(start);i++) interval.push_back(Interval(start[i], end[i]));

  vector<Interval> res = check(interval);

  for (Interval i : res) cout << i;

  return 0;
}