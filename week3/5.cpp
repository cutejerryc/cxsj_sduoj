#include <iostream>
using namespace std;

class Grid {
public:
    int grid_size, target_count, total_count;
    char grid[9][9];
    int used_columns[9] = {0};

    Grid(int size, int target): grid_size(size), target_count(target), total_count(0) {}

    void dfs(int placed_count, int row) {
        if (placed_count > target_count) {
            total_count++;
            return;
        }
        for (int i = row; i <= grid_size - (target_count - placed_count); i++) {
            for (int j = 1; j <= grid_size; j++) {
                if (!used_columns[j] && grid[i][j] == '#') {
                    used_columns[j] = 1;
                    dfs(placed_count + 1, i + 1);
                    used_columns[j] = 0;
                }
            }
        }
    }
};

int main() {
    int grid_size, target_count;
    while (true) {
        cin >> grid_size >> target_count;
        if (grid_size == -1 && target_count == -1) break;
        Grid qi_pan(grid_size, target_count);
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                cin >> qi_pan.grid[i + 1][j + 1];
            }
        }
        qi_pan.dfs(1, 1);
        cout << qi_pan.total_count << endl;
    }
    return 0;
}
