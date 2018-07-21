n = int(input())
p = []
for i in range(n):
    a, b = map(int, input().split())
    p.append([a, n - i])
    p.append([b, n - i])
p.sort(reverse=True)
i = n
for a, x in p:
    if x == i:
        i -= 1
print(['NO', 'YES'][i == 0])