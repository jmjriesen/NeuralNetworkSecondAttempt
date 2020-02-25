//
// Created by Jacob Riesen on 10/27/19.
//

#ifndef NEURALNETWORKSECONDATTEMPT_MYMATRIX_H
#define NEURALNETWORKSECONDATTEMPT_MYMATRIX_H


#include <vector>
#include "myVector.h"

class myMatrix {
private:
  std::vector<myVector> rowVectors;

public:
  explicit myMatrix(std::vector<myVector>);
  explicit myMatrix(myVector);
  myVector getCol(int i) const;
  unsigned long getNumCol()const;
  unsigned long getNumRow()const{ return rowVectors.size();}
  myMatrix(unsigned long  width,unsigned long  hight);
  void randomize();
  void mutate();

  myVector& operator[](int i){ return rowVectors[i];}
  myVector operator[](int i)const { return rowVectors[i];}

  myMatrix operator+(myMatrix matrix)const;
  myMatrix operator*(myMatrix matrix)const;
  myVector operator*(myVector vector)const;
  myMatrix transpose() const;

  myMatrix sigmoid() const;

  friend std::ostream &operator<<(std::ostream&, const myMatrix&);
};


#endif //NEURALNETWORKSECONDATTEMPT_MYMATRIX_H
