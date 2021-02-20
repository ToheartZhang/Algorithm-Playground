#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1330;
const int MAXM = 133;
const int MAXL = 66;

struct Node {
    int x, y, z;
};

const int dx[] = {0, 0, 0, 0, 1, -1};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {1, -1, 0, 0, 0, 0};

queue<Node> q;
int n, m, l, t, ans;
int pixel[MAXN][MAXM][MAXL];
bool vis[MAXN][MAXM][MAXL];

bool isInside(int x, int y, int z) {
    return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < l;
}

int BFS(Node start) {
    int cnt = 0;
    while (!q.empty()) {
        q.pop();
    }
    q.push(start);
    vis[start.x][start.y][start.z] = true;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6; i++) {
            int nxtX = now.x + dx[i];
            int nxtY = now.y + dy[i];
            int nxtZ = now.z + dz[i];
            if (isInside(nxtX, nxtY, nxtZ) && !vis[nxtX][nxtY][nxtZ] && pixel[nxtX][nxtY][nxtZ]) {
                q.push(Node({nxtX, nxtY, nxtZ}));
                vis[nxtX][nxtY][nxtZ] = true;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &l, &t);
    for (int k = 0; k < l; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &pixel[i][j][k]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                if (!vis[i][j][k] && pixel[i][j][k]) {
                    int vol = BFS(Node({i, j, k}));
                    if (vol >= t) {
                        ans += vol;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
