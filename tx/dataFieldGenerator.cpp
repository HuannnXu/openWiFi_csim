#include "encoder.h"
#include "dataFieldGenerator.h"
#include <random>
using namespace std;

dataBitStreamGenerator::dataBitStreamGenerator(DataType type, int length, int randomSeed)
{
    dataType = type;
    ppduLength = length;
    seed = randomSeed;
}

vector<int> dataBitStreamGenerator::generate()
{
    vector<int> data(ppduLength, 0);
    switch (dataType){
        case zeros:
            break;
        case ones:
            data = vector(ppduLength, 255);
            break;
        case random:
            mt19937 gen(seed);
            uniform_int_distribution<int> dist(0, 255);
            for(int i = 0; i < ppduLength; ++i){
                data[i] = dist(gen);
            }
            break;
        case rampUp:
            for(int i = 0; i < ppduLength; ++i){
                data[i] = i;
            }
            break;
        default:
            break;
    }
    
    return data;
}
