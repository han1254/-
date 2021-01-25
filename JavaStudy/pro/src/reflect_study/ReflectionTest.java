package reflect_study;

import java.io.File;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Date;
import java.util.Scanner;

public class ReflectionTest {
    public static void main(String[] args) {
        String name;
        if(args.length > 0) {
            name = args[0];
        } else {
            Scanner in = new Scanner(System.in);
            System.out.println("Enter class name (e.g. java.util.Date): ");
            name = in.next();
        }
        try {
            Class cl = Class.forName(name);
            Class superCl = cl.getSuperclass();
            String modifier = Modifier.toString(cl.getModifiers());
            if (modifier.length() > 0) {
                System.out.print(modifier + " ");
            }
            System.out.print("class " + name);
            if (superCl != null && superCl != Object.class) {
                System.out.println(" extends " + superCl.getName());
            }
            System.out.println("\n{\n");
            printConstructor(cl);
            System.out.println();
            printMethods(cl);
            System.out.println();
            printFields(cl);
            System.out.println();
            System.out.println("}");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static void printFields(Class cl) {
        Field[] declaredFields = cl.getDeclaredFields();
        for (Field f : declaredFields) {
            Class<?> type = f.getType();
            String name = f.getName();
            System.out.print("  ");
            String s = Modifier.toString(f.getModifiers());
            if (s.length() > 0) {
                System.out.print(s + " ");
            }
            System.out.println(type.getName() + " " + name + ";");
        }
    }

    private static void printMethods(Class cl) {
        Method[] declaredMethods = cl.getDeclaredMethods();
        for (Method m : declaredMethods) {
            Class returnType = m.getReturnType();
            String name = m.getName();
            System.out.print("  ");
            String modifiers = Modifier.toString(m.getModifiers());
            if (modifiers.length() > 0) {
                System.out.print(modifiers + " ");
            }
            System.out.print(returnType.getName() + " " + name + "(");
            Class<?>[] parameterTypes = m.getParameterTypes();
            for (int i = 0; i < parameterTypes.length; i++) {
                if (i > 0) {
                    System.out.print(", ");
                }
                System.out.print(parameterTypes[i].getName());
            }
            System.out.println(")");
        }
    }

    private static void printConstructor(Class cl) {
        Constructor[] declaredConstructors = cl.getDeclaredConstructors();
        for (Constructor c : declaredConstructors) {
            String name = c.getName();
            System.out.print("  ");
            String modifiers = Modifier.toString(c.getModifiers());
            if (modifiers.length() > 0) {
                System.out.print(modifiers + "  ");
            }

            System.out.print(name + "(");
            Class[] parameterTypes = c.getParameterTypes();
            for (int i = 0; i < parameterTypes.length; i++) {
                if (i > 0) {
                    System.out.print(", ");
                }
                System.out.print(parameterTypes[i].getName());
            }
            System.out.println(")");
        }
    }
}
