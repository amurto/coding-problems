#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int LGN = 18;

int combine(int x, int y)
{
    // use your combiner here
    return max(x, y);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sparse_table st(n);
    st.build(arr, n);
    while (q-- > 0)
    {
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << "\n";
    }
    return 0;
}
