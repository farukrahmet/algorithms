def heapify(a, i, heapsize):
    left = 2*i+1
    right = 2*i+2
    if left <= heapsize and a[left] > a[i]:
        a[i], a[left] = a[left], a[i]
        heapify(a, left, heapsize)

    if right <= heapsize and a[right] > a[i]:
        a[i], a[right] = a[right], a[i]
        heapify(a, right, heapsize)


def heapSort(a):
    j = 1
    while len(a)-j > 0:
        a[0], a[len(a)-j] = a[len(a)-j], a[0]
        heapsize = len(a)-j-1
        for i in range(heapsize, -1, -1):
            heapify(a, i, heapsize)
        j = j + 1


if __name__ == "__main__":
    a = [6, 5, 4, 3, 2, 1]
    heapsize = len(a) - 1
    for i in range(heapsize, -1, -1):
        heapify(a, i, heapsize)

    heapSort(a)
    print a
