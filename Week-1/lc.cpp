#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int g[maxn][maxn];
int n, m;

void dfs(int x, int y)
{
    g[x][y] = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int xx = x + i;
            int yy = y + j;
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == 1)
            {
                dfs(xx, yy);
            }

        }
    }
}

int main(void)
{
    scanf("N=%d, M=%d", &n, &m);
    string ip;
    char temp;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, ip);
        for (int k = 0; k < m; k++)
        {
            if (ip[k] == 'W')
                g[i][k] = 1;
            else

                g[i][k] = 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 1)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    printf("\n\n%d\n", cnt);
    return 0;
}
