class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        
        unordered_map<char, int> t_counts;
        for (char c : t) ++t_counts[c];

        int left = 0;
        int best_length = INT_MAX;
        int best_left = 0;
        int best_right = 0;

        int satisfied = 0;
        int requirements = static_cast<int>(t_counts.size());

        unordered_map<char, int> s_counts;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            char right_c = s[right];
            if (t_counts.find(right_c) != t_counts.end()) {
                ++s_counts[right_c];
                if (s_counts[right_c] == t_counts[right_c]) ++satisfied;

            }

            while (satisfied == requirements) {
                int len = right - left + 1;
                if (len < best_length) {
                    best_length = len;
                    best_left = left;
                    best_right = right;
                }
                char left_c = s[left];
                if (t_counts.find(left_c) != t_counts.end()) {
                    if (s_counts[left_c] == t_counts[left_c]) {
                        --satisfied;
                    }
                    --s_counts[left_c];
                }
                ++left;
            }
        }
        if (best_length == INT_MAX) return "";
        string result;
        for (int i = best_left; i < best_right + 1; ++i) {
            result += s[i];
        }
        return result;
    }
};
