#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 10000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<bool> vis(N + 1);
    vector<int> tmp = {6, 10, 15};
    for (int e : tmp)
        for (int i = e; i <= N; i += e)
            vis[i] = true;
    vector<int> seq;
    for (int i = 1; i <= N; i++)
        if (vis[i])
            seq.pb(i);
    swap(seq[2], seq[3]);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << seq[i] << " ";
    return 0;
}