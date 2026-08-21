class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> frequencies;
        for (char c : s) ++frequencies[c];

        priority_queue<pair<int, char>> max_heap;
        for (auto [k,v] : frequencies) {
            max_heap.push({v, k});
        }

        auto [v,k] = max_heap.top();
        if (v > (static_cast<int>(s.size()) + 1) / 2) return "";

        int index = 0;
        string result(static_cast<int>(s.size()), ' ');
        while (!max_heap.empty()) {
            auto [freq, letter] = max_heap.top();
            max_heap.pop();

            for (int i = 0; i < freq; ++i) {
                result[index] = letter;
                index += 2;
                if (index >= static_cast<int>(s.size())) index = 1;
            }
        }
        return result;

    }
};