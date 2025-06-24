#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <functional> // for std::hash

using namespace std;

// Function to hash passwords (simple and NOT secure for real use)
string hashPassword(const string& password) {
    hash<string> hasher;
    size_t hashed = hasher(password);
    return to_string(hashed);
}

// Check if username already exists
bool usernameExists(const string& username) {
    ifstream infile("users.txt");
    string storedUsername, storedPassword;

    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
}

// Register new user
void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already exists. Please try a different one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Store hashed password
    string hashedPassword = hashPassword(password);

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << hashedPassword << endl;

    cout << "Registration successful!\n";
}

// Login existing user
void loginUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    string hashedPassword = hashPassword(password);

    ifstream infile("users.txt");
    string storedUsername, storedPassword;
    bool loginSuccess = false;

    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == hashedPassword) {
            loginSuccess = true;
            break;
        }
    }

    if (loginSuccess) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Login failed! Incorrect username or password.\n";
    }
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
