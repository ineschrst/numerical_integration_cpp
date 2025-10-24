#include <iostream>
#include <cmath>
#include <chrono>
#include <string>
#include <fstream>
#include "integration.h"

double f1(double x) { return x * x; }
double f2(double x) { return std::sin(x); }
double f3(double x) { return std::exp(-5*x); }
double f4(double x) { return 1 / x; }

double f1_int(double x) { return 1.0/3 * std::pow(x, 3); }
double f2_int(double x) { return -std::cos(x); }
double f3_int(double x) { return -exp(-5*x)/5.0; }
double f4_int(double x) { return std::log(std::abs(x)); }

// caluclates an integral with the given method, gives the time of calculation and the error
void integrate_and_report(const std::string& method_name, double (*integral_method)(double (*f)(double), double, double, int), double (*f)(double), double a, double b, int n, double integration_result, std::string function) {
    
    auto start = std::chrono::high_resolution_clock::now();
    double result = integral_method(f, a, b, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << method_name << " Method\nIntegral of " << function << " from " << a << " to " << b << " ≈ " << result << std::endl;
    std::cout << method_name << " Error: " << std::abs(integration_result - result) << std::endl;
    std::cout << "Time: " << diff.count() << "s" << std::endl;

}

int main() {

    int choice; // user input chooses function
    std::cout << "Choose a function: 1=x^2, 2=sin(x), 3=exp(-5x), 4=1/x\n";
    std::cin >> choice;

    double (*f)(double) = nullptr;
    double (*f_int)(double) = nullptr;
    std::string function = "";
    switch(choice) {
        case 1: f = f1; f_int = f1_int; function = "x^2"; break; 
        case 2: f = f2; f_int = f2_int; function = "sin(x)"; break; 
        case 3: f = f3; f_int = f3_int; function = "exp(-5x)"; break; 
        case 4: f = f4; f_int = f4_int; function = "1/x"; break; 
        default: std::cout << "Invalid choice\n"; return 1;
    }

    double a = 0.1; 
    double b = 1.0;
    int n = 10000; 
    
    double int_result = f_int(b) - f_int(a);
    std::cout << "Integral of " << function << "from " << a << " to " << b << " ≈ " << int_result << std::endl;

    integrate_and_report("Trapezoid", trapezoid, f, a, b, n, int_result, function);

    integrate_and_report("Simpson", simpson, f, a, b, n, int_result, function);
    
    integrate_and_report("Monte Carlo", monte_carlo, f, a, b, n, int_result, function);
    // Monte Carlo converges slower, but works in any dimension. This makes it widely used in physics and computational science

    std::ofstream file("data/errors.csv");
    file << "n,trapezoid,simpson,montecarlo\n";
    for (int k = 0; k < 1000; k = k + 10) {
        double trap = trapezoid(f, a, b, k);
        double simp = simpson(f, a, b, k);
        double monte = monte_carlo(f, a, b, k);
        file << k << ","
             << std::abs(int_result - trap) << ","
             << std::abs(int_result - simp) << ","
             << std::abs(int_result - monte) << "\n";
    }
    file.close();

    return 0;
}