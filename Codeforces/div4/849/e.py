t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    total_sum = sum(arr)
    negative_sum = -10000000000000000
    count_negative = 0
    check = False
    for num in arr:
        if num < 0:
            negative_sum = min(num, negative_sum)
            count_negative += 1
        elif num == 0:
            check = True
    if(check):
        print(total_sum)
        continue
    if(count_negative%2):
        print(total_sum+(2*negative_sum))
        continue
    max_sum = total_sum + 2 * negative_sum
    
    print(max_sum)
