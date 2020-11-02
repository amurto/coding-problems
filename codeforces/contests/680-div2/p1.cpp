#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < n; i++)
        if (a[i] + b[i] > x)
            return "No";
    return "Yes";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}