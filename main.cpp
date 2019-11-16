#include <iostream>
#include "myVector.h"
#include "myMatrix.h"

int main() {
    myMatrix matrix0(2, 3);
    matrix0[0][0] = 0;
    matrix0[0][1] = 100;
    matrix0[0][2] = -20;
    matrix0[1][0] = 0;
    matrix0[1][1] = 0;
    matrix0[1][2] = 0;

    myMatrix matrix1(3, 2);

    matrix1[0][0] = 0;
    matrix1[0][1] = 1;
    matrix1[1][0] = 2;
    matrix1[1][1] = 3;
    matrix1[2][0] = 4;
    matrix1[2][1] = 5;

    std::cout << matrix0 << "\n";
    std::cout << matrix1 << "\n";
    myMatrix temp = matrix0.sigmoid();
    std::cout<< temp<<std::endl;
    std::cout << matrix0 * matrix1 << std::endl;


    return 0;
}