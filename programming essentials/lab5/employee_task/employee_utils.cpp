#include "main.h"

void create_employee()
{
    Employee *emp = new Employee;
    if (emp == NULL)
    {
        cout << "FAILED TO CREATE AN EMPLOYEE" << '\n';
        return;
    }
    if (head == NULL)
        head = emp;
    if (last != NULL)
        last->next = emp;
    last = emp;
    // --- Name input ---
    while (true)
    {
        cout << "Enter the employee's name (1-19 chars): ";
        cin >> ws; // skip leading whitespaces
        cin.getline(emp->name, 20);

        if (strlen(emp->name) == 0)
        {
            cout << "Name cannot be empty. Try again.\n";
            continue;
        }
        break;
    }

    // --- Age input ---
    while (true)
    {
        string line;
        int age;

        cout << "Enter the employee's age : ";
        getline(cin, line);

        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        bool valid = !line.empty();
        for (char c : line)
        {
            if (!isdigit(c))
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            cout << "Input must be ONLY a number.\n";
            continue;
        }

        age = std::stoi(line);
        if (age <= 0)
        {
            cout << "Invalid age. Please enter a number .\n";
            continue;
        }

        emp->age = age;
        break;
    }

    // --- Salary input ---
    while (true)
    {
        string line;
        int salary;

        cout << "Enter the employee's salary (>0): ";
        getline(cin, line);

        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        bool valid = !line.empty();
        for (char c : line)
        {
            if (!isdigit(c))
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            cout << "Input must be ONLY a number.\n";
            continue;
        }

        salary = std::stoi(line);
        if (salary <= 0)
        {
            cout << "Invalid salary. Please enter a positive number.\n";
            continue;
        }

        emp->salary = salary;
        break;
    }

    clearScreen();
    cout << "Employee added successfully!\n";
    emp->next = NULL;
}

void display_employees()
{
    clearScreen();
    Employee *first = head;
    int i = 0;
    while (first != NULL)
    {
        cout << "Employee no: " << i << "\n";
        cout << "Name       : " << first->name << "\n";
        cout << "Age        : " << first->age << "\n";
        cout << "Salary     : " << first->salary << "\n";
        cout << "--------------------------\n";
        first = first->next;
        i++;
    }
    cout << "\n[Press ESC or HOME to return]";
    int key;
    do
    {
        key = getKey();
    } while (key != KEY_ESCAPE && key != KEY_HOME);
}
