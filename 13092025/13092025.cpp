#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
private:
    string fullName;
    string domashniyTelefon;
    string rabochiyTelefon;
    string mobilnyyTelefon;
    string dopolnitelInfo;

public:
    Contact(const string& fullName, const string& domashniyTelefon, const string& rabochiyTelefon,
            const string& mobilnyyTelefon, const string& dopolnitelInfo)
        : fullName(fullName), domashniyTelefon(domashniyTelefon), rabochiyTelefon(rabochiyTelefon),
          mobilnyyTelefon(mobilnyyTelefon), dopolnitelInfo(dopolnitelInfo) {}
    void display() const {
        cout << "Full Name: " << fullName << endl;
        cout << "Home Phone: " << domashniyTelefon << endl;
        cout << "Work Phone: " << rabochiyTelefon << endl;
        cout << "Mobile Phone: " << mobilnyyTelefon << endl;
        cout << "Additional Info: " << dopolnitelInfo << endl;
    }
};

const string& getFullName() const { return fullName; }

void s1() const {
    cout << "FIO: " << fullName << endl;
    cout << "Domashniy telefon: " << domashniyTelefon << endl;
    cout << "Rabochiy telefon: " << rabochiyTelefon << endl;
    cout << "Mobilnyy telefon: " << mobilnyyTelefon << endl;
    cout << "Dopolnitel'naya informaciya: " << dopolnitelInfo << endl;
    cout << "-----------------------------" << endl;
}
};

void addContact(vector<Contact>& contacts) {
    string fullName, domashniyTelefon, rabochiyTelefon, mobilnyyTelefon, dopolnitelInfo;
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    
    cout << "Enter Home Phone: ";
    getline(cin, domashniyTelefon);
    
    cout << "Enter Work Phone: ";
    getline(cin, rabochiyTelefon);
    
    cout << "Enter Mobile Phone: ";
    getline(cin, mobilnyyTelefon);
    
    cout << "Enter Additional Info: ";
    getline(cin, dopolnitelInfo);
    
    contacts.emplace_back(fullName, domashniyTelefon, rabochiyTelefon, mobilnyyTelefon, dopolnitelInfo);
}

void displayContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
        return;
    }
    for (const auto& contact : contacts) {
        contact.display();
        cout << "-----------------------------" << endl;
    }
}

void searchContact(const vector<Contact>& contacts) {
    string searchName;
    cout << "Enter Full Name to search: ";
    getline(cin, searchName);
    
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getFullName() == searchName) {
            contact.display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found." << endl;
    }
}

void deleteContact(vector<Contact>& contacts) {
    string deleteName;
    cout << "Enter Full Name to delete: ";
    getline(cin, deleteName);
    
    auto it = remove_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
        return contact.getFullName() == deleteName;
    });
    
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

int main() {
    vector<Contact> contacts;
    int choice;
    
    do {
        cout << "Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    
}