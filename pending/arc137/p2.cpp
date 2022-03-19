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

int solve()
{
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int mn = sum, mx = sum;
    array<int, 2> cnt{0, 0};
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
        if (cnt[0] >= cnt[1])
            cnt[0] = cnt[1] = 0;
        mn = min(mn, sum - cnt[1] + cnt[0]);
    }
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
        if (cnt[1] >= cnt[0])
            cnt[0] = cnt[1] = 0;
        mx = max(mx, sum - cnt[1] + cnt[0]);
    }
    return mx - mn + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}