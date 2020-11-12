#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string ver;
    vector<int> prob(m), verdict(m);
    for (int i = 0; i < m; i++)
    {
        cin >> prob[i];
        cin >> ver;
        if (ver == "WA")
            verdict[i] = 0;
        else
            verdict[i] = 1;
    }
    vector<int> wrong(n + 1);
    unordered_set<int> SET;
    int pen = 0;
    for (int i = 0; i < m; i++)
    {
        if (verdict[i] == 0)
            wrong[prob[i]]++;
        else
        {
            if (SET.find(prob[i]) == SET.end())
            {
                SET.insert(prob[i]);
                pen += wrong[prob[i]];
            }
        }
    }
    cout << SET.size() << " " << pen << "\n";
    return 0;
}