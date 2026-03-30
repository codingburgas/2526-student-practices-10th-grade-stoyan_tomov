#include <iostream>
#include <fstream>
#include "../StaticLibrary1/AdminPanel.h"
using namespace std;

void printMenu()
{
    ifstream file("CinemaMenu.txt");
    if (!file)
    {
        cout << "Error: Could not open CinemaMenu.txt\n";
        return;
    }
    cout << file.rdbuf();
}

void moviesSection()
{
    cout << "\n===== MOVIES SECTION =====\n";
    cout << "This is where movies will be shown.\n\n";
}

int main()
{
    int choice;

    while (true)
    {
        printMenu();

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            moviesSection();
        }
        else if (choice == 5)
        {
            adminPanel();
        }
        else if(choice == 6)
        {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Option not added yet\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}

