package reflect_study;

import java.lang.reflect.Array;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.ArrayList;

public class ObjectAnalyzer {

    private ArrayList<Object> visited = new ArrayList<>();

    public String toString(Object obj) {
        if (obj == null) {
            return null;
        }
        if (visited.contains(obj)) {
            return "...";
        }
        visited.add(obj);
        Class<?> aClass = obj.getClass();
        if (aClass == String.class) {
            return (String)obj;
        }
        if (aClass.isArray()) {
            String r = aClass.getComponentType() + "[]{";
            for (int i = 0; i < Array.getLength(obj); i++) {
                if (i > 0) {
                    r += ",";
                }
                Object val = Array.get(obj, i);
                if (aClass.getComponentType().isPrimitive()) {
                    r += val;
                } else {
                    r += toString(val);
                }
            }
            return r + "}";
        }
        String r = aClass.getName();
        do {
            r += "[";
            Field[] declaredFields = aClass.getDeclaredFields();
            for (Field f : declaredFields) {
                if (!Modifier.isStatic(f.getModifiers())) {
                    if (!r.endsWith("[")) {
                        r += ",";
                    }
                    r += f.getName() + "=";
                    Class<?> type = f.getType();
                    try {
                        Object val = f.get(obj);
                        if (type.isPrimitive()) {
                            r += val;
                        } else {
                            r += toString(val);
                        }
                    } catch (IllegalAccessException e) {
                        e.printStackTrace();
                    }
                }
                r += "]";
                aClass = aClass.getSuperclass();
            }

        } while (aClass != null);
        return r;
    }
}
