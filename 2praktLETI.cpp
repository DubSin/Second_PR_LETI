#include <iostream>
#include <chrono>
using namespace std;


int* array_initialization() {
    int start = 0, end = 99, arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % (end - start + 1) + start;
    }
    return arr;
}

int main() {
    char action = 's'; // начальное положение action
    int *array; // указатель на массив
    bool is_sorted = false;
    while (action != 'e') {
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
        switch (action) 
        {
            case '1':
            array = array_initialization();
            case '2':
                char sort_action;
                cout << "1) Buble sort" << endl;
                cout << "2) Shaker sort" << endl;
                cout << "3) Comb sort" << endl;
                cout << "4) Insert sort" << endl;
                cout << "5) Quick sort" << endl;
        }
    }
}
