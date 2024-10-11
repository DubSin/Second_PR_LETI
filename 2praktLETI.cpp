#include <iostream>
#include <chrono>
using namespace std;


int main(){
    char action;
    while(action!='e'){
        cout << "Second practice LETI" << endl;
        cout << "1)Creates an array of size N = 100 and random elements in range from -99 to 99" << endl;
        cout << "2) Sort your array" << endl;
        cout << "3) Find max and min element in your array" << endl;
        cout << "4) Skip" << endl;
        cout << "5) Output quantity of elements less then a in sorted array(input a)" << endl;
        cout << "6) Output quantity of elements more then b in sorted array(input b)" << endl;
        cout << "7) Find if your element in sorted array(input your element)" << endl;
        cout << "8) Swaps array elements whose indices are entered by the user" << endl;
        cout << "Enter action from 1 to 8 or e to exit" << endl;
        cin >> action;
    }
}