// Last updated: 5/17/2026, 5:52:19 PM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int ans;
        vector<vector<int>> arr;
        for(int row=0;row<numRows;row++){
            vector<int> rowVals;  
            ans=1;
            for(int col=0;col<=row;col++){
                rowVals.push_back(ans);
                ans=ans* (row-col)/(col+1);
            }
            arr.push_back(rowVals);
        }
        return arr;
    }
};