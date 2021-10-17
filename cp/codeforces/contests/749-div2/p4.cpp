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

int query(vector<int> &arr, int n)
{
    cout << "? ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    int k;
    cin >> k;
    if (k == -1)
        exit(0);
    return k;
}

void solve()
{
    int n, k;
    cin >> n;
    vector<int> p(n + 1, n), arr(n + 1, 1);
    p[n] = 0;
    for (int i = 2; p[n] == 0 && i <= n; i++)
    {
        arr[n] = i;
        k = query(arr, n);
        if (k == 0)
            p[n] = n + 2 - i;
    }
    if (p[n] == 0)
        p[n] = 1;
    for (int i = 1; i < n; i++)
    {
        // find i
        if (i != p[n])
        {
            if (i < p[n])
            {
                for (int j = 1; j < n; j++)
                    arr[j] = n;
                arr[n] = n + i - p[n];
            }
            else
            {
                arr[n] = n;
                for (int j = 1; j < n; j++)
                    arr[j] = n + p[n] - i;
            }
            int k = query(arr, n);
            p[k] = i;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}