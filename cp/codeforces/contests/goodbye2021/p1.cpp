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

const int N = 105;
int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n), cnt(N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[abs(arr[i])]++;
    }
    for (int i = 1; i < N; i++)
        if (cnt[i] == 1)
            res++;
        else if (cnt[i] > 1)
            res += 2;
    if (cnt[0] > 0)
        res++;
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