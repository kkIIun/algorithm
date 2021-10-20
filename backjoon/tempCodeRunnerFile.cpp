
        case 3:
            for (ll c = 0; c < n; c++)
            {
                for (ll r = 0; r < n - 1; r++)
                {
                    if (!nMap[r][c])
                        continue;
                    ll temp = r + 1;
                    while (nMap[temp][c] == 0 && temp < n - 1)
                        temp++;
                    if (nMap[temp][c] == nMap[r][c])
                    {
                        nMap[r][c] *= 2;
                        nMap[temp][c] = 0;
                    }
                }
                for (ll r = 0; r < n; r++)
                    if (nMap[r][c])
                    {
                        ll nc = c, nr = r;
                        ans = max(ans, nMap[nr][nc]);
                        while (nc + dx[i] >= 0 && nr + dy[i] >= 0 && nMap[nr + dy[i]][nc + dx[i]] == 0)
                        {
                      