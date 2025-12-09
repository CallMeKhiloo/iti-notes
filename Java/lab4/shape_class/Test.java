import java.util.ArrayList;

public class Test {
    public static void print_shapes(ArrayList<Shape> arr){
        for(Shape s: arr){
            s.draw();
        }
    }
}
