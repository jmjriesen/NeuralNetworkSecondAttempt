//
// Created by Jacob Riesen on 10/27/19.
//

#include "myMatrix.h"
#include <iostream>
#include <utility>

myMatrix::myMatrix(std::vector<myVector> vectors) : rowVectors(std::move(vectors)) {

}

std::ostream &operator<<(std::ostream &ostream, const myMatrix &matrix) {
    ostream << "[\n";
    for (const auto &rowVector:matrix.rowVectors) {
        ostream << rowVector << "\n";
    }
    ostream << "]";
    return ostream;
}

myMatrix::myMatrix(unsigned long hight, unsigned long width) {
    std::vector<double> row(width, 0);
    for (int i = 0; i < hight; i++) {
        rowVectors.emplace_back(std::vector<double>(width, 0));

    }

}

myVector myMatrix::getCol(int i) const {
    std::vector<double> vector;
    for (auto &row:rowVectors) {
        vector.emplace_back(row[i]);
    }
    return myVector(vector);
}

myMatrix myMatrix::operator+(const myMatrix matrix) const {
    if (getNumCol() != matrix.getNumCol() || getNumRow() != matrix.getNumRow()) {
        throw std::range_error("the matrices are of different size");
    }
    std::vector<myVector> result;
    for (int i = 0; i < getNumRow(); i++) {
        result.emplace_back(rowVectors[i] + matrix[i]);
    }
    return myMatrix(result);
}

unsigned long myMatrix::getNumCol() const {
    if (rowVectors.empty()) {
        return 0;
    } else {
        return rowVectors[0].size();
    }
}

myMatrix myMatrix::operator*(const myMatrix matrix) const {
    if (getNumRow() != matrix.getNumCol()) {
        std::range_error("internal dementions do not match");
    }
    myMatrix result(getNumRow(), matrix.getNumCol());
    for (int i = 0; i < matrix.getNumCol(); i++) {
        auto col = matrix.getCol(i);
        for (int j = 0; j < getNumRow(); j++) {
            result[j][i] = rowVectors[j] * col;
        }
    }
    return result;
}

myVector myMatrix::operator*(const myVector vector) const {
    if (this->getNumCol() != vector.size()) {
        throw std::range_error("the vectors and matrix do not match dememntions");
    }
    myVector result(static_cast<int>(this->rowVectors.size()));
    for (int i = 0; i < this->rowVectors.size(); i++) {
        for (int j = 0; j < vector.size(); j++) {
            result[i] += vector[j] * (*this)[i][j];
        }
    }
    return result;
}


myMatrix myMatrix::sigmoid() const {
    myMatrix matrix(rowVectors.size(), rowVectors[0].size());

    for (int i = 0; i < matrix.rowVectors.size(); i++) {
        matrix[i] = (*this)[i].sigmoid();
    }

    return matrix;
}

void myMatrix::randomize() {
    for (auto &row:rowVectors) {
        row.randomize();
    }
}

void myMatrix::mutate() {
    for(auto& row:rowVectors){
        row.mutate();
    }

}



