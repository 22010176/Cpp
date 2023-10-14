#include<iostream>
#include<string>

using namespace std;

void findAndPrintUncommonChars(string str1, string str2) {
  string UncommonChars;
  for (char c : str1)
    if (str2.find(c) == string::npos)
      UncommonChars += c;

  for (char c : str2)
    if (str1.find(c) == string::npos)
      UncommonChars += c;

  cout << "Cac ki tu khong chung: " << UncommonChars << '\n';


}

int main() {
  string str1, str2;
  cout << "Enter string 1: ";
  getline(cin, str1);
  cout << "Enter string 2: ";
  getline(cin, str2);
  findAndPrintUncommonChars(str1, str2);
}