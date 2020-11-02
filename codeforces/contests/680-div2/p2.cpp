#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        cout << max(a1 + b1, a2 + b2) << "\n";
    }
    return 0;
}