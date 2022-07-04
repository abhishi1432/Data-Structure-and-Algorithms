class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n,1),right(n,1);
        for(int i=1;i<n;i++)
            left[i] = (ratings[i] > ratings[i-1]) ? left[i-1]+1 : 1;
        for(int i=n-2;i>=0;i--)
            right[i] = (ratings[i] > ratings[i+1]) ? right[i+1]+1 : 1;
        int ans=0;
        for(int i=0;i<n;i++)
            ans += max(left[i],right[i]);
        return ans;
    }
};