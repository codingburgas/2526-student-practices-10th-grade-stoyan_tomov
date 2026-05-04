#include <iostream>
#include <vector>
#include <string>
#include "AdminPanel.h"

using namespace std;

// Removed 'static' so menu.cpp can see this
vector<string> movies;

void listMovies() {
    if (movies.empty()) {
        cout << "No movies available.\n";
        return;
    }
    cout << "\n----- MOVIE LIST -----\n";
    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i] << endl;
    }
    cout << "-----------------------\n";
}

void addMovie() {
    cout << "Enter movie name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    movies.push_back(name);
    cout << "Movie added successfully.\n";
}

void removeMovie() {
    if (movies.empty()) {
        cout << "No movies to remove.\n";
        return;
    }
    listMovies();
    cout << "Enter movie number to remove: ";
    int index;
    cin >> index;
    if (index < 1 || index > movies.size()) {
        cout << "Invalid index.\n";
        return;
    }
    movies.erase(movies.begin() + (index - 1));
    cout << "Movie removed.\n";
}

void movieManagementMenu() {
    int choice = 0;
    while (choice != 4) {
        cout << "\n===== MOVIE MANAGEMENT =====\n";
        cout << "1. Add Movie\n";
        cout << "2. Remove Movie\n";
        cout << "3. List Movies\n";
        cout << "4. Back\n";
        cout << "Select: ";
        cin >> choice;
        switch (choice) {
        case 1: addMovie(); break;
        case 2: removeMovie(); break;
        case 3: listMovies(); break;
        case 4: return;
        default: cout << "Invalid option.\n"; break;
        }
    }
}

void adminPanel() {
    int choice = 0;
    while (choice != 4) {
        cout << "\n===== ADMIN PANEL =====\n";
        cout << "1. Movie Management\n";
        cout << "2. Showtime Management (coming soon)\n";
        cout << "3. System Statistics (coming soon)\n";
        cout << "4. Back\n";
        cout << "Select: ";
        cin >> choice;
        switch (choice) {
        case 1: movieManagementMenu(); break;
        case 2: cout << "Feature not implemented yet.\n"; break;
        case 3: cout << "Feature not implemented yet.\n"; break;
        case 4: return;
        default: cout << "Invalid option.\n"; break;
        }
    }
}