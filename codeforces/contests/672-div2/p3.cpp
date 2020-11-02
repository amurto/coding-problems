#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, q;
        cin >> n >> q;
        ll low = 0, high = 0, v, temp;
        for (int i = 0; i < n; i++) {
            cin >> v;
            temp = low;
            low = max(low, high - v);
            high = max(high, temp + v);
        }
        cout << max(low, high) << endl;
    }
    return 0;
}