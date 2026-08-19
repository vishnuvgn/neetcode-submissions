class Solution {
public:
    int trap(vector<int>& height) {
        if (static_cast<int>(height.size()) < 3) return 0;
        vector<int> maxLeft(static_cast<int>(height.size()), 0);
        vector<int> maxRight(static_cast<int>(height.size()), 0);
        for (int i = 1; i < static_cast<int>(height.size()); ++i) {
            maxLeft[i] = std::max(maxLeft[i-1], height[i-1]);
        }
        for (int i = static_cast<int>(height.size() - 2); i > -1; --i) {
            maxRight[i] = std::max(maxRight[i+1], height[i+1]);
        }
        int total = 0;
        for (int i = 0; i < static_cast<int>(height.size()); ++i) {
            int val = std::min(maxLeft[i], maxRight[i]) - height[i];
            if (val > 0) total += val;
        }
        return total;
    }
};