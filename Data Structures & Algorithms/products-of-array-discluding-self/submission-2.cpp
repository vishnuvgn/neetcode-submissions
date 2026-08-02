class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 1);
        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            prefix[i] = nums[i-1] * prefix[i-1];
        }
        
        std::vector<int> suffix(nums.size(), 1);
        for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
            suffix[i] = nums[i+1] * suffix[i+1];
        }

        std::vector<int> result;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            result.push_back(prefix[i] * suffix[i]);
        }
        return result;
        
    }
};
