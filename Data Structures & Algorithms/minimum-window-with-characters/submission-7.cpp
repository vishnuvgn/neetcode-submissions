class Solution {
public:
    string minWindow(string s, string t) {
        int best_length = INT_MAX;
        int best_left = 0;
        unordered_map<char, int> t_counts;
        for (char c : t) {
            ++t_counts[c];
        }

        unordered_map<char, int> s_counts;
        int left = 0;
        int requirements = static_cast<int>(t_counts.size());
        int satisfied = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            if (t_counts.find(s[right]) != t_counts.end()) {
                ++s_counts[s[right]];
                if (s_counts[s[right]] == t_counts[s[right]]) ++satisfied;
            }
            while (satisfied == requirements) {

                if (right - left + 1 < best_length) {
                    best_length = right - left + 1;
                    best_left = left;
                }
                
                if (t_counts.find(s[left]) != t_counts.end()) {
                    if (s_counts[s[left]] == t_counts[s[left]]) {
                        --satisfied;
                    }
                    --s_counts[s[left]];
                }
                
                ++left;
            }
        }
        if (best_length == INT_MAX) return "";
        return s.substr(best_left, best_length);
    }
};
