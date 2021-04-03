#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool valid(vector<int> &arr, int n)
{
    vector<int> cnt(2);
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
        if (cnt[1] > cnt[0])
            return false;
    }
    return true;
}

void display(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        (arr[i] == 0) ? cout << '(' : cout << ')';
    cout << "\n";
}

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> a(n), b(n);
    int inv = count(str.begin(), str.end(), '0');
    if (inv % 2 != 0)
    {
        cout << "NO\n";
        return;
    }
    queue<int> q1, q2;
    int c = n - inv, last = 0;
    int op = c / 2, cl = n / 2;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            if (op > 0)
            {
                op--;
                a[i] = b[i] = 0;
            }
            else
            {
                a[i] = b[i] = 1;
                cl--;
            }
        }
        else
        {
            a[i] = last;
            b[i] = last ^ 1;
            last ^= 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if ((str[i] == '0' && a[i] == b[i]) || (str[i] == '1' && a[i] != b[i]))
        {
            cout << "NO\n";
            return;
        }
    }
    if (!valid(a, n) || !valid(b, n))
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    display(a, n);
    display(b, n);
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