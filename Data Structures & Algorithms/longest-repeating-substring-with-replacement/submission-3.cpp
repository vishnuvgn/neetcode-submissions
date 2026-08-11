class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int best_length = 0;
        vector<int> counts(26, 0);
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            ++counts[s[right] - 'A'];
            int best_freq = *(std::max_element(counts.begin(), counts.end()));
            if (right - left + 1 - best_freq > k) {
                --counts[s[left] - 'A'];
                ++left;
            }
            else {
                best_length = std::max(right - left + 1, best_length);
            }
        }
        return best_length;
    }
};