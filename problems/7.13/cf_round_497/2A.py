p = 'aouie'
s = input()
t = s + 'a'
for i, x in enumerate(s):
    if x != 'n' and x not in p:
        if t[i + 1] not in p:
            print('NO')
            exit()
if s[-1] != 'n' and s[-1] not in p:
    print('NO')
    exit()
print('YES')