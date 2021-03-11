package enum_test;

public class Test {

    public static void main(String[] args) {
        System.out.println(searchMatrix(new int[][]{{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 3));

    }
    public static void main() {



    }

    public static boolean searchMatrix(int[][] matrix, int target) {
        int left = 0;
        int right = matrix.length * matrix[0].length - 1;
        int col = matrix[0].length;
        while(left <= right) {
            int mid = (left + right) >> 1;
            int i = mid / col;
            int j = mid % col;
            if(target > matrix[i][j]) {
                left = mid + 1;
            } else if(target < matrix[i][j]) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
