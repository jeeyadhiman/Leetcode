// Last updated: 5/17/2026, 5:52:04 PM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
    if (n == 0) return; // edge case: empty array
    k = k % n;  
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin()+k, nums.end());
    }
};