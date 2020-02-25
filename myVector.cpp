//
// Created by Jacob Riesen on 10/27/19.
//

#include <iostream>
#include "myVector.h"
#include <utility>
#include <vector>
#include <iomanip>
#include <cmath>
#include <random>

myVector::myVector(int length) {
    for (int i = 0; i < length; i++) {
        data.push_back(0.0);
    }
}

std::normal_distribution<> myVector::mutationDistribultion{0, 25};
std::uniform_real_distribution<double> myVector::uniform_real_distribution{-100, 100};
std::default_random_engine myVector::engine;

myVector::myVector(std::vector<double> vector) : data(std::move(vector)) {
}

double myVector::operator*(myVector &other) const {
    if (size() != other.size()) {
        throw std::range_error("the vectors are of different size");
    }
    double result = 0;
    for (int i = 0; i <(int) data.size(); i++) {
        result += data[i] * other[i];

    }
    return result;
}


std::ostream &operator<<(std::ostream &ostream, const myVector &vector) {
    ostream << "[";
    for (auto d:vector.data) {
        ostream << std::setw(3);
        ostream << d << " ";
    }
    ostream << "]";

    return ostream;
}

myVector myVector::operator+(const myVector &vector) const {
    std::vector<double> result;
    if (size() != vector.size()) {
        throw std::range_error("the vectors are of different size");
    }
    for (int i = 0; i <(int) vector.size(); i++) {
        result.emplace_back(data[i] + vector[i]);
    }

    return myVector(result);
}

myVector myVector::operator-(const myVector &vector) const {
    std::vector<double> result;
    if (size() != vector.size()) {
        throw std::range_error("the vectors are of different size");
    }
    for (int i = 0; i <(int) vector.size(); i++) {
        result.emplace_back(data[i] - vector[i]);
    }

    return myVector(result);
}

myVector myVector::sigmoid() const {
    myVector vector(static_cast<int>(this->size()));
    for (int i = 0; i <(int) this->size(); i++) {
        vector[i] = 1.0 / (1.0 + exp(-(*this)[i]));
    }
    return vector;
}

void myVector::randomize() {
    std::generate(std::begin(data), std::end(data), []() {
        return uniform_real_distribution(engine);
    });
}

void myVector::mutate() {
    for (auto &entry:data) {
        entry += mutationDistribultion(engine);
    }

}
