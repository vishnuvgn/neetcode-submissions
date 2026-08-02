class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> values(nums.begin(), nums.end());
        int best_length = 0;
        for (int num : nums) {
            if (values.find(num - 1) == values.end()) { // found min 
                int length = 1;
                int target = num + 1;
                while (values.find(target) != values.end()) {
                    ++length;
                    ++target;
                }
                best_length = std::max(best_length, length);
            }
        }
        return best_length;
    }
};