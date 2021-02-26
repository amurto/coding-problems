#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    ll n;
    cin >> n;
    return n & 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}