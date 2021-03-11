package collection_study;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.function.Consumer;

public class RemoveTest {

    public static void main(String[] args) {
        Collection<String> c = new ArrayList<>();
        c.add("a");
        c.add("b");
        c.add("c");
        c.add("d");
        Iterator<String> it = c.iterator();
//        it.next();
        it.remove();
        it.forEachRemaining(s -> {
            System.out.println(s);
        });
    }

}
