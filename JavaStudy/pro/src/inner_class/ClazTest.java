package inner_class;

public class ClazTest {
    public static void main(String[] args) {
        IClaz a = new BClaz();
        IRet ret = a.getRet();
        Class<? extends IRet> aClass = ret.getClass();
        System.out.println(aClass.getName());
    }
}
