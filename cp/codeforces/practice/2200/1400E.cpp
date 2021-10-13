// https://codeforces.com/contest/1400/problem/E
// Clear the Multiset

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

int calc(vector<int> &arr, int i, int j, int n)
{
    int mn = arr[i] + 1, c = 0, id = -1;
    for (int itr = i; itr <= j; itr++)
    {
        if (arr[itr] < mn)
        {
            mn = arr[itr];
            id = itr;
            c = 1;
        }
        else if (arr[itr] == mn)
            c++;
    }
    int l = 0, r = 0;
    if (id > i)
    {
        // i id-1
        int lmn = *min_element(arr.begin() + i, arr.begin() + id);
        l = lmn - mn + calc(arr, i, id - 1, n);
        if (lmn > mn)
            l = min(l, id - i);
    }
    if (id < j)
    {
        // id+1 j
        int rmn = *min_element(arr.begin() + id + 1, arr.begin() + j + 1);
        r = rmn - mn + calc(arr, id + 1, j, n);
        if (rmn > mn)
            r = min(r, j - id);
    }
    int dp0 = l + r;
    int dp1 = min(j - i + 1 - ((mn == 0) * c), mn + min(dp0, j - i + 1 - c));
    return (i == 0 && j == n - 1) ? dp1 : dp0;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return calc(arr, 0, n - 1, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}