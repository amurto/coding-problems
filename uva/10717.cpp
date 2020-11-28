// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1658
// 10717 - Mint

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    while (cin >> n >> t) {
        if (n==0 && t==0)
            break;
        vector<int> th(n), h(t);
        for (int i=0; i<n; i++)
            cin >> th[i];
        for (int i=0; i<t; t++)
            cin >> h[i];
    }
    return 0;
}