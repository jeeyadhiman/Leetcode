// Last updated: 5/17/2026, 5:51:34 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(),low=0, high=n-1;
        int mid,missing;
        while(low<=high){
            mid=(low+high)/2;
            missing=arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }
        return low+k;
    }
};