#include <string>
#include <iostream>

using namespace std;

const int MAX_CHAR = 26; // [a - z] contains 26 characters
void findAndPrintUncommonChars(string str1, string str2) {
  int present[MAX_CHAR]{}; // Khai bao mot mang so nguyen 26 o
  int l1 = str1.size(), l2 = str2.size(); // lay do dai sau 1 va sau 2

  for (int i = 0; i < l1; i++) present[str1[i] - 'a'] = 1; // tim tat ca ki tu co mat trong sau 1
  for (int i = 0; i < l2; i++) { // kiem tra tung ki tu co mat trong sau 2


    if (present[str2[i] - 'a'] == 1 || present[str2[i] - 'a'] == -1)
      // present[str2[i] - 'a'] == 1 (neu ma sau 1 da co ki tu nay roi)
      // present[str2[i] - 'a'] == -1 (neu ma ca 2 sau da co roi)
      present[str2[i] - 'a'] = -1; // thi dat vi tri ki tu la -1
    else present[str2[i] - 'a'] = 2;
  }

  // print all the uncommon characters
  for (int i = 0; i < MAX_CHAR; i++)
    if (present[i] == 1 || present[i] == 2) cout << (char(i + 'a')) << " ";
}

// Driver program to test above
int main() {
  string str1 = "egeksfroeegks";
  string str2 = "eegksquiz";
  findAndPrintUncommonChars(str1, str2);
  return 0;
}
