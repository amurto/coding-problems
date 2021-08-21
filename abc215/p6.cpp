#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = 1e9 + 5;
int solve()
{
    int n, res = 0;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    int low = 0, high = inf;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool f = false;
        queue<pii> q;
        int mn = inf, mx = 0;
        for (int i = 0; !f && i < n; i++)
        {
            int x = arr[i].first;
            while (!q.empty() && q.front().first <= x - mid)
            {
                mn = min(mn, q.front().second);
                mx = max(mx, q.front().second);
                q.pop();
            }
            if (mn <= arr[i].second - mid || mx >= arr[i].second + mid)
                f = true;
            q.push(arr[i]);
        }
        if (f)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}