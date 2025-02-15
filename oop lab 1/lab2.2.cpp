#include <iostream>
using namespace std;

int** createMatrix(int rows,int cols) {
    int** matrix= new int*[rows];
    for(int i=0;i <rows;i++)
        matrix[i]=new int[cols];
    return matrix;
}

void inputMatrix(int** matrix,int rows,int cols){
    for(int i=0;i<rows;i++)
        for (int j =0;j< cols;j++)
            cin>> matrix[i][j];
}

void displayMatrix(int** matrix,int rows,int cols) {
    for (int i=0;i<rows; i++) {
        for (int j=0;j<cols;j++)
            cout<<matrix[i][j]<< " ";
        cout<< endl;
    }
}

void deleteMatrix(int** matrix,int rows){
    for(int i=0;i <rows;i++)
        delete[] matrix[i];
    delete[]matrix;
}

int main(){
    int rows,cols;
    cout<<"Enter number of rows and columns: "<<endl;
    cin>>rows >>cols;

    int** A=createMatrix(rows, cols);
    int** B=createMatrix(rows,cols);
    int** sum = createMatrix(rows,cols);
    int** diff =createMatrix( rows,cols);

    cout<<"Enter elements of first matrix: "<<endl;
    inputMatrix(A,rows,cols);

    cout<<"Enter elements of second matrix: "<<endl;
    inputMatrix(B,rows,cols);

    for (int i= 0;i<rows; i++)
        for(int j=0;j<cols;j++){
            sum[i][j]=A[i][j] +B[i][j];
            diff[i][j]=A[i][j]- B[i][j];
        }

    cout<<"Sum of matrices: "<<endl;
    displayMatrix(sum,rows,cols);

    cout<<"Difference of matrices: "<<endl;
    displayMatrix(diff,rows,cols);

    deleteMatrix(A,rows);
    deleteMatrix(B,rows);
    deleteMatrix(sum,rows);
    deleteMatrix(diff,rows);

    return 0;
}
