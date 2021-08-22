#ifdef amurto
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
    if (k == 1)
    {
        for (int i = n; i > 0; i--)
            res.pb(i);
        display(res);
        return;
    }
    for (int i = 0; i < k; i++)
    {
        if (i == 0)
        {
            int cur = arr[i];
            while (cur > 0)
            {
                res.pb(cur);
                cur--;
            }
        }
        else if (i == k - 1)
        {
            int cur = arr[i];
            if (arr[i] < n)
                cur = n;
            while (cur > arr[i - 1])
            {
                res.pb(cur);
                cur--;
            }
        }
        else
        {
            int cur = arr[i];
            while (cur > arr[i - 1])
            {
                res.pb(cur);
                cur--;
            }
        }
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