def merge_sort(array):
    if len(array) > 1:
        mid = len(array)/2

        left = array[:mid]
        right = array[mid:]

        merge_sort(left)
        merge_sort(right)

        i = 0
        x = 0
        y = 0

        while x < len(left) and y < len(right):
            if left[x] < right[y]:
                array[i] = left[x]
                x += 1
                i += 1
            else:
                array[i] = right[y]
                y += 1
                i += 1

        while x < len(left):
            array[i] = left[x]
            x += 1
            i += 1

        while y < len(right):
            array[i] = right[y]
            y += 1
            i += 1

        return array
