#include <iostream>
#include "libraryM.h"
using namespace std;

int main()
{
    matrix mat1,mat2;
    cout << "Enter your first matrix: "<< endl;
    cin >> mat1;
    cout << "Enter your second matrix: "<< endl;
    cin >> mat2;
    cout << "First matrix: " << endl;
    cout<<mat1 << endl;
    cout << "Second matrix: " << endl;
    cout<<mat2 << endl;
    while(true)
    {
        int y;
        cout<<"Choose Student number \"0,1,2,3\":";
        cin>>y;

        while(y==0)
        {
            string x;
            cout<<"Choose your operator: ";
            cin>>x;

            if(x=="+")
            {
                cout<<"your Result is: " << endl;
                cout<<(mat1+mat2)<<endl;
            }
            if(x=="-")
            {
                cout<<"your Result is: " << endl;
                cout<<(mat1-mat2)<<endl;
            }
            if(x=="*")
            {
                cout<<"your Result is: " << endl;
                cout<<(mat1*mat2)<<endl;
            }
            if(x=="+,")
            {
                int z;
                cout<<"Enter your scalar:";
                cin>>z;

                cout<<"your Result is: " << endl;
                cout<<(mat1+z)<<endl;
            }
            if(x=="-,")
            {
                int z;
                cout<<"Enter your scalar:";
                cin>>z;

                cout<<"your Result is: " << endl;
                cout<<(mat1-z)<<endl;
            }
            if(x=="*,")
            {
                int z;
                cout<<"Enter your scalar:";
                cin>>z;

                cout<<"your Result is: " << endl;
                cout<<(mat1*z)<<endl;
            }
            if(x=="0")
            {
                break;
            }
        }

        while(y==1)
        {
            string x;
            cout<<"Choose your operator: ";
            cin>>x;

            if(x=="+=")
            {
                cout<<"your Result is: " << endl;
                cout<<(mat1+=mat2)<<endl;
            }
            if(x=="-=")
            {
                cout<<"your Result is: " << endl;
                cout<<(mat1-=mat2)<<endl;
            }
            if(x=="+=,")
            {
                int z;
                cout<<"Enter your scalar:";
                cin>>z;

                cout<<"your Result is: " << endl;
                cout<<(mat1+=z)<<endl;
            }
            if(x=="-=,")
            {
                int z;
                cout<<"Enter your scalar:";
                cin>>z;

                cout<<"your Result is: " << endl;
                cout<<(mat1-=z)<<endl;
            }
            if(x=="++")
            {
                int y;
                cout<<"Choose your matrix: ";
                cin>>y;
                if(y==1)
                {
                    ++mat1;
                    cout<<"your Result is: " << endl;
                    cout<<mat1<<endl;
                }
                if(y==2)
                {
                    ++mat2;
                    cout<<"your Result is: " << endl;
                    cout<<mat2<<endl;
                }
            }
            if(x=="--")
            {
                int y;
                cout<<"Choose your matrix: ";
                cin>>y;
                if(y==1)
                {
                    --mat1;
                    cout<<"your Result is: " << endl;
                    cout<<mat1<<endl;
                }
                if(y==2)
                {
                    --mat2;
                    cout<<"your Result is: " << endl;
                    cout<<mat2<<endl;
                }
            }
            if(x=="0")
            {
                break;
            }
        }

        while(y==2)
        {
            string x;
            cout<<"Choose your operator: ";
            cin>>x;


            if(x=="==")
            {
                cout<<"your Result is: " << endl;
                cout<<(mat1==mat2)<<endl;
            }
            if(x=="!=")
            {
                cout<<"your Result is: " << endl;
                cout<<(mat1!=mat2)<<endl;
            }
            if(x=="sq")
            {
                int y;
                cout<<"Choose your matrix: ";
                cin>>y;
                if(y==1)
                {
                    mat1.isSquare();
                    cout<<"your Result is: " << endl;
                    cout<<mat1<<endl;
                }
                if(y==2)
                {
                    mat2.isSquare();
                    cout<<"your Result is: " << endl;
                    cout<<mat2<<endl;
                }
            }
            if(x=="sym")
            {
                int y;
                cout<<"Choose your matrix: ";
                cin>>y;
                if(y==1)
                {
                    mat1.isSymetric();
                    cout<<"your Result is: " << endl;
                    cout<<mat1<<endl;
                }
                if(y==2)
                {
                    mat2.isSymetric();
                    cout<<"your Result is: " << endl;
                    cout<<mat2<<endl;
                }

            }
            if(x=="iden")
            {
                int y;
                cout<<"Choose your matrix: ";
                cin>>y;
                if(y==1)
                {
                    mat1.isIdentity();
                    cout<<"your Result is: " << endl;
                    cout<<mat1<<endl;
                }
                if(y==2)
                {
                    mat2.isIdentity();
                    cout<<"your Result is: " << endl;
                    cout<<mat2<<endl;
                }
            }
            if(x=="trans")
            {
                int y;
                cout<<"Choose your matrix: ";
                cin>>y;
                if(y==1)
                {
                    mat1.transpose();
                    cout<<"your Result is: " << endl;
                    cout<<mat1<<endl;
                }
                if(y==2)
                {
                    mat2.transpose();
                    cout<<"your Result is: " << endl;
                    cout<<mat2<<endl;
                }

            }
            if(x=="0")
            {
                break;
            }
        }
        while(y==3)
        {
            string x;
            cout<<"Choose your operator: ";
            cin>>x;
            if(x=="=")
            {
                matrix mat3;
                int y;
                cout<<"Choose your matrix: ";
                cin>>y;
                if(y==1)
                {
                    mat3=mat1;
                    cout<<"your Result is: " << endl;
                    cout<<mat3<<endl;
                }
                if(y==2)
                {
                    mat3=mat2;
                    cout<<"your Result is: " << endl;
                    cout<<mat3<<endl;
                }
            }
            if(x=="0")
            {
                break;
            }
        }
    }


}

