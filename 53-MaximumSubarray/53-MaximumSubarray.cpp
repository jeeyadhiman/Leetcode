// Last updated: 5/17/2026, 5:52:37 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxS=INT_MIN;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            maxS=max(maxS,curr);
            if(curr<0)
            curr=0;
        }
        return maxS;
    }
};