// Last updated: 5/17/2026, 5:52:05 PM
class Solution {
 public:
    int majorityElement(vector<int>& nums){
        int count=0;
        int ele=nums[0];
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele=nums[i];
                count++;
            }
            else if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};