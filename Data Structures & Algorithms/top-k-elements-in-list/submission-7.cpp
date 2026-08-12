class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<std::vector<int>> buckets(static_cast<int>(nums.size()) + 1);
        std::unordered_map<int,int> counts;
        for (int num : nums) {
            ++counts[num];
        }

        for (auto [num, freq] : counts) {
            buckets[freq].push_back(num);
        }
        std::vector<int> result;
        for (auto it = buckets.rbegin(); it != buckets.rend(); ++it) {
            std::vector temp = *it;
            for (auto val : temp) {
                result.push_back(val);
                --k;
                if (k == 0) return result;
            }
            
        }
        return {};
    }
};