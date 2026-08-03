class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int, int>> st;

        for (int i = 0; i < static_cast<int>(temperatures.size()); ++i) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                auto [temp, index] = st.top();
                st.pop();
                result[index] = i - index;
            }
            st.push({temperatures[i], i});
        }   
        return result;
    }
};
