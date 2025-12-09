import java.util.Random;

public class task4 {
    public static void main(String [] args){
        int size = 1000;
        int[] array = new int[size];
        Random rand = new Random();

        for (int i = 0; i < size; i++) {
            array[i] = rand.nextInt(10000);
        }

        long startTime = System.nanoTime();

        int min = array[0];
        int max = array[0];

        for (int i = 1; i < size; i++) {
            if (array[i] < min) min = array[i];
            if (array[i] > max) max = array[i];
        }

        long endTime = System.nanoTime();

        long duration = endTime - startTime;
        System.out.println("Minimum value: " + min);
        System.out.println("Maximum value: " + max);
        System.out.println("Search running time: " + duration + " nanoseconds");
}
}
