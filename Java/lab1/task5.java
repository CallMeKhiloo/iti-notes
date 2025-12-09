import java.util.Random;
import java.util.Arrays;

public class task5 {
    public static void main(String [] args){
        int size = 1000;
        int[] array = new int[size];
        Random rand = new Random();

        for (int i = 0; i < size; i++) {
            array[i] = rand.nextInt(10000);
        }

        Arrays.sort(array);

        int target = rand.nextInt(20000);
        System.out.println("Target to search: " + target);

        long startTime = System.nanoTime();

        int index = binarySearch(array, target);

        long endTime = System.nanoTime();

        long duration = endTime - startTime;
        if (index != -1) {
            System.out.println("Target found at index: " + index);
        } else {
            System.out.println("Target not found in the array.");
        }
        System.out.println("Binary search running time: " + duration + " nanoseconds");
}
public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

}
