import java.util.Map;
import java.util.TreeMap;
import java.util.SortedSet;
import java.util.TreeSet;

public class Dictionary {
    private Map<Character, SortedSet<String>> mp;

    public Dictionary() {
        mp = new TreeMap<>();
    }

    public void printAll() {
        System.out.println("The Dictionary contents : ");
        for (Character c : mp.keySet()) {
            System.out.println("key " + c + " has values: ");
            for (String s : mp.get(c))
                System.out.println("    " + s);
        }
    }

    public void printSpecific(Character key) {
        System.out.println("Key " + key + " has values: ");
        for (String s : mp.get(key))
            System.out.println("    " + s);
    }

    public void add(String word) {
        char key = Character.toUpperCase(word.charAt(0));

        mp.putIfAbsent(key, new TreeSet<>());
        mp.get(key).add(word);
    }

}