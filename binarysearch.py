def binary_search(a, aranan):
    last = len(a) - 1
    head = 0
    i = (last+head)/2
    while head <= last and a[i] != aranan:
        if aranan < a[i]:
            last = i - 1
        else:
            head = i + 1
        i = (last+head)/2
    if a[i] == aranan:
        return i
    else:
        return -1
