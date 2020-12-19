#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    string r, b;
    cin >> r >> b;
    int eq = 0, rw = 0, bw = 0;
    for (int i = 0; i < n; i++)
        if (r[i] > b[i])
            rw++;
        else if (r[i] < b[i])
            bw++;
        else
            eq++;

    if (rw > bw)
        cout << "RED\n";
    else if (bw > rw)
        cout << "BLUE\n";
    else
        cout << "EQUAL\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}