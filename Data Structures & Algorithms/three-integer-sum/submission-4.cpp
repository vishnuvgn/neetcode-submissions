class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    int old_left = nums[left];
                    int old_right = nums[right];

                    while (left < right && old_left == nums[left]) ++left;
                    while (left < right && old_right == nums[right]) --right;

                }
                else if (nums[left] + nums[right] < target) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
        return result;
    }
};