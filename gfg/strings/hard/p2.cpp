// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
// Alien Dictionary

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int G[26][26], vis[26];

// Topological Sort
void topSort(stack<int> &STACK, int p) {
    if (vis[p] == -1 || vis[p] == 1)
        return;
    vis[p] = 1;
    for (int j=0; j<26; j++)
        if (G[p][j] == 1)
            topSort(STACK, j);
    STACK.push(p);
}

string findOrder(string dict[], int N, int K) {
    int p1=0, p2=0;
    stack<int> STACK;
    memset(G, 0, sizeof(G));
    memset(vis, -1, sizeof(vis));

    for (int i=0; i<N-1; i++) {
        p1=0;p2=0;
        while (p1<dict[i].length() && p2<dict[i+1].length() && dict[i][p1] == dict[i+1][p2]) {
            vis[dict[i][p1] - 97] = 0;
            p1++;
            p2++;
        }
        if (p1 < dict[i].length() && p2< dict[i+1].length())
            G[dict[i][p1] - 97][dict[i+1][p2] - 97] = 1;
        while (p1 < dict[i].length()) {
            vis[dict[i][p1] - 97] = 0;
            p1++;
        }
        while (p2 < dict[i+1].length()) {
            vis[dict[i+1][p2] - 97] = 0;
            p2++;
        }
    }

    for (int i=0; i<26; i++)
        topSort(STACK, i);

    string ans="";
    while (!STACK.empty()) {
        char c = STACK.top() + 97;
        ans+=c;
        STACK.pop();
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int N, K;
        cin>>N>>K;
        string dict[N];
        for (int i=0; i<N; i++) 
            cin>>dict[i];
        cout<<findOrder(dict, N, K)<<endl;
    }
    return 0;
}