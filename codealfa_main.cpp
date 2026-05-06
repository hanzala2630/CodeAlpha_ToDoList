#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Task class
class Task {
public:
    string title;
    bool completed;
};

// Global task list
vector<Task> tasks;

// Load tasks from file
void loadFromFile() {
    ifstream file("tasks.txt");
    Task t;

    while (getline(file, t.title, '|')) {
        file >> t.completed;
        file.ignore();
        tasks.push_back(t);
    }
}

// Save tasks to file
void saveToFile() {
    ofstream file("tasks.txt");

    for (auto &t : tasks) {
        file << t.title << "|" << t.completed << endl;
    }
}

// Add new task
void addTask() {
    Task t;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, t.title);
    t.completed = false;
    tasks.push_back(t);

    cout << "Task Added Successfully!\n";
}

// View all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].title;

        if (tasks[i].completed)
            cout << " [Done]";
        else
            cout << " [Pending]";

        cout << endl;
    }
}

// Mark task as complete
void markComplete() {
    int num;
    cout << "Enter task number: ";
    cin >> num;

    if (num > 0 && num <= tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

// Main function
int main() {
    loadFromFile();

    int choice;

    while (true) {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Complete\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markComplete(); break;
            case 4:
                saveToFile();
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}