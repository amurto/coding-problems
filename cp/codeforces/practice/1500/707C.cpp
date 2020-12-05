// https://codeforces.com/contest/707/problem/C
// Pythagorean Triples

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool ps(ll v) {
    ll s = floor(sqrt(v));
    return (s*s == v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin >> n;
    cout << ps(n) << "\n";
    return 0;
}
