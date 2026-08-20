class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> frequencies;
        for (int num : nums) ++frequencies[num];
        vector<vector<int>> buckets(nums.size() + 1, vector<int>());
        for (auto [num, freq] : frequencies) {
            buckets[freq].push_back(num);
        }
        vector<int> result;
        for (int i = static_cast<int>(buckets.size()) - 1; i > -1; --i) {
            for (int val : buckets[i]) {
                result.push_back(val);
                --k;
            }
            if (k == 0) return result;
        }
        return {};

    }
};