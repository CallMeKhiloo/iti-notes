package controllers;

import utils.ItemNotFoundException;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.Scanner;

import models.Book;
import models.Client;
import models.Library;
import models.LibraryItem;
import models.Magazine;

public class Menu {
    private Library<LibraryItem> library;
    private ArrayList<Client> clients;
    private Scanner sc;

    public Menu(Library<LibraryItem> library, ArrayList<Client> clients) {
        this.library = library;
        this.clients = clients;
        this.sc = new Scanner(System.in);
    }

    public void start() {
        while (true) {
            System.out.println("\n=== Main Menu ===");
            System.out.println("1. Library Menu");
            System.out.println("2. Client Menu");
            System.out.println("3. Exit");
            int choice = readInt("Choose an option: ", 1, 3);

            switch (choice) {
                case 1:
                    libraryMenu();
                    break;
                case 2:
                    clientMenu();
                    break;
                case 3:
                    System.out.println("Exiting system...");
                    return;
            }
        }
    }

    private void libraryMenu() {
        while (true) {
            System.out.println("\n=== Library Menu ===");
            System.out.println("1. Book Menu");
            System.out.println("2. Magazine Menu");
            System.out.println("3. Back to Main Menu");
            int choice = readInt("Choose an option: ", 1, 3);

            switch (choice) {
                case 1:
                    itemCrudMenu(library, "Book");
                    break;
                case 2:
                    itemCrudMenu(library, "Magazine");
                    break;
                case 3:
                    return;
            }
        }
    }

    private <T extends LibraryItem> void itemCrudMenu(Library<LibraryItem> library, String typeName) {
        while (true) {
            System.out.println("\n=== " + typeName + " Menu ===");
            System.out.println("1. Add " + typeName);
            System.out.println("2. View Items");
            System.out.println("3. Update Item Title");
            System.out.println("4. Delete Item");
            System.out.println("5. Back to Library Menu");
            int choice = readInt("Choose an option: ", 1, 5);

            switch (choice) {
                case 1:
                    String id = readString("Enter ID: ");
                    String title = readName("Enter Title: ");
                    if (typeName.equals("Book")) {
                        while (!library.addItem(new Book(id, title))) {
                            id = readString("You entered a duplicate Id, Enter a unique Id plz!!\n");
                        }
                    } else {
                        while (!library.addItem(new Magazine(id, title))) {
                            id = readString("You entered a duplicate Id, Enter a unique Id plz!!\n");
                        }
                    }
                    System.out.println(typeName + " added successfully.");
                    break;

                case 2:
                    library.displayItems();
                    break;

                case 3:
                    String updateId = readString("Enter ID of item to update: ");
                    String newTitle = readName("Enter new title: ");
                    try {
                        library.updateItemTitle(updateId, newTitle);
                        System.out.println("Title updated successfully.");
                    } catch (ItemNotFoundException e) {
                        System.out.println(e.getMessage());
                    }
                    break;

                case 4:
                    String deleteId = readString("Enter ID of item to delete: ");
                    try {
                        boolean deleted = library.deleteItem(deleteId);
                        if (deleted)
                            System.out.println("Item deleted successfully.");
                    } catch (ItemNotFoundException e) {
                        System.out.println(e.getMessage());
                    }
                    break;

                case 5:
                    return;
            }
        }
    }

    private void clientMenu() {
        while (true) {
            System.out.println("\n=== Client Menu ===");
            System.out.println("1. Add Client");
            System.out.println("2. View Clients");
            System.out.println("3. Update Client");
            System.out.println("4. Delete Client");
            System.out.println("5. Back to Main Menu");
            int choice = readInt("Choose an option: ", 1, 5);

            switch (choice) {
                case 1:
                    String id = readString("Enter ID: ");
                    String name = readName("Enter Name: ");
                    String email = readEmail("Enter Email: ");
                    while (findClientById(id) != null) {
                        id = readString("You entered a duplicate Id, please enter a unique one: ");
                    }
                    clients.add(new Client(id, name, email));
                    System.out.println("Client added successfully.");
                    break;

                case 2:
                    if (clients.isEmpty()) {
                        System.out.println("No clients found.");
                    } else {
                        for (Client client : clients) {
                            client.getClientDetails(client.getId());
                        }
                    }
                    break;

                case 3:
                    String updateId = readString("Enter ID of client to update: ");
                    Client clientToUpdate = findClientById(updateId);
                    if (clientToUpdate != null) {
                        String newName = readName("Enter new name: ");
                        String newEmail = readEmail("Enter new email: ");
                        clientToUpdate.setName(newName);
                        clientToUpdate.setEmail(newEmail);
                        System.out.println("Client updated successfully.");
                    } else {
                        System.out.println("Client not found.");
                    }
                    break;

                case 4:
                    String deleteId = readString("Enter ID of client to delete: ");
                    Client clientToDelete = findClientById(deleteId);
                    if (clientToDelete != null) {
                        clients.remove(clientToDelete);
                        System.out.println("Client deleted successfully.");
                    } else {
                        System.out.println("Client not found.");
                    }
                    break;

                case 5:
                    return;
            }
        }
    }

    private Client findClientById(String id) {
        for (Client client : clients) {
            if (client.getId().equals(id))
                return client;
        }
        return null;
    }

    private int readInt(String prompt, int min, int max) {
        while (true) {
            try {
                System.out.print(prompt);
                int value = Integer.parseInt(sc.nextLine());
                if (value < min || value > max) {
                    System.out.println("Input must be between " + min + " and " + max);
                    continue;
                }
                return value;
            } catch (NumberFormatException e) {
                System.out.println("Invalid input! Please enter a number.");
            }
        }
    }

    private String readString(String prompt) {
        System.out.print(prompt);
        String input = sc.nextLine().trim();
        while (true) {
            if (input.isEmpty()) {
                System.out.println("Input cannot be empty. Please try again.");
                input = sc.nextLine().trim();
            } else
                return input;
        }
    }

    private String readEmail(String prompt) {
        String input = readString(prompt);
        while (true) {
            String regexString = "^[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,6}$";
            Pattern ptrn = Pattern.compile(regexString, Pattern.CASE_INSENSITIVE);

            Matcher matcher = ptrn.matcher(input);
            if (!matcher.matches()) {
                System.out.println("Email is not valid. Please try again.");
                input = sc.nextLine().trim();
                continue;
            }
            return input;
        }
    }

    private String readName(String prompt) {
        String input = readString(prompt);
        while (true) {
            Boolean isvalid = true;
            for (char c : input.toCharArray()) {
                if (c != ' ' && !Character.isLetter(c)) {
                    System.out.println("Name cannot have numbers or special characters. Please try again.");
                    isvalid = false;
                    break;
                }
            }
            if (isvalid)
                return input;
            input = sc.nextLine().trim();
        }
    }
}