// Group Anagrams Together
// https://practice.geeksforgeeks.org/problems/k-anagrams-1/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        unordered_map<string, int> m;
        vector<int> ans;
        for (int i=0; i<n; i++) {
            string str;
            cin>>str;
            sort(str.begin(), str.end());
            m[str]++;
        }
        for (auto it=m.begin(); it != m.end(); it++)
            ans.pb(it->second);
        sort(ans.begin(), ans.end());
        for (int v: ans)
            cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}