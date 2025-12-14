package models;

public class Magazine extends LibraryItem {

    public Magazine(String id, String title) {
        super(id, title);
    }

    @Override
    public String[] getItemDetails() {
        return new String[] { getId(), getTitle(), String.valueOf(getAvailability()) };
    }
}
