#ifndef _FOOD_H_
#define _FOOD_H_

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Food {
private:
  string name;
  double price;
public:
  Food() :name{ to_string(rand()) }, price{ (double)rand() / 100 } {}
  Food(string name, double price) : name{ name }, price{ price } {}
  void setName(string name) { this->name = name; }

  string getName() { return name; }
  void setPrice(double price) { this->price = price; }
  double getPrice() { return price; }
};

class CannedFood : public Food {
private:
  int numberBox;
public:
  CannedFood() : Food(), numberBox{ rand() % 100 } {}
  CannedFood(string name, double price, int numberBox) : Food(name, price), numberBox{ numberBox } {}

  void display() { cout << *this << endl; }
  void setNumberBox(int numberBox) { this->numberBox = numberBox; }
  int getNumberBox() { return numberBox; }
  static void sortNumberBox(vector<CannedFood>& vt) { sort(vt.begin(), vt.end(), [](CannedFood& a, CannedFood& b) {return a.getNumberBox() > b.getNumberBox();}); }
  friend ostream& operator<< (ostream& out, CannedFood& a) {
    out << "Name: " << a.getName() << endl;
    out << "Price: " << a.getPrice() << endl;
    out << "Number box: " << a.getNumberBox() << endl;
    return out;
  }
};

class nonCFood : public Food {
private:
  double weight;
public:
  nonCFood() : Food(), weight{ (double)rand() / 100 } {}
  nonCFood(string name, double price, double weight) : Food(name, price), weight{ weight } {}

  void display() { cout << *this << endl; }
  void setWeight(double weight) { this->weight = weight; }
  double getWeight() { return weight; }
  static void sortWeight(vector<nonCFood>& vt) { sort(vt.begin(), vt.end(), [](nonCFood& a, nonCFood& b) {return a.getWeight() > b.getWeight();}); }
  friend ostream& operator<< (ostream& out, nonCFood& a) {
    out << "Name: " << a.getName() << endl;
    out << "Price: " << a.getPrice() << endl;
    out << "Weight: " << a.getWeight() << endl;
    return out;
  }
};

#endif
