#include <iostream>

double Power(double x, int n) {
    if (n == 0) {
        return 1; // Base case: x^0 = 1
    }
    if (n < 0) {
        x = 1 / x; // Handle negative exponents
        n = -n;    // Convert n to positive
    }
    
    double halfPower = Power(x, n / 2);
    
    // If n is even
    if (n % 2 == 0) {
        return halfPower * halfPower;
    } else { // If n is odd
        return halfPower * halfPower * x;
    }
}

int main() {
    double x;
    int n;
    
    std::cout << "Enter the base (x): ";
    std::cin >> x;
    std::cout << "Enter the exponent (n): ";
    std::cin >> n;

    double result = Power(x, n);
    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}
