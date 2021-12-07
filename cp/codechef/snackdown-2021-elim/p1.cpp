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

void range_sort(vector<int> &arr, int l, int r, int n)
{
    set<int> st;
    for (int i = l; i <= r; i++)
        st.insert(arr[i]);
    for (int i = l; i <= r; i++)
    {
        arr[i] = *st.begin();
        st.erase(st.begin());
    }
}

int calc1(vector<int> arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != arr[i])
        {
            range_sort(arr, i, min(n - 1, i + k - 1), n);
            break;
        }
    }
    if (is_sorted(arr.begin(), arr.end()))
        return 1;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != arr[i])
        {
            range_sort(arr, i, min(n - 1, i + k - 1), n);
            break;
        }
    }
    if (is_sorted(arr.begin(), arr.end()))
        return 2;
    return 3;
}

int calc2(vector<int> arr, int n, int k)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + 1 != arr[i])
        {
            range_sort(arr, max(0, i - k + 1), i, n);
            break;
        }
    }
    if (is_sorted(arr.begin(), arr.end()))
        return 1;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != arr[i])
        {
            range_sort(arr, i, min(n - 1, i + k - 1), n);
            break;
        }
    }
    if (is_sorted(arr.begin(), arr.end()))
        return 2;
    return 3;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        cin >> arr[i];
    }
    if (is_sorted(arr.begin(), arr.end()))
        return 0;
    int c1 = calc1(arr, n, k), c2 = calc2(arr, n, k);
    return min(c1, c2);
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