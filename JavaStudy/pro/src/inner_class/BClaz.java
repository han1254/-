package inner_class;

public class BClaz extends AClaz {


    public IRet getRet(int a) {
        System.out.println("运行了B");
        return new ClazInner();
    }

    public class ClazInner implements IRet {

        @Override
        public void add() {

        }

        @Override
        public int out() {
            return 1;
        }
    }
}
