def binary_search(array, wanted):
    last = len(array) - 1
    head = 0
    i = (last+head)/2
    while head <= last and array[i] != wanted:
        if wanted < array[i]:
            last = i - 1
        else:
            head = i + 1
        i = (last+head)/2
    if array[i] == wanted:
        return i
    else:
        return -1
