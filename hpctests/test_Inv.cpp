#include <iostream>
#include "Timer.hpp"
#include <iostream>
#include <complex>
#include <algorithm>
#include <math.h>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Sparse>
#include <eigen3/Eigen/SparseCholesky>
#include <eigen3/Eigen/SparseLU>
#include <iomanip>
#include <vector>
#include <complex>
#include <time.h>

void test() {
    return;
}

std::vector<Eigen::MatrixXcf> mytestfunc();
void mytestfunc2(std::vector<Eigen::MatrixXcf>& MADI);
int main() {
    timer* timer0 = new timer();

    {
        timer0->start();
        for (auto i = 0; i < 10; i++)
            std::vector<Eigen::MatrixXcf> D = mytestfunc();
        timer0->end();
        std::cerr << "timer0" << timer0->totalTime;
    }

    {
        
        int n = 1000;
        std::vector<Eigen::MatrixXcf> MADI(n);
        for (auto i = 0; i < n; i++)
            MADI[i] = Eigen::MatrixXcf(1000, 1000);
        
        timer0->start();
        for (auto i = 0; i <10;i++)
            mytestfunc2(MADI);
        timer0->end();
        std::cerr << "timer1" << timer0->totalTime;

    }
    return 0;

}

std::vector<Eigen::MatrixXcf> mytestfunc() {
    int n = 1000;
    std::vector<Eigen::MatrixXcf> MADI(n);
    for (auto i = 0; i < n; i++)
        MADI[i] = Eigen::MatrixXcf(1000, 1000);

    return MADI;
}

void mytestfunc2(std::vector<Eigen::MatrixXcf>& MADI) {
    for (auto i = 0; i < MADI.size(); i++) 
        MADI[i].setZero();
}