package inner_class;

public class Outer {
    private int a = 0;
    public int b = 5;
    private String t = "hello";

    public static void main(String[] args) {
        Outer outer = new Outer();
        outer.startTest();
        outer.localInnerTest(1);
    }

    public void startTest() {
        Inner inner = new Inner();
        inner.printStr();
    }

    public class Inner {
        public void printStr() {
            System.out.println(a);
            System.out.println(b);
//            System.out.println(t);
        }
    }

    public void localInnerTest(int value) {
        class LocalInner {
            private int localA = 1;
            private String localS = "lalalal";

            public void printValue() {
                System.out.println(a);
                System.out.println(localA);
                System.out.println(localS);
                if (value == 1) {
                    System.out.println("isTrue");
                } else {
                    System.out.println("isFalse");
                }
            }
        }
        LocalInner localInner = new LocalInner();
        localInner.printValue();
    }
}
