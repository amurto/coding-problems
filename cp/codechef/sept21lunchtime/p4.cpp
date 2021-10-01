#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int l = 1, last = 0;
    for (int r = 1; r <= n; r++)
    {
        if (r != arr[r])
        {
            if (pos[r] >= l && pos[r] <= r)
            {
                if (last == 0)
                    last = pos[r];
                else if (last > pos[r])
                    l = last;
                else
                    last = pos[r];
            }
            if (arr[r] >= l && arr[r] <= r)
            {
                if (last == 0 || arr[last] < arr[r])
                    last = r;
                else
                {
                    if (last > arr[r])
                        l = arr[r] + 1;
                    else
                    {
                        l = last + 1;
                        last = r;
                    }
                }
            }
        }
        else
            last = r;
        res += 1ll * (r - l + 1);
    }
    return res;
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