// Last updated: 5/17/2026, 5:51:31 PM
class Solution {
public:
    int findmax(vector<int> bloomDay,int n){
        int max1=bloomDay[0];
        for(int i=1;i<n;i++){
            max1=max(max1,bloomDay[i]);
        }
        return max1;
    }
    int findmin(vector<int> bloomDay,int n){
        int min1=bloomDay[0];
        for(int i=1;i<n;i++){
            min1=min(min1,bloomDay[i]);
        }
        return min1;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=findmin(bloomDay,n);
        int high=findmax(bloomDay,n);
        int mid,count=0,ans=-1,cnt=0;
        while(low<=high){
            cnt=0;
            count=0;
            mid=(low+high)/2;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid)
                count++;
                else{
                    cnt=cnt+(count/k);
                    count=0;
                }
            }
              cnt=cnt+(count/k); 
            if(cnt>=m){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};