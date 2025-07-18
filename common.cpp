#include "common.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos(-1);

int reverseBits(int n, int bits) {
    int reversed = 0;
    for (int i = 0; i < bits; ++i) {
        if ((n >> i) & 1)
            reversed |= 1 << (bits - 1 - i);
    }
    return reversed;
}
//current fft version is the not normalized version
void fft(vector<complex<double> >&in, vector<complex<double> >& out) //bfp fft to be updated...
{
    int N = in.size();
    if ((N & (N - 1)) != 0) {
        cerr << "Input size must be a power of 2.\n";
        exit(1);
    }

    int logN = log2(N);
    out.resize(N);

    // Bit-reversal copy
    for (int i = 0; i < N; ++i) {
        int j = reverseBits(i, logN);
        out[j] = in[i];
    }

    // Iterative FFT
    for (int s = 1; s <= logN; ++s) {
        int m = 1 << s;
        complex<double> wm = polar(1.0, -2.0 * PI / m);
        for (int k = 0; k < N; k += m) {
            complex<double> w = 1;
            for (int j = 0; j < m / 2; ++j) {
                complex<double> t = w * out[k + j + m / 2];
                complex<double> u = out[k + j];
                out[k + j] = u + t;
                out[k + j + m / 2] = u - t;
                w *= wm;
            }
        }
    }
}

void ifft(vector<complex<double>> &in, vector<complex<double>> &out)
{
    vector<complex<double>> temp = in;
    for (auto& x : temp) x = conj(x);
    fft(temp, out);
    for (auto& x : out) x = conj(x) / double(out.size());
}