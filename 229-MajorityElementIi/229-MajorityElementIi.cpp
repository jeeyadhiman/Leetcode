// Last updated: 5/17/2026, 5:52:00 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>n/3 && find(arr.begin(), arr.end(), nums[i]) == arr.end()){
                arr.push_back(nums[i]);
            }
            if(arr.size()==2){
                break;
            }
        }
        
        return arr;
    }
};