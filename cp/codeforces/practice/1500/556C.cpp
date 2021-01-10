// https://codeforces.com/contest/556/problem/C
// Case of Matryoshkas

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int t = 0, res = 0;
    for (int i = 0; i < k; i++)
    {
        int sz;
        cin >> sz;
        vector<int> arr(sz);
        for (int j = 0; j < sz; j++)
            cin >> arr[j];
        if (arr[0] == 1)
        {
            int j = 1;
            while (j < sz && arr[j] - arr[j - 1] == 1)
                j++;
            res += sz - j;
            t += sz - j;
        }
        else
        {
            t += sz - 1;
            res += sz;
        }
    }
    cout << res + t << "\n";
    return 0;
}