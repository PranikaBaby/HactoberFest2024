#include <iostream>
using namespace std;

// Function to calculate HCF using the Euclidean algorithm
int calculateHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using the formula LCM(a, b) = (a * b) / HCF(a, b)
int calculateLCM(int a, int b, int hcf) {
    return (a * b) / hcf;
}

int main() {
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Calculate HCF
    int hcf = calculateHCF(num1, num2);

    // Calculate LCM
    int lcm = calculateLCM(num1, num2, hcf);

    // Display the results
    cout << "HCF of " << num1 << " and " << num2 << " is: " << hcf << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm << endl;

    return 0;
}
