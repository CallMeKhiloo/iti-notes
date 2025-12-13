import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) {
        ArrayList<Student> students = new ArrayList<>();
        ArrayList<Course> courses = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);

        boolean exit = false;

        while (!exit) {
            System.out.println("=== Student Registration System ===");
            System.out.println("1. Student Management");
            System.out.println("2. Course Management");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // for new line

            switch (choice) {
                case 1:
                    studentMenu(scanner, students, courses);
                    break;
                case 2:
                    courseMenu(scanner, courses);
                    break;
                case 3:
                    exit = true;
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
        scanner.close();
    }

    private static void studentMenu(Scanner sc, ArrayList<Student> students, ArrayList<Course> courses) {
        boolean back = false;
        while (!back) {
            System.out.println("\n--- Student Management ---");
            System.out.println("1. Add new student");
            System.out.println("2. Register student for courses");
            System.out.println("3. Print student report");
            System.out.println("4. Back to main menu");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    // Add student
                    System.out.print("Enter student ID: ");
                    int id;
                    while (true) {
                        try {
                            id = Integer.parseInt(sc.nextLine());
                            break;
                        } catch (Exception e) {
                            System.out.println("invalid argument ID, Enter a valid number");
                        }
                    }
                    while (isDupilcateStudentId(students, id)) {
                        System.out.println("Duplicate student ID !!!!!\nEnter a unique ID: ");
                        id = sc.nextInt();
                    }
                    System.out.print("Enter student name: ");
                    String name = sc.nextLine();
                    students.add(new Student(id, name)); // autoboxing with id
                    System.out.println("Student added successfully!");
                    break;
                case 2:
                    // Register student for courses
                    System.out.print("Enter student ID: ");
                    int stuId = sc.nextInt();
                    sc.nextLine();
                    Student student = findStudentById(students, stuId);
                    if (student == null) {
                        System.out.println("Student not found!");
                        break;
                    }
                    // Show available courses
                    if (courses.isEmpty()) {
                        System.out.println("No courses available.");
                        break;
                    }
                    System.out.println("Available courses:");
                    for (Course c : courses) {
                        System.out.println(c.getCourseId() + " - " + c.getCourseName());
                    }
                    // Enter courses as comma-separated IDs
                    System.out.print("Enter course IDs to register (comma separated without spaces): ");
                    String line = sc.nextLine();
                    StringTokenizer st = new StringTokenizer(line, ",");
                    while (st.hasMoreTokens()) {
                        int cid = Integer.parseInt(st.nextToken().trim());
                        Course course = findCourseById(courses, cid);
                        if (course != null) {
                            System.out.print("Enter grade for " + course.getCourseName() + " (or leave blank): ");
                            String gradeInput = sc.nextLine();
                            Double grade = gradeInput.isEmpty() ? null : Double.parseDouble(gradeInput);
                            student.registerCourse(course, grade);
                        } else {
                            System.out.println("Course ID " + cid + " not found.");
                        }
                    }
                    break;
                case 3:
                    // Print student report
                    System.out.print("Enter student ID: ");
                    int reportId = sc.nextInt();
                    sc.nextLine();
                    Student s = findStudentById(students, reportId);
                    if (s != null) {
                        s.printReport();
                    } else {
                        System.out.println("Student not found!");
                    }
                    break;
                case 4:
                    back = true;
                    break;
                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }

    private static void courseMenu(Scanner sc, ArrayList<Course> courses) {
        boolean back = false;
        while (!back) {
            System.out.println("\n--- Course Management ---");
            System.out.println("1. Add new course");
            System.out.println("2. View all courses");
            System.out.println("3. Back to main menu");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter course ID: ");
                    int cid;
                    while (true) {
                        try {
                            cid = Integer.parseInt(sc.nextLine());
                            break;
                        } catch (Exception e) {
                            System.out.println("invalid argument ID, Enter a valid number");
                        }
                    }
                    while (isDupilcateCourseId(courses, cid)) {
                        System.out.println("Duplicate course ID !!!!!\nEnter a unique ID: ");
                        cid = sc.nextInt();
                    }
                    System.out.print("Enter course name: ");
                    String cname = sc.nextLine();
                    System.out.print("Enter credit hours: ");
                    int credits;
                    while (true) {
                        try {
                            credits = Integer.parseInt(sc.nextLine());
                            break;
                        } catch (Exception e) {
                            System.out.println("invalid argument credit hours, Enter a valid number");
                        }
                    }
                    courses.add(new Course(cid, cname, credits));
                    System.out.println("Course added successfully!");
                    break;
                case 2:
                    if (courses.isEmpty()) {
                        System.out.println("No courses available.");
                    } else {
                        System.out.println("Courses:");
                        for (Course c : courses) {
                            System.out.println(c.getCourseId() + " - " + c.getCourseName() + " (" + c.getCreditHours()
                                    + " credits)");
                        }
                    }
                    break;
                case 3:
                    back = true;
                    break;
                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }

    private static Student findStudentById(ArrayList<Student> students, int id) {
        for (Student s : students) {
            if (s.getId() == id)
                return s; // unboxing happens here ya m3lm
        }
        return null;
    }

    private static boolean isDupilcateStudentId(ArrayList<Student> students, int id) {
        for (Student s : students) {
            return s.getId() == id; // unboxing
        }
        return false;
    }

    private static boolean isDupilcateCourseId(ArrayList<Course> courses, int id) {
        for (Course c : courses) {
            return c.getCourseId() == id; // unboxing
        }
        return false;
    }

    private static Course findCourseById(ArrayList<Course> courses, int id) {
        for (Course c : courses) {
            if (c.getCourseId() == id)
                return c; // also here
        }
        return null;
    }
}