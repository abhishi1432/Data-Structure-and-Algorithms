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
// bool cmp(const pair<int,int> &a,const pair<int,int>&b){if(a.second == b.second){return a.first < b.first;}return a.second < b.second;}
/*=================================================================*/

class BSTNode{
	public:
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode(){
		data=INT_MIN;
		left=NULL;
		right=NULL;
	}
};

BSTNode* createBSTNode(int key){
	BSTNode* newNode=new BSTNode();
	newNode->data=key;   //(*newNode).data=key;  this also works 
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

void insertBST(BSTNode** root,int key){
	if(*root==NULL){
		*root=createBSTNode(key);
		return;
	}
	if(key<= (*root)->data)
		insertBST(&(*root)->left,key);
	else
		insertBST(&(*root)->right,key);
}

bool searchBST(BSTNode* root,int key){
	if(root==NULL)
		return false;
	if(root->data==key)
		return true;
	else if(key<= root->data)
		searchBST(root->left,key);
	else
		searchBST(root->right,key);
}
BSTNode* Findmin(BSTNode* root){
	if(root->left==NULL)
		return root;
	Findmin(root->left);
} 
void deleteNode(BSTNode** root,int key){
	if(root ==NULL)
		return;
	if(key < (*root)->data)
		deleteNode(&(*root)->left,key);
	else if(key > (*root)->data)
		deleteNode(&(*root)->right,key);
	else{
		if((*root)->left==NULL && (*root)->right==NULL)  //case1 if it is a leaf node
		{
			(*root)==NULL;
			delete(*root);
		}
		else if((*root)->left == NULL){   //if only right child is present
			BSTNode* temp=(*root)->right;
			(*root)=(*root)->right;
			delete(temp);
		}
		else if((*root)->right == NULL){   //if only left child is present
			BSTNode* temp=(*root)->left;
			(*root)=(*root)->left;
			delete(temp);
		}
		else{      //if it has two childrens
			BSTNode* temp=Findmin((*root)->right);
			(*root)->data=temp->data;
			deleteNode(&(*root)->right,temp->data);
		}
	}
}
void solve() {
	BSTNode* root_check=NULL;
	root_check=createBSTNode(3);
	cout<<root_check->data<<nline;

	BSTNode* root=NULL;
	insertBST(&root,5);
	insertBST(&root,11);
	insertBST(&root,9);
	insertBST(&root,13);
	insertBST(&root,15);
	insertBST(&root,18);
	insertBST(&root,1);
	insertBST(&root,25);
	insertBST(&root,2);
	insertBST(&root,4);
	insertBST(&root,3);
	insertBST(&root,14);

	/*
							 5
						/        \
					   1	   	  11
						 \	    / 	 \
						  2	   9      13
						   \	  		\
							4 			 15
						  /	  			/    \
						 3	  		   14     18
												\
												 25	
	*/
	cout<<root->data<<nline;
	cout<<root->left->data<<nline;
	cout<<root->right->right->right->left->data<<nline;

	cout<<(searchBST(root,1)? "FOUND" : "NOT FOUND")<<nline;
	cout<<(searchBST(root,18)? "FOUND" : "NOT FOUND")<<nline;
	cout<<(searchBST(root,22)? "FOUND" : "NOT FOUND")<<nline;

	//2nd BST tree
	BSTNode* root2=NULL;
	insertBST(&root2,12);
	insertBST(&root2,5);
	insertBST(&root2,15);
	insertBST(&root2,3);
	insertBST(&root2,7);
	insertBST(&root2,13);
	insertBST(&root2,17);
	insertBST(&root2,1);
	insertBST(&root2,9);
	insertBST(&root2,19);

	/*
							12
						/        \
					   5	   	  15
					 /	 \	    / 	 \
					3	  7	   13      17
				  /		   \	  		\
				 1			9			 19 		      
	*/
	cout<<root2->right->left->data<<nline;

	//deleting task
	cout<<root2->left->right->data<<nline;
	deleteNode(&root2,7);
	cout<<root2->left->right->data<<nline;	

	cout<<root2->right->data<<nline;
	deleteNode(&root2,15);
	cout<<root2->right->data<<nline;

	

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