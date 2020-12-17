#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, s = 0;
    ll cur = 0, des = 0, last = 0;
    bool move = false;

    cin >> n;
    vector<ll> T(n), X(n), pos(n + 1);
    for (int i = 0; i < n; i++)
        cin >> T[i] >> X[i];
    for (int i = 0; i < n; i++)
    {
        if (move)
        {
            if (T[i] - last >= abs(cur - des))
            {
                cur = des;
                move = false;
            }
            else
            {
                if (des < cur)
                    cur -= abs(T[i] - last);
                else
                    cur += abs(T[i] - last);
            }
        }
        pos[i] = cur;
        if (!move)
        {
            des = X[i];
            move = true;
        }
        last = T[i];
    }
    if (move)
        cur = des;
    pos[n] = cur;
    for (int i = 0; i < n; i++)
    {
        ll mn = min(pos[i], pos[i + 1]), mx = max(pos[i], pos[i + 1]);
        if (X[i] >= mn && X[i] <= mx)
            s++;
    }
    return s;
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