#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll f = 3 * n * (n + 4) + 2;
    ll s = n * (n + 4) + 2;
    if (n%2 == 0)
        f -= s;
    else 
        f+=s;
    f/=8;
    f++;
    cout << f << "\n";
    return 0;
}