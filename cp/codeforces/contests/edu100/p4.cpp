#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, mn = 0, mx = 0;
        cin >> n;
        vector<int> B(n), A;
        vector<bool> vis(2 * n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
            vis[B[i]] = true;
        }
        for (int i = 1; i <= 2 * n; i++)
            if (!vis[i])
                A.pb(i);
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < A.size() && A[j] <= B[i])
                j++;
            if (j < A.size())
            {
                j++;
                mn++;
            }
        }
        for (int i = n - 1, j = A.size() - 1; i >= 0; i--)
        {
            while (j >= 0 && A[j] >= B[i])
                j--;
            if (j >= 0)
            {
                j--;
                mx++;
            }
        }
        mx = n - mx;
        cout << abs(mx - mn) + 1 << "\n";
    }
    return 0;
}