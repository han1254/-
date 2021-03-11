package clone_test;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CloneTest {

    static class Test implements Serializable {
        public int a;
        public int b;

        Test(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        List<Test> list = new ArrayList<>();
        list.add(new Test(1, 2));
        list.add(new Test(2, 3));
        list.add(new Test(3, 4));
        System.out.println(deepCopy(list));
    }

    public static <T> T deepCopy(T src) throws IOException, ClassNotFoundException {
        T objRes = null;
        ByteArrayOutputStream boStream = new ByteArrayOutputStream();
        ObjectOutputStream ooStream = new ObjectOutputStream(boStream);
        ooStream.writeObject(src);
        ooStream.close();

        ByteArrayInputStream biStream = new ByteArrayInputStream(boStream.toByteArray());
        ObjectInputStream oiStream = new ObjectInputStream(biStream);
        objRes = (T)oiStream.readObject();
        oiStream.close();
        return objRes;
    }
}
