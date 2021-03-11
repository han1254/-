package inner_class;

public class Other {

    private Outer.Inner inner;

    public static void main(String[] args) {
        Other other = new Other();
    }

    public Other() {
        Outer outer = new Outer();
        inner = outer.new Inner();

        inner.printStr();
    }
}
