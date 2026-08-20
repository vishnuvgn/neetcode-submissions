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
        unordered_map<char, int> s_counts;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            char right_c = s[right];
            auto it = t_counts.find(right_c);
            if (it != t_counts.end()) {
                ++s_counts[right_c];
            }

            while (is_subset(s_counts, t_counts)) {
                int len = right - left + 1;
                if (len < best_length) {
                    best_length = len;
                    best_left = left;
                    best_right = right;
                }
                char left_c = s[left];
                --s_counts[left_c];
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

    bool is_subset(unordered_map<char, int>& s_counts, unordered_map<char, int>& t_counts) {
        for (auto [chr, count] : t_counts) {
            if (s_counts[chr] < t_counts[chr]) return false;
        }
        return true;
    }


};
