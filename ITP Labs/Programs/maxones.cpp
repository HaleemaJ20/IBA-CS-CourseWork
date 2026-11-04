#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   

std::vector<std::vector<int>> gen_random_matrix(int m, int n)
{
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    std::srand(std::time(0)); 

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = std::rand() % 2; 
        }
    }
    return matrix;
}

void print_matrix(std::vector<std::vector<int>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int find_max_ones_row(std::vector<std::vector<int>> a)
{
    int maxRow = 0;
    int maxCount = -1;

    for (int i = 0; i < a.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxRow = i;
        }
    }

    return maxRow;
}

int find_max_ones_col(std::vector<std::vector<int>> a)
{
    int rows = a.size();
    int cols = a[0].size();

    int maxCol = 0;
    int maxCount = -1;

    for (int j = 0; j < cols; j++)
    {
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            if (a[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxCol = j;
        }
    }

    return maxCol;
}

int main()
{
    std::vector<std::vector<int>> matrix = gen_random_matrix(4, 4);

    std::cout << "Generated 4x4 Matrix:" << std::endl;
    print_matrix(matrix);

    int rowIndex = find_max_ones_row(matrix);
    int colIndex = find_max_ones_col(matrix);

    std::cout << "\nRow with most 1s: " << rowIndex + 1 << std::endl;      //+1 to convert from 0-based index  
    std::cout << "Column with most 1s: " << colIndex + 1 << std::endl;     //to 1-based counting (for user display)


    return 0;
}
