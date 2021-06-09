// https://codeforces.com/contest/1103/problem/B
// Game with modulo

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    string str;
    cin >> str;
    return (str == "x") ? 1 : 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> pws;
    pws.pb(0);
    for (int i = 0; i <= 30; i++)
        pws.pb(1 << i);
    string t;
    cin >> t;
    while (t == "start")
    {
        int id = -1;
        for (int i = 0; id == -1 && i < pws.size() - 1; i++)
        {
            int q = query(pws[i], pws[i + 1]);
            if (q == 1)
                id = i;
        }
        int low = pws[id] + 1, high = pws[id + 1], res = pws[id];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (query(pws[id], mid))
                high = mid - 1;
            else
            {
                res = max(res, mid);
                low = mid + 1;
            }
        }
        cout << "! " << res + 1 << endl;
        cin >> t;
    }
    return 0;
}