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
bool cmp(const pair<int,int> &a,const pair<int,int>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
/*=================================================================*/

class Node{
public:
	int data;
	Node* next;
};

void print_LinkedList(string str,Node *n){ 
	cout<<str<<": ";
	while(n !=NULL){
		cout<< n->data<<" ";
		n=n->next;
	}
	cout<<"\n";
}
void add_NodeAtFront(Node** head,int val){  
 //head is a pointer to the pointer so that we dont have to explicitly return new head value.
	//pointer is passed by ref so it will automatically get updated
	//this is used universally ,other one is which i thought.
	Node* newNode=new Node();                  
	newNode->data=val;
	newNode->next= (*head);
	(*head)=newNode;
}

Node* add_NodeAtFront_M2(Node* head,int val){
	Node* newNode=new Node();
	newNode->data=val;
	newNode->next=head;
	head=newNode;
	return head;
}

void add_NodeafterGivenNode(Node* prev_Node,int val){
	if (prev_Node == NULL){
		cout<<"Not possible to add after this node."<<nline;
		return;
	}
	Node* newNode=new Node();
	newNode->data=val;
	newNode->next=prev_Node->next;
	prev_Node->next=newNode;
}

void add_NodeAtEnd(Node** head,int val){
	Node* newNode=new Node();
	newNode->data=val;
	newNode->next=NULL;

	if(*head==NULL){
		*head=newNode;
		return;
	}
	Node* last=(*head);
	while(last->next!=NULL)
		last=last->next;

	last->next=newNode;
}

void delete_Node(Node** head,int position){
	if (*head == NULL)
		return;

	Node* temp= *head;
	if(position == 0)
	{
		*head= temp->next;
		free(temp);
		return;
	}
	for(int i=0;temp!=NULL && i<position-1;i++){
		temp=temp->next;
	}

	if(temp == NULL || temp->next==NULL)
		return;

	Node* next_node= temp->next->next;
	temp->next=next_node;
}
bool detectLoop(Node* head){
	unordered_set<Node*> s;

	while(head!=NULL){
		if(s.find(head)!=s.end())
			return true;
		s.insert(head);
		head=head->next;
	}
	return false;
}

void solve() {
	Node* head =NULL;
	Node* second=NULL;
	Node* third=NULL;

	head =new Node();
	second=new Node();
	third=new Node();

	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;

	// print_LinkedList("Add Node",head);

	add_NodeAtFront(&head,6);
	// print_LinkedList("Add at front",head);

	head=add_NodeAtFront_M2(head,9);
	// print_LinkedList("Add at front",head);

	add_NodeafterGivenNode(second,10);
	// print_LinkedList("Add after given node",head);


	add_NodeAtEnd(&head,88);
	// print_LinkedList("Add note at the end",head);


	head->next->next->next->next=head;
	cout<<detectLoop(head);
	// delete_Node(&head,2);
	// print_LinkedList("Delete Node",head);


	// delete_Node(&head,0);
	// print_LinkedList("Delete Node",head);

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
