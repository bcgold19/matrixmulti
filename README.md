# Matrix Algebra

Defined matrix class as matrices
(User can use +,* operators, if dimensionalities are matched for two matrices)

## How to use?
1. Instantiage matrix 
```c++
	matrices mat1({{1,2,3},{2,1,2}});
	matrices mat2({{1,2,3},{2,1,2}});
	matrices mat3({1,2},{2,3},{4,5});
```	

2. Addition and Multiplication	
```c++
	matrices add_two_mat(mat1+mat2); //notice that add_two_mat is also a matrices object. 
	matrices multiple(mat1* mat3);
```        
3. Scalar multiplication and Addition are also available.

```c++
	matrices mati(12* mat1); //scalar can be located at either right and left
	matrices mati1(12+mat1);	
```	
4. Print your matrix with simple "cout" code.
```c++
	cout<<mat1<<endl;
```

## Soon

Checking for the linear independency and several decompositions will be updated, as soon as possible.
