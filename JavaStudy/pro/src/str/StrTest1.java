package str;

import java.util.Arrays;

public class StrTest1 {

    public static void main(String[] args) {
        String str = "Hello World";
        StringBuilder sb = new StringBuilder("Hello World");
        System.out.println(sb.toString().equals(str));
        System.out.println(reverseWords("Let's take LeetCode contest"));
        System.out.println("*" + trans("    h  i ".trim(), 4) + "*");

        System.out.println(Arrays.toString("    a     ".split(" ")));
    }

    private static void strTest2() {



    }

    public static String trans(String s, int n) {
        // write code here
        String[] splitRes = s.split(" ");
        StringBuilder sb = new StringBuilder();
//         if(s.charAt(s.length() - 1) == ' ') {
//             sb.append(' ');
//         }
        for(int i = splitRes.length - 1; i >= 0; i--) {
            for(char t : splitRes[i].toCharArray()) {
                if(t >= 'a' && t <= 'z') {
                    t += 'A' - 'a';
                } else  {
                    t -= 'A' - 'a';
                }
                sb.append(t);
            }
            if(i > 0) {
                sb.append(' ');
            }

        }
        return sb.toString();
    }

    public static String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        StringBuilder tempSb = new StringBuilder();
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == ' ') {
                tempSb.reverse();
                tempSb.append(' ');
                sb.append(tempSb.toString());
                tempSb = new StringBuilder();
            } else {
                tempSb.append(s.charAt(i));
            }
        }
        sb.append(tempSb.toString());
        return sb.toString();
    }
}
