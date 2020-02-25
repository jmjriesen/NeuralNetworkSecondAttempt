#include <iostream>
#include "myVector.h"
#include "myMatrix.h"
#include "NeuralNetwork.h"
#include "Experiment.h"
#include <chrono>
#include <vector>

std::vector<int> temp;

#define println(x) std::cout<<(x)<<std::endl

int main() {
  experimentSetup();
    auto before = std::chrono::system_clock::now();
    experiment1();
    auto after = std::chrono::system_clock::now();
    std::cout<<(after-before).count()<<std::endl;
    std::cout << std::endl;

    before = std::chrono::system_clock::now();
    experiment2();
    after = std::chrono::system_clock::now();
    std::cout<<(after-before).count()<<std::endl;
    std::cout << std::endl;

    before = std::chrono::system_clock::now();
    experiment3();
    after = std::chrono::system_clock::now();
    std::cout<<(after-before).count()<<std::endl;

    return 0;
}
