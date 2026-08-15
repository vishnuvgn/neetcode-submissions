class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        int num_rows = static_cast<int>(grid.size());
        int num_cols = static_cast<int>(grid[0].size());
        vector<vector<bool>> visited(
            num_rows,
            vector<bool>(num_cols, false)
            );
        for (int r = 0; r < num_rows; ++r) {
            for (int c = 0; c < num_cols; ++c) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    ++num_islands;
                    bfs(r, c, visited, grid);
                }
            }
        }
        return num_islands;
    }

    void bfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        std::queue<std::pair<int,int>> q;
        visited[r][c] = true;
        q.push({r, c});
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            int dir[4][2] = {
                {1, 0},
                {-1, 0},
                {0, 1},
                {0, -1},
            };

            for (auto [dr, dc] : dir) {
                int new_row = row + dr;
                int new_col = col + dc;
                if (new_row >= 0 && new_row < static_cast<int>(grid.size()) 
                && new_col >= 0 && new_col < static_cast<int>(grid[0].size())) {
                    if (grid[new_row][new_col] == '1' && !visited[new_row][new_col]) {
                        visited[new_row][new_col] = true;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
    }
};
