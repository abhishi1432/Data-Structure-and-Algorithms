#include<bits/stdc++.h>
using namespace std;

void DeeptiCopy(void *dest,void *src,size_t n){
	char *csrc =(char *)src;
	char *cdest=(char *)dest;

	for(int i=0;i<n;i++)
		cdest[i]=csrc[i];
}
int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	int ara[1000050]={0},bra[1000050]={0};
	for(int i=0;i<n;i++){
		ara[i]=s[i]-'A';
	}
	for(int i=30;i>=0;i--){
		if(k & (1<<i)){
			for(int j=0;j<n;j++){
				int out=(j-(1<<i))%n;
				if(out<0){
					out+=n;
				}
				bra[out]=ara[j]^ara[out];
			}
			DeeptiCopy(ara,bra,sizeof(ara));
		}
	}
	for(int i=0;i<n;i++){
		s[i]=ara[i]+'A';
	}
	cout<<s<<endl;

	return 0;
}