package inner_class;

public class AClaz implements IClaz {


    @Override
    public IRet getRet() {
        return getRet(0);
    }

    public IRet getRet(int a) {
        System.out.println("运行了AClaz");
        return new ClazInner();
    }

    public class ClazInner implements IRet {

        @Override
        public void add() {

        }

        @Override
        public int out() {
            return 0;
        }
    }
}
