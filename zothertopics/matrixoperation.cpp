//
// Created by zozo on 1/26/20.
//

#include <iostream>
#include "eigen-3.3.7/Eigen/Dense"
using Eigen::MatrixXd;
int main()
{
    MatrixXd m(4,4);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
}