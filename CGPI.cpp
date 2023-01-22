/*Write a program to enter records of Five students, which should contain fields like roll No., name, CGPI, semester. (a) List all 
record of all students having CGPI greater than k. (b) Insert a new record of student at kth position and print the final record.
*/
#include <iostream>
#include <vector>
using namespace std;

struct Student {
  int rollNo;
  string name;
  float CGPI;
  int semester;
};

vector<Student> students;

void insertRecord(int k, int rollNo, string name, float CGPI, int semester) {
  Student newStudent = {rollNo, name, CGPI, semester};
  students.insert(students.begin() + k, newStudent);
}

void printRecords() {
  for (int i = 0; i < students.size(); i++) {
    cout << "Roll No: " << students[i].rollNo << endl;
    cout << "Name: " << students[i].name << endl;
    cout << "CGPI: " << students[i].CGPI << endl;
    cout << "Semester: " << students[i].semester << endl;
    cout << endl;
  }
}

int main() {
  int n = 5;
  for (int i = 0; i < n; i++) {
    int rollNo, semester;
    string name;
    float CGPI;
    cout << "Enter record for student " << i + 1 << ":" << endl;
    cout << "Roll No: ";
    cin >> rollNo;
    cout << "Name: ";
    cin >> name;
    cout << "CGPI: ";
    cin >> CGPI;
    cout << "Semester: ";
    cin >> semester;
    students.push_back({rollNo, name, CGPI, semester});
  }
  cout << "All records:" << endl;
  printRecords();

  cout << "Enter a value of k: ";
  float k;
  cin >> k;
  cout << "Records of students having CGPI greater than " << k << ":" << endl;
  for (int i = 0; i < students.size(); i++) {
    if (students[i].CGPI > k) {
      cout << "Roll No: " << students[i].rollNo << endl;
      cout << "Name: " << students[i].name << endl;
      cout << "CGPI: " << students[i].CGPI << endl;
      cout << "Semester: " << students[i].semester << endl;
      cout << endl;
    }
  }

  int kth;
  cout << "Enter the position k at which you want to insert a new record: ";
  cin >> kth;
  int rollNo;
  string name;
  float CGPI;
  int semester;
  cout << "Enter the rollNo, name, CGPI and semester of the new student: ";
  cin >> rollNo >> name >> CGPI >> semester;
  insertRecord(kth, rollNo, name, CGPI, semester);

  cout << "Final records:" << endl;
  printRecords();

  return 0;
}
