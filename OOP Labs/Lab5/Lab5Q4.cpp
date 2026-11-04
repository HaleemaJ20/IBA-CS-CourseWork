#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Position {
    int x;
    int y;
};

class Player {
private:
    Position pos;

public:
    Player() {
        pos.x = 0;
        pos.y = 0;
    }

    Position getPosition() const {
        return pos;
    }

    void displayPosition() const {
        cout << "Player Position: (" << pos.x << ", " << pos.y << ")" << endl;
    }

    friend class Grid;
};

class Enemy {
private:
    Position pos;

public:
    Enemy() {
        pos.x = 0;
        pos.y = 0;
    }

    void moveRandomly(int gridWidth, int gridHeight) {
        int direction = rand() % 4; // 0=up,1=down,2=left,3=right

        if (direction == 0 && pos.y > 0)
            pos.y--;
        else if (direction == 1 && pos.y < gridHeight - 1)
            pos.y++;
        else if (direction == 2 && pos.x > 0)
            pos.x--;
        else if (direction == 3 && pos.x < gridWidth - 1)
            pos.x++;
    }

    bool detectPlayer(const Player& player) const {
        Position p = player.getPosition();

        // Same row
        if (pos.y == p.y)
            return true;

        // Same column
        if (pos.x == p.x)
            return true;

        // Adjacent cell
        if (abs(pos.x - p.x) <= 1 && abs(pos.y - p.y) <= 1)
            return true;

        return false;
    }

    Position getPosition() const {
        return pos;
    }

    friend class Grid;
};

class Grid {
private:
    int width;
    int height;

public:
    Grid(int w, int h) {
        width = w;
        height = h;
    }

    void placePlayer(Player& player) {
        player.pos.x = rand() % width;
        player.pos.y = rand() % height;
    }

    void placeEnemies(vector<Enemy>& enemies) {
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].pos.x = rand() % width;
            enemies[i].pos.y = rand() % height;
        }
    }

    void display(const Player& player, const vector<Enemy>& enemies) const {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {

                bool printed = false;

                Position p = player.getPosition();
                if (p.x == x && p.y == y) {
                    cout << "P ";
                    printed = true;
                }

                for (int i = 0; i < enemies.size(); i++) {
                    Position e = enemies[i].getPosition();
                    if (e.x == x && e.y == y) {
                        cout << "E ";
                        printed = true;
                    }
                }

                if (!printed)
                    cout << ". ";
            }
            cout << endl;
        }
    }
};

int main() {

    srand(time(0));

    const int WIDTH = 6;
    const int HEIGHT = 6;
    const int MAX_STEPS = 15;

    Grid grid(WIDTH, HEIGHT);
    Player player;
    vector<Enemy> enemies(3); 

    grid.placePlayer(player);
    grid.placeEnemies(enemies);

    cout << "Initial Positions:\n";
    player.displayPosition();
    grid.display(player, enemies);
    cout << "---------------------------\n";

    bool detected = false;

    for (int step = 1; step <= MAX_STEPS; step++) {

        cout << "Step " << step << ":\n";

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].moveRandomly(WIDTH, HEIGHT);

            if (enemies[i].detectPlayer(player)) {
                cout << "ALERT! Enemy " << i + 1 << " detected the player!\n";
                detected = true;
            }
        }

        grid.display(player, enemies);
        cout << "---------------------------\n";

        if (detected)
            break;
    }

    if (!detected)
        cout << "Simulation ended. Player survived.\n";

    return 0;
}
