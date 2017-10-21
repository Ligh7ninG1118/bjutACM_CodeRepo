#include <bits/stdc++.h>

using namespace std;
const int maxn = 255;

struct pos
{
    int x, y, cnt;

    pos(int a, int b, int c)
    {
        x = a;
        y = b;
        cnt = c;
    }
};

int g[maxn][maxn];  //POS = noise level; 0 = empty; -1 = blocked;
int nlvl[maxn][maxn]{0};
int vis[maxn][maxn];

int n, m, mtp, lmt;
int mov[4][2] = {{-1, 0},
                 {0,  -1},
                 {1,  0},
                 {0,  1}};

void bfs(int x, int y)
{
    nlvl[x][y] += g[x][y] * mtp;
    queue<pos> q;
    q.push(pos(x, y, (g[x][y] * mtp)));
    memset(vis, 0, sizeof(vis));
    vis[x][y] = 1;
    while (!q.empty())
    {
        pos temp = q.front();
        q.pop();
        if (temp.cnt <= 0)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int xx = temp.x + mov[i][0];
            int yy = temp.y + mov[i][1];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] != -1 && vis[xx][yy] == 0)
            {
                vis[xx][yy] = 1;
                nlvl[xx][yy] += (int) temp.cnt / 2;
                q.push(pos(xx, yy, (int) temp.cnt / 2));
            }
        }

    }
}

int main(void)
{
    scanf("%d %d %d %d", &n, &m, &mtp, &lmt);
    getchar();
    string ip;
    for (int i = 0; i < n; i++)
    {
        getline(cin, ip);
        for (int j = 0; j < ip.length(); j++)
        {
            if (isalpha(ip[j]))
                g[i][j] = ip[j] - 'A' + 1;
            else if (ip[j] == '.')
                g[i][j] = 0;
            else
                g[i][j] = -1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] > 0)
                bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nlvl[i][j] > lmt)
                res++;
        }
    }
    printf("%d", res);
    return 0;
}