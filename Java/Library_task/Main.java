import java.util.ArrayList;

import models.Client;
import models.Library;
import models.LibraryItem;
import controllers.Menu;


public class Main {
    public static void main(String args[]) {
        Library<LibraryItem> library = new Library<>();
        ArrayList<Client> clients = new ArrayList<>();

        Menu menu = new Menu(library, clients);
        menu.start();
    }
} 