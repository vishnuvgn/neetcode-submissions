class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int num_rows = static_cast<int>(grid.size());
        int num_cols = static_cast<int>(grid[0].size());
        
        int fresh_count = 0;
        int time = 0;

        queue<tuple<int, int, int>> q; // queue of rotten, <timestep, row, col>

        for (int r = 0; r < num_rows; ++r) {
            for (int c = 0; c < num_cols; ++c) {
                if (grid[r][c] == 1) ++fresh_count;
                else if (grid[r][c] == 2) {
                    q.push({0,r,c});
                }
            }
        }

        int dir[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            auto [ts, row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : dir) {
                int new_row = row + dr;
                int new_col = col + dc;

                if (0 <= new_row && new_row < num_rows && 0 <= new_col && new_col < num_cols) {
                    if (grid[new_row][new_col] == 1) { // fresh
                        q.push({ts + 1, new_row, new_col});
                        grid[new_row][new_col] = 2;
                        time = std::max(time, ts + 1);
                        --fresh_count;
                    }
                }   
            }
        }
        if (fresh_count == 0) return time;
        return -1;

    }
};
