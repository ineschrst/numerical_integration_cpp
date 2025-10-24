#ifndef integration_h
#define integration_h

double trapezoid(double (*f)(double), double a, double b, int n);
double simpson(double (*f)(double), double a, double b, int n);
double monte_carlo(double (*f)(double), double a, double b, int n);

#endif 