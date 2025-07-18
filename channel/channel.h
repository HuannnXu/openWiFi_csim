#ifndef CHANNEL_H
#define CHANNEL_H
#include "../config.h"
#include <vector>
#include <complex>
using namespace std;

class channel{
  channelMode channelModel;
  int numTxAntenna;
  int numRxAntenna;
  public:
  channel(trxConfig& config);
  vector<vector<complex<double> > > fadingChannel(vector<vector<complex<double> > >& txsignal);
};

#endif // CHANNEL_H