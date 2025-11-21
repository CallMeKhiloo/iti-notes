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
        cout << "Enter the employee's age : ";
        cin >> emp->age;

        if (cin.fail() || emp->age <= 0)
        {
            cout << "Invalid age. Please enter a number .\n";
            cin.clear();                                                   // clear error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input from the buffer
            continue;
        }
        break;
    }

    // --- Salary input ---
    while (true)
    {
        cout << "Enter the employee's salary (>0): ";
        cin >> emp->salary;

        if (cin.fail() || emp->salary <= 0)
        {
            cout << "Invalid salary. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

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
