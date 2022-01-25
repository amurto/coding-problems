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
    int n;
    cin >> n;
    vector<int> arr(4 * n), cnt(n + 1);
    for (int i = 0; i < 4 * n - 1; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (cnt[i] < 4)
            return i;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}