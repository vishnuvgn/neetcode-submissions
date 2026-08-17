class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        std::sort(intervals.begin(), intervals.end());
        for (auto& interval : intervals) {
            if (static_cast<int>(result.size()) == 0) result.push_back(interval);
            else {
                auto& last_interval = result[static_cast<int>(result.size()) - 1];
                if (interval[0] > last_interval[1]) result.push_back(interval);
                else {
                    last_interval[1] = std::max(last_interval[1], interval[1]);
                }
            }
        }
        return result;
    }
};
