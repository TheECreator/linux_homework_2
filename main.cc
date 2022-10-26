#include "Polynomial.h"
#include <iostream>

int main(int argc, char** argv){
    Linux103::Polynomial my_Polynomial(argc, argv);
    std::cout << my_Polynomial.calculate(72) << "\n";
    my_Polynomial.print();
    my_Polynomial.derive().print();
}