#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

//-------------------------------matrix multiplication-------------------------------------------//
//usage of the matrix multiplication
//1. declare two matrix,by using vector, for instance, vector< vector<double> > matrix(n,vector<double>(m,2)) 
// vector< vector<double> > matrix2(m,vector<double>(k,1)) , notice that if dimensionalities are not matching, then it will directly call the error message
//here, I just choose return type double, as most of the matrix is dealing with realnumbers
//2. substitute two matrices into function : matrixmultiple(matrix1,matrix2);
//3. return type of this function is a multi-dimensional vector
//4. you can check the result matrix by looping result:
// ****
// Subordinate functions 1) dot-product 2)length of vector 3)sum of vector element : both functions return type is double. these functions will be surely useful, for those who want to calculate
// a sum of square
// lastly, I have extracted each column vector by assigning extraction function. 

//-------------------computation power will be weaker here, although pointers are used for passing arguments, since I have used double for loop, in the matrix multiplication
// this feature will be improved soon
double multiplying(double& p1, double& p2) {
    return p1 * p2;
}
double sumofvector(vector<double>& vec) {
    if (vec.size() == 0) {
        return 0.0;
    }
    else if (vec.size() == 1) {
        return vec[0];
    }
    else {
        double sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            sum = sum + vec[i];
        }
        return sum;
    }
}

double dotproduct(vector<double>& obj1, vector<double>& obj2) {
    if (obj1.size() == obj2.size()) {

        vector<double> transition;
        for (int i = 0; i < obj1.size(); i++) {
            transition.push_back(obj1[i] * obj2[i]);
        }
        return sumofvector(transition);
    }
    else {
        cout << "Check dimensionality of the vector" << endl;
    }
}
double lenVec(vector<double>* vec) {
    double result = dotproduct(*vec, *vec);
    return result;
}
vector<double> colvector(vector< vector<double> >& mat, int n) {
    //you must use index n   
    vector<double> colvec;

    for (int row = 0; row < mat.size(); row++) {
        for (int col = 0; col < mat[0].size(); col++) {
            if (col == n) {
                colvec.push_back(mat[row][col]);
            }
        }
    }
    return colvec;
}

template<typename T>
vector< vector<T> > matrixmultiple(vector< vector<T> >& obj1, vector< vector<T> >& obj2) {
    if (obj1[0].size() == obj2.size()) {
        vector< vector<double> > resultmat(obj1.size(), vector<double>(obj2[0].size(), 0));
        for (int row = 0; row < obj1.size(); row++) {
            for (int col = 0; col < obj2[0].size(); col++) {
                vector<double> strangevec;
                strangevec = colvector(obj2, col);
                resultmat[row][col] = dotproduct(obj1[row], strangevec);
            }
        }
        return resultmat;
    }
    else {
        cout << "error has been occured" << endl;
    }
}
int main()
{
    vector< vector<double> > matrix1(2, vector<double>(3, 2));
    vector< vector<double> > matrix2(3, vector<double>(2, 2));
    //sanity check for extracting column vector
    vector< vector<double> > resultmat = matrixmultiple(matrix1, matrix2);

    return 0;
}

