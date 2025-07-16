#ifndef CONFIG_H
#define CONFIG_H
enum channelMode{awgn,dNLOS};
class trxConfig{
    public:
        int randomSeed;
        channelMode channel;
        int numTxAntenna;
        int numRxAntenna;
};

#endif // CONFIG_H