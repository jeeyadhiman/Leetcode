// Last updated: 5/17/2026, 5:52:50 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int sum;
        unordered_map<int,int> hmap;
        for(int i=0;i<nums.size();i++){
            sum=target-nums[i];
            if(hmap.find(sum) != hmap.end()){
                result.push_back(hmap[sum]);
                result.push_back(i);
                break;
            }
            hmap[nums[i]] = i;
        }
        return result;
    }
};