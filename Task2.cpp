#include <iostream>
using namespace std;

class Matrix
{
    int rowsNum;
    int columnsNum;
    int *rows;
    int *columns;

    public:

        Matrix(int r, int col)
        {
            rowsNum = r;
            columnsNum = col;

            rows = 
        }

        void transpose()
        {
            columnsNum = rowsNum;
            rowsNum = columnsNum;
        }

        void resize(int r, int col)
        {
            int *newRows = new int(r);
            int *newCol = new int(col);
        }

        void display()
        {
            for (int i = 0; i < rowsNum; i++)
            {
                for (int j = 0; j < columnsNum; j++)
                {
                    cout << 
                }
            }
        }
};

int main()
{


    return 0;
}