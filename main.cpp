#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <sstream>
using namespace std;

class Menu {
  public: 
  void Main_menu(void);
  void editMenu(void);
};

class Emp {
  public:
  void NEW_EMP(void);
  void Display(void);
  void readRecord(void);
  void Delete(int);
  void list(void);
  void Modify(int);
  void ADD(int, string, string, string, int, int, int, string, string, int, string, string);
  void dis(int);
  void SALARY_SLIP();
  vector<string> fetchEmployee(string);
  int calculateTotalSalary(int daysWorked, int hoursWorked, char grade, float basicSalary);
  void printSalarySlip(string salarySlipMonth, int totalSalary, vector<string> emp, int numberOfDaysWorked);
  int code, day, month, year, num, dnum;
  string name, address, phone, desig;
  string grade, house, convense;
  float loan, basic;
};

// THIS IS MENU FUNCTION

void Menu::Main_menu(void) {
  int choose;
  while(1){
  cout << "CSC511 Team 3 Payroll Management System";
  cout << endl;
  cout << "PAYROLL MANAGEMENT SYSTEM";
  cout << endl;
  cout << "1: NEW EMPLOYEE";
  cout << endl;
  cout << "2: DISPLAY EMPLOYEE";
  cout << endl;
  cout << "3: LIST OF EMPLOYEES";
  cout << endl;
  cout << "4: SALARY SLIP";
  cout << endl;
  cout << "5: EDIT MENU";
  cout << endl;
  cout << "0: QUIT";
  cout << endl;
  cout << "ENTER YOUR CHOICE :";

  cin >> choose;
   if (choose == 1) {
   Emp E;
   E.NEW_EMP();
  }
  else if (choose == 2) {
   Emp E;
   E.readRecord();
  }
  else if (choose == 3) {
    Emp E;
    E.list();
  }
  else if(choose == 4){
      Emp E;
      E.SALARY_SLIP();
  }
  else if (choose == 5) {
    editMenu();
  }
  else {
    break;
  }
  }
}


// THE FUNCTION OF SALARY SLIP

void Emp::SALARY_SLIP(){
    vector<string> monthsInAYear = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int  numberOfDaysWorked, numberOfHoursPerDay;
    string empCode, empName, empDesignation, salarySlipMonth ;
    char empGrade;
    cout << "****** Generate Salary Slip of an Employee ****** " << endl;
    cout << "\n" << "Enter the employee Code: " ;
    cin >> empCode;
   
    cout << "\n" << "Working Months in a year for an employee are: " << "\n\n";
    for(vector<string>::iterator it = monthsInAYear.begin(); it != monthsInAYear.end(); it++)
    {
        cout << *it << "  ";
    }
    
    cout << "\n\n" << "Enter the name of the employee: " ;
    cin >> empName;
   
    cout << "\n" << "Enter the designation of the employee: ";
    cin >> empDesignation;
    
    cout<< "\n" << "Enter the grade of the employee(A, B, C): ";
    cin >> empGrade;
    
    cout <<  "\n" << "Which month's salary slip are you looking for " << empName << ": ";
    cin >> salarySlipMonth;
    
    cout << "\n" << "We will require additional information ...";
    cout << "\n";
    cout << "\n" << "How many days has the employee worked in the month of " << salarySlipMonth << ": ";
    cin >> numberOfDaysWorked;
    cout << "\n" << "Enter the number of hours worked per day: ";
    cin >> numberOfHoursPerDay;
 
    vector<string> emp = this -> fetchEmployee(empCode);
    int totalSalary = this -> calculateTotalSalary(numberOfDaysWorked, numberOfHoursPerDay, empGrade, stof(emp[9]));
    this -> printSalarySlip(salarySlipMonth, totalSalary, emp, numberOfDaysWorked);
    cout << "Employee" << totalSalary;
}

int Emp::calculateTotalSalary(int daysWorked, int hoursWorked, char grade, float basicSalary){
    
    switch(grade){
        case 'A':
            return (basicSalary + 50 * hoursWorked*daysWorked );
            break;
        case 'B':
            return (basicSalary + 45 * hoursWorked*daysWorked );
            break;
        case 'C':
            return (basicSalary + 40 * hoursWorked*daysWorked );
            break;
    }
    
    return 0;
    
}

// THE FUNCTION OF PRINTING THE SALARY SLIP

void Emp::printSalarySlip(string salarySlipMonth, int totalSalary, vector<string> emp, int numberOfDaysWorked){
     cout << "\n\n" ;
    cout << "******  Salary Slip for the month of " << salarySlipMonth << "  ******";
    cout << "\n\n" ;
    cout << "Name: " << emp[1];
    cout << "\t\t\t";
    cout << "Number of days worked: " << numberOfDaysWorked;
    cout << "\n\n" ;
    cout << "Basic Salary: " << emp[9];
    cout << "\t\t\t";
    cout << "Allowances: " << (totalSalary - stoi(emp[9]));
    cout << "\t\t\t";
    cout << "Deductions: " << 0;
    cout << "\n\n" ;
    cout << "Total Salary: " << totalSalary;
    cout << "\n\n\n";
    cout << "****** End of salary slip ******";
    cout << "\n\n\n" ;
}

// THE FUNCTION OF FETCH EMPLOYEE

vector<string> Emp::fetchEmployee(string empCode){
    
    fstream fin;
    fin.open("test.csv", ios:: in);
    vector<string> empList;
    string line, word;
    
    if (fin.is_open()) {
    while (fin.good()) {
      empList.clear();
      getline(fin, line);
      stringstream s(line);
      while(getline(s, word, ',')){
        empList.push_back(word);
    }
        if(empList[0] == empCode){
            fin.close();
            return empList;
        }
    }
    }
    fin.close();
    cout << "Rows " << empList[0] << empList[1];
    return empList;
    
}


// THIS IS EDIT MENU FUNCTION

void Menu::editMenu(void){
  int choose, dnum;
  while(1){
    system("cls");
    cout << "EDIT MENU" << endl;
    cout << "1: DELETE RECORD" << endl;
    cout << "2: MODIFY RECORD" << endl;
    cout << "0: EXIT"<< endl;
    cin >> choose;
    if (choose == 1) {
      Emp E;
      cout << "Which Code you want to remove? ";
      cin >> dnum;
      E.Delete(dnum);
    } else if (choose == 2) {
      Emp E;
      cout << "Which Code you want to modify" << endl;
      cin >> dnum;
      E.Delete(dnum);
      E.Modify(dnum);
    } else {
      return;
    }
  }
}

// THIS FUNCTION MODIFY EMPLOYEE RECORD

void Emp::Modify(int dnum) {
  string ename, eaddress, ephone;
  string egrade, ehouse, econv, edesig;
  int eday, emonth, eyear;
  float eloan, ebasic;

  cout << "Enter your revised name:  " << endl;
  cin >> ename;
  cout <<"Enter you new address:  " <<endl;
  cin >> eaddress;
  cout << "Enter your new phone number: " <<endl;
  cin >> ephone;
  cout << "Enter the year you come to this company: " << endl;
  cin >> eyear;
  cout << "Enter the month you come to this company: " << endl;
  cin >> emonth;
  cout << "Enter the day you come to this company: " << endl;
  cin >> eday;
  cout << "Enter Designation of the employee: " << endl;
  cin >> edesig;
  cout << "Enter Grade of the Employee(A, B, C, D): " << endl;
  cin >> egrade;
  cout << "Enter the basic salary of the employee: " << endl;
  cin >> ebasic;
  cout << "House(y,n)" << endl;
  cin >> ehouse;
  cout << "Convense(y,n)" << endl;
  cin >> econv; 

  ADD(dnum, ename, eaddress, ephone, eyear, emonth, eday, edesig, egrade, ebasic, ehouse, econv);
}

// THIS FUNCTION READ TEST.CSV AND DELETE THE NUMBER LINE

void Emp::Delete(int dnum) {
  ifstream fin;
  fin.open("test.csv");
  ofstream temp;
  int roll4;
  string line, word;
  vector<string> row;
  temp.open("temp.csv");

  while (fin.good()) {
    row.clear();
    getline(fin, line);
    stringstream s(line);
    while(getline(s, word, ',')) {
      row.push_back(word);
    }
    roll4 = stoi(row[0]);
    if (roll4 != dnum) {
      temp << line << endl;
    }
  }
  temp.close();
  fin.close();
  remove("test.csv");
  rename("temp.csv","test.csv");   
}

// THIS FUNCTION ADD NEW EMPLOYEE

void Emp::NEW_EMP(void) {
  string ename, eaddress, ephone;
  string egrade, ehouse, econv, edesig;
  int ecode, eday, emonth, eyear;
  float eloan, ebasic;
  cout << "Enter your code in company: " << endl;
  cin >> ecode; 
  cout << "Enter your name:  " << endl;
  cin >> ename;
  cout <<"Enter you address:  " <<endl;
  cin >> eaddress;
  cout << "Enter your phone number: " <<endl;
  cin >> ephone;
  cout << "Enter the year you come to this company: " << endl;
  cin >> eyear;
  cout << "Enter the month you come to this company: " << endl;
  cin >> emonth;
  cout << "Enter the day you come to this company: " << endl;
  cin >> eday;
  cout << "Enter Designation of the employee: " << endl;
  cin >> edesig;
  cout << "Enter Grade of the Employee(A, B, C, D): " << endl;
  cin >> egrade;
  cout << "Enter the basic salary of the employee: " << endl;
  cin >> ebasic;
  cout << "House(y,n)" << endl;
  cin >> ehouse;
  cout << "Convense(y,n)" << endl;
  cin >> econv; 

  ADD(ecode, ename, eaddress, ephone, eyear, emonth, eday, edesig, egrade, ebasic, ehouse, econv);
}

//THIS FUNCTION ADD THE RECORD IN TEST.CSV FILE

void Emp::ADD(int ecode, string ename, string eaddress, string ephone, int eyear, int emonth, int eday, string edesig, string egrade, int ebasic, string ehouse, string econv) {
  fstream file;
  file.open("test.csv", ios::app | ios:: out);
  code = ecode;
  name = ename;
  address = eaddress;
  phone = ephone;
  year = eyear;
  month = emonth;
  day = eday;
  desig = edesig;
  grade = egrade;
  basic = ebasic;
  house = ehouse;
  convense = econv;
  file << code <<"," << name <<"," << address <<"," <<phone<<"," << year<< "," << month  <<"," << day  <<"," <<  desig  <<"," <<  grade  <<"," <<  basic  <<"," <<  house  <<"," <<  convense << "\n";
  file.close();
}

// THIS FUNCTION READ TEST.CSV FILE FOR EMPLOYEE RECORD

void Emp:: readRecord(){
fstream fin;
fin.open("test.csv", ios:: in);
int rollNum, roll4, count = 0;
cout << "which Employee you are looking for?" << endl;
cin >> rollNum;
vector<string> row;
string line, word, temp2;

if (fin.is_open()) {
while (fin.good()) {
  row.clear();
  getline(fin, line);
  stringstream s(line);
  while(getline(s, word, ',')){
    row.push_back(word);
  }
  roll4 = stoi(row[0]);
  if (roll4 == rollNum) {
    count = 1;
    cout << "Employee code: " << row[0] <<endl;
    cout << "Employee name: " << row[1] <<endl;
    cout << "Employee address: " << row[2] <<endl;
    cout << "Employee phone: " << row[3] <<endl;
    cout << "Year of Joining: " << row[4] <<endl;
    cout << "Month of Joining: " << row[5] <<endl;
    cout << "Day of Joining: " << row[6] <<endl;
    cout << "Designation of Employee: " << row[7] <<endl;
    cout << "Grade of Empolyee: " << row[8] <<endl;
    cout << "Employee basic salary: " << row[9] <<endl;
    cout << "House: " << row[10] <<endl;
    cout << "Convense: " << row[11] <<endl;
    cout << endl;
    break;
  }
}
if (count == 0) {
  cout << "Not found!!" <<endl;
}
}
fin.close();
}

// THIS FUNCTION LIST EMPLOYEE NAME AND CATEGORY

void Emp:: list(){
  fstream fin;
fin.open("test.csv", ios:: in);
int rollNum, roll4, count = 0, listNum;
cout << "How many employee want to list?" << endl;
cin >> listNum;
vector<string> row;
string line, word, temp2;

if (fin.is_open()) {
while (fin.good()) {
  count = 1;
  int i = 1;
  
  while (i <= listNum) {
    row.clear();
    getline(fin, line);
    stringstream s(line);
    while(getline(s, word, ',')){
      row.push_back(word);
     }
    roll4 = stoi(row[0]);
    if (roll4 == i) {
      cout << "Employee code: " << row[0] << " Name: " << row[1] << endl;;
    }
    i++;
  }
}
if (count == 0) {
  cout << "Not found!!" <<endl;
}
}
fin.close();
}

// MAIN FUNCTION CALLING MAIN MENU

int main () {
  Menu menu;
  menu.Main_menu();
  return 0;
}
