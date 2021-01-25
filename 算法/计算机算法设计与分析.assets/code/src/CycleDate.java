public class CycleDate {

    public static void main(String[] args) {

    }

    private static int[][] cycleDate(int k) {
        int n = 1;
        int[][] resTable;
        for (int i = 0; i < k; i++) {
            n *= 2;
        }
        resTable = new int[n][n];
        for (int i = 0; i < n; i++) {
            resTable[0][i] = i + 1;
        }
        int m = 0;

    }

}
