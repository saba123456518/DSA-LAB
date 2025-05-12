#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 100;

char maze[MAX][MAX];
bool visited[MAX][MAX];
int parentX[MAX][MAX], parentY[MAX][MAX];
int queueX[MAX * MAX], queueY[MAX * MAX]; 
int rows, cols;

int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1}; 

void reset() {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            visited[i][j] = false;
            parentX[i][j] = parentY[i][j] = -1;
        }
}

bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && 
           (maze[x][y] == '.' || maze[x][y] == 'E') && !visited[x][y];
}

void inputMaze() {
    cout << "Enter maze (" << rows << "x" << cols << ") [#: Wall, .: Path, S: Start, E: End]:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> maze[i][j];
}

void printMaze() {
    cout << "\nMaze:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << maze[i][j] << ' ';
        cout << '\n';
    }
}

void findStartEnd(int &sx, int &sy, int &ex, int &ey) {
    sx = sy = ex = ey = -1;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] == 'S') { sx = i; sy = j; }
            if (maze[i][j] == 'E') { ex = i; ey = j; }
        }
    if (sx == -1 || ex == -1) {
        cout << "Start (S) or End (E) is missing in the maze.\n";
        exit(1);
    }
}

void markPath(int ex, int ey, int sx, int sy) {
    int x = ex, y = ey;
    while (!(x == sx && y == sy)) {
        if (maze[x][y] != 'E') maze[x][y] = '*';
        int px = parentX[x][y];
        int py = parentY[x][y];
        x = px;
        y = py;
    }
}

void solveBFS(int sx, int sy, int ex, int ey) {
    reset();
    int front = 0, rear = 0;
    queueX[rear] = sx;
    queueY[rear] = sy;
    rear++;
    visited[sx][sy] = true;

    bool found = false;

    while (front < rear) {
        int x = queueX[front];
        int y = queueY[front];
        front++;

        if (x == ex && y == ey) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                parentX[nx][ny] = x;
                parentY[nx][ny] = y;
                queueX[rear] = nx;
                queueY[rear] = ny;
                rear++;
            }
        }
    }

    if (found) {
        cout << "\nMaze solved using BFS!\n";
        markPath(ex, ey, sx, sy);
    } else {
        cout << "\nNo path found using BFS.\n";
    }
}

bool dfs(int x, int y, int ex, int ey) {
    if (!isValid(x, y)) return false;
    visited[x][y] = true;
    if (x == ex && y == ey) return true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) {
            parentX[nx][ny] = x;
            parentY[nx][ny] = y;
            if (dfs(nx, ny, ex, ey)) return true;
        }
    }
    return false;
}

void solveDFS(int sx, int sy, int ex, int ey) {
    reset();
    if (dfs(sx, sy, ex, ey)) {
        cout << "\nMaze solved using DFS!\n";
        markPath(ex, ey, sx, sy);
    } else {
        cout << "\nNo path found using DFS.\n";
    }
}

int main() {
    cout << "Enter maze dimensions (rows cols): ";
    cin >> rows >> cols;

    inputMaze();

    int sx, sy, ex, ey;
    findStartEnd(sx, sy, ex, ey);

    int choice;
    cout << "\nChoose solving method:\n1. DFS\n2. BFS\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        solveDFS(sx, sy, ex, ey);
    else
        solveBFS(sx, sy, ex, ey);

    printMaze();
    return 0;
}
