#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum element in an array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Counting sort function for a specific digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array to store sorted numbers
    int count[10] = {0};   // Array to store the count of digits (0-9)

    // Store the count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copy the sorted numbers into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr);

    // Perform counting sort for each digit, starting from the least significant digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr;
    int n, element;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        arr.push_back(element);
    }

    // Perform Radix Sort
    radixSort(arr);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
