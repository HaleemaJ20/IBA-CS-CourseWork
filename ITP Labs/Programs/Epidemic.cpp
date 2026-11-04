#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    srand(time(0));

    const int MAX_SIZE = 100;
    const int RECOVERY_DAYS = 5;
    const int SIM_DAYS = 30;

    int W, H, I;
    double p, w;

    cout << "Enter grid width and height: ";
    cin >> W >> H;
    cout << "Enter initial number of infected individuals: ";
    cin >> I;
    cout << "Enter infection probability p (0..1): ";
    cin >> p;
    cout << "Enter worsening probability w (0..1): ";
    cin >> w;

    if (W <= 0 || H <= 0 || W > MAX_SIZE || H > MAX_SIZE || I <= 0 || I >= W * H || p < 0 || p > 1 || w < 0 || w > 1) {
        cout << "Invalid input values.\n";
        return 0;
    }

    int grid[MAX_SIZE][MAX_SIZE] = {0};
    int daysInfected[MAX_SIZE][MAX_SIZE] = {0};

    for (int i = 0; i < I; ) {
        int x = rand() % H;
        int y = rand() % W;
        if (grid[x][y] == 0) {
            grid[x][y] = 1 + rand() % 9; 
            i++;
        }
    }

    cout << "Initial grid state:\n";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 0) cout << ".";
            else if (grid[i][j] == -1) cout << "R";
            else if (grid[i][j] == 10) cout << "X";
            else cout << grid[i][j];
        }
        cout << endl;
    }

    for (int day = 1; day <= SIM_DAYS; day++) {
        int newGrid[MAX_SIZE][MAX_SIZE];
        int newDays[MAX_SIZE][MAX_SIZE];

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                newGrid[i][j] = grid[i][j];
                newDays[i][j] = daysInfected[i][j];
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int state = grid[i][j];

                if (state == 0) { 
                    int maxSeverity = 0;
                    int infectedNeighbor = 0;

                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, -1, 1};
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                            if (grid[ni][nj] >= 1 && grid[ni][nj] <= 9) {
                                infectedNeighbor = 1;
                                if (grid[ni][nj] > maxSeverity) maxSeverity = grid[ni][nj];
                            }
                        }
                    }

                    if (infectedNeighbor && ((double)rand() / RAND_MAX) < p) {
                        newGrid[i][j] = 1 + rand() % maxSeverity; 
                        if (newGrid[i][j] > 9) newGrid[i][j] = 9;
                        newDays[i][j] = 0;
                    }
                }

                else if (state >= 1 && state <= 9) { 
                    newDays[i][j]++;

                    if (((double)rand() / RAND_MAX) < w) {
                        newGrid[i][j]++;
                        if (newGrid[i][j] > 9) newGrid[i][j] = 10; 
                    } else {
                        newGrid[i][j]--;
                        if (newGrid[i][j] < 1) newGrid[i][j] = 1;
                    }

                    if (newDays[i][j] >= RECOVERY_DAYS && newGrid[i][j] != 10) {
                        newGrid[i][j] = -1;
                        newDays[i][j] = 0;
                    }
                }

                else if (state == -1 || state == 10) {
                    newGrid[i][j] = state;
                }
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                grid[i][j] = newGrid[i][j];
                daysInfected[i][j] = newDays[i][j];
            }
        }

        int healthy = 0, infected = 0, recovered = 0, dead = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == 0) healthy++;
                else if (grid[i][j] >= 1 && grid[i][j] <= 9) infected++;
                else if (grid[i][j] == -1) recovered++;
                else if (grid[i][j] == 10) dead++;
            }
        }

        cout << "Day " << day << ": Healthy: " << healthy
             << ", Infected: " << infected
             << ", Recovered: " << recovered
             << ", Dead: " << dead << endl;
    }

    cout << "Final grid state:\n";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 0) cout << ".";
            else if (grid[i][j] == -1) cout << "R";
            else if (grid[i][j] == 10) cout << "X";
            else cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
