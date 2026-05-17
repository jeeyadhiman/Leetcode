// Last updated: 5/17/2026, 5:52:14 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ln=1;
        if (n == 0) return 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int it: st){
            if(st.find(it-1)== st.end()){
                int count=1;
                while(st.find(it+1)!=st.end()){
                    count++;
                    ln=max(ln,count);
                    it++;
                }
            }
        }
       return ln;
    }
};