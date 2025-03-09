#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return -1; 
    }

    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) { 
            maxVal = arr[i];
        }
    }

    return maxVal;
}

int main() {
    int arr[] = {10, 45, 3, 89, 29, 56};
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout << "The largest number in the array is: " << findMax(arr, n) << endl;
    return 0;
}
