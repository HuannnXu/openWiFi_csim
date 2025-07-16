#ifndef TX_H
#define TX_H
#include "config.h"
#include <vector>
#include <complex>
using namespace std;
class TX{
public:
    TX(const trxConfig& config);
    vector<vector<complex<double> > > transmit();
};

#endif // TX_H