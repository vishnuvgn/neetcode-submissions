class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<int> seen;
        int left = 0;
        int best_length = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                ++left;
            }
            seen.insert(s[right]);
            best_length = std::max(best_length, right - left + 1);
        }
        return best_length;
    }
};
