def solve():
    t = int(input().strip())
    mod = 10**9 + 7
    for _ in range(t):
        n = int(input().strip())
        s = input().strip()
        dp = [[0]*26 for _ in range(n+1)]
        prefix_sum = [0]*(n+1)
        ans = 0
        for i in range(1, n+1):
            for j in range(26):
                dp[i][j] = dp[i-1][j]
            dp[i][ord(s[i-1]) - ord('a')] = (prefix_sum[i-1] + 1) % mod
            prefix_sum[i] = (prefix_sum[i-1] + dp[i][ord(s[i-1]) - ord('a')]) % mod
            ans = (ans + dp[i][ord(s[i-1]) - ord('a')]) % mod
        print(ans)

solve()
