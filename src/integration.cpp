#include "integration.h"
#include <iostream>
#include <random> // to get random values for the monte_carlo method

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

double simpson(double (*f)(double), double a, double b, int n) {
    if (n <= 0) return 0.0; // avoid division by zero
    if (n % 2 != 0) {
        // To use this Simpson Rule Implementation, n needs to be even
        std::cout << "Warning: Simpson's Rule needs an even number n. Therefore n will be increased by 1." << std::endl;
        n += 1; 
    }

    double h = (b - a) / n; 
    double integral_sum = 0.0; 

    integral_sum = f(a) + f(b);
    
    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;

        if (i % 2 != 0) {
            // Odd indices have weight 4
            integral_sum += 4 * f(x_i);
        } else {
            // Even indices have weight 2
            integral_sum += 2 * f(x_i);
        } 
    }

    double integral = (h / 3.0) * integral_sum;
    return integral;
}

double monte_carlo(double (*f)(double), double a, double b, int n) {
    if (n <= 0) return 0.0;

    // Random number generator
    std::mt19937 gen; // default seed 
    std::uniform_real_distribution<double> dist(a, b);

    double sum = 0.0;
    for (int i=0; i < n; ++i) {
        double x = dist(gen);
        sum += f(x);
    }

    double mean = sum / n;
    return (b - a) * mean;
}