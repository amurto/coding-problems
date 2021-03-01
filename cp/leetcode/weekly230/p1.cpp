#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    map<string, int> mp;
    mp["type"] = 1;
    mp["color"] = 2;
    mp["name"] = 3;
    int cnt = 0;
    for (vector<string> i : items)
        cnt += (i[mp[ruleKey] - 1] == ruleValue);
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<string>> items = {{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}};
    string ruleKey = "color", ruleValue = "silver";
    cout << countMatches(items, ruleKey, ruleValue) << "\n";
    return 0;
}