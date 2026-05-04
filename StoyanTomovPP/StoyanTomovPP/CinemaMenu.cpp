#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../StaticLibrary1/AdminPanel.h"

using namespace std;

void printMenu() {
    ifstream file("CinemaMenu.txt");
    if (!file) {
        cout << "Error: Could not open CinemaMenu.txt\n";
        return;
    }
    cout << file.rdbuf();
}

void moviesSection() {
    cout << "\n===== MOVIES SECTION =====\n";
    if (movies.empty()) {
        cout << "No movies currently showing.\n";
    }
    else {
        for (int i = 0; i < (int)movies.size(); i++) {
            cout << i + 1 << ". " << movies[i].name << endl;
        }
    }
    cout << "\nPress Enter to return...";
    cin.ignore();
    cin.get();
}

int main() {
    int choice;
    while (true) {
        printMenu();
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) moviesSection();
        else if (choice == 3) showtimesSection();
        else if (choice == 5) adminPanel();
        else if (choice == 6) break;
    }
    return 0;
}