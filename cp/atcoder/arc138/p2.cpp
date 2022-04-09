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

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), is_valid(n), suf(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (arr[0] == 1)
        return false;
    is_valid[0] = 1;
    for (int i = 1, p = 1; i < n; i++, p ^= 1)
        if (is_valid[i - 1] > 0 && arr[i] == p)
            is_valid[i] = is_valid[i - 1] + 1;
    suf[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        if (arr[i] != arr[i + 1])
            suf[i]++;
    }
    if (is_valid[n - 1] > 0)
        return true;
    for (int i = 0; i < n - 1; i++)
    {
        int req = suf[i + 1];
        if (arr[i] != arr[i + 1])
        {
            if (is_valid[i] - 1 >= req)
                return true;
        }
        else
        {
            if (is_valid[i] >= req)
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}