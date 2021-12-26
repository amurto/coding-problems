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

const int inf = 1e9 + 7;
int calc(vector<int> &arr, int n)
{
    if (is_sorted(arr.begin(), arr.end()))
        return 0;
    int res = 0, last = 1;
    queue<int> q;
    for (int x : arr)
    {
        q.push(x);
        if (x == 1 || x == n)
            last = x;
    }
    while (q.front() != last)
    {
        q.push(q.front());
        q.pop();
        res++;
    }
    if (last == n)
        res++;
    return res;
}

int solve()
{
    int n, res = inf;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    res = calc(arr, n);
    reverse(arr.begin(), arr.end());
    res = min(res, calc(arr, n) + 1);
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