//
// Created by Jacob Riesen on 11/16/19.
//

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int inputSize, int numberOfHiddenLayers, int hiddenLayerSize, int outputSize) {
    //waits and biases for the first hidden layer.
    waits.emplace_back(static_cast<unsigned long>(hiddenLayerSize), static_cast<unsigned long>(inputSize));
    baises.emplace_back(hiddenLayerSize);


    //waits and biases for the all but the first hidden layer.
    for (int i = 1; i < numberOfHiddenLayers; i++) {
        waits.emplace_back(hiddenLayerSize, hiddenLayerSize);
        baises.emplace_back(hiddenLayerSize);
    }

    //waits and biases for the the last layer.
    waits.emplace_back(outputSize, hiddenLayerSize);
    baises.emplace_back(outputSize);

}

myVector NeuralNetwork::calculate(myVector vector) const {
    for (int i = 0; i < waits.size(); i++) {
        vector = (waits[i] * vector + baises[i]).sigmoid();
    }
    return vector;
}

void NeuralNetwork::randomize() {
    for (auto &layer:waits) {
        layer.randomize();
    }
    for (auto &layer:baises) {
        layer.randomize();
    }

}
