class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> max_heap;
        for (int i = 0; i < static_cast<int>(points.size()); ++i) {
            int x = points[i][0];
            int y = points[i][1];

            double dist = sqrt(pow(x, 2) + pow(y, 2));

            if (static_cast<int>(max_heap.size()) < k) {
                max_heap.push({dist, i});
            }
            else {
                if (max_heap.top().first > dist) {
                    max_heap.pop();
                    max_heap.push({dist, i});
                }
            }
        }
        vector<vector<int>> result;
        result.reserve(k);

        while (!max_heap.empty()) {
            auto [dist, i] = max_heap.top();
            result.push_back(points[i]);
            max_heap.pop();
        }
        return result;
    }
};