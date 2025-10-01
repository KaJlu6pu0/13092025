#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Contact {
private:
    char* fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

public:
    Contact(const char* name = "", const string& home = "", const string& work = "",
        const string& mobile = "", const string& info = "")
        : homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(info)
    {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }

    Contact(const Contact& other)
        : homePhone(other.homePhone), workPhone(other.workPhone),
        mobilePhone(other.mobilePhone), additionalInfo(other.additionalInfo)
    {
        fullName = new char[strlen(other.fullName) + 1];
        strcpy(fullName, other.fullName);
    }

    ~Contact() {
        delete[] fullName;
    }

    inline const char* getFullName() const { return fullName; }
    inline void setFullName(const char* name) {
        delete[] fullName;
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }

    void display() const {
        cout << "Full Name: " << fullName << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
        cout << "Additional Info: " << additionalInfo << endl;
        cout << "-----------------------------" << endl;
    }

    void saveToFile(ofstream& outFile) const {
        outFile << fullName << '\n'
            << homePhone << '\n'
            << workPhone << '\n'
            << mobilePhone << '\n'
            << additionalInfo << '\n';
    }

    void loadFromFile(ifstream& inFile) {
        char buffer[256];
        inFile.getline(buffer, 256);
        setFullName(buffer);
        getline(inFile, homePhone);
        getline(inFile, workPhone);
        getline(inFile, mobilePhone);
        getline(inFile, additionalInfo);
    }
};

void addContact(vector<Contact>& contacts) {
    char name[256];
    string home, work, mobile, info;

    cout << "Enter Full Name: ";
    cin.ignore();
    cin.getline(name, 256);
    cout << "Enter Home Phone: "; getline(cin, home);
    cout << "Enter Work Phone: "; getline(cin, work);
    cout << "Enter Mobile Phone: "; getline(cin, mobile);
    cout << "Enter Additional Info: "; getline(cin, info);

    contacts.emplace_back(name, home, work, mobile, info);
}

void displayContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
        return;
    }
    for (const auto& contact : contacts) {
        contact.display();
    }
}

void searchContact(const vector<Contact>& contacts) {
    char searchName[256];
    cout << "Enter Full Name to search: ";
    cin.ignore();
    cin.getline(searchName, 256);

    bool found = false;
    for (const auto& contact : contacts) {
        if (strcmp(contact.getFullName(), searchName) == 0) {
            contact.display();
            found = true;
            break;
        }
    }
    if (!found) cout << "Contact not found." << endl;
}

void deleteContact(vector<Contact>& contacts) {
    char deleteName[256];
    cout << "Enter Full Name to delete: ";
    cin.ignore();
    cin.getline(deleteName, 256);

    auto it = remove_if(contacts.begin(), contacts.end(),
        [&](const Contact& contact) {
            return strcmp(contact.getFullName(), deleteName) == 0;
        });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted." << endl;
    }
    else {
        cout << "Contact not found." << endl;
    }
}

void saveContactsToFile(const vector<Contact>& contacts, const string& filename) {
    ofstream outFile(filename);
    for (const auto& contact : contacts) {
        contact.saveToFile(outFile);
    }
    cout << "Contacts saved to file." << endl;
}

void loadContactsFromFile(vector<Contact>& contacts, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "File not found." << endl;
        return;
    }

    contacts.clear();
    while (inFile.peek() != EOF) {
        Contact c;
        c.loadFromFile(inFile);
        contacts.push_back(c);
    }
    cout << "Contacts loaded from file." << endl;
}

int main() {
    vector<Contact> contacts;
    int choice;
    string filename = "contacts.txt";

    do {
        cout << "\nMenu:\n1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Delete Contact\n5. Save Contacts\n6. Load Contacts\n7. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addContact(contacts); break;
        case 2: displayContacts(contacts); break;
        case 3: searchContact(contacts); break;
        case 4: deleteContact(contacts); break;
        case 5: saveContactsToFile(contacts, filename); break;
        case 6: loadContactsFromFile(contacts, filename); break;
        case 7: cout << "Exiting...\n"; break;
        }
    } while (choice != 7);
}
