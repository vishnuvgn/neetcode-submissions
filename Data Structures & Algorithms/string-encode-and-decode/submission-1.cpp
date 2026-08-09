class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (const string& s : strs) {
            result += to_string(s.size());
            result += '#';
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string_view view(s);
        int idx = 0;
        while (idx < s.size()) {
            int end = idx;
            while (s[end] != '#') {
                ++end;
            }
            int len = stoi(s.substr(idx, end - idx));
            result.push_back(s.substr(end+1, len));
            idx = end + len + 1;
        }
        return result;
    }
};


