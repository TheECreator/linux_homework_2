#include <iostream>
#include "Polynomial.h"
#include <cmath>

Linux103::Polynomial::Polynomial(int argc, char** argv):
argc_(argc), argv_(argv){
    if(argc > 1){
        std::vector<int> temp;
        for(int i = 1; i < argc - 1; i += 2){
            temp.push_back(atoi(argv[i]));
            temp.push_back(atoi(argv[i + 1]));
            koef_degrees_.push_back(temp);
            temp.clear();
        }
    }
}

Linux103::Polynomial::Polynomial(std::vector<std::vector<int>> koef_degrees):koef_degrees_(koef_degrees){
}

//why do we need add ?
void Linux103::Polynomial::add (int coef, int degree) {
    std::vector<int> temp;
    temp.push_back(coef);
    temp.push_back(degree);
    koef_degrees_.push_back(temp);
}

long long int Linux103::Polynomial::calculate(int xValue) const{
    long long int result{};

    for(int i = 0; i < koef_degrees_.size(); ++i){
        result += koef_degrees_[i][0] * std::pow(xValue, koef_degrees_[i][1]);
    }

    return result;
}

void Linux103::Polynomial::print() const{
    for(int i = 0; i < koef_degrees_.size(); ++i){
        std::cout << koef_degrees_[i][0] << " x^" << koef_degrees_[i][1];
        if(i != koef_degrees_.size() - 1){
            std::cout << " + ";
        }
    }
    std::cout << "\n";
}

Linux103::Polynomial Linux103::Polynomial::derive() const {
    std::vector<std::vector<int>> derived;
    std::vector<int> temp;

    for(int i = 0; i < koef_degrees_.size(); ++i){
        temp.push_back(koef_degrees_[i][0] * koef_degrees_[i][1]);
        temp.push_back(koef_degrees_[i][1] - 1);
        derived.push_back(temp);
        temp.clear();       
    }

    return Polynomial(derived);
}
