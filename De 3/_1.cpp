#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct A {
  string name;
  int votes;

  A(string name, int votes = 0) : name{ name }, votes{ votes } {}
  A& operator++() {
    votes++;
    return *this;
  }
  A operator++(int) {
    A a = *this; ++*this;
    return a;
  }
  friend ostream& operator<< (ostream& out, A& a) {
    out << a.name << " " << a.votes;
    return out;
  }
  bool operator==(A& other) { return other.name == this->name; }
};

int main() {
  vector<string> names; // = { "john","jackie","johnny","john","jackie","jamie","jamie","john","johnny","jamie","johnny","john" }
  names = { "andy","blake","clark" };
  vector<A> votes;

  for (string& name : names) {
    if (find_if(votes.begin(), votes.end(), [name](A& a) { return a.name == name; }) == votes.end()) votes.push_back(A(name));
    ++*find_if(votes.begin(), votes.end(), [name](A& a) { return a.name == name; });
  }

  sort(votes.begin(), votes.end(), [](A& a, A& b) { return a.votes > b.votes; });
  if (votes[0].votes > votes[1].votes) {
    cout << votes[0];
    return 0;
  }

  int highest = votes[0].votes;
  sort(votes.begin(), votes.end(), [highest](A& a, A& b) { return a.votes == highest && b.votes == highest && a.name.size() < b.name.size(); });
  cout << votes[0];
  return 0;
}