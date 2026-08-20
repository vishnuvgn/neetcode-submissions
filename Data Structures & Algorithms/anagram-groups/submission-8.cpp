class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (string s : strs) {
            vector<int> counts(26, 0);
            for (char c : s) {
                ++counts[c - 'a'];
            }
            string str_counts;
            for (int i = 0; i < 26; ++i) {
                str_counts += to_string(counts[i]);
                str_counts += ',';
            }

            groups[str_counts].push_back(s);
        }

        vector<vector<string>> result;
        for (auto [k, v] : groups) {
            result.push_back(v);
        }
        return result;

    }
};
