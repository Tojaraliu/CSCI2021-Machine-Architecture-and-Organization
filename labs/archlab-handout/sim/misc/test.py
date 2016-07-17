src = [10, 176, 3072]
dst = [273, 546, 819]

result = 0
len = 3
i = 0

while (len > 0):
    val = src[i]
    dst[i] = val
    i += 1
    result ^= val
    len -= 1


print(dst)
print(result)