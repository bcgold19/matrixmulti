#pragma once
#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
namespace pmatricnames {
    class matrices {
    private:
        vector<vector<double>> mat;

    public:
        matrices() :mat({ {0} }) {}
        matrices(vector< vector<double> > mat) :mat(mat) {}
        matrices(const matrices& other) { mat = other.mat; }
        ~matrices() {}

        //Get function for overloading + and * operator
        vector<vector<double>> GetMat() {
            return this->mat;
        }
        //---------------------------
        double lowDim() const { return mat.size(); }
        double colDim() const {
            return mat[0].size();
        }
        void print() {
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[0].size(); j++) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
        }


    };
    ostream& operator<<(ostream& stream, matrices& mat) {
        vector<vector<double>> target(mat.GetMat());
        for (int i = 0; i < target.size(); i++) {
            for (int j = 0; j < target[0].size(); j++) {
                stream << target[i][j] << " ";
            }
            stream << endl;
        }
        return stream;
    }
    matrices operator+(matrices& mat1, matrices& mat2) {
        vector< vector<double> > obj1(mat1.GetMat());
        vector< vector<double> > obj2(mat2.GetMat());
        if (obj1.size() == obj2.size() && obj1[0].size() == obj2[0].size()) {
            vector< vector<double> > resultmat(obj1.size(), vector<double>(obj2[0].size(), 0));
            //generated zero matrix with corresponding dimension
            for (int row = 0; row < obj1.size(); row++) {
                for (int col = 0; col < obj2[0].size(); col++) {
                    resultmat[row][col] = obj1[row][col] + obj2[row][col];
                }
            }
            return matrices(resultmat);
        }
        else {
            cout << "check dimensionalities" << endl;
            return matrices({ {0} });
        }
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
    matrices operator*(matrices& mat1, matrices& mat2) {
        vector< vector<double> > obj1(mat1.GetMat());
        vector< vector<double> > obj2(mat2.GetMat());
        if (obj1[0].size() == obj2.size()) {
            vector< vector<double> > resultmat(obj1.size(), vector<double>(obj2[0].size(), 0));
            //generated zero matrix with corresponding dimension
            for (int row = 0; row < obj1.size(); row++) {
                for (int col = 0; col < obj2[0].size(); col++) {
                    vector<double> strangevec;
                    strangevec = colvector(obj2, col);
                    resultmat[row][col] = dotproduct(obj1[row], strangevec);
                }
            }
            return matrices(resultmat);
        }
        else {
            cout << "check dimensionalities" << endl;
            return matrices({ {0} });
        }
    }

}