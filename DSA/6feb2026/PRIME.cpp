#include <bits/stdc++.h>
using namespace std;



int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int>prime(n+1,true);
	prime[0] = prime[1] = false;
	for(int i =2;i<=n;i++){
	    if(prime[i]){
	        for(int j = 2 * i;j<=n;j+=i){
	            prime[j] = false;
	        }
	    }
	}
	for(int i = 2;i<=n;i++){
		if(prime[i]) cout<<i<<" ";
	}
	return 0;
}
	

