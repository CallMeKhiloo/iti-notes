import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {

        ArrayList<Rectangle> rectangles = new ArrayList<>();
        ArrayList<Circle> circles = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        System.out.print("How many rectangles do you want to create? ");
        int rectCount;
        while (true){
            try{
                rectCount = Integer.parseInt(sc.nextLine());
                break;
            }
            catch(Exception e){
                System.out.println("Invalid number!\nEnter a valid number plz");
            }
        }

        for (int i = 0; i < rectCount; i++) {
            System.out.println("Rectangle #" + (i + 1));

            System.out.print("Enter width: ");
            int w = sc.nextInt();

            System.out.print("Enter height: ");
            int h = sc.nextInt();

            Rectangle r = new Rectangle();
            r.setWidth(w);
            r.setHeight(h);

            rectangles.add(r);
        }

        sc.nextLine();

        System.out.print("How many circles do you want to create? ");
        int circleCount;
        while (true){
            try{
                circleCount = Integer.parseInt(sc.nextLine());
                break;
            }
            catch(Exception e){
                System.out.println("Invalid number!\nEnter a valid number plz");
            }
        }

        for (int i = 0; i < circleCount; i++) {
            System.out.println("Circle #" + (i + 1));

            System.out.print("Enter radius: ");
            int radius = sc.nextInt();

            Circle c = new Circle();
            c.setRadius(radius);

            circles.add(c);
        }

        ArrayList<Shape> shapes = new ArrayList<>();
        shapes.addAll(rectangles);
        shapes.addAll(circles);

        Test.print_shapes(rectangles);

        sc.close();
    }
}