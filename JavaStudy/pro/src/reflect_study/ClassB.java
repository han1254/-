package reflect_study;

public class ClassB extends ClassA {

    public int b;
    public ClassB(int a, int b) {
        super(a);
        this.b = b;
    }
    public ClassB(int a) {
        super(a);
        b = 0;
    }
    public void methodB() {
        System.out.println("this is B");
    }

    private void privateB() {
        System.out.println("this is private B");
    }
}
