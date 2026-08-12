class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::less<std::pair<int, int>>
        > frequencies;

        std::unordered_map<int, int> counts;
        for (int i : nums) {
            ++counts[i];
        }

        for (auto [k, v] : counts) {
            frequencies.push({v, k});
        }
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            auto [v,k] = frequencies.top();
            frequencies.pop();
            result.push_back(k);
        }
        return result;

    }
};