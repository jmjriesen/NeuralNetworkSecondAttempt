#include <iostream>
#include "myVector.h"
#include "myMatrix.h"
#include "NeuralNetwork.h"
#define println(x) std::cout<<(x)<<std::endl

int main() {
    myMatrix matrix0(2, 3);
    matrix0[0][0] = 1;
    matrix0[0][1] = 2;
    matrix0[0][2] = 3;
    matrix0[1][0] = 4;
    matrix0[1][1] = 5;
    matrix0[1][2] = 6;

    myVector myVector1(3);
    myVector1[0]=1;
    myVector1[1]=2;
    myVector1[2]=-1;

    myVector myVector2(3);
    myVector2[0]=1;
    myVector2[1]=2;
    myVector2[2]=-1;


    myMatrix matrix1(3, 2);

    matrix1[0][0] = 0;
    matrix1[0][1] = 1;
    matrix1[1][0] = 2;
    matrix1[1][1] = 3;
    matrix1[2][0] = 4;
    matrix1[2][1] = 5;

    //std::cout << matrix0 << "\n";
    //std::cout << matrix1 << "\n";
    //myMatrix temp = matrix0.sigmoid();
    //std::cout<< temp<<std::endl;
    //std::cout << matrix0 * matrix1 << std::endl;
    std::cout<<matrix0<<std::endl;
    std::cout << matrix0*myVector1<<std::endl;
    NeuralNetwork network(3,5,6,7);
    network.randomize();
    println(network.calculate(myVector1));


    return 0;
}