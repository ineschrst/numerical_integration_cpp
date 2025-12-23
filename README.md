# Numerical Integration in C++

This project implements and compares several **numerical integration methods** in C++.  
It was created as a small playground to practice and improve my **C++ programming skills** while working with classical numerical algorithms.

## Implemented Methods

- Trapezoidal Rule  
- Simpson’s Rule  
- Monte Carlo Integration  

Each numerical result is compared to an **analytical solution** to compute absolute errors.

## Features

- Arbitrary functions via function pointers
- Analytical reference integrals for validation
- Runtime measurement using `std::chrono`
- Error analysis for increasing numbers of intervals
- Export of error data to CSV

## Error Analysis & Visualization

- Error data is written to `data/errors.csv` and not published on github
- A Jupyter notebook is included that loads this file and visualizes the convergence behavior of the different methods

## Project Structure
```
. 
├── src/
│ └── main.cpp
│ └── integration.h
│ └── integration.cpp
├── data/
│ └── errors.csv
├── plots/
│ └── making_plots.ipynb
└── Makefile
```
## Purpose

This project was used to experiment with:
- Numerical integration techniques
- Clean C++ code structure
- Basic performance and error analysis
