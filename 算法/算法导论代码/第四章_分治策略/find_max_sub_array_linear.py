'''
《算法导论》中文版第三版 p74 4.1-5 最大子数组问题(线性时间)
'''
def find_maximum_subarray(A):
    bundary_max = A[0]
    bundary_left = 0
    bundary_right = 0
    global_max = A[0]
    global_left = 0
    global_right = 0
    for i in range(1, len(A)):
        if bundary_max + A[i] > A[i]:
            bundary_max = bundary_max + A[i]
            bundary_right = i
        else:
            bundary_max = A[i]
            bundary_left = i
            bundary_right = i
        if bundary_max > global_max:
            global_max = bundary_max
            global_left = bundary_left
            global_right = bundary_right
            
    return global_left, global_right, global_max

if __name__ == '__main__':
    a = [100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97]
    A = a[1:len(a)]
    tempA = a[:len(a) - 1]
    for i in range(len(A)):
        A[i] = A[i] - tempA[i]
    result = find_maximum_subarray(A)
    # (result[0] + 1) - 1)：比如我们计算的结果是7-10，本质意思是A[7] + ... + A[10]的这个子数组和最大，但是
    # A[7]记录的是第8（数组下标从零开始，所以A[7]是第8个数据）天的价格与第7天的差值，我们应该从第7天买入，所以
    # 减一（加一只是为了还原在数组中本来的位置）；
    # 
    # 而result[1]不变，只需要加一还原真实的位置即可
    #
    print(str((result[0] + 1) - 1) + '--->' + str(result[1] + 1) + '==>' + str(result[2]))
