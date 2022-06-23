/*
	A B H I S H E K    S I N G H
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
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define all_rev(x) (x).rbegin(), (x).rend()

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

/*==============================================================*/
/*    Newly added templates */

template <class T> void print_vec(vector<T> v);  //printing any vector
template <class T> void print_set(set<T> s);  //printing set of any datatype
template <class T> void input_vec(vector<T> &v , int n);  //taking input of n elements of any data type into a vector
template <class T, class V, class X>V binarySearch(vector<T> a, V n, X item);  //binary search on vector
template <class T> void print_vec(vector<T> v){ for(T i:v){ cout<<i<<" ";}cout<<nline;} 
template <class T> void print_set(set<T> s){for(T i:s){cout<<i<<" ";}cout<<nline;}  
template <class T> void input_vec(vector<T> &v , int n){for(int i=0;i<n;i++){int temp;cin>>temp;v.pb(temp);}}   
template <class T, class V, class X>V binarySearch(vector<T> a, V n, X item){  V low = 0; V high = n - 1; while(low<=high){{V mid = (low + high)/2; if (a[mid] == item) return mid; else if (a[mid] < item) low = mid + 1; else high = mid - 1;}} return -1;}

/*===============================================================*/

/*  Special puropose functions */

// ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
// ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
// bool revsort(ll a, ll b) {return a > b;}
// void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
// ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
// void google(int t) {cout << "Case #" << t << ": ";}
// vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
// ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
// ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
// ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
// ll lcm(int a, int b){return (a / gcd(a, b)) * b;}

/*=================================================================*/
int search_linear(string str,int low,int high,char ch){
	for(int i=low;i<high;i++){
		if(ch==str[i])
			return i;
	}
	return -1;
}
int longestCommonSubsequence(string text1, string text2) {
	int l1=text1.size();
	int l2=text2.size();
	int ans=0;
	string res="";
	for(int i=0;i<l1;i++){
		int index=-1;
		int localAns=0;
		res="";
		for(int j=i;j<l1;j++){
			int temp = search_linear(text2,index+1,l2,text1[j]);
			if(temp!=-1){
				localAns+=1;
				res=res+text1[j];
				index = temp;
				ans = max(localAns,ans);
			}
			// cout<<temp<<" "<<index<<" "<<text1[j]<<" "<<ans<<" "<<res<<nline;
		}
	}
	return ans;
}

int longestCommonSubsequence_UsingRecursion(string &text1,string &text2,int ind1,int ind2,vector<vector<int>>&memo){
	if(ind1==text1.size() || ind2==text2.size()){
		return 0;
	}
	if(memo[ind1][ind2]!=-1)
		return memo[ind1][ind2];
	else if(text1[ind1]==text2[ind2]){
		int temp=longestCommonSubsequence_UsingRecursion(text1,text2,ind1+1,ind2+1,memo);
		memo[ind1+1][ind2+1]=temp;
		return 1 + temp;
	}
	else
		return max(longestCommonSubsequence_UsingRecursion(text1,text2,ind1,ind2+1,memo),longestCommonSubsequence_UsingRecursion(text1,text2,ind1+1,ind2,memo));
}


int longestCommonSubsequence_UsingDP(string text1,string text2, vector<vector<long long>>&dp){
	int n=text1.size(),m=text2.size();
	// cout<<n<<" "<<m<<nline;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(text1[i]==text2[j]){
				if(i==0 || j==0)
					dp[i][j]=1;
				else
					dp[i][j] = 1LL + dp[i-1][j-1];
			}
			else{
				if(i==0 && j!=0)
					dp[i][j]=dp[i][j-1];
				else if(j==0 && i!=0)
					dp[i][j] = dp[i-1][j];
				else if(i==0 && j==0)
					dp[i][j] = 0;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n-1][m-1];
}

int call_all_functions_here(string text1,string text2){
	
	/*
		Time complexity of this function is O(n1*n2*n3) ~ O(n^3)
		Not working for all of the test cases.
	*/
	return longestCommonSubsequence(text1,text2);
		
	/*
		Recursion--> O(2*n)
		Recursion + Memoization
		Time complexity of this is O(n1*n2) i.e size of the memoization table
	*/
	vector<vector<int>> memo(text1.size()+1,vector<int>(text2.size()+1,-1));
	return longestCommonSubsequence_UsingRecursion(text1,text2,0,0,memo);

	/*
		Time complexiyt of this solution is O(n1*n2)
	*/
	vector<vector<long long>> dp(text1.size(),vector<long long>(text2.size(),0));
	return longestCommonSubsequence_UsingDP(text1,text2,dp);

}
void solve() {
	string text1,text2;
	getline(cin,text1);
	getline(cin,text2);
	cout<<call_all_functions_here(text1,text2)<<nline;

}


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