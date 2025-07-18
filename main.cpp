#include <iostream>
#include <complex>
#include <vector>
#include "tx/tx.h"
#include "rx/rx.h"
#include "channel/channel.h"
#include "config.h"
using namespace std;

int main(int argc, char* argv[]){
    int maxError = 20;
    int numPackets = 100;
    trxConfig config;
    int randomSeed = config.randomSeed;
    channel chan(config);
    TX tx(config);
    RX rx(config);
    for(int i = 0, error = 0; i < numPackets && error < maxError; ++i){
        vector<vector<complex<double>>> txSignal = tx.transmit();
        vector<vector<complex<double>>> rxReceived = chan.fadingChannel(txSignal);
    }
    return 0;
}