class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> time_map;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = time_map.find(key);
        if (it == time_map.end()) return "";

        auto& values = it->second;
        if (timestamp < values[0].first) return "";

        int best_index = -1;

        int left = 0;
        int right = static_cast<int>(values.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values[mid].first <= timestamp) {
                best_index = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (best_index == -1) return "";
        return values[best_index].second;
    }
};
