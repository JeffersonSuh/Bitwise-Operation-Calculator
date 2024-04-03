// Suh, Jefferson       CS130 Section 27623     02/13/2024
// First Laboratory Assignment - Bitwise Operation Calculator

#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

unsigned int result;
unsigned long long int firstOperand, secondOperand;
int signedVal;
char choice;

int main() {
  // Start by calculating the size in bits of your operands.
  int bitSize = sizeof(unsigned long long int) * 8;

  // Then issue message 1 described later in this assignment.
  cout << "Bitwise Operation Calculator - CS130 - " << bitSize
       << " bits - Jefferson Suh\n"
       << endl;

  // The C++ program should then display a menu and prompt the user for a menu
  // choice.
  do {
    cout << "Enter one of the following choices:" << endl;
    cout << "& - AND" << endl;
    cout << "| - OR" << endl;
    cout << "^ - XOR" << endl;
    cout << "~ - NOT" << endl;
    cout << "- - Negate" << endl;
    cout << "< - Left shift (logical shift only)" << endl;
    cout << "> - Right shift (logical shift only)" << endl;
    cout << "# - Stop execution" << endl;
    cin >> choice;
    cout << "\n";

    if (choice != '&' && choice != '|' && choice != '^' && choice != '~' &&
        choice != '-' && choice != '<' && choice != '>' && choice != '#') {
      // Invalid choice values should be rejected.
      cout << "Invalid choice " << choice << ", please try again." << endl;
      continue;
    }
    if (choice == '#') {
      cout << "Calculation ended." << endl;
      break;
    }
    if (choice == '~' || choice == '-') {
      cout << "Enter value for operand:" << endl;
      cin >> signedVal;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input error, enter choice and values again." << endl;
        continue;
      }
    } else {
      // Otherwise, ask the user for the operands using
      cout << "Enter values for first and second operand:" << endl;
      cin >> firstOperand >> secondOperand;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input error, enter choice and values again." << endl;
        continue;
      }
      cout << "\n";
    }
    switch (choice) {
    case '&':
      result = firstOperand & secondOperand;
      break;
    case '|':
      result = firstOperand | secondOperand;
      break;
    case '^':
      result = firstOperand ^ secondOperand;
      break;
    case '~':
      result = ~signedVal;
      break;
    case '-':
      result = -signedVal;
      break;
    case '<':
      if (secondOperand >= bitSize) {
        cout << "Shift value " << secondOperand << " exceeds bit size "
             << bitSize << endl;
        result = 0;
      } else {
        result = firstOperand << secondOperand;
      }
      break;
    case '>':
      if (secondOperand >= bitSize) {
        cout << "Shift value " << secondOperand << " exceeds bit size "
             << bitSize << endl;
        result = 0;
      } else {
        result = firstOperand >> secondOperand;
      }
      break;
    }
    cout << "Result:" << result << " [Hexadecimal:" << hex << setw(bitSize / 4)
         << setfill('0') << result << "]" << dec << endl;
  } while (true);

  return 0;
}