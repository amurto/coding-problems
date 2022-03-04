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
    int n, N = 0, S = 0;
    cin >> n;
    string str;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> str;
    for (char ch : str)
        if (ch == 'N')
            N++;
        else
            S++;
    if (is_sorted(arr.begin(), arr.end()))
        return 0;
    if (N == 0 || S == 0)
        return -1;
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    int l = 0, r = n - 1;
    while (l < n && arr[l] == tmp[l])
        l++;
    while (r >= 0 && arr[r] == tmp[r])
        r--;
    int n_l = 0, s_l = 0, n_r = 0, s_r = 0;
    for (int i = 0; i <= l; i++)
        if (str[i] == 'N')
            n_l++;
        else
            s_l++;
    for (int i = n - 1; i >= r; i--)
        if (str[i] == 'N')
            n_r++;
        else
            s_r++;
    if ((n_l > 0 && s_r > 0) || (s_l > 0 && n_r > 0))
        return 1;
    return 2;
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