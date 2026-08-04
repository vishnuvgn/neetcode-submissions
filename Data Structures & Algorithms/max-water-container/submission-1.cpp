class Solution {
public:
    int maxArea(vector<int>& heights) {
        int best_area = INT_MIN;
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;
        while (left < right) {
            int area = (right - left) * std::min(heights[left], heights[right]);
            best_area = std::max(best_area, area);
            if (heights[left] < heights[right]) ++left;
            else --right;
        }
        return best_area;
    }
};
