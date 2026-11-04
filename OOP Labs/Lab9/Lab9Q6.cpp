#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int CELL_SIZE = 10;

const int COLS = SCREEN_WIDTH / CELL_SIZE;
const int ROWS = SCREEN_HEIGHT / CELL_SIZE;

class Grid {
private:
    vector<vector<bool>> current;
    vector<vector<bool>> next;

public:
    Grid() {
        current.resize(ROWS);
        next.resize(ROWS);
        for (int y = 0; y < ROWS; y++) {
            current[y].resize(COLS, false);
            next[y].resize(COLS, false);
        }
    }

    void clear() {
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                current[y][x] = false;
            }
        }
    }

    void randomize() {
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                current[y][x] = rand() % 2;
            }
        }
    }

    void toggleCell(int x, int y) {
        current[y][x] = !current[y][x];
    }

    // Count alive neighbors (toroidal)
    int countNeighbors(int x, int y) {
        int count = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;

                int nx = (x + dx + COLS) % COLS;
                int ny = (y + dy + ROWS) % ROWS;

                if (current[ny][nx]) count++;
            }
        }
        return count;
    }

    // Update grid using double buffering
    void update() {
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                int neighbors = countNeighbors(x, y);

                if (current[y][x]) {
                    // Alive
                    if (neighbors < 2 || neighbors > 3)
                        next[y][x] = false; // Dies
                    else
                        next[y][x] = true;  // Lives
                } else {
                    // Dead
                    if (neighbors == 3)
                        next[y][x] = true; // Becomes alive
                    else
                        next[y][x] = false;
                }
            }
        }

        // Swap buffers
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                current[y][x] = next[y][x];
            }
        }
    }

    void draw() {
        for (int y = 0; y < ROWS; y++) {
            for (int x = 0; x < COLS; x++) {
                if (current[y][x])
                    DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, GREEN);
            }
        }
    }
};

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of Life");
    SetTargetFPS(60);

    srand(time(0));

    Grid grid;

    bool paused = true;
    float timer = 0;
    float updateInterval = 0.15f; // 150ms per generation

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_SPACE)) paused = !paused;
        if (IsKeyPressed(KEY_R)) grid.randomize();
        if (IsKeyPressed(KEY_C)) grid.clear();

        // Toggle cell with mouse (only when paused)
        if (paused && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            int x = mouse.x / CELL_SIZE;
            int y = mouse.y / CELL_SIZE;

            if (x >= 0 && x < COLS && y >= 0 && y < ROWS)
                grid.toggleCell(x, y);
        }

        if (!paused) {
            timer += GetFrameTime();
            if (timer >= updateInterval) {
                grid.update();
                timer = 0;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        grid.draw();

        DrawText(paused ? "PAUSED" : "RUNNING", 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}