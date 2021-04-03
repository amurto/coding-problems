#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, f = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b)
        return true;
    vector<int> cntA(n);
    if (a[0] == '0')
        cntA[0]++;
    for (int i = 1; i < n; i++)
        cntA[i] = cntA[i - 1] + (a[i] == '0');
    for (int i = n - 1; i >= 0; i--)
    {
        int v = a[i] - '0', l = i + 1;
        v ^= f;
        if (f > 0)
            cntA[i] = i + 1 - cntA[i];
        if (v != b[i] - '0')
        {
            if (l & 1 || cntA[i] != l / 2)
                return false;
            f ^= 1;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}