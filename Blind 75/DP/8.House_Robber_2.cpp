/*
	A B H I S H E K    S I N G H
*/

#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define nline "\n"
#define set_bits __builtin_popcountll
#define pb push_back

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


/*============================================================*/
/*    debug() functions */

template <class T> void _print(T t) {cerr << t;}  
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void print_vec(vector<T> v);  //printing any vector
template <class T> void print_set(set<T> s);  //printing set of any datatype
template <class T> void input_vec(vector<T> &v , int n);  //taking input of n elements of any data type into a vector
template <class T, class V, class X>V binarySearch(vector<T> a, V n, X item);  //binary search on vector
template <class T> void print_vec(vector<T> v){ for(T i:v){ cout<<i<<" ";}cout<<nline;} 
template <class T> void print_set(set<T> s){for(T i:s){cout<<i<<" ";}cout<<nline;}  
template <class T> void input_vec(vector<T> &v , int n){for(int i=0;i<n;i++){int temp;cin>>temp;v.pb(temp);}}   
template <class T, class V, class X>V binarySearch(vector<T> a, V n, X item){  V low = 0; V high = n - 1; while(low<=high){{V mid = (low + high)/2; if (a[mid] == item) return mid; else if (a[mid] < item) low = mid + 1; else high = mid - 1;}} return -1;}

/*=================================================================*/
int DP_rob_Helper(vector<int>& nums,int start,int end){
	/*
		Time complexity of this solution is O(n)+O(n).
		Space compleixity is O(n)
		Top-Down approach(Try to follow bottom-up in DP as it is suggested by many)
	*/
	vector<int>dp(end+1,0);
	dp[end-1]=nums[end-1];
	int neg = 0;
	for(int i=end-2;i>=start;i--){
		dp[i] = max(dp[i+2]+nums[i], dp[i+1]);
	}
	return dp[start];

	/*
		To further optimize it for space we can just use two variables to strore dp[i+2] and dp[i+1]
		as only this is used.
	*/

}

int rob(vector<int>& nums) {
	int n=nums.size();
	/*
	This is same as House robber 1 .... in this we first find the max sum leaving the first 
	element and then leaving the last element(as we know 1st and last are adjacent so they cant be together) , then returning the max of it.
	*/
	if(n==1)
		return nums[0];
    return max(DP_rob_Helper(nums,0,n-1),DP_rob_Helper(nums,1,n));
}

void solve() {
	int n;
	cin>>n;
	vector<int> arr;
	input_vec(arr,n);
	cout<<rob(arr)<<nline;	

}


/*==================================================================*/

int main() {
	fastio();
	#ifndef ONLINE_JUDGE
		freopen("error.txt", "w", stderr);
	#endif

	solve();
	return 0;
}