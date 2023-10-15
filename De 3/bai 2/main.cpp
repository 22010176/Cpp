#include <iostream>
#include <string>
#include <vector>

#include "Food.cpp"

using namespace std;

void Solve(int a = 3, int b = 3) {
  vector<CannedFood> cf;
  for (int i = 0; i < a; i++) cf.push_back(CannedFood());

  CannedFood::sortNumberBox(cf);
  cf[0].setPrice(cf[0].getPrice() / 2);

  for (CannedFood& a : cf) a.display();

  vector<nonCFood> ncf;
  for (int i = 0; i < b; i++) ncf.push_back(nonCFood());
  nonCFood m = *max_element(ncf.begin(), ncf.end(), [](nonCFood& a, nonCFood& b) {return a.getWeight() > b.getWeight();});
  m.setWeight(m.getWeight() / 2);

  nonCFood::sortWeight(ncf);
  for (nonCFood& a : ncf) a.display();
}

int main() {
  srand(time(NULL));

  Solve();
  return 0;
}