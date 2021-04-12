#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(int i, int j)
{
    cout << "1 " << i << " " << j << endl;
    int sz;
    string str;
    cin >> sz;
    if (sz == -1)
        exit(0);
    if (sz > 0)
        cin >> str;
    return sz;
}

int main()
{
    int n, sz, cur = 1;
    char ch;
    cin >> n;
    vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector<char> res(n + 1);
    while (cur <= n)
    {
        cout << "1 " << pos[cur] << " " << pos[cur] << endl;
        cin >> sz >> ch;
        int low = cur, high = n, mx = cur;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (query(pos[cur], pos[mid]) > 0)
            {
                mx = max(mx, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        for (int i = cur; i <= mx; i++)
            res[pos[i]] = ch;
        cur = mx + 1;
    }
    cout << "2 ";
    for (int i = 1; i <= n; i++)
        cout << res[i];
    cout << endl;
    cin >> sz;
    return 0;
}