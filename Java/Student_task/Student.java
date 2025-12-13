import java.util.ArrayList;

public class Student implements StudentActions{
    private Integer id;
    private String name;
    private ArrayList<CourseRegistration> registrations;

    public Student(Integer id, String name){ // no registrations cause it's optional
        this.id = id;
        this.name = name;
        this.registrations = new ArrayList<>();
    }

    public Integer getId(){
        return id;
    }

    public String getName(){
        return name;
    }

    public ArrayList<CourseRegistration> getRegistrations(){
        return registrations;
    }

    @Override
    public void registerCourse(Course course, Double grade){ // grade can be null so it's still optional
        this.registrations.add(new CourseRegistration(course, grade)); // autoboxing with grade is done in main
    }

    @Override
    public void printReport(){
        StringBuilder sb = new StringBuilder();
    sb.append("--- Report for ").append(name)
      .append(" (ID: ").append(id).append(") ---\n");

    if (registrations.isEmpty()) {
        sb.append("No registrations registered.\n");
    } else {
        for (CourseRegistration cr : registrations) {
            sb.append(cr.getCourse().getCourseName())
              .append(": ").append(cr.getGrade()).append("\n");
        }
    }

    sb.append("-----------------------------------");
    
    System.out.println(sb.toString());
    }

    private class CourseRegistration{
        private Course course;
        private Double grade;

        public CourseRegistration(Course course, Double grade){
            this.course = course;
            this.grade = grade;
        }

        public Course getCourse(){
            return course;
        }

        public Double getGrade(){
            return grade;
        }
    }
}