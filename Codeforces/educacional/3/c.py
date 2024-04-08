

n = int(input())
#ler vetor de inteiros
a = list(map(int, input().split()))

soma = sum(a)
a.sort()
ans = 0
med = soma // n
rest = n - (soma % n)

for i in range(n):
    if med > a[i]:
        if rest == 0:
            med += 1
        ans += med - a[i]
        if rest >= 0:
            rest -= 1

print(ans)

