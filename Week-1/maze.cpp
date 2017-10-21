#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
struct pos
{
    int x, y, cnt;

    pos()
    {
        x = -1;
        y = -1;
        cnt = 0;
    }

    pos(int a, int b, int c)
    {
        x = a;
        y = b;
        cnt = c;
    }
};

int maze[maxn][maxn];
int m, n;
int mov[4][2] = {{1, 0},
                 {0, 1},
                 {-1, 0},
                 {0, -1}};
pos q[100005];

int bfs(int sx, int sy, int ex, int ey)
{
    if (sx == ex && sy == ey)
        return 0;
    int sel = 0, save = 1;
    q[sel] = pos(sx, sy, 0);
    while (sel < save)
    {
        pos test = q[sel++];
        for (int i = 0; i < 4; i++)
        {
            int tx = test.x + mov[i][0];
            int ty = test.y + mov[i][1];
            if (maze[tx][ty] && tx >= 0 && tx < m && ty >= 0 && ty < n)
            {
                if (tx == ex && ty == ey)
                {
                    return test.cnt + 1;
                }
                q[save++] = pos(tx, ty, test.cnt + 1);
                maze[tx][ty] = 0;
            }
        }
    }
    return -1;
}

int main(void)
{
    string ip;
    scanf("N=%d, M=%d", &m, &n);
    int sx, sy, ex, ey;
    memset(maze, 0, sizeof(maze));
    for (int i = 0; i < m; i++)
    {
        cin >> ip;
        for (int j = 0; j < n; j++)
        {
            if (ip[j] == '.')
                maze[i][j] = 1;
            if (ip[j] == '#')
                maze[i][j] = 0;
            if (ip[j] == 'S')
            {
                sx = i;
                sy = j;
                maze[i][j] = 0;
            }
            if (ip[j] == 'G')
            {
                ex = i;
                ey = j;
                maze[i][j] = 1;
            }
        }
    }
    cout << bfs(sx, sy, ex, ey) << endl;

    return 0;
}