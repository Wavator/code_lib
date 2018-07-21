n, h = map(float, input().split(' '))
print(' '.join(['%.9f' % (((k + 1) / n) ** 0.5 * h) for k in range(int(n) - 1)]))