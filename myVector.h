//
// Created by Jacob Riesen on 10/27/19.
//

#ifndef NEURALNETWORKSECONDATTEMPT_MYVECTOR_H
#define NEURALNETWORKSECONDATTEMPT_MYVECTOR_H


#include <vector>
#include <random>

class myVector {
private:
    std::vector<double> data;
    static std::uniform_real_distribution<double> uniform_real_distribution;
    static std::default_random_engine engine;

public:
    explicit myVector(int length);

    //explicit myVector(myVector &vector);

    explicit myVector(std::vector<double>);

    double operator*(myVector& rhs) const;

    unsigned long size()const { return data.size();}
    void randomize();

    double &operator[](int i){ return data[i];}

    double operator[](int i) const { return data[i];}


    friend std::ostream &operator<<(std::ostream&, const myVector&);

    myVector operator+(const myVector& vector)const ;
    myVector operator-(const myVector& vector)const ;

    myVector sigmoid() const;
};


#endif //NEURALNETWORKSECONDATTEMPT_MYVECTOR_H
