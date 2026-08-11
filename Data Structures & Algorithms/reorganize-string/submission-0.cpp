class Solution {
public:
    string reorganizeString(string s) {
        std::priority_queue<
            std::pair<int,char>,
            std::vector<std::pair<int,char>>,
            std::less<std::pair<int,char>>
        > frequencies;
        std::string result(s.size(), ' ');
        std::vector<int> counts(26,0);
        
        for (char c : s) {
            ++counts[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (counts[i] != 0) frequencies.push(std::pair{counts[i], static_cast<char>('a' + i)});
        }

        int max_freq = frequencies.top().first;
        if (max_freq > (static_cast<int>(s.size()) + 1) / 2) return "";
        int index = 0;
        while (!frequencies.empty()) {
            auto [freq, letter] = frequencies.top();
            frequencies.pop();
            for (int i = 0; i < freq; ++i) {
                result[index] = letter;
                index += 2;

                if (index >= static_cast<int>(s.size())) {
                    index = 1;
                }
            }       
        }
        return result;
    }
};