/*
	A B H I S H E K    S I N G H
	S.no : 11
*/

#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

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

int naive_rob_Helper(vector<int>& nums,int ind,int n){
	/*
		Time complexity of this solution is O(2^n).
		Space compleixity is O(1)
		Approach : We have used the concept of taking and not taking a element.
		-If you took a element then move to the index+2 as you cant take adjacent elements.
		-If you did not took the element then move 1 index forward.
		-Base Case : If we reach at last element ,it means the previous elementn was not taken so we have to take this last element , so return that element.

	*/
	if(ind==n-1)
		return nums[ind];
	if(ind>=n)
		return 0;
	int take_current = nums[ind] + naive_rob_Helper(nums,ind+2,n);
	int leave_current = 0 + naive_rob_Helper(nums,ind+1,n);
	return max(take_current,leave_current);
}
int memo_rob_Helper(vector<int>& nums,int ind,int n,vector<int>&memo){
	/*
		Time complexity of this solution is O(2^n).
		Space compleixity is O(1)
	*/
	if(ind==n-1)
		return nums[ind];
	if(ind>=n)
		return 0;
	int take_current;
	if(memo[ind+2]!=-1)
		take_current = nums[ind] + memo[ind+2];
	else{
		memo[ind+2] = memo_rob_Helper(nums,ind+2,n,memo); 
		take_current = nums[ind] + memo[ind+2];
	}
	int leave_current;
	if(memo[ind+1]!=-1)
		leave_current = 0 + memo[ind+1];
	else{
		memo[ind+1] = memo_rob_Helper(nums,ind+1,n,memo);
		leave_current = 0 + memo[ind+1];
	}
	return max(take_current,leave_current);
}

int rob(vector<int>& nums) {
	int n=nums.size();
      return naive_rob_Helper(nums,0,n);
      vector<int>memo(n+1,-1);
      return memo_rob_Helper(nums,0,n,memo);
}

void solve() {
	int n;
	cin>>n;
	vector<int> arr;
	input_vec(arr,n);
	cout<<rob(arr)<<nline;	

}

/*=======================================================================*/
int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	auto start1 = high_resolution_clock::now();
	solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
	return 0;
}