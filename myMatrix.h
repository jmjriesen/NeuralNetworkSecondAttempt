//
// Created by Jacob Riesen on 10/27/19.
//

#ifndef NEURALNETWORKSECONDATTEMPT_MYMATRIX_H
#define NEURALNETWORKSECONDATTEMPT_MYMATRIX_H


#include <vector>
#include "myVector.h"

class myMatrix {



    std::vector<myVector> rowVectors;
private:

public:
    myVector getCol(int i) const;
    unsigned long getNumCol()const;
    unsigned long getNumRow()const{ return rowVectors.size();}
    explicit myMatrix(std::vector<myVector>);
    myMatrix(unsigned long  width,unsigned long  hight);

    myVector& operator[](int i){ return rowVectors[i];}
    myVector operator[](int i)const { return rowVectors[i];}

    myMatrix operator+(myMatrix matrix)const;
    myMatrix operator*(myMatrix matrix)const;
    myMatrix sigmoid()const ;

    friend std::ostream &operator<<(std::ostream&, const myMatrix&);
};


#endif //NEURALNETWORKSECONDATTEMPT_MYMATRIX_H