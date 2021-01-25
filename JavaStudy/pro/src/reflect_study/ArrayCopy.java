package reflect_study;

import java.lang.reflect.Array;

public class ArrayCopy {

    public static void main(String[] args) {
        Integer[] test = new Integer[]{1, 2, 3, 5, 7, 9, 10, 12, 5};
        Object o = goodCopyOf(test, 5);
    }

    public static Object[] badCopyOf(Object[] a, int newLength) {
        Object[] newArray = new Object[newLength];
        System.arraycopy(a, 0, newArray, 0, Math.min(a.length, newLength));
        return newArray;
    }

    public static Object goodCopyOf(Object[] a, int newLength) {
        Class<? extends Object[]> aClass = a.getClass();
        if (!aClass.isArray()) {
            return null;
        }
        Class<?> componentType = aClass.getComponentType();
        int length = Array.getLength(a);
        Object newArray = Array.newInstance(componentType, newLength);
        System.arraycopy(a, 0, newArray, 0, Math.min(newLength, length));
        return newArray;
    }


}
