# matrixmulti
a babystep of matrix multiplication

MATRIX MULTIPLE
usage of the matrix multiplication
1. declare two matrix,by using vector, 
for instance, vector< vector<double> > matrix(n,vector<double>(m,2)) 
 vector< vector<double> > matrix2(m,vector<double>(k,1)) ,
 
 notice that if dimensionalities are not matching, 

then it will directly call the error message
here, I just choose return type double, as most of the matrix is dealing with realnumbers

2. substitute two matrices into function : matrixmultiple(matrix1,matrix2);
3. return type of this function is a multi-dimensional vector
4. you can check the result matrix by looping result:

 Subordinate functions 1) dot-product 2)length of vector 3)sum of vector element : 
 both functions return type is double. these functions will be surely useful, for those who want to calculate
 a sum of square.
 lastly, I have extracted each column vector by assigning extraction function. 

-------------------
computation power will be weaker here, although pointers are used for passing arguments, 
since I have used double for loop, in the matrix multiplication
// this feature will be improved soon
