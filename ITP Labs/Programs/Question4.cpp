#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;
const int RECOVERY_DAYS = 5;
const int SIM_DAYS = 30;

void printGrid(int grid[MAX_SIZE][MAX_SIZE], int W, int H) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int state = grid[i][j];
            if (state == 0) cout << '.';
            else if (state >= 1 && state <= 9) cout << state;
            else if (state == -1) cout << 'R';
            else if (state == 10) cout << 'X';
        }
        cout << endl;
    }
}

void countStates(int grid[MAX_SIZE][MAX_SIZE], int W, int H,
                 int &healthy, int &infected, int &recovered, int &dead) {
    healthy = infected = recovered = dead = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int s = grid[i][j];
            if (s == 0) healthy++;
            else if (s >= 1 && s <= 9) infected++;
            else if (s == -1) recovered++;
            else if (s == 10) dead++;
        }
    }
}

bool hasInfectedNeighbor(int grid[MAX_SIZE][MAX_SIZE], int H, int W, int r, int c, int &maxSeverity) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    maxSeverity = 0;
    bool found = false;

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
            if (grid[nr][nc] >= 1 && grid[nr][nc] <= 9) {
                found = true;
                int sampled = rand() % grid[nr][nc] + 1;
                if (sampled > maxSeverity) maxSeverity = sampled;
            }
        }
    }
    return found;
}

int main() {
    srand(time(0));

    int W, H, I;
    double p, w;

    cout << "Enter grid width and height: ";
    cin >> W >> H;

    if (W <= 0 || H <= 0 || W > 100 || H > 100) {
        cout << "Invalid grid size." << endl;
        return 0;
    }

    cout << "Enter initial number of infected individuals: ";
    cin >> I;

    if (I <= 0 || I >= W * H) {
        cout << "Invalid number of infected individuals." << endl;
        return 0;
    }

    cout << "Enter infection probability p (0..1): ";
    cin >> p;

    cout << "Enter worsening probability w (0..1): ";
    cin >> w;

    if (p < 0 || p > 1 || w < 0 || w > 1) {
        cout << "Probabilities must be between 0 and 1." << endl;
        return 0;
    }

    int grid[MAX_SIZE][MAX_SIZE] = {0};
    int nextGrid[MAX_SIZE][MAX_SIZE] = {0};
    int daysInfected[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            daysInfected[i][j] = -1;

    int infectedCount = 0;
    while (infectedCount < I) {
        int r = rand() % H;
        int c = rand() % W;
        if (grid[r][c] == 0) {
            grid[r][c] = rand() % 9 + 1; 
            daysInfected[r][c] = 0;
            infectedCount++;
        }
    }

    cout << "\nInitial grid state:\n";
    printGrid(grid, W, H);

    for (int day = 1; day <= SIM_DAYS; day++) {
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                nextGrid[i][j] = grid[i][j];

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int state = grid[i][j];

                if (state == 0) {
                    int maxSev = 0;
                    if (hasInfectedNeighbor(grid, H, W, i, j, maxSev)) {
                        double chance = (double)rand() / RAND_MAX;
                        if (chance <= p) {
                            nextGrid[i][j] = maxSev;
                            daysInfected[i][j] = 0;
                        } else {
                            nextGrid[i][j] = 0;
                        }
                    }

                } else if (state >= 1 && state <= 9) { 
                    daysInfected[i][j]++;

                    double chance = (double)rand() / RAND_MAX;
                    bool worsen = (chance <= w);

                    if (state == 9 && worsen) {
                        nextGrid[i][j] = 10; 
                        daysInfected[i][j] = -1;
                    } else if (daysInfected[i][j] >= RECOVERY_DAYS) {
                        nextGrid[i][j] = -1; 
                        daysInfected[i][j] = -1;
                    } else {
                        if (worsen) state++;
                        else state--;
                        if (state < 1) state = 1;
                        if (state > 9) state = 9;
                        nextGrid[i][j] = state;
                    }

                } else if (state == -1 || state == 10) {
                    nextGrid[i][j] = state;
                }
            }
        }

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                grid[i][j] = nextGrid[i][j];

        int healthy, infected, recovered, dead;
        countStates(grid, W, H, healthy, infected, recovered, dead);

        cout << "Day " << day << ": "
             << "Healthy: " << healthy << ", "
             << "Infected: " << infected << ", "
             << "Recovered: " << recovered << ", "
             << "Dead: " << dead << endl;
    }

    cout << "\nFinal grid state:\n";
    printGrid(grid, W, H);

    return 0;
}
