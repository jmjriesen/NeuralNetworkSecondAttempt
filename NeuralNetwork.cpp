//
// Created by Jacob Riesen on 11/16/19.
//

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int inputSize, int numberOfHiddenLayers, int hiddenLayerSize, int outputSize) {
    waits.emplace_back(static_cast<unsigned long>(inputSize), static_cast<unsigned long>(hiddenLayerSize));
    baises.emplace_back(inputSize);
    for (int i = 0; i < numberOfHiddenLayers; i++) {
        waits.emplace_back(hiddenLayerSize, hiddenLayerSize);
        baises.emplace_back(hiddenLayerSize);
    }
    waits.emplace_back(numberOfHiddenLayers, outputSize);
    baises.emplace_back(outputSize);

}

myVector NeuralNetwork::calculate(myVector vector) const {
    for(int i= 0;i<waits.size();i++){
        vector = (waits[i]*vector+baises[i]).sigmoid();
    }
    return myVector(0);
}
