class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (auto task : tasks) {
            ++counts[task];
        }
        
        priority_queue<pair<int,char>, vector<pair<int,char>>, less<pair<int,char>>> max_heap;
        for (auto [letter, count] : counts) { // k log k where k is the number of distinct tasks
            max_heap.push({count, letter});
        }
        int first_free = 0;
        vector<char> task_list(1,' ');

        while (!max_heap.empty()) {
            auto [count, task] = max_heap.top();
            max_heap.pop();
            for (int i = 0; i < count; ++i) {
                int idx = first_free + i * (n + 1);
                while (idx >= static_cast<int>(task_list.size())) {
                    task_list.push_back(' ');
                }
                task_list[idx] = task;
            }
            first_free = find_first_free(first_free, task_list);
        }
        return static_cast<int>(task_list.size());

    }

    int find_first_free(int prev, vector<char>& task_list) {
        for (int i = prev + 1; i < static_cast<int>(task_list.size()); ++i) {
            if (task_list[i] == ' ') return i;
        }
        return static_cast<int>(task_list.size());
    }

};
