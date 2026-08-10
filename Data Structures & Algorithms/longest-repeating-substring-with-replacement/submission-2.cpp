class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char,int> counts;
        int best_freq = 0;
        int best_length = 0;
        int left = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            ++counts[s[right]];
            best_freq = std::max(best_freq, counts[s[right]]);
            if (right - left + 1 - best_freq > k) {
                --counts[s[left]];
                ++left;
            }
            best_length = std::max(best_length, right - left + 1);
        }
        return best_length;
    }
};