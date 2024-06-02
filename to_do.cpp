#include <iostream>
#include <vector>
#include <string>

void display_menu () 
{
    std::cout << "Menu:\n";
    std::cout << "1. Add new task\n";
    std::cout << "2. Display task\n";
    std::cout << "3. Delete tas\n";
    std::cout << "4. Quit\n";
}

void add_new_task(std::vector<std::string>& tasks_list)
{
    std::string task;
    std::cout << "Add a new task: ";
    std::getline(std::cin, task);
    tasks_list.push_back(task);
}

void display_task(std::vector<std::string>& task_list)
{
    std::cout << "Tasks lists:\n";

    for (int i = 0; i < task_list.size(); i++) {
        std::cout << i + 1 << "." << task_list[i] << "\n";
    }
}

void delete_task(std::vector<std::string>& task_list)
{
    int index;
    std::cout<< "Enter task's number to delete: ";
    std::cin >> index;
    std::cin.ignore();

    if (index > 0 && index <= static_cast<int>(task_list.size())) {
        task_list.erase(task_list.begin() + index - 1);
    } else {
        std::cout << "Invalid number.\n";
    }
}

int main () 
{
    std::vector<std::string> tasks_list;
    int choice;

    do {
        display_menu();
        std::cout << "Make a choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1:
            add_new_task(tasks_list);
            break;
        case 2:
            display_task(tasks_list);
            break;
        case 3:
            delete_task(tasks_list);
            break;
        case 4:
            std::cout << "Bye !\n";
        default :
            break;
        }
    } while (choice != 4);
    return 0;
}