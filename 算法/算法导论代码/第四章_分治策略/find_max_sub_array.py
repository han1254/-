import sys
import math


def find_max_crossing_subarray(A, low, mid, high):
    left_sum = -sys.maxsize - 1
    temp_sum = 0
    max_left = mid
    max_right = mid + 1
    for i in range(mid, low - 1, -1):
        temp_sum = temp_sum + A[i]
        if temp_sum > left_sum:
            left_sum = temp_sum
            max_left = i

    right_sum = -sys.maxsize - 1
    temp_sum = 0
    for j in range(mid + 1, high + 1, 1):
        temp_sum = temp_sum + A[j]
        if temp_sum > right_sum:
            right_sum = temp_sum
            max_right = j

    return max_left, max_right, left_sum + right_sum

'''
《算法导论》中文版第三版 p67 4.1 最大子数组问题
'''
def find_maximum_subarray(A, low, high):
    if high == low:
        return low, high, A[low]
    else:
        mid = math.floor((low + high) / 2)
        (left_low, left_high, left_sum) = find_maximum_subarray(A, low, mid)
        (right_low, right_high, right_sum) = find_maximum_subarray(A, mid + 1, high)
        (cross_low, cross_high, cross_sum) = find_max_crossing_subarray(A, low, mid, high)
        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum


if __name__ == '__main__':
    a = [100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97]
    A = a[1:len(a)]
    tempA = a[:len(a) - 1]
    for i in range(len(A)):
        A[i] = A[i] - tempA[i]

    print(find_maximum_subarray(A, 0, len(A) - 1))
