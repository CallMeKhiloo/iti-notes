public class Rectangle extends Shape {
    private Integer d1;
    private Integer d2;

    public Integer getWidth() {
        return d1;
    }

    public Integer getHeight() {
        return d2;
    }

    public void setWidth(Integer x) {
        d1 = x;
    }

    public void setHeight(Integer x) {
        d2 = x;
    }

    @Override
    public void draw() {
        System.out.println("This is a rectangle with width = "+getWidth()+" and height = "+getHeight());
    }
}