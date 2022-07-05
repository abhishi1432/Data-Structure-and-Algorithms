class Solution {
public:
    int findLongestConseqSubseq_hashing(vector<int>nums,int n){
	map<long long,long long>mp;
	for(int i=0;i<n;i++){
		mp[nums[i]]++;
	}
	int prev_elem =INT_MAX;
	int result=1,ans=1;
	for(auto itr:mp){
		if(prev_elem+1LL==itr.first)
			ans++;
		else
			ans=1;
		prev_elem=itr.first;
		result=max(result,ans);
	}
	return result;
}
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        return findLongestConseqSubseq_hashing(nums,nums.size());
        }
};


class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        sort(nums.begin(),nums.end());
        int prev_elem=nums[0];
        int ans=1;
        int result=1;
        for(int i=1;i<n;i++){ 		
           nums[i]==prev_elem+1 ?ans++:(nums[i]==prev_elem)?ans=ans:ans=1;
            result=max(result,ans);
            prev_elem=nums[i];
        }
        return result;
        }
};