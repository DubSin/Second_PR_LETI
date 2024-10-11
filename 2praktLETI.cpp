#include <iostream>
#include <chrono>
#include <conio.h>
using namespace std;

void buble_sort(int arr[], int size){
    int temp;
    for(int i=0; i < size; i++){
        for (int j=0; j < size - 1; j++){
            if (arr[j + 1] < arr[j]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;    
                }
        }
    }
}

void show_array(int arr[], int size){
    cout << "Your array: ";
    for (int i=0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int a_quantity(int arr[], int size, int a){
    int count = 0;
    for (int i=0; i < size; i++){
        if(arr[i] >= a){
            break;
        }
        count++;
    }
    return count;
}

int b_quantity(int arr[], int size, int b){
    int count = 0;
    for (int i=size - 1; i >= 0; i--){
        if(arr[i] <= b){
            break;
        }
        count++;
    }
    return count;
}

int binary_search(int arr[], int start, int end, int value){
    if (end >= start){
        int mid = start + ((end - start) / 2);
        if(arr[mid] == value){
            return mid;
        }
        if (arr[mid] > value){
            return binary_search(arr, start, mid - 1, value);
        }
        return binary_search(arr, mid + 1, end, value);
    }
    return -1;
}

int main() {
    const int size = 100;
    char action = 's'; // начальное положение action
    int array[size];
    bool is_sorted = false, is_initialized = false;
    cout << "Second practice LETI" << endl;
    while (action != 'e') {
        cout << "MENU" << endl;
        cout << "1)Creates an array of size N = 100 and random elements in range from -99 to 99" << endl;
        cout << "2) Sort your array" << endl;
        cout << "3) Find max and min element in your array" << endl;
        cout << "4) Skip" << endl;
        cout << "5) Output quantity of elements less then a in sorted array(input a)" << endl;
        cout << "6) Output quantity of elements more then b in sorted array(input b)" << endl;
        cout << "7) Find if your element in sorted array(input your element)" << endl;
        cout << "8) Swaps array elements (input element indexes)" << endl;
        cout << "Enter action from 1 to 8 or e to exit: ";
        cin >> action;
        switch (action) 
        {
            case '1':
            {
                int start = -size + 1, end = size  - 1; 
                for (int i = 0; i < size; i++) {
                    array[i] = rand() % (end - start + 1) + start;
                }
                }
                is_initialized = true;
                is_sorted = false;
                show_array(array, size);
                getch();
                break;
            case '2':
                if (is_initialized) 
                {
                    buble_sort(array, size);
                    show_array(array, size);
                    is_sorted = true;
                }
                else{
                    cout << "Your array is not initialized" << endl;      
                }
                getch();
                break;
            case '3':
                if (is_sorted){
                    cout << "Min element: " << array[0] << " Max element: " << array[99] << endl; 
                }
                else{
                    cout << "Array is not sorted" << endl;
                }
                getch();
                break;
            case '4':
                cout << "Not working (((" << endl;
                getch();
                break;
            case '5':
                if (is_sorted){
                    int a;
                    cout << "Input number a: ";
                    cin >> a;
                    cout << "Quantity of element less then " << a << ": " << a_quantity(array, size, a) << endl;
                }
                else{
                    cout << "Array is not sorted" << endl;
                }
                getch();
                break;
             case '6':
                if (is_sorted){
                    int b;
                    cout << "Input number b: ";
                    cin >> b;
                    cout << "Quantity of element more then " << b << ": " << b_quantity(array, size, b) << endl;

                }
                else{
                    cout << "Array is not sorted" << endl;
                }
                getch();
                break;
            case '7':
                if(is_sorted)
                {
                    int value, ans;
                    cout << "Enter the value of element you want to find: ";
                    cin >> value;
                    ans = binary_search(array, 0, size - 1, value);
                    if (ans != -1){
                        cout << "Your number was found in " << ans << " index";
                    }
                    else{
                        cout << "Your number is not in the array" << endl;
                    }
                }
                else{
                    cout << "Array is not sorted";
                }
                getch();
                break;
            case '8':
                int first_index, second_index;
                cout << "Input 2 indexes which you want to swap: ";
                cin >> first_index >> second_index;
                swap(array[first_index], array[second_index]);
                show_array(array, size);
                getch();
                break;
        }
    }
}
