#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 105;
int move(vector<int>&v, ll n, ll &r){
    int j = n-1;
    while(j >= 0 && v[j] != 1) 
        j--;
    swap(v[j], v[j+1]);
    r--;
    return r;
}
int main() {
    ll C[N][N], Sum[N][N];
    ll n, r;
    cin >> n >> r;
    vector<string> s(n);
    for(auto &i : s) cin >> i;
    for(int i = 0; i < N; i++){
        C[i][0] = C[i][i] = 1;
        Sum[i][0] = 1;
    }
    
    for(int i = 1; i < N; i++){
        for(int j = 1; j < i; j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
            Sum[i][j] += Sum[i][j-1] + C[i][j];
        }
        Sum[i][i] = Sum[i][i-1] + C[i][i];  
    }
    
    int i = 0;
    while(i <= n && Sum[n][i] < r) i++;
    i--;
    r -= Sum[n][i];
    int k = i+1;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        if(i < k) v[i] = 1;
        else v[i] = 0;
        // cout << v[i] << " ";
    }
    r--;
    while(r != 0 && move(v,n,r) != 0);
    for(int i = 0; i < n; i++){
        if(v[i]) cout << s[i] << " ";
    }
    return 0;
}