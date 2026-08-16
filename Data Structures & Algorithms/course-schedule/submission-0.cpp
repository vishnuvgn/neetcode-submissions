class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, queue<int>> prereq_map;
        for (auto pairing : prerequisites) {
            prereq_map[pairing[0]].push(pairing[1]);
        }

        for (int course = 0; course < numCourses; ++course) {
            unordered_set<int> path;
            if (!dfs(course, path, prereq_map)) return false;
        }
        return true;
    }

    bool dfs(int course, unordered_set<int>& path, unordered_map<int, queue<int>>& prereq_map) {
        auto it = path.find(course);
        if (it != path.end()) {
            return false;
        }

        auto it_2 = prereq_map.find(course);
        if (it_2 == prereq_map.end() || it_2->second.empty()) {
            path.erase(course);
            return true;
        }
        path.insert(course);
        int next_course = prereq_map[course].front();
        prereq_map[course].pop();
        return dfs(next_course, path, prereq_map);
        
    }
};