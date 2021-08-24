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

void display(vector<int> &res)
{
    for (int r : res)
        cout << r << " ";
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(k), res;
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    vector<vector<int>> sts(k);
    for (int i = 0; i < k; i++)
    {
        int lim = arr[i];
        if (i == k - 1)
            lim = n;
        for (int j = lim; j >= arr[i]; j--)
            sts[i].pb(j);
    }
    deque<int> dq;
    int last = 0;
    for (int i = 0; i < k; i++)
    {
        if (!dq.empty())
        {
            res.pb(dq.front());
            dq.pop_front();
        }
        for (int j = last + 1; j < arr[i]; j++)
            dq.pb(j);
        for (int e : sts[i])
            res.pb(e);
        last = arr[i];
    }
    while (!dq.empty())
    {
        res.pb(dq.back());
        dq.pop_back();
    }
    display(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}