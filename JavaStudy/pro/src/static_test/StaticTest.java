package static_test;

public class StaticTest {

    public static void main(String[] args) {
        new Man();
    }
}

class Tool {

    private String owner = "";
    public Tool(String owner) {
        this.owner = owner;
        System.out.println("I am a tool of " + owner + ":constructor");
    }
}

class Person {


    static {
        System.out.println("I am a person:static");
    }

    // 代码块和成员的构造函数先后顺序会改变
    {
        System.out.println("I am a person:normal");
    }
    Tool tool = new Tool("Person");

    public Person() {
        System.out.println("I am a person:constructor");
    }
}

class Man extends Person {
    Tool tool = new Tool("Man");
    static {
        System.out.println("I am a man:static");
    }

    {
        System.out.println("I am a man:normal");
    }

    public Man() {
        System.out.println("I am a man:constructor");
    }
}
