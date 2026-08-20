class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int left = 0;
        int best_length = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            int length = right - left + 1;
            ++counts[s[right]];
            int most_freq = 0;
            for (auto [chr, count] : counts) {
                most_freq = max(most_freq, count);
            }

            while (length - most_freq > k) {
                --counts[s[left]];
                most_freq = 0;
                for (auto [chr, count] : counts) {
                    most_freq = max(most_freq, count);
                }
                ++left;
                length = right - left + 1;
            }
            best_length = max(best_length, length);
        }
        return best_length;
    }
};