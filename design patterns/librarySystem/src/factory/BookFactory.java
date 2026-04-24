package factory;

import models.Book;
import models.EBook;
import models.HistoricalBook;
import models.PhysicalBook;

public class BookFactory {

    public enum bookType {
        EBOOK,
        HISTORICAL,
        PHYSICAL,
    }

    public Book createBook(bookType type, String title) {
        if (type == bookType.EBOOK)
            return new EBook(title);
        else if (type == bookType.HISTORICAL)
            return new HistoricalBook(title);
        else if (type == bookType.PHYSICAL)
            return new PhysicalBook(title);
        throw new IllegalArgumentException("this is an invalid type: " + type);
    }
}
