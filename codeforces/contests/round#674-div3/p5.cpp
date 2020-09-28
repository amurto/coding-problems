#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
ll findMax(ll n, ll aR, ll aS, ll aP, ll bR, ll bP, ll bS) {
    ll count = min(aR, bS) + min(aP, bR) + min(aS, bP);
    return count;
}

ll findMin(ll n, ll aR, ll aS, ll aP, ll bR, ll bP, ll bS) {
    ll count = max(aR, bS) + max(aP, bR) + max(aS, bP);
    return count;
}

int main() {
        ll n, aR, aS, aP, bR, bS, bP;
        cin>>n>>aR>>aS>>aP>>bR>>bS>>bP;

        
    return 0;
}