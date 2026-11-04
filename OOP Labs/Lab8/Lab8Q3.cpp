#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
private:
    int rows, cols;
    T **data;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        data = new T *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new T[cols];
        }
    }

    Matrix(const Matrix &other)
    {
        rows = other.rows;
        cols = other.cols;

        data = new T *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void setValue(int i, int j, T value)
    {
        data[i][j] = value;
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Error: Matrices must have same dimensions!" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    void multiplyByScalar(T val)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] *= val;
            }
        }
    }
};

int main()
{
    Matrix<int> m1(2, 2), m2(2, 2);

    m1.setValue(0, 0, 1);
    m1.setValue(0, 1, 2);
    m1.setValue(1, 0, 3);
    m1.setValue(1, 1, 4);

    m2.setValue(0, 0, 5);
    m2.setValue(0, 1, 6);
    m2.setValue(1, 0, 7);
    m2.setValue(1, 1, 8);

    cout << "Matrix 1:\n";
    m1.display();
    cout << "Matrix 2:\n";
    m2.display();

    Matrix<int> sum = m1 + m2;
    cout << "Sum:\n";
    sum.display();

    m1.multiplyByScalar(2);
    cout << "Matrix 1 after scalar multiplication:\n";
    m1.display();

    return 0;
}