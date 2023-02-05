// Salesperson's Paycheck
// Instructor's Solution
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream fin;           // For file input
  string fname;           // Input file name, provided by user
  string first;           // Employee first name, input
  string last;            // Employee last name, input
  double salary;          // Base salary, input
  double commission_pct;  // Commission percentage, input
  double total_sales;     // Total sales, input
  double expenses;        // Employee expenses, input
  double commission;      // Commission, output
  double total;           // Total paycheck, output

  // Prompt for and open the input file
  cout << "Enter file name: ";
  getline(cin, fname);
  fin.open(fname);
  if (!fin) {
    cout << "Could not open file " << fname << endl;
    exit(0);
  }

  // Input employee information from the file
  fin >> first >> last; // Line 1: first and last name
  fin >> salary >> commission_pct; // Line 2: salary and commission percentage
  fin >> total_sales; // Line 3: total sales
  fin >> expenses; // Line 4: total expenses

  // Close the file (no longer needed)
  fin.close();

  // Calculate commission and total pay
  commission = total_sales * commission_pct / 100;
  total = salary + commission + expenses;

  // Formatted output
  cout << endl;
  cout << fixed << setprecision(2);
  cout << "Payroll data for " << first << " " << last << endl << endl;
  cout << "Base Salary: " << setw(10) << salary << endl;
  cout << "Commission:  " << setw(10) << commission << " (" <<
    setprecision(1) << commission_pct << setprecision(2) << "% of " <<
    total_sales << ")\n";
  cout << "Expenses:    " << setw(10) << expenses << endl;
  cout << "               --------\n";
  cout << "Total:       " << setw(10) << total << endl;
}
