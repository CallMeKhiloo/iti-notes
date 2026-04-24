import models.Book;
import models.User;
import factory.BookFactory;
import factory.BookFactory.bookType;

public class Main {
    public static void main(String[] args) {
        LibraryService AlexLibrary = LibraryService.GetLibraryInstance();
        LibraryService xLibrary = LibraryService.GetLibraryInstance();
        LibraryService yLibrary = LibraryService.GetLibraryInstance();

        if (AlexLibrary == xLibrary && xLibrary == yLibrary)
            System.out.println("singleton works");

        BookFactory factory = new BookFactory();
        Book book = factory.createBook(bookType.EBOOK, "xxxxxx");
        System.out.println(book.getTitle());

        AlexLibrary.addBook(new Book("Harry Potter"));
        AlexLibrary.addBook(new Book("Lord of the Rings"));

        User user = new User("John", true);

    }
}
