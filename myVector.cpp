//
// Created by Jacob Riesen on 10/27/19.
//

#include <iostream>
#include "myVector.h"
#include <utility>
#include <vector>
#include <iomanip>
#include <cmath>

myVector::myVector(int length) {
 for(int i=0;i<length;i++){
     data.push_back(0.0);
 }
}

//myVector::myVector(myVector &vector) {
//data = vector.data;

//}

myVector::myVector(std::vector<double>  vector) :data(std::move(vector)) {

}

double myVector::operator*(myVector & other) const{
    if(size()!= other.size()){
        throw std::range_error("the vectors are of different size");
    }
    double result =0;
    for(int i=0; i<data.size();i++){
        result+=data[i]*other[i];

    }
    return result;
}


std::ostream &operator<<(std::ostream & ostream, const myVector& vector) {
    ostream<<"[";
    for(auto d:vector.data){
        ostream<<std::setw(3);
        ostream<<d<<" ";
    }
    ostream<<"]";

    return ostream;
}

myVector myVector::operator+(const myVector &vector) const {
    std::vector<double> result;
    if(size()!= vector.size()){
        throw std::range_error("the vectors are of different size");
    }
    for(int i=0;i<vector.size();i++){
        result.emplace_back(data[i]+vector[i]);
    }

    return myVector(result);
}

myVector myVector::sigmoid() const {
    myVector vector(static_cast<int>(this->size()));
    for(int i=0;i<this->size();i++){
        vector[i] = 1.0/(1.0+exp(-(*this)[i]));
    }
    return vector;
}