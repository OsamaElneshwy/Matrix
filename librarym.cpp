#include "libraryM.h"
#include<iostream>
using namespace std;
matrix::matrix()
{

}

matrix::matrix(int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}
//***********************************************************
ostream& operator<< (ostream& out,matrix mat)
{
    for (int i=0 ; i < mat.row ; i++ )
    {
        for (int j=0 ; j<mat.col ; j++ )
        {
            out << mat.data[i][j] << "   " ;
        }
        cout << endl;
    }
    return out;
}

istream& operator>> (istream& in, matrix& mat)
{
    int row,col;
    cout<<"Enter your row: ";
    cin>>row;
    cout<<"Enter your column: ";
    cin>>col;
    cout<<"Enter your element: ";
    int data[row*col];
    for(int i=0; i<row*col; i++)
    {
        in>>data[i];
    }

    matrix(row,col,data,mat);
    return in;
}



//*********************************************************************


matrix matrix::operator+(matrix mat2)
{
    if((this->row==mat2.row)&&(this->col==mat2.col))
    {
        matrix mat;
        int data[mat2.row];
        matrix(mat2.row,mat2.col, data, mat);
        for(int i=0; i<mat2.row; i++)
        {
            for(int j=0; j<mat2.col; j++)
            {
                mat.data[i][j]=this->data[i][j]+mat2.data[i][j];
            }
        }
        return mat;
    }
    else
    {
        cout<<"The two matrices haven't the same dimensions"<<endl;
        return mat2;
    }
}


matrix matrix::operator-(matrix mat2)
{
    if((this->row==mat2.row)&&(this->col==mat2.col))
    {
        matrix mat;
        int data[mat2.row];
        matrix(mat2.row,mat2.col, data, mat);
        for(int i=0; i<mat2.row; i++)
        {
            for(int j=0; j<mat2.col; j++)
            {
                mat.data[i][j]=this->data[i][j]-mat2.data[i][j];
            }
        }
        return mat;
    }
    else
    {
        cout<<"The two matrices haven't the same dimensions"<<endl;
        return mat2;
    }
}


matrix matrix:: operator*(matrix mat2)
{
    if((this->col==mat2.row))
    {
        matrix mat;
        int data[mat2.row];
        matrix(this->row,mat2.col, data, mat);
        for(int i=0; i<this->row; i++)
        {
            for(int j=0; j<mat2.col; j++)
            {
                int sum=0;
                for(int k=0; k<this->row; k++)
                {
                    sum=sum+this->data[i][k]*mat2.data[k][j];
                }
                mat.data[i][j]=sum;
            }

        }
        return mat;
    }
    else
    {
        cout<<"The number of Columns of matrix(1) not equal the number of rows of matrix(2)"<<endl;
        return mat2;
    }
}


matrix matrix::operator+ (int scalar)
{
    matrix mat;
    int data[this->row];
    matrix(this->row,this->col, data, mat);
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            mat.data[i][j]=this->data[i][j]+scalar;
        }
    }
    return mat;
}


matrix matrix::operator- (int scalar)
{
    matrix mat;
    int data[this->row];
    matrix(this->row,this->col, data, mat);
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            mat.data[i][j]=this->data[i][j]-scalar;
        }
    }
    return mat;
}


matrix matrix :: operator*  (int scalar)
{
    matrix mat;
    int data[this->row];
    matrix(this->row,this->col, data, mat);
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            mat.data[i][j]=this->data[i][j]*scalar;
        }
    }
    return mat;
}
//*************************************************************

matrix matrix:: operator+= (matrix& mat2)
{
    if((this->row==mat2.row)&&(this->col==mat2.col))
    {
        for ( int i=0 ; i<mat2.row; i++)
        {
            for (int j=0 ; j<mat2.col ; j++)
            {
                mat2.data[i][j]= this->data[i][j]+mat2.data[i][j];
            }
        }
        return mat2;
    }
    else
    {
        cout<<"The two matrices haven't the same dimensions"<<endl;
        return mat2;
    }
}


matrix matrix:: operator-= (matrix& mat2)
{
    if((this->row==mat2.row)&&(this->col==mat2.col))
    {
        for ( int i=0 ; i<mat2.row; i++)
        {
            for (int j=0 ; j<mat2.col ; j++)
            {
                mat2.data[i][j]= this->data[i][j]-mat2.data[i][j];
            }
        }
        return mat2;
    }
    else
    {
        cout<<"The two matrices haven't the same dimensions"<<endl;
        return mat2;
    }
}

matrix matrix:: operator+= (int scalar)
{
    for ( int i=0 ; i<this->row ; i++)
    {
        for (int j=0 ; j<this->col ; j++)
        {
            this->data[i][j]=this->data[i][j]+scalar;
        }
    }
    matrix mat;
    int data[this->row];
    matrix(this->row,this->col, data, mat);
    for ( int i=0 ; i<this->row ; i++)
    {
        for (int j=0 ; j<this->col ; j++)
        {
            mat.data[i][j]=this->data[i][j];
        }
    }
    return mat;
}


matrix matrix:: operator-= (int scalar)
{
    for ( int i=0 ; i<this->row ; i++)
    {
        for (int j=0 ; j<this->col ; j++)
        {
            this->data[i][j]=this->data[i][j]-scalar;
        }
    }
    matrix mat;
    int data[this->row];
    matrix(this->row,this->col, data, mat);
    for ( int i=0 ; i<this->row ; i++)
    {
        for (int j=0 ; j<this->col ; j++)
        {
            mat.data[i][j]=this->data[i][j];
        }
    }
    return mat;
}


void matrix:: operator++ ()
{
    for ( int i=0 ; i<this->row ; i++)
    {
        for (int j=0 ; j<this->col ; j++)
        {
            this->data[i][j]=this->data[i][j]+1 ;
        }
    }
}

void matrix:: operator-- ()
{
    for ( int i=0 ; i<this->row ; i++)
    {
        for (int j=0 ; j<this->col ; j++)
        {
            this->data[i][j]=this->data[i][j]-1 ;
        }
    }
}

//*********************************************************************************

bool matrix::operator== (matrix mat2)
{
    int x;
    if ((this->row == mat2.row ) && (this->col==mat2.col))
    {
        for (int i=0 ; i<this->row ; i++ )
        {
            for (int j = 0 ; j<this->col; j++ )
                if (this->data[i][j]==mat2.data[i][j])
                    x=true;

                else
                    x=false;
        }
    }
    else
        x=false;
    if ( x  == 1 )
    {
        cout << "True , The matrix is equal" << endl;
    }
    else if (  x == 0 )
    {
        cout << "False , The matrix is not equal" << endl;
        return x;
    }
}


bool matrix:: operator!= (matrix mat2)
{
    int x;
    if ((this->row != mat2.row ) || (this->col!=mat2.col))
    {
        x=true;
    }
    else if ((this->row == mat2.row ) && (this->col==mat2.col))
    {
        for (int i=0 ; i<this->row ; i++ )
        {
            for (int j = 0 ; j<this->col; j++ )
                if (this->data[i][j]!=mat2.data[i][j])
                    x=true;

                else
                    x=false;
        }
    }
    if ( x  == 1 )
    {
        cout << "True , The two matrices are not equal" << endl;
    }
    else if (  x == 0 )
    {
        cout << "False , The matrix is  equal" << endl;
        return x;
    }
}


bool matrix::isSquare()
{
    bool x;
    if (this->row == this->col )
    {
        x= true;
    }
    else
        x= false;
    if ( x  == 1 )
    {
        cout << "True , The matrix is square" << endl;
    }
    else if (  x == 0 )
    {
        cout << "False , The matrix is not square" << endl;
    }
}


bool matrix:: isSymetric ()
{
    int x=0;
    if ( this->col != this->row )
    {
        cout << "The matrix can not be symmetric ";
    }
    else if (this->col == this->row )
    {
        for (int i=0 ; i<this->row; i++ )
        {
            for (int j=0 ; j<this->col ; j++ )
            {
                if (this->data[i][j]==this->data[j][i])
                    x+=1;

            }

        }

        if (this->col*this->row != x)
        {
            cout << "the matrix is not symmetric";
        }
        else if (this->col*this->row == x)
        {
            cout << "the matrix is  symmetric";
        }

    }
}


bool matrix:: isIdentity ()
{
    bool x, y;
    if ( this->row != this->col )
    {
        x=false;
    }
    else if (this->row == this->col)
    {
        for (int i=0 ; i< this->row ; i++ )
        {
            for ( int j=0 ; j<this->col ; j++ )
            {
                if ((i==j) && (this->data[i][j]) == 1 )
                {
                    x=true;
                }
                if ( (i!=j) && ( this->data[i][j]==0 ) )
                {
                    y=true;
                }
                else
                    x = false;
            }
        }
    }
    if (( y && x ) == 1 )
    {
        cout << "True , The matrix is identical and square" << endl;
    }
    else if ( (y && x) == 0 )
    {
        cout << "False , The matrix is not identical  " << endl;
    }
}


matrix matrix:: transpose()
{
    matrix mat1;
    int data[this->row];
    matrix(this->row, this->col, data, mat1);
    for (int i=0 ; i<mat1.row ; i++)
    {
        for (int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]=this->data[j][i];
        }
    }
    return mat1;
}
//***********************************************************************

matrix& matrix:: operator= (matrix mat2)
{
    this->row = mat2.row;
    this->col = mat2.col;
    this->data = new int*[this->row];

    for (int i = 0; i < this->row; i++)
    {
        this->data[i] = new int [this->col];
    }
    for (int i = 0; i < mat2.row; i++)
    {
        for (int j = 0; j < mat2.col; j++)
        {
            this->data[i][j] = mat2.data[i][j];
        }
    }
}
