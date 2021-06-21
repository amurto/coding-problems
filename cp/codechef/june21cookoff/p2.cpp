#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class triplet
{
public:
    int a, b, c;
    triplet() {}
    triplet(int a, int b, int c) : a(a), b(b), c(c) {}
};

bool check(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
        if ((arr[i - 1] ^ arr[i]) == 0)
            return false;
    for (int i = 0; i < n - 2; i++)
        if ((arr[i] ^ arr[i + 2]) > 0)
            return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    if (n <= 3)
    {
        if (check(arr, n))
        {
            cout << "0\n";
            return;
        }
        vector<int> ids = {0, 1, 2};
        do
        {
            vector<int> tmp = arr;
            tmp[ids[2]] = tmp[ids[0]] ^ tmp[ids[1]];
            if (check(tmp, n))
            {
                cout << "1\n";
                for (int id : ids)
                    cout << id + 1 << " ";
                cout << "\n";
                return;
            }
        } while (next_permutation(ids.begin(), ids.end()));
        cout << "-1\n";
        return;
    }
    if (count(arr.begin(), arr.end(), 0) == n)
    {
        cout << "-1\n";
        return;
    }
    vector<triplet> ops;
    int a = -1, b = -1;
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            a = i;
    if (a == -1)
    {
        ops.pb(triplet(0, 1, 2));
        arr[2] = arr[0] ^ arr[1];
        ops.pb(triplet(0, 1, 3));
        arr[3] = arr[0] ^ arr[1];
        ops.pb(triplet(2, 3, 0));
        arr[0] = arr[2] ^ arr[3];
        a = 0;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            b = i;
    for (int i = 0; i < n; i++)
    {
        if (i != a && i != b)
        {
            ops.pb(triplet(a, b, i));
            arr[i] = arr[a] ^ arr[b];
        }
    }
    int p = a & 1;
    if (p == 0)
    {
        a = 1;
        b = 3;
    }
    else
    {
        a = 0;
        b = 2;
    }
    for (int i = 0, d = 0; i < n; i++, d ^= 1)
    {
        if (p == d)
        {
            ops.pb({a, b, i});
            arr[i] = arr[a] ^ arr[b];
        }
    }
    cout << ops.size() << "\n";
    for (triplet t : ops)
        cout << t.a + 1 << " " << t.b + 1 << " " << t.c + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}