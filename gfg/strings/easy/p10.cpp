// https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string/0
// Remove all duplicates from a given string

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        string s;
        cin>>s;
        int i=0;
        unordered_set<char> unique;
        while (true) {
            if (i>=s.length())
                break;
            if (unique.find(s[i]) == unique.end()) {
                unique.insert(s[i]);
                i++;
            } else {
                s.erase(i,1);
            }
        }
        cout<<s<<endl;
    }
    return 0;
}