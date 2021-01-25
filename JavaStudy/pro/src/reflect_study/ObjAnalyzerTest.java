package reflect_study;

public class ObjAnalyzerTest {
    public static void main(String[] args) {
        ClassB b = new ClassB(1);
        System.out.println(new ObjectAnalyzer().toString(b));
    }
}
