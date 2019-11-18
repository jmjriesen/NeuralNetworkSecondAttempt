//
// Created by Jacob Riesen on 11/16/19.
//

#ifndef NEURALNETWORKSECONDATTEMPT_NEURALNETWORK_H
#define NEURALNETWORKSECONDATTEMPT_NEURALNETWORK_H


#include "myMatrix.h"

class NeuralNetwork {
public:
    NeuralNetwork(int inputSize, int numberOfHiddenLayers,int hiddenLayerSize,int outputSize);

    std::vector<myMatrix> waits;
    std::vector<myVector> baises;
myVector calculate(myVector vector) const;

};


#endif //NEURALNETWORKSECONDATTEMPT_NEURALNETWORK_H
