import java.util.*;
public class QuickSort {
	public static void main(String[] args) {
		int[] quickArray = new int[]{9, 8, 4, 6, 5, 7, 1, 2, 3, 47, 99, 0, 52, -8};
		quickSort(quickArray);
		System.out.println(Arrays.toString(quickArray));
	}

	/**
	 * [补充：快速排序]
	 * @param arr 
	 */
	public static void quickSort(int[] arr) {
		quickSort(arr, 0, arr.length - 1);
	}

	public static void quickSort(int[] arr, int start, int end) {
		if (start >= end) {
			return;
		}
		int partitionIndex = partition(arr, start, end);
		quickSort(arr, start, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, end);
	}

	public static int partition(int[] arr, int start, int end) {
		int pivot = start;
		int smallerThanPiovtIndex = pivot + 1;
		for (int i = smallerThanPiovtIndex; i <= end; i++) {
			if (arr[i] < arr[pivot]) {
				swap(arr, i, smallerThanPiovtIndex++);
			}
		}
		// swap the last number that smaller than pivot whith the pivot
		swap(arr, pivot, --smallerThanPiovtIndex);
		return smallerThanPiovtIndex;
	}

	public static void swap(int[] arr, int pos1, int pos2) {
		int temp = arr[pos1];
		arr[pos1] = arr[pos2];
		arr[pos2] = temp;
	}
}
