class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counts;
        for (char c : s) ++counts[c];

        priority_queue<pair<int, char>, vector<pair<int,char>>, less<pair<int, char>>> max_heap;
        for (auto [ch, co] :counts) max_heap.push({co,ch});


        auto [top_freq, top_char] = max_heap.top();
        if (top_freq > (static_cast<int>(s.size()) + 1) / 2) return "";
        string result(static_cast<int>(s.size()), ' ');
        int index = 0;
        while (!max_heap.empty()) {
            auto [freq, chr] = max_heap.top();
            max_heap.pop();

            for (int i = 0; i < freq; ++i) {
                result[index] = chr;
                index += 2;
                if (index >= static_cast<int>(s.size())) index = 1;
            }
        }
        return result;

    }
};