
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        last[i] = i;
        dp[i][i] = 1;
    }

    for (ll i = 1; i <= n; i++)
        for (ll j = i; j <= n; j++)
            if (arr[i] < arr[j])
            {
                if (last[j] != j && dp[last[j]][j] > dp[last[i]][i] + 1)
                    continue;
                dp[i][j] = dp[last[i]][i] + 1;
                last[j] = i;
                if (ans.first < dp[i][j])
                {
                    ans.first