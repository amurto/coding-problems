// Print all subsequences of a string

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void getSS(string soFar, string &s, vector<string> &ans, int cur) {
    if (cur==s.length()) {
        ans.pb(soFar);
        return;
    }
    getSS(soFar, s, ans, cur+1);
    soFar.pb(s[cur]);
    getSS(soFar, s, ans, cur+1);
}

int main() {
    string s;
    cin>>s;
    vector<string> ans;
    getSS("", s, ans, 0);
    for (string v: ans)
        cout<<v<<"\n";
    return 0;
}