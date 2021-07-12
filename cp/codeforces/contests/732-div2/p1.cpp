#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    queue<int> pos, neg;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        int d = abs(a[i] - b[i]);
        if (a[i] > b[i])
        {
            while (d > 0)
            {
                neg.push(i + 1);
                d--;
            }
        }
        else if (a[i] < b[i])
        {
            while (d > 0)
            {
                pos.push(i + 1);
                d--;
            }
        }
    }
    int sz1 = pos.size(), sz2 = neg.size();
    if (sz1 != sz2)
    {
        cout << "-1\n";
        return;
    }
    cout << pos.size() << "\n";
    while (!pos.empty())
    {
        cout << neg.front() << " " << pos.front() << "\n";
        pos.pop();
        neg.pop();
    }
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