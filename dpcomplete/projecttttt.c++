#include <iostream>
#include <stdexcept> 
#include <limits>  
using namespace std;

void divideNumbers() {
    double num1, num2;

    try {
        cout << "Enter the numerator: ";
        if (!(cin >> num1)) {
            throw invalid_argument("Invalid input! Please enter a numeric value.");
        }
        
        cout << "Enter the denominator: ";
        if (!(cin >> num2)) {
            throw invalid_argument("Invalid input! Please enter a numeric value.");
        }
        
        if (num2 == 0) {
            throw runtime_error("Error! Division by zero is not allowed.");
        }
        
        double result = num1 / num2;
        cout << "The result of " << num1 << " divided by " << num2 << " is " << result << endl;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl; 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl; 
    }
    catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl; 
    }
}

int main() {
    divideNumbers();
    return 0;
}
