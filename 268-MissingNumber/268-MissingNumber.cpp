// Last updated: 5/17/2026, 5:51:55 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),add=0;
        int sum=n*(n+1)/2;
        for(int i=0;i<n;i++){
            add=add+nums[i];
        }
        sum=sum-add;
        return sum;
    }
};
