class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int best_profit = 0;
        for (int right = 0; right < static_cast<int>(prices.size()); ++right) {
            if (right == left) continue;
            if (prices[right] > prices[left]) {
                best_profit = std::max(best_profit, prices[right] - prices[left]);
            }
            else {
                left = right;
            }

        }
        return best_profit;
    }
};
