#include <iostream>
#include <cmath>
#include "integration.h"

double f(double x) {
    return x * x;
}

int main() {
    double a = 0.0; 
    double b = 1.0;
    int n = 100; 
    
    double result = trapezoid(f, a, b, n);
    std::cout << "Integral of x^2 from " << a << " to " << b << " ≈ " << result << std::endl;

    return 0;
}