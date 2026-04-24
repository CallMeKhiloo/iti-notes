import java.util.ArrayList;
import java.util.List;

import models.Book;
import models.User;

public class LibraryService {
    private static LibraryService instance;
    private List<Book> books = new ArrayList<>();

    private LibraryService() {

    }

    public static LibraryService GetLibraryInstance() {
        if (LibraryService.instance == null) {
            LibraryService.instance = new LibraryService();
        }
        return LibraryService.instance;
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public Book findBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equalsIgnoreCase(title)) {
                return book;
            }
        }
        return null;
    }

    public void borrowBook(String title, User user) {
        Book book = findBook(title);
        if (book != null) {
            book.borrowBook(user);
        } else {
            System.out.println("Book not found.");
        }
    }

    public void returnBook(String title) {
        Book book = findBook(title);
        if (book != null) {
            book.returnBook();
        } else {
            System.out.println("Book not found.");
        }
    }
}
