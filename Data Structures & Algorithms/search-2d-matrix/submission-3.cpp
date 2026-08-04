class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_count = static_cast<int>(matrix.size());
        int col_count = static_cast<int>(matrix[0].size());
        int left = 0;
        int right = row_count * col_count - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / col_count;
            int c = mid % col_count;

            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};
