// https://codeforces.com/contest/1237/problem/D
// Balanced Playlist

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 6e5 + 5, LGN = 18;
int sp[N][LGN], hp[N];

void init()
{
    // highest power of 2 less than i
    hp[0] = hp[1] = 0;
    for (int i = 2; i < N; i++)
        hp[i] = hp[i / 2] + 1;
}

void build(vector<int> &arr, int n)
{
    // sparse table initialization with input array
    for (int i = 0; i < n; i++)
        sp[i][0] = arr[i];
    // works for min, max, gcd
    // updates not supported
    for (int k = 1; k < LGN; k++)
        for (int i = 0; i < n; i++)
            sp[i][k] = min(sp[i][k - 1], sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
}

int query(int l, int r)
{
    int dis = r - l + 1;
    return min(sp[l][hp[dis]], sp[r - (1 << hp[dis]) + 1][hp[dis]]);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(3 * n), nxt(3 * n + 1), fin(3 * n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
        arr[i + 2 * n] = arr[i];
    }
    build(arr, 3 * n);
    stack<int> st;
    for (int i = 0; i < 3 * n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nxt[st.top()] = 3 * n;
        st.pop();
    }
    fin[3 * n] = -1;
    for (int i = 3 * n - 1; i >= 0; i--)
    {
        int low = i + 1, high = 3 * n - 1, res = 3 * n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (2 * query(i, mid) < arr[i])
            {
                res = min(res, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (res < nxt[i])
            fin[i] = res;
        else
            fin[i] = fin[nxt[i]];
    }
    for (int i = 0; i < n; i++)
    {
        if (fin[i] >= 0)
            fin[i] -= i;
        cout << fin[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}