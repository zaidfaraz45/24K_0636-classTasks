#include <iostream>
using namespace std;

class Matrix 
{
    int rowsNum;
    int colsNum;
    int **matrix;

    public:
        Matrix(int r, int c) 
        {
            rowsNum = r;
            colsNum = c;

            matrix = new int*[rowsNum];
            for (int i = 0; i < rowsNum; i++) 
            {
                matrix[i] = new int[colsNum];
                for (int j = 0; j < colsNum; j++) 
                {
                    matrix[i][j] = 0;
                }
            }
        }

        void resize(int newR, int newC, int fill) 
        {
            int **newData = new int*[newR];
            for (int i = 0; i < newR; i++)
            {
                newData[i] = new int[newC];
                for (int j = 0; j < newC; j++) 
                {
                    if (i < rowsNum && j < colsNum) 
                    {
                        newData[i][j] = matrix[i][j]; 
                    } 
                    else 
                    {
                        newData[i][j] = fill;
                    }
                }
            }

            for (int i = 0; i < rowsNum; i++) 
            {
                delete[] matrix[i];
            }
            delete[] matrix;

            rowsNum = newR;
            colsNum = newC;
            matrix = newData;
        }

        void transpose() 
        {
            int **newData = new int*[colsNum];
            for (int i = 0; i < colsNum; i++) 
            {
                newData[i] = new int[rowsNum];
                for (int j = 0; j < rowsNum; j++) 
                {
                    newData[i][j] = matrix[j][i];
                }
            }

            for (int i = 0; i < rowsNum; i++) 
            {
                delete[] matrix[i];
            }
            delete[] matrix;

            int temp = rowsNum;
            rowsNum = colsNum;
            colsNum = temp;

            matrix = newData;
        }

        void addToOddIndices() 
        {
            for (int i = 0; i < rowsNum; i++) 
            {
                for (int j = 0; j < colsNum; j++) 
                {
                    if ((i + j) % 2 == 1) 
                    {
                        matrix[i][j] += 2;
                    }
                }
            }
        }

        void display() 
        {
            for (int i = 0; i < rowsNum; i++) 
            {
                for (int j = 0; j < colsNum; j++) 
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        ~Matrix() 
        {
            for (int i = 0; i < rowsNum; i++) 
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
};

int main() {
    Matrix m(3, 3);  
    cout << "Original matrix:\n";
    m.display();

    cout << "\nAfter resizing to 4x5:\n";
    m.resize(4, 5, 7);
    m.display();

    cout << "\nAfter transposing:\n";
    m.transpose();
    m.display();

    cout << "\nAfter adding 2 to odd indices:\n";
    m.addToOddIndices();
    m.display();

    return 0;
}
