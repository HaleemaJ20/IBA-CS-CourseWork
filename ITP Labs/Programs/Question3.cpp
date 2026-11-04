#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    const int WIDTH = 80;
    const int HEIGHT = 20;
    double xmin, xmax;

    cout << "Enter range of x (in radians):\n";
    cout << "xmin = ";
    cin >> xmin;
    cout << "xmax = ";
    cin >> xmax;

    if (xmin >= xmax)
    {
        cout << "Invalid range! xmin must be smaller than xmax.\n";
        return 0;
    }

    const double ymin = -1.0;
    const double ymax = 1.0;

    char plotGrid[HEIGHT + 1][WIDTH + 1];
    for (int row = 0; row <= HEIGHT; row++)
        for (int col = 0; col <= WIDTH; col++)
            plotGrid[row][col] = ' ';

    int xAxisRow = HEIGHT / 2;
    int yAxisCol = (int)round((-xmin) / (xmax - xmin) * WIDTH);

    if (xAxisRow >= 0 && xAxisRow <= HEIGHT)
        for (int col = 0; col <= WIDTH; col++)
            plotGrid[xAxisRow][col] = '-';

    if (yAxisCol >= 0 && yAxisCol <= WIDTH)
        for (int row = 0; row <= HEIGHT; row++)
            plotGrid[row][yAxisCol] = '|';

    if (yAxisCol >= 0 && yAxisCol <= WIDTH && xAxisRow >= 0 && xAxisRow <= HEIGHT)
        plotGrid[xAxisRow][yAxisCol] = '+';

    for (int col = 0; col <= WIDTH; col++)
    {
        double x = xmin + col * (xmax - xmin) / WIDTH;
        double y = sin(x);
        int yPos = (int)round((ymax - y) / (ymax - ymin) * HEIGHT);
        if (yPos >= 0 && yPos <= HEIGHT)
            plotGrid[yPos][col] = '*';
    }

    for (int row = 0; row <= HEIGHT; row++)
    {
        for (int col = 0; col <= WIDTH; col++)
            cout << plotGrid[row][col];
        cout << endl;
    }

    return 0;
}
