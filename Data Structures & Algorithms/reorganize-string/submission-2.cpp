class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> counts;
        for (char c: s) ++counts[c];
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int,char>>> max_heap;

        for (auto [ch, co] : counts) max_heap.push({co, ch});

        auto [co, ch] = max_heap.top();
        if (co > (static_cast<int>(s.size()) + 1) / 2) return "";
        int index = 0;
        string result(static_cast<int>(s.size()), ' ');
        while (!max_heap.empty()) {
            auto [co, ch] = max_heap.top();
            max_heap.pop();
            for (int i = 0; i < co; ++i) {
                result[index] = ch;
                index += 2;
                if (index >= static_cast<int>(s.size())) index = 1;
            }
            
        }
        return result;

    }
};