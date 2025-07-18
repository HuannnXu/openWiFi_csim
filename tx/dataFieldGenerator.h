#ifndef DATAFIELDGENERATOR_H
#define DATAFIELDGENERATOR_H
#include "../config.h"
#include <vector>
using namespace std;

enum DataType{zeros, ones, random, rampUp};

class dataBitStreamGenerator{
public:
    DataType dataType;
    int ppduLength;
    int seed;
    dataBitStreamGenerator(DataType type, int length, int randomSeed);
    vector<int> generate(); 
};

#endif // DATAFIELDGENERATOR_H