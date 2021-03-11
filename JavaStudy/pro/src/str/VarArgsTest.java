package str;

public class VarArgsTest {
    public static void m1(String s, String... ss) {
        System.out.println(s);
        for (int i = 0; i < ss.length; i++) {
            System.out.println(ss[i]);
        }
    }

    public static void main(String[] args) {

//        m1("");
//        m1("aaa");
//        m1("aaa", "bbb");
        String a = "hello" + "2";
        String b = "hell" + "o2";
        System.out.println(a == b);
        final String c = "hello";
        final String d = "2";
        System.out.println(a == (c + d));

        int[] arr = new int[]{1332802,1177178,1514891,871248,
                753214,123866,1615405,328656,1540395,968891,
                1884022,252932,1034406,1455178,821713,486232,
                860175,1896237,852300,566715,1285209,1845742,
                883142,259266,520911,1844960,218188,1528217,
                332380,261485,1111670,16920,1249664,1199799,
                1959818,1546744,1904944,51047,1176397,190970,
                48715,349690,673887,1648782,1010556,1165786,937247,
                986578,798663};


    }

    private int k = -1;
    int res = -1;
    public int findKth(int[] a, int n, int K) {
        // write code here
        k = K;
        quickSort(a, 0, a.length - 1);
        return res;
    }

    public void quickSort(int[] arr, int left, int right) {
        if(left == right && left == k - 1) {
            res = arr[k - 1];
            return;
        }
        if(left < right) {
            int pivot = partition(arr, left, right);
            quickSort(arr, left, pivot - 1);
            quickSort(arr, pivot + 1, right);
        }
    }

    public int partition(int[] arr, int left, int right) {
        int pivot = left;
        int index = left + 1;
        for(int i = index; i <= right; i++) {
            if(arr[i] > arr[pivot]) {
                int temp = arr[index];
                arr[index] = arr[i];
                arr[i] = temp;
                index++;
            }
        }
        int temp = arr[pivot];
        arr[pivot] = arr[index - 1];
        arr[index - 1] = temp;
        return index - 1;
    }

}
