class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            vector<int> counts(26,0);
            for (char c : s) {
                ++counts[c - 'a'];
            }
            string result = "";
            for (int i = 0; i < 26; ++i) {
                result += counts[i];
                result += ',';
            }
            groups[result].push_back(s);
        }
        vector<vector<string>> answer;
        for (auto [k, v] : groups) {
            answer.push_back(v);
        }
        return answer;
    }
};
