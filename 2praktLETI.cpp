#include <iostream>
#include <chrono>
#include <conio.h>
using namespace std;

int partition(int arr[], int size, int start, int end) {
    int pivot = arr[end];
    int i = (start - 1);
    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

void quick_sort(int arr[], int size, int start, int end) {
    if (start < end) {
        int mid = partition(arr, size, start, end);
        quick_sort(arr, size, start, mid - 1);
        quick_sort(arr, size, mid + 1, end);
    }
}

void insert_sort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void buble_sort(int arr[], int size){
    int temp;
    for(int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            if (arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}   

void show_array(int arr[], int size) {
    cout << "Your array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int a_quantity(int arr[], int size, int a) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= a) {
            break;
        }
        count++;
    }
    return count;
}

int b_quantity(int arr[], int size, int b) {
    int count = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] <= b) {
            break;
        }
        count++;
    }
    return count;
}

int binary_search(int arr[], int start, int end, int value) {
    if (end >= start) {
        int mid = start + ((end - start) / 2);
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            return binary_search(arr, start, mid - 1, value);
        }
        return binary_search(arr, mid + 1, end, value);
    }
    return -1;
}

int avarage_value(int arr[], int size) {
    int max = -100, min = 100, avg;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i]; 
        }     
    }
    avg = (max + min) / 2;
    return avg;
}

void show_same_avarage(int arr[], int size, int avg, bool is_sorted) {
    int mid = size / 2;
    int count = 0;
    if (is_sorted) {
        int sample_size = 10;
        cout << "Indexes of same elements: ";
        for (int i = mid - sample_size; i < mid + sample_size + 1; i++) {
            if (arr[i] == avg) {
                cout << i << " ";
                count++;
            }
        }
        cout << endl;
        cout << "Count of same elements: " << count << endl;
    }
    else {
        cout << "Indexes of same elements: ";
        for (int i = 0; i < size; i++) {
            if (arr[i] == avg){
                cout << i << " ";
                count++;
            }
            
        }
        cout << endl;
        cout << "Count of same elements: " << count << endl;

    }
}

void make_sum_cur_next(int arr[], int size){
    for(int i=0; i< size; i++){
        if(i == size - 1){
            arr[i] = arr[i] + arr[0];
        }
        else{
            arr[i] = arr[i] + arr[i + 1];
        }
    }
}

int main() {
    srand(time(0));
    const int size = 100;
    char action = 's'; // начальное положение action
    int array[size]{};
    bool is_sorted = false, is_initialized = false;
    cout << "Second practice LETI" << endl;
    while (action != 'e') {
        cout << "MENU" << endl;
        cout << "1)Creates an array of size N = 100 and random elements in range from -99 to 99" << endl;
        cout << "2) Sort your array" << endl;
        cout << "3) Find max and min element in your array" << endl;
        cout << "4) Find avarage between max and min in sorted and unsorted array" << endl;
        cout << "5) Output quantity of elements less then a in sorted array(input a)" << endl;
        cout << "6) Output quantity of elements more then b in sorted array(input b)" << endl;
        cout << "7) Find if your element in sorted array(input your element)" << endl;
        cout << "8) Swaps array elements (input element indexes)" << endl;
        cout << "9) Make every element in arrays as a sum of current and next element" << endl;
        cout << "Enter action from 1 to 9 or e to exit: ";
        cin >> action;
        switch (action)
        {
        case '1':
        {
            int start = -size + 1, end = size - 1;
            for (int i = 0; i < size; i++) {
                array[i] = rand() % (end - start + 1) + start;
            }
        }
        is_initialized = true;
        is_sorted = false;
        show_array(array, size);
        _getch();
        break;
        case '2':
            if (is_initialized)
            {
                char sort_action;
                cout << "Select type of sort you want \n1)Buble sort \n2)Insert Sort \n3)Quick sort" << endl;
                cin >> sort_action;
                auto start_time = chrono::steady_clock::now();
                switch(sort_action){
                    case '1':
                        buble_sort(array, size);
                        break;
                    case '2':
                        insert_sort(array, size);
                        break;
                    case '3':
                        quick_sort(array, size, 0, size - 1);
                        break;
                }
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;

                show_array(array, size);
                is_sorted = true;
            }
            else {
                cout << "Your array is not initialized" << endl;
            }
            _getch();
            break;
        case '3':
            if (is_sorted) {
                auto start_time = chrono::steady_clock::now();
                cout << "Min element: " << array[0] << " Max element: " << array[99] << endl;
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;
            }
            else {
                cout << "Array is not sorted" << endl;
            }
            _getch();
            break;
        case '4':
            if (is_sorted) {
                int avg = (array[0] + array[99]) / 2;
                show_same_avarage(array, size, avg, is_sorted);
            }
            else  if (is_initialized) {
                int avg = avarage_value(array, size);
                show_same_avarage(array, size, avg, is_sorted);
            }
            else{
                cout << "Array is not initialazed" << endl;
            }
            cin.get();
            break;
        case '5':
            if (is_sorted) {
                int a;
                cout << "Input number a: ";
                cin >> a;
                auto start_time = chrono::steady_clock::now();
                cout << "Quantity of element less then " << a << ": " << a_quantity(array, size, a) << endl;
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;
            }
            else {
                cout << "Array is not sorted" << endl;
            }
            _getch();
            break;
        case '6':
            if (is_sorted) {
                int b;
                cout << "Input number b: ";
                cin >> b;
                auto start_time = chrono::steady_clock::now();
                cout << "Quantity of element more then " << b << ": " << b_quantity(array, size, b) << endl;
                auto end_time = chrono::steady_clock::now();
                auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                cout << "runtime: " << run_time.count() << "ns" << endl;

            }
            else {
                cout << "Array is not sorted" << endl;
            }
            _getch();
            break;
        case '7':
            if (is_sorted)
            {
                int value, ans;
                cout << "Enter the value of element you want to find: ";
                cin >> value;
                auto start_time = chrono::steady_clock::now();
                ans = binary_search(array, 0, size - 1, value);
                if (ans != -1) {
                    cout << "Your number was found in " << ans << " index" << endl;
                    auto end_time = chrono::steady_clock::now();
                    auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
                    cout << "runtime: " << run_time.count() << "ns" << endl;

                }
                else {
                    cout << "Your number is not in the array" << endl;
                }
            }
            else {
                cout << "Array is not sorted";
            }
            _getch();
            break;
        case '8':
            if (is_initialized)
            {
            int first_index, second_index;
            cout << "Input 2 indexes which you want to swap: ";
            cin >> first_index >> second_index;
            auto start_time = chrono::steady_clock::now();
            swap(array[first_index], array[second_index]);
            auto end_time = chrono::steady_clock::now();
            auto run_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
            cout << "runtime: " << run_time.count() << "ns" << endl;
            show_array(array, size);
            }
            else {
                cout << "Array is not initialized";
            }
            _getch();
            break;
        case '9':
            if(is_initialized){
                make_sum_cur_next(array, size);
                show_array(array, size);
            }
            else{
                cout << "Array is not initialized" << endl;
            }
            _getch();
            break;
        }
    }
}
