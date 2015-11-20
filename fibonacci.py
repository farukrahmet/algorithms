def normal(n):
    if n == 0:
        return 0
    elif n==1:
        return 1
    else:
        return normal(n-2) + normal(n-1)

def dynamic(aa, n):
    while len(aa) != n:
        leng = len(aa)
        aa.append(aa[leng-1] + aa[leng-2])

    return aa[-1]

import time
n = int(raw_input('n:?'))
aa = [1,1]
t1 = time.time()
dynamic(aa, n)
t2 = time.time()
print "Fibo with recursive : " + str(t2-t1)
t1 = time.time()
normal(n)
t2 = time.time()
print "Fibo with dynamic programming: " + str(t2-t1)

