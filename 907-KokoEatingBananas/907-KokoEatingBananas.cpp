// Last updated: 5/17/2026, 5:51:38 PM
class Solution {
public:
    long long totalh(vector<int> piles,int k,int n){
        long long total=0;
        for(int i=0;i<n;i++){
            total+=ceil((double)piles[i]/(double)k);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,mid;
        int ans;
        int max1=piles[0];
        int n=piles.size();
        for(int i=1;i<n;i++){
            if(piles[i]>max1){
                max1=piles[i];
            }
        }
        int high=max1;
        while(low<=high){
            mid=(low+high)/2;
            long long total=totalh(piles,mid,n);
            if(total<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};