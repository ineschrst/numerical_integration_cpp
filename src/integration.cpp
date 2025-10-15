#include "integration.h"

// Trapezoid rule for numerical integration
double trapezoid(double (*f)(double), double a, double b, int n) {
    if (n <= 0) return 0.0; // avoid division by zero 
    double h = (b - a) / n; 
    double sum = 0.5 * (f(a) + f(b)); // endpoints
    for (int i = 1; i < n; ++i) {
        double x = a + i * h; 
        sum += f(x);
    }
    return sum * h; 
}