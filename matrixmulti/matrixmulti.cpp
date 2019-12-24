#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "matrices.h"
using namespace std;
using namespace pmatricnames;

int main() {
    matrices mat1({ {1,2,3},{4,5,6} });
    matrices mat2({ {1,2},{3,4},{5,6} });
    matrices mat3(mat1 * mat2);
    cout << mat3 << endl;

}