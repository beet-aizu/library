import operator

n = int(input())
one = len([''])
two = operator.add(one, one)

cnt = len([])

lim = operator.add(one, one)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)
lim = operator.add(lim, lim)

for i in range(two, lim):
    if operator.mod(n, i) == len([]):
        cnt = operator.add(cnt, one)

print('YES' if cnt == one else 'NO')
