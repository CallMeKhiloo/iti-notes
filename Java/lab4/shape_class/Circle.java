public class Circle extends Shape {
    private Integer radius;

    public Integer getRadius() {
        return radius;
    }

    public void setRadius(Integer r) {
        radius = r;
    }

    @Override
    public void draw() {
        System.out.println("This is a Cicle with radius = "+getRadius());
    }
}