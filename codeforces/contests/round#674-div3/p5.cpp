#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int findMin(int n, int aR, int aS, int aP, int bR, int bS, int bP) {
    return (aR>bP+bR ? aR-(bP+bR) : 0) + (aS>bR+bS ? aS-(bR+bS) : 0) + (aP>bP+bS ? aP-(bP+bS) : 0);
}

int findMax(int n, int aR, int aS, int aP, int bR, int bS, int bP) {
    return min(aR, bS) + min(aS, bP) + min(aP, bR);
}

int main() {
    int n, aR, aS, aP, bR, bS, bP;
    cin>>n>>aR>>aS>>aP>>bR>>bS>>bP;     
    cout<<findMin(n,aR,aS,aP,bR,bS,bP)<<" "<<findMax(n,aR,aS,aP,bR,bS,bP)<<endl;
    return 0;
}