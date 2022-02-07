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

const int LGN = 19;

int combine(int x, int y)
{
    // use your combiner here
    return __gcd(x, y);
}

struct sparse_table
{
    vector<vector<int>> sp;
    vector<int> hp;
    sparse_table(int n)
    {
        sp.resize(n, vector<int>(LGN));
        hp.resize(n + 1);
        // highest power of 2 less than i
        hp[0] = hp[1] = 0;
        for (int i = 2; i <= n; i++)
            hp[i] = hp[i / 2] + 1;
    }
    sparse_table() = default;

    void build(vector<int> &arr, int n)
    {
        // sparse table initialization with input array
        for (int i = 0; i < n; i++)
            sp[i][0] = arr[i];
        // works for min, max, gcd
        // updates not supported
        for (int k = 1; k < LGN; k++)
            for (int i = 0; i < n; i++)
                sp[i][k] = combine(sp[i][k - 1], sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
    }

    int query(int l, int r)
    {
        int dis = r - l + 1;
        return combine(sp[l][hp[dis]], sp[r - (1 << hp[dis]) + 1][hp[dis]]);
    }
};

void solve()
{
    int n;
    cin >> n;
    int pr = 7999993;
    vector<int> arr(n), res(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sparse_table st(n);
    st.build(arr, n);
    int last = -1, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int low = last + 1, high = i, id = i;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int g = st.query(mid, i);
            if (g < i - mid + 1)
                low = mid + 1;
            else
            {
                id = min(id, mid);
                high = mid - 1;
            }
        }
        if (st.query(id, i) == i - id + 1)
        {
            last = i;
            arr[i] = pr;
            cnt++;
        }
        res[i] = cnt;
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}