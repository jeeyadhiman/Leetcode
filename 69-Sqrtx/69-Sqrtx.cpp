// Last updated: 5/17/2026, 5:52:34 PM
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int low = 1, high = x, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

             long long sq = 1LL * mid * mid;

            if (sq == x) {
                return mid;   // exact square root
            }
            else if (sq < x) {
                ans = mid;    // mid is a possible answer
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
