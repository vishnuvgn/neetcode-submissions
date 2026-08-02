class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = seen.find(target - nums[i]);
            if (it != seen.end()) {
                return {it->second, i};
            }
            else {
                seen[nums[i]] = i;
            }   
        }
        return {};
    }
};
