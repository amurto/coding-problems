// https://codeforces.com/contest/888/problem/G
// Xor-MST

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Bit Trie
// set LGN to 60 for long long
const int N = 2e5 + 5, LGN = 30;
int t[N * LGN][2], cnt[N * LGN], mask = 1;

void insert(int x, int v, int bit)
{
    if (bit == -1)
    {
        cnt[v]++;
        return;
    }
    int child = (x >> bit) & 1;
    if (t[v][child] == 0)
        t[v][child] = ++mask;
    insert(x, t[v][child], bit - 1);
    // keep running sum
    cnt[v]++;
}

// min xor with x
int query(int x, int v, int bit)
{
    if (bit == -1)
        return 0;
    int child = (x >> bit) & 1;
    if (t[v][child] > 0)
        return query(x, t[v][child], bit - 1);
    return (1 << bit) | query(x, t[v][child ^ 1], bit - 1);
}

ll dfs(vector<int> &arr, int v, int l, int r, int bit)
{
    if (bit==-1 || r <= l)
        return 0;
    int low = l, high = r, id = low - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int b = (arr[mid] >> bit) & 1;
        if (b == 0)
        {
            id = max(id, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    ll cost = dfs(arr, t[v][0], l, id, bit - 1) + dfs(arr, t[v][1], id + 1, r, bit - 1);
    if (id >= l && id < r)
    {
        int mn = 1 << 30;
        for (int i = l; i <= id; i++)
            mn = min(mn, (1 << bit) | query(arr[i], t[v][1], bit - 1));
        cost += 1ll * mn;
    }
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        insert(arr[i], 1, LGN);
    }
    sort(arr.begin(), arr.end());
    cout << dfs(arr, 1, 0, n - 1, LGN);
    return 0;
}