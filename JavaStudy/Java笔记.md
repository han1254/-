## 反射

### 1. Constructor、Method、Field

### 2. 设置访问权限

方法一：调用Field、Method或者Constructor对象的setAccessible方法

方法二：（将所有的field设置为可访问）AssessibleObject.setAccessible(fields, true);

### 3. 几种方法

Class

`getComponentType()`获得数组的单个元素的类型，返回Class

`isPrimitive`类型是否为基本类型

### 4. 使用反射编写泛型数组代码

```java

```





### 5. invoke调用静态方法

```java
double dx = (to - from) / (n - 1);
for(double x = from; x <= to; x += dx) {
    double y = (Double)f.invoke(null, x);
    
}
```

