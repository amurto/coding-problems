// https://leetcode.com/problems/dungeon-game/
// Dungeon Game

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int M = dungeon.size(), N = dungeon[0].size();
    dungeon[M-1][N-1] = (dungeon[M-1][N-1] >= 0) ? 1 : dungeon[M-1][N-1] * -1 + 1;  
    for (int i=M-1; i>=0; i--) {
        for (int j=(i==M-1) ? N-2 : N-1; j>=0; j--) {
            int next = min((i+1 < M) ? dungeon[i+1][j] : INT_MAX, (j+1<N) ? dungeon[i][j+1] : INT_MAX);
            if (dungeon[i][j] >= 0) 
                if (dungeon[i][j] >= next)
                    dungeon[i][j] = 1;
                else
                    dungeon[i][j] = next - dungeon[i][j]; 
            else 
                dungeon[i][j] = next + dungeon[i][j]*-1;
        }
    }
    return dungeon[0][0];
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> dungeon(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> dungeon[i][j];
    cout << calculateMinimumHP(dungeon) << "\n";
    return 0;
}