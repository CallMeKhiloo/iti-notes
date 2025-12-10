package lambda_as_argument;

public class Main {
    public static void main(String args[]) {
        System.out.println(betterString("fsdf", "sfadsdfa", (x, y) -> true));
    }

    public static String betterString(String s1, String s2, Operation op) {
        return op.apply(s1, s2) ? s1 : s2;
    }
}
