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
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
// ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
// void google(int t) {cout << "Case #" << t << ": ";}
// vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
// ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
// ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
// ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
// ll lcm(int a, int b){return (a / gcd(a, b)) * b;}
// bool cmp(const pair<int,int> &a,const pair<int,int>&b){if(a.second == b.second){return a.first < b.first;}return a.second < b.second;}
/*=================================================================*/
class MinHeap{
private:       //by defualt it is private
	int* arr;   //pointer to point the elemtne of the heap
	int capacity;  //capacity of the heap
	int heap_size;   //number of elements in the heap
public:
	MinHeap(int cap);
	int parent(int i);
	int leftChild(int i);
	int rightChild(int i);
	void MinHeapify(int);   //to create heap data structure
	int getMin();  //get root element
	int extractMin();  //get and delete the rooot element
	void decreaseKey(int i,int val);
	void deleteKey(int i);
	void insertKey(int key);
	void linearSearch(int);
	void printArray();
	int height();
};

MinHeap::MinHeap(int cap){
	heap_size=0;
	capacity=cap;
	arr=new int[cap];
}
int MinHeap::parent(int i){
	return (i-1)/2;
}
int MinHeap::leftChild(int i){
	return (2*i + 1);
} 
int MinHeap::rightChild(int i){
	return (2*i +2);
}
int MinHeap::getMin(){
	if(heap_size==0)
		return INT_MIN;
	else
		return arr[0];
}
int MinHeap::extractMin(){
	if(heap_size==0)
		return INT_MIN;
	else if(heap_size==1){
		heap_size--;
		return arr[0];
	}
	else{
		int sol=arr[0];
		arr[0]=arr[--heap_size];
		MinHeapify(0);
		return sol;
	}
}

void MinHeap::insertKey(int key){
	if(heap_size==capacity){
		cout<<"Overflow: Could not insert value to the heap"<<nline;
		return;
	}
	arr[heap_size]=key;
	int i=heap_size;
	heap_size++;

	//Fix the minheap property if it is voilated
	while(i!=0 && arr[parent(i)]> arr[i]){
		swap(arr[i],arr[parent(i)]);
		i=parent(i);
	}
}

void MinHeap::decreaseKey(int i,int val){
	arr[i] = val;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
       swap(arr[i], arr[parent(i)]);
       i = parent(i);
    }
}

void MinHeap::deleteKey(int i){
	if(heap_size==0)
		return;
	else{
		arr[i]=arr[--heap_size];
		MinHeapify(i);
	}
/*
	decreaseKey(i,INT_MIN);   //make the key to be delted as INT_MiN
	extractMin();			//extract the MIN key which will be now present at the root node
*/
}
void MinHeap::MinHeapify(int i){
	
	int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;
    if (l < heap_size && arr[l] < arr[i])
        smallest = l;
    if (r < heap_size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i){
        swap(arr[i], arr[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::linearSearch(int val){

	for(int i=0;i<heap_size;i++){
		if(arr[i]==val){
			cout<<"value found!"<<nline;
			return;
		}
	}
	cout<<"value not found!"<<nline;
}

void MinHeap::printArray(){

	for(int i=0;i<heap_size;i++)
		cout<<arr[i]<<" ";
	cout<<nline;
}

int MinHeap::height(){

	return ceil(log2(heap_size+1))-1;
}

class MaxHeap{
private:	
	int *arr;
	int capacity;
	int size;
public:
	MaxHeap(int cap);
	int getParent(int i);
	int getLeft(int);
	int getRight(int);
	int getMax();
	int extractMax();
	void deleteKey(int);
	void MaxHeapify(int);
	void decreaseKey(int,int);
	int heignt();
	void printArray();
	void insertKey(int);
}
MaxHeap::MaxHeap(int x){
	capacity=x;
	size=0;
}
int MaxHeap::getParent(int i){
	return (i-1)/2;
}
int MaxHeap::getLeft(int i){
	return (2*i +1);
}
int MaxHeap::getRight(int i){
	return (2*i+2);
}
int MaxHeap::getMax(){
	if(size==0)
		return INT_MIN;
	else
		return arr[0];
}
int MaxHeap::extractMax(){
	if(size==0)
		return INT_MIN;
	else if(size==1){
		size--;
		return arr[0];
	}
	else{
		int sol=arr[0];
		arr[0]=arr[--size];
		MaxHeapify(0);
		return sol;
	}
}
void MinHeap::decreaseKey(int i,int val){
	arr[i] = val;
    while (i != 0 && arr[parent(i)] < arr[i])
    {
       swap(arr[i], arr[parent(i)]);
       i = parent(i);
    }
}
int MaxHeap::deleteKey(int i){
	decreaseKey(i,INT_MAX);
	extractMax()
	/*
	if(size==0)
		return;
	else{
		arr[i]=arr[--size];
		MaxHeapify(i);
	}
	*/
}


void solve() {
	int capacity=10;
	MinHeap mh(capacity);
	cout<<"minheap created!"<<nline;

	mh.insertKey(12);
	mh.insertKey(11);
	mh.insertKey(16);
	mh.insertKey(9);
	mh.insertKey(8);
	mh.insertKey(7);
	mh.insertKey(5);
	mh.insertKey(14);
	mh.insertKey(2);
	mh.printArray();
	/*
				    2
				 /    \
			   5        7
			 /  \      /  \				___________________________
			9    11   16   8 		    |2 |5 |7 |9 |11|16|8|14|12|
		  /	 \							|__|__|__|__|__|__|_|__|__|
		 14	 12 						 0  1  3  4  5  6  7  8  9	
	
	*/
	
	mh.deleteKey(2);
	mh.printArray();
	/*
				    2
				 /    \
			   5        8
			 /  \      /  \				_________________________
			9    11   16   12 		    |2 |5 |8 |9 |11|16|12|14|
		  /	 							|__|__|__|__|__|__|__|__|
		 14	 							 0  1  3  4  5  6  7  8  	
	
	*/
	

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