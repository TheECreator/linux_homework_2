#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <vector>

namespace Linux103
{
    class Polynomial
    {
        public:
            Polynomial(int argc, char** argv);
            Polynomial(std::vector<std::vector<int>> koef_degrees);
            void add(int coef, int degree) ;
            void print() const;
            long long int calculate(int xValue) const;
            Polynomial derive() const;
        private:
            int    argc_;
            char** argv_;
            std::vector<std::vector<int>> koef_degrees_;
    };
}

#endif
