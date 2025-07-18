#include "tx.h"
#include "../common.h"
#include <iostream>
#include <vector>
#include <complex>
using namespace std;
void append(vector<vector<complex<double> > >& a, vector<vector<complex<double> > >& b){
    if(a.size() != b.size()){
        cout << "the sizes of txSignal don't match" << endl;
        exit(1);
    }
    for(int i = 0; i < a.size(); ++i){
        a[i].insert(a[i].end(), b[i].begin(), b[i].end());
    }
};

TX::TX(const trxConfig& config)
{
}
vector<vector<complex<double> > > TX::transmit()
{
    vector<vector<complex<double> > > txTdSignal;
    vector<vector<complex<double> > > LSTF_tdSignal;
    vector<vector<complex<double> > > LLTF_tdSignal;
    append(txTdSignal, LSTF_tdSignal);
    return txTdSignal;
}

