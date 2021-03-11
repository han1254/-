package collection_study;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class LinkedListTest {
    public static void main(String[] args) {
        List<String> a = new LinkedList<>();
        a.add("Amy");
        a.add("ZhangSan");
        a.add("NiuLili");
        List<String> b = new LinkedList<>();
        b.add("Bob");
        b.add("Doug");
        b.add("Frances");
        b.add("Gloria");
        ListIterator<String> aIter = a.listIterator();
        Class<? extends ListIterator> aClass = aIter.getClass();
        System.out.println(aClass.getName());
        System.out.println("当前的nextIndex:" + aIter.nextIndex());
        Iterator<String> bIter = b.iterator();
        while(bIter.hasNext()) {
            System.out.println("..................................");
            System.out.println("进入循环，当前的nextIndex为:" + aIter.nextIndex());
            if (aIter.hasNext()) {
                aIter.next();
            }
            System.out.println("添加前的nextIndex:" + aIter.nextIndex());
            aIter.add(bIter.next());
            System.out.println("添加后的nextIndex:" + aIter.nextIndex());
            System.out.println("..................................");
        }
        System.out.println(a);
    }
}
