# TeColor
An easy-to-use color technology utility library made with C++ and Eigen.

## Introduction
TeColor is a C++ algorithm library for computational color technology. It is built based upon [Eigen](http://eigen.tuxfamily.org), a linear algebra library for C++. It provides basic and extended utility data structure and functions for the following fields: spectral analysis, colorimetry, color appearance models, and color space conversions. It is still a work in progress and the architecture may change. 

## Why TeColor
There are tons of utility functions for computational color technology scattering all over the internet. However, there are problems with most of them: 

- Many of them are written in MATLAB, which is obviously a proprietary language that is not easy and not free to be integrated into your own software. 
- Some of them are written in C++. However, most of them are designed for single sample calculation, or using a for-loop for many samples, without any vectorized optimization.
- Many of the existing functions are ad hoc, lacking a large collection of utilities covering most of the aspects of color science and technology. Moreover, some of them have errors, which might be misleading.

TeColor tries to solve those problems through these ways:
- TeColor tries to combine the advantages of MATLAB and C++ written functions by leveraging Eigen library, which provides most of the functionalities of MATLAB matrix computation, and makes vectorization optimization possible. 
- Eigen has pitfalls for general users from MATLAB. TeColor tries to wrap the pitfalls of using Eigen, but keep the code meaningful for color technology. 
- Also, TeColor is cross-platform, and can be easily embedded into many common languages. A command-line demo is provided and more demos for OS X GUI, iOS, Windows, and more will come.
- TeColor is planned to be continuously evolving. More and more utilities will be added in a regular basis.

## Usage
- TeColor uses Cmake, a cross-platform make system. You will need the latest Cmake and Eigen library to use TeColor. 
- Simply include everything by `#include <TeColor/TeColor>`. It uses MIT License, and can be compiled together with your code, or linked statically.
- The default Cmake configuration will produce a static library `TeColor.a` and a demo executable `tecolor_demo`.
- A full documentation is coming soon.

## License
MIT License.



