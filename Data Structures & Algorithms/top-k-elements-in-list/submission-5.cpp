class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            ++counts[num];
        }
        
        std::vector<std::vector<int>> count_table(nums.size() + 1);
        for (auto [num, freq] : counts) {
            count_table[freq].push_back(num);
        }
        std::vector<int> result;
        for (auto it = count_table.rbegin(); it != count_table.rend(); ++it) {
            result.insert(result.end(), (*it).begin(), (*it).end());
            k -= (*it).size();
            if (k == 0) {
                return result;
            }
        }
        return {};
    }
};