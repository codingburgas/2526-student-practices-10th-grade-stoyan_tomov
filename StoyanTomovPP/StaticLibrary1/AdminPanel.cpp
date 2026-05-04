#include <iostream>
#include <vector>
#include <string>
#include "AdminPanel.h"

using namespace std;

vector<Movie> movies;

// Main Menu Option 3 Logic
void showtimesSection() {
    cout << "\n===== SHOWTIME LIST =====\n";
    if (movies.empty()) {
        cout << "No movies available.\n";
    }
    else {
        for (const auto& m : movies) {
            cout << "MOVIE: " << m.name << "\nSHOWTIMES: ";
            if (m.showtimes.empty()) cout << "TBD";
            else {
                for (const auto& t : m.showtimes) cout << "[" << t << "] ";
            }
            cout << "\n-------------------------\n";
        }
    }
    cout << "Press Enter to go back...";
    cin.ignore();
    cin.get();
}

// --- HELPER FUNCTIONS ---
void listMovies() {
    if (movies.empty()) {
        cout << "No movies in system.\n";
        return;
    }
    for (int i = 0; i < (int)movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].name << endl;
    }
}

// --- MOVIE MANAGEMENT (ADMIN OPTION 1) ---
void addMovie() {
    cout << "Enter movie name: ";
    cin.ignore();
    string n;
    getline(cin, n);
    Movie m; m.name = n;
    movies.push_back(m);
    cout << "Movie added successfully!\n";
}

void removeMovie() {
    if (movies.empty()) {
        cout << "Nothing to remove.\n";
        return;
    }
    listMovies();
    cout << "Enter number to remove: ";
    int idx; cin >> idx;
    if (idx >= 1 && idx <= (int)movies.size()) {
        movies.erase(movies.begin() + (idx - 1));
        cout << "Movie deleted.\n";
    }
    else cout << "Invalid index.\n";
}

void movieManagementMenu() {
    int choice = 0;
    while (choice != 4) {
        cout << "\n--- MOVIE MANAGEMENT ---\n";
        cout << "1. Add Movie\n2. Remove Movie\n3. List Movies\n4. Back\nSelect: ";
        cin >> choice;
        if (choice == 1) addMovie();
        else if (choice == 2) removeMovie();
        else if (choice == 3) { cout << "\n--- CURRENT MOVIES ---\n"; listMovies(); }
        else if (choice == 4) return;
    }
}

// --- SHOWTIME MANAGEMENT (ADMIN OPTION 2) ---
void addShowtime() {
    if (movies.empty()) {
        cout << "Add a movie first!\n";
        return;
    }
    cout << "\nSelect a movie:\n";
    listMovies();
    cout << "Selection: ";
    int idx; cin >> idx;
    if (idx < 1 || idx >(int)movies.size()) return;

    cout << "Enter showtime (e.g. 18:30): ";
    string t; cin >> t;
    movies[idx - 1].showtimes.push_back(t);
    cout << "Showtime added to " << movies[idx - 1].name << "!\n";
}

void showtimeManagementMenu() {
    int choice = 0;
    while (choice != 2) {
        cout << "\n--- SHOWTIME MANAGEMENT ---\n";
        cout << "1. Add Showtime\n2. Back\nSelect: ";
        cin >> choice;
        if (choice == 1) addShowtime();
        else if (choice == 2) return;
    }
}

// --- MAIN ADMIN PANEL ---
void adminPanel() {
    int choice = 0;
    while (choice != 4) {
        cout << "\n===== ADMIN PANEL =====\n";
        cout << "1. Movie Management\n2. Showtime Management\n3. Stats (Soon)\n4. Back\nSelect: ";
        cin >> choice;
        switch (choice) {
        case 1: movieManagementMenu(); break;
        case 2: showtimeManagementMenu(); break;
        case 4: return;
        }
    }
}