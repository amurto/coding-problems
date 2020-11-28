#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> str(6);
    for (int i = 0; i < 6; i++)
        cin >> str[i];
    sort(str.begin(), str.end(), greater<int>());
    int n, note;
    cin >> n;
    vector<queue<pair<int, int>>> q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> note;
        for (int fret : str)
            q[i].push({note - fret, i});
    }

    set<pair<int, int>> SET;

    // Fill set with n notes
    for (queue<pair<int, int>> cur : q)
        SET.insert(cur.front());

    // Calculate answer
    int ans = INT_MAX;

    // Set contains n notes at a time
    // Answer is maximal - minimal
    // min(ans, last - first)
    // Set runs until any of the note queue becomes empty
    while (SET.size() == n)
    {
        ans = min(ans, SET.rbegin()->first - SET.begin()->first);
        int itr = SET.begin()->second;
        SET.erase(SET.begin());
        if (!q[itr].empty())
        {
            SET.insert(q[itr].front());
            q[itr].pop();
        }
    }

    cout << ans << "\n";
    return 0;
}