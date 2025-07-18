#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <vector>
#include <complex>
using namespace std;

void fft(vector<complex<double> >& in, vector<complex<double> >& out);
void ifft(vector<complex<double> >& in, vector<complex<double> >& out);

#endif // COMMON_H