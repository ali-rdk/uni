#include <iostream>

using namespace std;

class matrix
{
private:
    int row, col;
    int mat[2][2];

public:
    matrix()
    {
        row = 2;
        col = 2;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    void set_matrix()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Enter the value of matrix[" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
        }
    }

    void display_matrix()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    matrix operator+(matrix n);

    matrix operator*(matrix n);

    matrix operator*(int n);
};

matrix matrix::operator+(matrix n)
{
    matrix temp;
    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.col; j++)
        {
            temp.mat[i][j] = mat[i][j] + n.mat[i][j];
        }
    }
    return temp;
}

matrix matrix::operator*(matrix n)
{
    matrix temp;
    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.col; j++)
        {
            for (int k = 0; k < temp.col; k++)
            {
                temp.mat[i][j] += mat[i][k] * n.mat[k][j];
            }
        }
    }
    return temp;
}

matrix matrix::operator*(int n)
{
    matrix temp;
    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.col; j++)
        {
            temp.mat[i][j] = mat[i][j] * n;
        }
    }
    return temp;
}

int main(void)
{
    matrix m1, m2, m3, m4;

    m1.set_matrix();
    cout << "Matrix 1: " << endl;
    m1.display_matrix();

    m2.set_matrix();
    cout << "Matrix 2: " << endl;
    m2.display_matrix();

    cout << "Addition of two matrices: " << endl;
    m3 = m1 + m2;
    m3.display_matrix();

    cout << "Multiplication of two matrices: " << endl;
    m4 = m1 * m2;
    m4.display_matrix();

    cout << "Multiplication of matrix with integer: " << endl;
    m4 = m1 * 2;
    m4.display_matrix();

    return 0;
}