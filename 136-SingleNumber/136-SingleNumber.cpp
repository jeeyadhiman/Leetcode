// Last updated: 5/17/2026, 5:52:12 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for ( int val : nums){
            sum=sum^val;
        }
        return sum;
    }
};