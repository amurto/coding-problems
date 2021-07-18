#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    int j = 0, k = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for (int i = 0; j < n && k < n && i < n; i++)
    {
        while (j < n && b[j] <= a[i])
            j++;
        while (j < n && k < n && c[k] <= b[j])
            k++;
        cnt += (j < n && k < n);
        j++;
        k++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}