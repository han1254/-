
def partition(arr, start, end):
    if start == end:
        return start
    i = start
    j = end
    pivot = arr[start]

    while i < j:
        while i < j and arr[j] > pivot:
            j = j - 1
        while i < j and arr[i] <= pivot:
            i = i + 1
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp

    temp = arr[start]
    arr[start] = arr[i]
    arr[i] = temp
    return i


def quick_sort(arr, start, end):
    print(arr)
    if start == end:
        return
    index = partition(arr, start, end)
    if index > start:
        quick_sort(arr, start, index - 1)
    if index < end:
        quick_sort(arr, index + 1, end)

if __name__ == '__main__':

	t = [3, 100, 56, 32, 11, 9, 5, 2, 999, 13]
    quick_sort(t, 0, len(t) - 1)
    print(t)