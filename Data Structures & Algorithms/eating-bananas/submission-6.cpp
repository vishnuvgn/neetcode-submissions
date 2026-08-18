class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int best_k = INT_MAX;
        int left_k = 1;
        int right_k = INT_MIN;
        for (auto pile : piles) {
            right_k = std::max(right_k, pile);
        }

        while (left_k <= right_k) {
            int mid_k = left_k + (right_k - left_k) / 2;
            int calc_h = calculate_hours(piles, mid_k);
            if (calc_h > h) left_k = mid_k + 1;
            else {
                best_k = std::min(best_k, mid_k);
                right_k = mid_k - 1;
            }
        }
        return best_k;

    }

    int calculate_hours(vector<int>& piles, int k) {
        int h = 0;
        for (auto pile : piles) {
            h += (pile + k - 1) / k;
        }
        return h;
    }

};
