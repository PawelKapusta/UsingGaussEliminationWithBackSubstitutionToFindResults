#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double x[7];

    double rightVector[7]={1, 2, 3, 4, 5, 6, 7};

    double matrix[7][7]={{4, 1, 0, 0, 0, 0, 1},
                         {1, 4, 1, 0, 0, 0, 0},
                         {0, 1, 4, 1, 0, 0, 0},
                         {0, 0, 1, 4, 1, 0, 0},
                         {0, 0, 0, 1, 4, 1, 0},
                         {0, 0, 0, 0, 1, 4, 1},
                         {1, 0, 0, 0, 0, 1, 4}};



    for(int i=0; i < 7; i++)
    {
        for(int j= i + 1; j < 7; j++)
        {

            double c= matrix[j][i] / matrix[i][i];
            rightVector[j]= rightVector[j] - c * rightVector[i];

            for(int k=i; k <= 7; k++)
            {
                if(i == k){
                    matrix[j][k]=0;
                }else{
                    matrix[j][k]= matrix[j][k] - c * matrix[i][k];
                }
            }

        }
    }
    cout<<endl;

    cout<<"Tridiagonal matrix: " <<endl;

    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            cout << setprecision(4) << matrix[i][j] << "\t";
        }
        cout<<endl;
    }


    for(int i=6; i>=0; i--) //  backsubstitution
    {
        double sum=0.0;

        for(int j=i+1; j<7; j++)
        {

            if(i!=j) sum+= matrix[i][j] * x[j];
        }
        x[i]= (rightVector[i] - sum) / matrix[i][i];
    }
    cout << endl;

    cout<<"Result:"<<endl;

    for(int i=0; i<7; i++)
    {
        cout<<"x"<<i+1<<"="<<setprecision(7)<<x[i]<<endl;
    }

    return 0;
}