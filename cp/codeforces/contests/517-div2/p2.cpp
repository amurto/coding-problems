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

bool calc(vector<int> &arr, vector<int> &a, vector<int> &b, int n)
{
    for (int i = 1; i < n; i++)
    {
        arr[i] = -1;
        for (int num = 0; num <= 3; num++)
            if ((arr[i - 1] | num) == a[i - 1] && (arr[i - 1] & num) == b[i - 1])
                arr[i] = num;
        if (arr[i] == -1)
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n - 1), b(n - 1), arr(n);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];
    for (int num = 0; num <= 3; num++)
    {
        arr[0] = num;
        if (calc(arr, a, b, n))
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}