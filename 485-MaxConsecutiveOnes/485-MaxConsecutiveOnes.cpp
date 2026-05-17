// Last updated: 5/17/2026, 5:51:50 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), max = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                    count++;
                    if (max < count)
                        max = count;
                } 
                else
                    count = 0;
            }
        return max;
        }
    };