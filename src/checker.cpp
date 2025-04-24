#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>

#include "testlib.h"

int main(int argc, char** argv) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int d = inf.readInt();
    int m = inf.readInt();
    int k = inf.readInt();

    long long correct_cnt = 0;

    for (int i = 0; i < m; ++i) {
        std::set<int> output;
        int tmp;
        for (int j = 0; j < k; ++j) {
            tmp = ouf.readInt(1, n);
            output.insert(tmp);
        }
        for (int j = 0; j < k; ++j) {
            tmp = ans.readInt();
            if (output.find(tmp) != output.end()) {
                ++correct_cnt;
            }
        }
    }
    
    double acc = 1. * correct_cnt / m / k;
    quitf(acc >= .95 ? _ok:_wa, "acc=%f", acc);
    return 0;
}