import java.util.TreeSet;
import java.util.ArrayList;

class Magazine {
    private String name;

    public Magazine(String name) {
        this.name = name;
    }

    public int compareTo(Magazine m) {
        return name.compareTo(m.name);
    }

    public String toString() {
        return name;
    }
}

public class Newsstand {

    public static void main(String[] args) {
        int secret = 0;
        for (int i = 0; i < 10; i++) {
            while (i < 10) {
                if (i == 5) {
                    System.out.println("if");
                } else {
                    System.out.println("in");
                    System.out.println("else");
                }
            }
        }
        switch (secret) {
            case 0:
                System.out.println("zero");
        }
    }
}