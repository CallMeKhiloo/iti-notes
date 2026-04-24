public class Main {
    public static void main(String[] args) {
        LibraryService AlexLibrary = LibraryService.GetLibraryInstance();
        LibraryService xLibrary = LibraryService.GetLibraryInstance();
        LibraryService yLibrary = LibraryService.GetLibraryInstance();

        if (AlexLibrary == xLibrary && xLibrary == yLibrary)
            System.out.println("singleton works");


        AlexLibrary.addBook(new Book("Harry Potter"));
        AlexLibrary.addBook(new Book("Lord of the Rings"));

        User user = new User("John", true);

    }
}
