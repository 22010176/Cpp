// InventoryItem .h

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>
using namespace std;

class InventoryItem {
private:
  string description;
  double cost;
  int units;
public:
  // Constructor 1
  InventoryItem() {
    description = " ";
    cost = 0.0;
    units = 0;
  }
  // Constructor 2
  InventoryItem(string desc) {
    description = desc;
    cost = 0.0;
    units = 0;
  }
  // Constructor
  InventoryItem(string desc, double c, int u) {
    description = desc;
    cost = c;
    units = u;
  }

  void setDescription(string d) { description = d; }
  void setCost(double c) { cost = c; }
  void setUnits(int u) { units = u; }
  string getDescription() { return description; }
  double getCost() { return cost; }
  int getUnits() { return units; }
};
# endif