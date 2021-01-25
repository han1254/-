package reflect_study;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Scanner;
import java.util.logging.FileHandler;

public class GetTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String pac = scanner.nextLine();
        pac = "reflect_study.ClassB";
        try {
            Class<?> aClass = Class.forName(pac);
            printConstructor(aClass);
            printFields(aClass);
            printMethods(aClass);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    public static void printConstructor(Class cl) {
        Constructor[] constructors = cl.getConstructors();
        for (Constructor c : constructors) {
            String s = Modifier.toString(c.getModifiers());
            if (s.length() > 0) {
                System.out.print(s + " ");
            }
            System.out.print(c.getName() + "(");
            Class[] parameterTypes = c.getParameterTypes();
            for (int i = 0; i < parameterTypes.length; i++) {
                if (i > 0) {
                    System.out.print(", ");
                }
                System.out.print(parameterTypes[i].getName());
            }
            System.out.println(");");
        }
        System.out.println();
    }
    public static void printFields(Class cl) {
        Field[] fields = cl.getFields();
        for (Field f : fields) {
            String s = Modifier.toString(f.getModifiers());
            if (s.length() > 0) {
                System.out.print(s + " ");
            }
            Class<?> type = f.getType();
            System.out.print(type.getName() + " ");
            System.out.println(f.getName() + ";");
        }
    }

    public static void printMethods(Class cl) {
        Method[] methods = cl.getDeclaredMethods();
        for(Method m : methods) {
            String s = Modifier.toString(m.getModifiers());
            if (s.length() > 0) {
                System.out.print(s + " ");
            }
            Class<?> returnType = m.getReturnType();
            System.out.print(returnType.getName() + " " + m.getName() + " (");
            Class<?>[] parameterTypes = m.getParameterTypes();
            for (int i = 0; i < parameterTypes.length; i++) {
                if (i > 0) {
                    System.out.print(", ");
                }
                System.out.print(parameterTypes[i].getName());
            }
            System.out.println(");");
        }
    }
}
