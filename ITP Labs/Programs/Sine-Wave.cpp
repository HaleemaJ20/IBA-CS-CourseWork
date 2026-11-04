#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    const int W = 80;
    const int H = 20;
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

    char grid[H + 1][W + 1];
    for (int i = 0; i <= H; i++)
        for (int j = 0; j <= W; j++)
            grid[i][j] = ' ';

    int mid_y = H / 2;
    int mid_x = (int)round((-xmin) / (xmax - xmin) * W);

    if (mid_y >= 0 && mid_y <= H)
        for (int j = 0; j <= W; j++)
            grid[mid_y][j] = '-';

    if (mid_x >= 0 && mid_x <= W)
        for (int i = 0; i <= H; i++)
            grid[i][mid_x] = '|';

    if (mid_x >= 0 && mid_x <= W && mid_y >= 0 && mid_y <= H)
        grid[mid_y][mid_x] = '+';

    for (int j = 0; j <= W; j++)
    {
        double x = xmin + j * (xmax - xmin) / W;
        double y = sin(x);
        int grid_y = (int)round((ymax - y) / (ymax - ymin) * H);
        if (grid_y >= 0 && grid_y <= H)
            grid[grid_y][j] = '*';
    }

    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
            cout << grid[i][j];
        cout << endl;
    }

    return 0;
}
