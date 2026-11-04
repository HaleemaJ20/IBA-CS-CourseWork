#include <cstddef>
#include <iostream>

int** create_matrix(std::size_t rows, std::size_t cols)
{
    int** matrix{new int*[rows]};

    for (std::size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (std::size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void delete_matrix(int** matrix, std::size_t rows)
{
    for (std::size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    std::size_t rows{3};
    std::size_t cols{4};
    int** mat{create_matrix(rows, cols)};

    if (mat != nullptr)
    {
        int count{1};
        for (std::size_t i{0}; i < rows; i++)
        {
            for (std::size_t j{0}; j < cols; j++)
            {
                mat[i][j] = count++;
            }
        }

        for (std::size_t i{0}; i < rows; i++)
        {
            for (std::size_t j{0}; j < cols; j++)
            {
                std::cout << mat[i][j] << '\t';
            }
            std::cout << std::endl;
        }

        delete_matrix(mat, rows);
        std::cout << "Matrix freed." << std::endl;
    }

    return 0;
}
