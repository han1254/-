package enum_test;

public class EnumTestMain {

    public static void main(String[] args) {
        EnumTest en1 = EnumTest.FIRST;
        EnumTest en2 = EnumTest.SECOND;
        System.out.println(en1.compareTo(en2));
    }
}
