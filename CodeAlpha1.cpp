#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class task
{
private:
    string desc;   // Description of the task
    string status; // Current_Status of the task

public:
    task(string val1, string val2 = "To be Done") : desc(val1), status(val2)
    {
    }

    ~task() = default;

    string get_desc() { return desc; }
    string get_status() { return status; }
    void change_status(string val1) { status = val1; } 
};

void add_task(vector<task> &vec, string val1, string val2 = "To Be Done") // Add a task into the task_list
{

    vec.push_back(task(val1, val2));
    cout << "Task Added Successfully!!" << endl;
}

void line(int n) // A simple line used for formatting
{
    for (int i(0); i < n; i++)
    {
        cout << '-';
    }
    cout << "+" << endl;
}

void display_tasks(vector<task> &vec) // Display list of the tasks in a formmated way(SQL)
{

    line(140);

    cout << setw(105) << left << "Task Description"
         << "  |  "
         << setw(30) << "Status"
         << "|" << endl;

    line(140);

    for (int i(0); i < vec.size(); i++)
    {
        cout << setw(5) << i + 1 << setw(100) << left << vec[i].get_desc() << "  |  " << setw(30) << vec[i].get_status() << "|" << endl;
    }

    line(140);
}

void remove_task(vector<task> &vec, int index) // Remove a task from the task_list at a given index
{
    vec.erase(vec.begin() + (index - 1));
    cout << "Task Removed Successfully!!" << endl;
}

void change_task_status(vector<task> &vec, int index, string val1) // Change task Status at a given index
{
    vec[index - 1].change_status(val1);
}

void start()
{
    vector<task> task_list;
    int choice;
    do
    {
        cout << "1. Add Task\n2. Remove Task\n3. Change Task Status\n4. Display Tasks\n5. Quit\nEnter your choice: ";
        cin >> choice;
        string desc, status;
        int index;

        switch (choice)
        {
        case 1:
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, desc);
            cout << "Enter task status (or leave empty for default 'To Be Done'): ";
            getline(cin, status);
            if (status.empty())
            {
                add_task(task_list, desc);
            }
            else
            {
                add_task(task_list, desc, status);
            }
            break;
        case 2:
            cout << "Enter task number to remove: ";
            cin >> index;
            remove_task(task_list, index);
            break;
        case 3:
            cout << "Enter task number to change status: ";
            cin >> index;
            cout << "Enter new status: ";
            cin.ignore();
            getline(cin, status);
            change_task_status(task_list, index, status);
            break;
        case 4:
            display_tasks(task_list);
            break;
        case 5:
            cout << "Quitting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);
}

int main()
{
    start();

    return 0;
}