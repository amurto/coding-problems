#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve(vector<ll> arr, int n)
{
    bool same = true;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            same = false;
    }
    if (same)
    {
        cout << "NO"
             << "\n";
        return;
    }
    cout << "YES"
         << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        int L = 0, R = n - 1, start = 0, end = 0;
        while (R > i && arr[R] == arr[i])
            R--;
        if (R > i)
        {
            start = i + 1;
            end = R + 1;
        }
        else
        {
            while (L < i && arr[L] == arr[i])
                L++;
            start = L + 1;
            end = i + 1;
        }
        cout << start << " " << end << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr, n);
    }
    return 0;
}