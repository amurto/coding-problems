// https://codeforces.com/problemset/problem/522/A
// Reposts

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int height(unordered_map<string, vector<string>> &MAP, string cur)
{
    int h = 0;
    for (string child : MAP[cur])
        h = max(h, height(MAP, child));
    return h + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    unordered_map<string, vector<string>> MAP;
    string name1, reposted, name2;
    for (int i = 0; i < n; i++)
    {
        cin >> name1 >> reposted >> name2;
        transform(name1.begin(), name1.end(), name1.begin(), ::tolower); 
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower); 
        MAP[name2].push_back(name1);
    }
    cout << height(MAP, "polycarp") << "\n";
    return 0;
}
