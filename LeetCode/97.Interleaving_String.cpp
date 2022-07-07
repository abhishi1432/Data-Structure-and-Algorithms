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
template <class T> void input_vec(vector<T> &v , int n){for(int i=0;i<n;i++){T temp;cin>>temp;v.pb(temp);}}   
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
bool Naive_isInterleave_Helper(string &s1,string &s2, string &s3,int a,int b,int c){
	/*
		Time complexity is : O(2^(s1 + s2)) where s1 and s2 are sizes of s1 and s2 respectively
		Space compleiyt is : O(s1 + s2) ,it is the size of stack of recursive call
	*/
	if(c == s3.size() && a == s1.size() && b == s2.size())
		return true;
	bool ans = false;
	if(a < s1.size() && s1[a] == s3[c] && c < s3.size()){
		// cout<<a<<" "<<b<<" "<<c<<nline;
		ans |= Naive_isInterleave_Helper(s1, s2, s3, a+1, b, c+1);
	}
	if(b < s2.size() && s2[b] == s3[c] && c < s3.size()){
		// cout<<a<<" "<<b<<" "<<c<<nline;
		ans |= Naive_isInterleave_Helper(s1, s2, s3, a, b+1, c+1);
	}
	return ans;
}
bool Memo_isInterleave_Helper(string &s1,string &s2, string &s3,int a,int b,int c,vector<vector<int>>&memo){
	/*
		Time complexity is : O((s1 * s2)) where s1 and s2 are sizes of s1 and s2 respectively 
			as the memo array is of size s1*s2 so each index (a,b) will be calculated only once
		Space compleiyt is : O(s1 + s2) + O(s1 * s2) ,it is the size of stack of recursive call and memo array
	*/
	if(c == s3.size() && a == s1.size() && b == s2.size())  //when we reached a point when there are no elements left in s1,s2,s3
		return true;
	bool ans = false;
	if(memo[a][b] == 0)
		return false;
	if(memo[a][b] == 1)
		return true;
	if(a < s1.size() && s1[a] == s3[c] && c < s3.size()){
		// cout<<a<<" "<<b<<" "<<c<<nline;
		ans |= Memo_isInterleave_Helper(s1, s2, s3, a+1, b, c+1,memo);
	}
	if(b < s2.size() && s2[b] == s3[c] && c < s3.size()){
		// cout<<a<<" "<<b<<" "<<c<<nline;
		ans |= Memo_isInterleave_Helper(s1, s2, s3, a, b+1, c+1,memo);
	}
	return memo[a][b] = (ans ? 1 : 0);
}

bool isInterleave(string &s1, string &s2, string &s3) {
	if(s1.size() + s2.size() != s3.size())
		return false;
    // return Naive_isInterleave_Helper(s1,s2,s3,0,0,0);

	/* size is taken 1 larger as a and b may reaach the size and indexoutofbound kind 
	 of exception may arrise .so to be on safe side take size 1 greater. */
    vector<vector<int>>memo(s1.size()+1,vector<int>(s2.size()+1,-1));
    return Memo_isInterleave_Helper(s1,s2,s3,0,0,0,memo);
}

void solve() {
	/* Write your code here.*/
	string s1,s2,s3;
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,s3);
	cout<<isInterleave(s1,s2,s3)<<nline;
}

/*==================================================================*/

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