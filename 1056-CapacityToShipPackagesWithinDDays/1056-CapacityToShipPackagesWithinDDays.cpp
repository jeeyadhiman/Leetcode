// Last updated: 5/17/2026, 5:51:35 PM
class Solution {
public:
    int totalf(vector<int> weights,int n){
        int total=0;
        for(int i=0;i<n;i++){
            total=total+weights[i];
        }
        return total;
    }
    int findmax(vector <int> weights,int n){
        int max1=weights[0];
        for(int i=1;i<n;i++){
            max1=max(max1,weights[i]);
        }
        return max1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=findmax(weights,n);
        int high=totalf(weights,n);
        int mid ,ans;
        while(low<=high){
            mid=(low+high)/2;
            int count=1,amt=0;
            for(int i=0;i<n;i++){
                if(amt+weights[i]<=mid){
                    amt=amt+weights[i];
                }
                else{
                  count++; 
                  amt=0; 
                  amt=amt+weights[i];
                }
            }
            if(count<=days){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};