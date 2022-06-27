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
class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(){
		data=-1;
		left=NULL;
		right=NULL;
	}
};
Node* createNode(int key){
	Node* temp=new Node();
	temp->data=key;
	return temp;
}
Node* search_LevelOrderTraversal(Node* root,int key){
	if(root==NULL)
		return root;

	queue<Node*> q;
	q.push(root);
	Node* out;
	out=NULL;

	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		if(temp->data==key)
			out=temp;
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	return out;
}

void insert_using_LevelOrderTraversal(Node** root,int key){
	Node* tempNode=createNode(key);   //created a node to be inserted

	//check if tree is empty then insert make the node to be inserted as the root node
	if(*root==NULL){
		*root=tempNode;
		return;
	}


	queue<Node*> q;
	q.push(*root);

	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
       
       //checks for the left node
		if(temp->left==NULL){
			temp->left=tempNode;
			return;
		}
		else{
			q.push(temp->left);
		}

		//checks for the right node
		if(temp->right==NULL){
			temp->right=tempNode;
			return;
		}
		else{
			q.push(temp->right);
		}
	}

}

void setExtremerightNode_to_NULL(Node* root,Node* extremeRight){
	queue<Node*> q;
	q.push(root);
	Node* tmp;
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		if(tmp->left!=NULL){
			if(tmp->left=extremeRight){
				tmp->left=NULL;
				return;
			}
			else{
				q.push(extremeRight->left);
			}
		}
		if(tmp->right!=NULL){
			if(tmp->right=extremeRight){
				tmp->right=NULL;
				return;
			}
			else{
				q.push(extremeRight->right);
			}
		}
	}

}

void deleteNode(Node* root,int key){
	if(root==NULL)
		return;
	queue<Node*> q;
	q.push(root);

	Node* temp,*out;
	//using the while loop we have got the key position in tree and the rightmost and deepest node of the tree.
	//so we will replace the node to be deleted with the deepest node.
	while(!q.empty()){
		temp=q.front();
		q.pop();

		if(temp->data == key)
			out=temp;
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
	if(out!=NULL){
		out->data=temp->data;

	//now we need to delete the deepest node, for that first we need to find the parent of deepest node.
		setExtremerightNode_to_NULL(root,temp);
	}
}

// Traversal
void DFT_Inorder(Node* root){
	if(root==NULL)
		return;
	DFT_Inorder(root->left);
	cout<<root->data<<" ";
	DFT_Inorder(root->right);
}
void DFT_Preorder(Node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	DFT_Preorder(root->left);
	DFT_Preorder(root->right);
}
void DFT_Postorder(Node* root){
	if(root==NULL)
		return;
	DFT_Postorder(root->left);
	DFT_Postorder(root->right);
	cout<<root->data<<" ";
}


/*
	Iterative DFT Reference  : strivers take u forward
	https://youtu.be/lxTGsVXjwvM
*/
void DFT_Inorder_Iterative(Node* root){
	if(root==NULL)
		return;
	stack<Node*> s;
	Node* temp = root;
	while(true){
		if(temp!=NULL){
			s.push(temp);
			temp= temp->left;
		}
		else{
			if(s.empty() == true)
				break;
			temp = s.top();
			s.pop();
			cout<<temp->data<<" ";
			temp= temp->right;
		}
	}
}
void DFT_Preorder_Iterative(Node* root){
	/*
		For this we use stack and then put element in it as first right then left
		As the left will be on top so it will be printed before right(since stack in LIFO).
	*/
	if(root==NULL)
		return;
	stack<Node*> s;
	s.push(root);
	while(!s.empty()){
		Node* temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
		if(temp->right!=NULL)
			s.push(temp->right);
		if(temp->left!=NULL)
			s.push(temp->left);
	}
}
void DFT_Postorder_Iterative(Node* root){
	if(root==NULL)
		return;
	stack<Node*> s1,s2;
	s1.push(root);
	while(!s1.empty()){
		root = s1.top();
		s1.pop();
		s2.push(root);
		if(root->left!=NULL)
			s1.push(root->left);
		if(root->right!=NULL)
			s1.push(root->right);
	}
	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
}
void BFT(Node* root){
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* temp=q.front();
		q.pop();

		cout<<temp->data<<" ";
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}
string BFTrecursive(Node* root,int level){
	if(root==NULL)
		return "-";
	if(level==1) return to_string(root->data);
	else
		return BFTrecursive(root->left,level-1)+" "+BFTrecursive(root->right,level-1);
	return "";
}

void printBFTRecursive(Node* root,int height){
	for(int i=1;i<=height;i++)
		cout<< BFTrecursive(root,i)<<nline;
}

void find_maxElem(Node* root,int* max){
	if(root==NULL)
		return;
	if(*max<root->data)
		*max=root->data;
	find_maxElem(root->left,max);
	find_maxElem(root->right,max);
}






void solve() {
	Node* root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->right->left=createNode(5);
	root->right->right=createNode(6);
	/*
						1
					   / \
					  2   3
					 /   / \
					4    5  6

	*/
	DFT_Inorder_Iterative(root);
	cout<<"\n\n\n";
	DFT_Preorder_Iterative(root);
	cout<<"\n\n\n";
	DFT_Postorder_Iterative(root);
	cout<<"\n\n\n";
	
	cout<<root->data<<nline<<root->left->data<<nline<<root->right->data<<nline;



	//Lever order traversal or breadth first Search in binary tree
	//https://www.youtube.com/watch?v=zuuAPYiMYDA
	Node* node=search_LevelOrderTraversal(root,3);   //gives the deepest occurence of the elemnt in the binary tree





	//Insertign in a tree in such manner that it looks for the missing children of any parent.
	/*
						1
					  /   \
					 2     3
				   /  \   /  \
				  4    X   5    6
		Here we will insert at X as this is help in preserving the formula H<=O(log n)
		Keeping height as much less as possible
	
	*/
	cout<<root->left->right<<nline;
	insert_using_LevelOrderTraversal(&root,41);
	cout<<root->left->right->data<<nline;
	// for(int i=1;i<=6;i++)
	// 	insert_using_LevelOrderTraversal(&root,i);
	// cout<<root->right->left->left->data<<nline;
	/*

						 1
					   /    \
					  2      3
				    /  \     /  \
				   4    41   5    6
				  / \   /\   /\
				 1  2  3 4  5  6
	*/


	//deleting a node from binary tree
	// cout<<root->left->right<<nline;
	// deleteNode(root,41);
	cout<<nline<<"PREORDER: ";
	DFT_Preorder(root);
	cout<<nline<<"INORDER: ";
	DFT_Inorder(root);
	cout<<nline<<"POSTORDER: ";
	DFT_Postorder(root);
	cout<<nline<<"LevelOrder or BFT: ";
	BFT(root);
	cout<<nline;
	cout<<BFTrecursive(root,1)<<nline;
	cout<<BFTrecursive(root,2)<<nline;
	cout<<BFTrecursive(root,3)<<nline;


	printBFTRecursive(root,3);


	int max=root->data;
	find_maxElem(root,&max);
	cout<<"Max = "<<max<<nline;
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