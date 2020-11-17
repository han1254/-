
#补充，汉诺塔问题
def hanoi(left, mid, right, disks_num):
	if disks_num == 1:
		print(left + "-->" + right)
		return
	else:
		hanoi(left, right, mid, disks_num - 1)
		hanoi(left, mid, right, 1)
		hanoi(mid, left, right, disks_num - 1)

if __name__ == '__main__':
	hanoi('A', 'B', 'C', 5)