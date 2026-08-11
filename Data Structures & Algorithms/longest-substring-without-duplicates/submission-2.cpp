class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best_length = 0;
        unordered_set<char> seen;
        int left = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                ++left;
            }
            seen.insert(s[right]);
            best_length = std::max(right - left + 1, best_length);
        }
        return best_length;
    }
};
