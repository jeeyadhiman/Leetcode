// Last updated: 5/17/2026, 5:51:44 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;
        unordered_map<int, int> mpp;

        mpp[0] = 1; // important! handles subarrays starting from index 0
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum-k)!=mpp.end()){
                count += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return count;
    }
};
