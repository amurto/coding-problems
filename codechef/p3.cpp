#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool OneBit(int n)
{
    for (int i = 0; i < 29; i++)
    {
        if (n & (1 << i))
        {
            n = n >> i;
            break;
        }
    }
    if (n == 1)
        return true;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    if (OneBit(n))
    {
        cout << -1 << "\n";
        return;
    }
    int arr[n + 1];
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        if (OneBit(i))
        {
            arr[i + 1] = i;
            arr[i] = i + 1;
            i++;
        } else {
            arr[i] = i;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
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
        solve();
    }
    return 0;
}