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

using namespace std;

std::vector<Eigen::MatrixXcf> mytestfunc(int nrows, int ncols, int nvector) {
// testing returning by value and allocating/deallocating each time.
    
    std::vector<Eigen::MatrixXcf> MADI(nvector);
    for (auto i = 0; i < nvector; i++)
        MADI[i] = Eigen::MatrixXcf::Zero(nrows, ncols);

    return MADI;
}

void mytestfunc2(std::vector<Eigen::MatrixXcf>& MADI) {
    
    //testing passing externally allocated.
    auto n=MADI.size();
    //cerr << "vector size " << n << endl;
    for (auto i = 0; i < n; i++) 
        MADI[i].setZero();
}

std::vector<Eigen::MatrixXcf> mytestfunc(int nrows, int ncols);
void mytestfunc2(std::vector<Eigen::MatrixXcf>& MADI);
int main() {

    int ncalls=1000;
    int nrows=100;
    int ncols=100;
    int nvector=100;
    
    {
        timer* timer0 = new timer();
        timer0->start();
        for (auto i = 0; i < ncalls; i++)
            std::vector<Eigen::MatrixXcf> D = mytestfunc(nrows, ncols, nvector);
        timer0->end();
        std::cerr << "timer0->" << timer0->totalTime << endl;
    }

    {
        
        timer* timer1 = new timer();
        timer1->start();
        std::vector<Eigen::MatrixXcf> MADI(nvector);
        for (auto i = 0; i < nvector; i++)
            MADI[i] = Eigen::MatrixXcf(nrows, ncols);
        
        
        for (auto i = 0; i <ncalls;i++)
            mytestfunc2(MADI);
        timer1->end();
        std::cerr << "timer1->" << timer1->totalTime;

    }
    return 0;

}

