#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
int freq[N];
int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    memset(freq, 0, sizeof(freq));
    cin >> arr[0];
    freq[arr[0]]++;
    int MAX = arr[0];
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i-1] != arr[i])
            freq[arr[i]]++;
        MAX = max(MAX, arr[i]);
    }
    if (n == 1)
        return 0;
    int op = INT_MAX;
    for (int i = 1; i <= MAX; i++)
    {
        if (freq[i] == 0)
            continue;
        int occ = freq[i] + 1;
        if (arr[0] == i)
            occ--;
        if (arr[n - 1] == i)
            occ--;
        op = min(op, occ);
    }
    return op;
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
        cout << solve() << "\n";
    }
    return 0;
}