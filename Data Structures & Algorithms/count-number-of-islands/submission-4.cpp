class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < static_cast<int>(grid.size()); ++i) {
            for (int j = 0; j < static_cast<int>(grid[0].size()); ++j) {
                if (grid[i][j] == '1') { 
                    bfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '0';
        int dir[4][2] = {
            {1,0},
            {-1,0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dir) {
                int new_row = r + dr;
                int new_col = c + dc;

                if (0 <= new_row && new_row < static_cast<int>(grid.size()) 
                && 0 <= new_col && new_col < static_cast<int>(grid[0].size())) {
                    if (grid[new_row][new_col] == '1') {
                        grid[new_row][new_col] = '0';
                        q.push({new_row, new_col});
                        
                    }
                }
            }
        }
    }

};
