#ifndef LIBRARYM_H
#define LIBRARYM_H

#include <iostream>

using namespace std;

class matrix
{
private:
    int** data;
    int row,col;
public:
    matrix();
    matrix(int row, int col, int num[], matrix& mat);
//***************************************************
    friend ostream& operator<< (ostream& out ,matrix mat);
    friend istream& operator>> (istream& in, matrix &mat);
//***************************************************
    matrix operator+(matrix mat2);
    matrix operator-(matrix mat2);
    matrix operator*(matrix mat2);
    matrix operator+ (int scalar);
    matrix operator- (int scalar);
    matrix operator* (int scalar);
//**************************************************
    matrix operator+= (matrix& mat2);
    matrix operator-= (matrix& mat2);
    matrix operator+= (int scalar);
    matrix operator-= (int scalar);
    void   operator++ ();
    void   operator-- ();
//**************************************************
    bool operator== (matrix mat2);
    bool operator!= (matrix mat2);
    bool isSquare();
    bool isSymetric();
    bool isIdentity();
    matrix transpose();
//*********************************************************
    matrix& operator= (matrix mat2);
};

#endif // LIBRARYM_H
