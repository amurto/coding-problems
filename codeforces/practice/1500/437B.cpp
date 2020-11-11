// https://codeforces.com/problemset/problem/437/B
// The Child and Set

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int lowbit(int x)
{
    for (int i = 0; i < 18; i++)
        if (x & (1 << i))
            return (1 << i);
    return -1;
}

void solve(int sum, int limit)
{
    unordered_set<int> res;
    int sofar = 0;
    for (int num = 1; num <= limit; num++)
    {
        sofar += lowbit(num);
        res.insert(num);
        if (sofar >= sum)
        {
            int diff = sofar - sum;
            // for diff = 1010
            // remove 1000 and 10
            for (int j = 0; j < 18; j++)
                if (diff >> j & 1)
                    res.erase(1 << j);
            cout << res.size() << "\n";
            for (int x : res)
                cout << x << " ";
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int sum, limit;
    cin >> sum >> limit;
    solve(sum, limit);
    return 0;
}