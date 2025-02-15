#include<iostream>
using namespace std;

int** createMatrix(int rows,int cols){
    int** matrix =new int*[rows];
    for (int i=0;i<rows;i++)
        matrix[i]=new int[cols];
    return matrix;
}
void inputMatrix(int** matrix,int rows,int cols) {
    for (int i=0;i <rows;i++)
        for(int j=0;j<cols;j++)
            cin>>matrix[i][j];
}
void displayMatrix(int** matrix,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            cout<<matrix[i][j];
        cout<<endl;
    }
}


void deleteMatrix(int** matrix,int rows){
    for(int i=0; i< rows;i++)
        delete[] matrix[i];
    delete[] matrix;
}
int main(){
    int r1,c1, r2,c2;
    cout<<"Enter rows and columns of first matrix: ";
    cin>>r1>> c1;
    cout <<"Enter rows and columns of second matrix: ";
    cin >>r2>>c2;

    if (c1!=r2){
        cout<<"Matrix multiplication not possible.\n";
        return 0;
    }

    int** A=createMatrix(r1, c1);
    int** B=createMatrix(r2,c2);
    int** result =createMatrix(r1,c2);

    cout<<"Enter elements of first matrix: "<<endl;
    inputMatrix(A,r1,c1);

    cout<<"Enter elements of second matrix: "<<endl;
    inputMatrix(B,r2,c2);

    for (int i=0; i<r1;i++)
        for(int j=0;j<c2;j++){
            result[i][j]=0;
            for(int k=0;k<c1;k++)
                result[i][j]+=A[i][k]*B[k][j];
        }
    cout<<"Resultant matrix: "<<endl;
    displayMatrix(result,r1,c2);
    deleteMatrix(A,r1);
    deleteMatrix(B,r2);
    deleteMatrix(result,r1);
    return 0;
}
