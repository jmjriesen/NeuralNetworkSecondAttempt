//
// Created by Jacob Riesen on 11/27/19.
//

#include <iostream>
#include "Experiment.h"
#include "NeuralNetwork.h"

void experiment1() {
    std::vector<myVector> trainingData(1000, myVector(2));
    for (auto &data:trainingData) {
        data.randomize();
    }

    NeuralNetwork recordHolder(2, 5, 5, 2);
    int record = 0;

    for (int i = 0; i < 100; i++) {
        NeuralNetwork challenger(2, 5, 5, 2);
        int challengerScore = 0;
        for (auto &data:trainingData) {
            auto result = challenger.calculate(data);

            if (data[0] > data[1] && result[0] > result[1] || data[0] < data[1] && result[0] < result[1]) {
                challengerScore++;
            }
        }
        if (challengerScore > record) {
            recordHolder = challenger;
            record = challengerScore;
        }

    }
    for(int i=0;i<10;i++) {
        std::vector<myVector> testingData(100, myVector(2));

        for (auto &data:testingData) {
            data.randomize();
        }
        int score = 0;
        for (auto &data:testingData) {
            auto result = recordHolder.calculate(data);

            if (data[0] > data[1] && result[0] > result[1] || data[0] < data[1] && result[0] < result[1]) {
                score++;
            }
        }
        std::cout << score << std::endl;
    }
}
void experiment2() {
    std::vector<myVector> trainingData(1000, myVector(2));
    for (auto &data:trainingData) {
        data.randomize();
    }

    NeuralNetwork recordHolder(2, 5, 5, 2);
    int record = 0;

    for (int i = 0; i < 100; i++) {
        NeuralNetwork challenger=recordHolder;
        challenger.mutate();
        int challengerScore = 0;
        for (auto &data:trainingData) {
            auto result = challenger.calculate(data);

            if (data[0] > data[1] && result[0] > result[1] || data[0] < data[1] && result[0] < result[1]) {
                challengerScore++;
            }
        }
        if (challengerScore > record) {
            recordHolder = challenger;
            record = challengerScore;
        }

    }
    std::cout<< std::endl;
    for(int i=0;i<10;i++) {
        std::vector<myVector> testingData(100, myVector(2));

        for (auto &data:testingData) {
            data.randomize();
        }
        int score = 0;
        for (auto &data:testingData) {
            auto result = recordHolder.calculate(data);

            if (data[0] > data[1] && result[0] > result[1] || data[0] < data[1] && result[0] < result[1]) {
                score++;
            }
        }
        std::cout << score << std::endl;
    }
}
