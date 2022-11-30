#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
  char num1[50], num2[50], op_menu[4], exit_menu[4], *end_ptr;
  int valid, op, exit;
  float a, b;
  cout << "\nWelcome to the calculator written in C++\n";
  beg:
  do {
    cout << "\nType the first number: ";
    fgets(num1, 50, stdin);
    a = strtof(num1, &end_ptr);
    if (num1 == end_ptr) {
      cout << "\nError. Please, type a number.\n";
      valid = 0;
    } else if (strchr(num1, ',') != NULL) {
      cout << "\nPlease, use the dot for float numbers.\n";
      valid = 0;
    } else {
      valid = 1;
    }
  } while (!valid);
  do {
      cout << "\nWhich operation?\n\n1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Percentage\n6 - Power\n\nOption: ";
      fgets(op_menu, 4, stdin);
      op = atoi(op_menu);
      if (strlen(op_menu) != 2 || op < 1 || op > 6) {
        cout << "\nInvalid option.\n";
        valid = 0;    
      } else {
        valid = 1;
      }
  } while (!valid);
  mid:
  do {
      cout << "\nType the second number: ";
      fgets(num2, 50, stdin);
      b = strtof(num2, &end_ptr);
      if (num2 == end_ptr) {
        cout << "\nError. Please, type a number.\n";
        valid = 0;
      } else if (strchr(num2, ',') != NULL) {
        cout << "\nPlease, use the dot for float numbers.\n";
        valid = 0;
      } else {
        valid = 1;
      }
  } while (!valid);
  switch(op) {
      case 1:
          cout << "\n" << a << " plus " << b << " is equal to: " << a + b << endl;
          break;
      case 2:
          cout << "\n" << a << " minus " << b << " is equal to: " << a - b << endl;
          break;
      case 3:
          cout << "\n" << a << " times " << b << " is equal to: " << a * b << endl;
          break;
      case 4:
          if (b == 0) {
            cout << "\n" << "\nIt's not possible to divide by zero.\n";
            goto mid;
          } else {
            cout << "\n" << a << " divided by " << b << " is equal to: " << a / b << endl;
            break;
          }
      case 5:
          cout << "\n" << "The percentage of " << a << " in " << b << " is equal to: " << a / b * 100 << "%\n";
          break;
      case 6:
          cout << "\n" << a << " to the power " << b << " is equal to: " << pow(a,b) << endl;
          break;
  }
  do {
      cout << "\nDo you wish to continue?\n\n1 - Yes\n2 - No\n\nOption: ";
      fgets(exit_menu, 4, stdin);
      exit = atoi(exit_menu);
      if (strlen(exit_menu) != 2 || exit < 1 || exit > 2) {
        cout << "\nInvalid option.\n";
        valid = 0;    
      } else if (exit == 1) {
        goto beg;
      } else if (exit == 2) {
        valid = 1;
      }
      } while (!valid);
}