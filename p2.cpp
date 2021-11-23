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

bool calc(vector<int> &arr, int n, int x)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else
        {
            if (arr[i] == x)
            {
                while (i < j && arr[i] == x)
                    i++;
                if (i == j)
                    return true;
                if (arr[i] == arr[j])
                {
                    i++;
                    j--;
                }
                else
                    return false;
            }
            else if (arr[j] == x)
            {
                while (i < j && arr[j] == x)
                    j--;
                if (i == j)
                    return true;
                if (arr[i] == arr[j])
                {
                    i++;
                    j--;
                }
                else
                    return false;
            }
            else
                return false;
        }
    }
    return true;
}
bool solve()
{
    int n, l = 0, r = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (arr[i] != arr[j])
        {
            l = arr[i];
            r = arr[j];
            break;
        }
    }
    if (l == 0)
        return true;
    bool res = false;
    if (calc(arr, n, l) || calc(arr, n, r))
        res = true;
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
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}