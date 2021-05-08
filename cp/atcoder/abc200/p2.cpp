#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    while (k > 0)
    {
        if (n % 200 == 0)
            n /= 200;
        else
            n = n * 1000 + 200;
        k--;
    }
    cout << n << "\n";
    return 0;
}