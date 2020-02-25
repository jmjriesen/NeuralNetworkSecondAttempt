//
// Created by Jacob Riesen on 11/27/19.
//

#include <iostream>
#include <sys/param.h>
#include "Experiment.h"
#include "NeuralNetwork.h"

const int trainingDataSize = 1000;
const int testingDataSize = 100;
std::vector<myVector> trainingData(trainingDataSize, myVector(2));
std::vector<std::vector<myVector>> testingData(10, std::vector(testingDataSize, myVector(2)));

void experimentSetup() {
    for (auto &data:trainingData) {
        data.randomize();
    }
    for (auto &dataSet:testingData) {
        for (auto &data:dataSet) {
            data.randomize();
        }
    }
}

std::pair<int, double> calculateScore(const NeuralNetwork &network, const std::vector<myVector> &dataSet) {
    int score = 0;
    double cost = 0;
    for (auto &data:dataSet) {
        auto result = network.calculate(data);
        //I should make this cost function different
        if ((data[0] > data[1] && result[0] > result[1]) || (data[0] < data[1] && result[0] < result[1])) {
            score++;
        }

        if (data[0] > data[1]) {
            cost += pow(result[0] - 0, 4) + pow(result[1] - 1, 4);
        } else {
            cost += pow(result[0] - 1, 4) + pow(result[1] - 0, 4);
        }
    }
    return std::make_pair(score,cost);
}

std::vector<std::pair<int,double>> testNetwork(const NeuralNetwork &network) {
    std::vector<std::pair<int,double>>results;
    for (auto &dataSet:testingData) {
        auto score = calculateScore(network, dataSet);
        results.push_back(score);
        std::cout << score.first << std::endl;
    }
    return results;
}

void experiment1() {

    NeuralNetwork recordHolder(2, 2, 20, 2);
    auto record = calculateScore(recordHolder, trainingData);

    for (int i = 0; i < 100; i++) {
        NeuralNetwork challenger(2, 2, 20, 2);

        auto challengerScore = calculateScore(challenger, trainingData);


        if (challengerScore.second > record.second) {
            recordHolder = challenger;
            record = challengerScore;
        }

    }
    testNetwork(recordHolder);

}

void experiment2() {
    NeuralNetwork recordHolder(2, 2, 20, 2);
    auto record = calculateScore(recordHolder, trainingData);

    for (int i = 0; i < 100; i++) {
        NeuralNetwork challenger = recordHolder;
        challenger.mutate();
        auto challengerScore = calculateScore(challenger, trainingData);

        if (challengerScore.second > record.second) {
            recordHolder = challenger;
            record = challengerScore;
        }

    }
    testNetwork(recordHolder);
}

void experiment3() {

    NeuralNetwork recordHolder(2, 2, 20, 2);

    auto record = calculateScore(recordHolder, trainingData);

    //batches
    for (int i = 0; i < 10; i++) {
        std::vector<std::pair<NeuralNetwork, std::pair<int,double>>> challangers(10, std::make_pair(recordHolder, record));
        for (auto &network_Score:challangers) {
            network_Score.first.mutate();
        }

        // testing batch
        for (auto &network_Score:challangers) {
            network_Score.second = calculateScore(network_Score.first, trainingData);
        }
        //updating if anything in the batch is new record holder.
        for (auto &network_Score:challangers) {
            if (network_Score.second > record) {
                recordHolder = network_Score.first;
                record = network_Score.second;
            }
        }

    }
    testNetwork(recordHolder);
}
