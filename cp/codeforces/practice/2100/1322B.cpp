// https://codeforces.com/contest/1322/problem/B
// Present

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

const int K = 26;

// find [l,r]
ll calc(vector<int> &arr, int n, int l, int r)
{
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // find l
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[i] + arr[mid] >= l)
                high = mid;
            else
                low = mid + 1;
        }
        int l_id = low, r_id = low;
        // find r
        if (arr[i] + arr[l_id] >= l && arr[i] + arr[l_id] <= r)
        {
            low = l_id, high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[i] + arr[mid] <= r)
                {
                    r_id = max(r_id, mid);
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            cnt += 1ll * (r_id - l_id + 1);
        }
    }
    return cnt;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> st(n);
    for (int b = 0; b < K; b++)
    {
        for (int i = 0; i < n; i++)
        {
            st[i] |= ((arr[i] & 1) << b);
            arr[i] >>= 1;
        }
        vector<int> tmp = st;
        sort(tmp.begin(), tmp.end());
        int h = 1 << (b + 1);
        int l = 1 << b, r = h - 1;
        ll bits = calc(tmp, n, l, r) + calc(tmp, n, h | l, h | r);
        if (bits & 1)
            res |= (1 << b);
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