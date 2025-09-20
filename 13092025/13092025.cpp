// 13092025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class Student {
private:
    char* lname;
    char* name;
    char* mname;
    Date birthDate;
    char* phone;
    char* city;
    char* country;
    char* university;
    char* uniCity;
    char* uniCountry;
    char* group;

    char* copyString(const char* src) {
        char* dest = new char[strlen(src) + 1];
        strcpy(dest, src);
        return dest;
    }

    static int count;

public:

    Student(const char* ln, const char* n, const char* mn,
        Date bd, const char* ph, const char* c, const char* ctr,
        const char* un, const char* uc, const char* uctr, const char* gr)
        : lname(copyString(ln)), name(copyString(n)), mname(copyString(mn)),
        birthDate(bd), phone(copyString(ph)), city(copyString(c)),
        country(copyString(ctr)), university(copyString(un)),
        uniCity(copyString(uc)), uniCountry(copyString(uctr)), group(copyString(gr)) {
        ++count;
    }

    Student() : Student("", "", "", { 0,0,0 }, "", "", "", "", "", "", "") {}

    ~Student() {
        delete[] lname;
        delete[] name;
        delete[] mname;
        delete[] phone;
        delete[] city;
        delete[] country;
        delete[] university;
        delete[] uniCity;
        delete[] uniCountry;
        delete[] group;
        --count;
    }

    static int getCount() {
        return count;
    }

    void input() {
        char buffer[100];

        cout << "Enter last name: ";
        cin.getline(buffer, 666);
        lname = copyString(buffer);

        cout << "Enter first name: ";
        cin.getline(buffer, 1478);
        name = copyString(buffer);

        cout << "Enter middle name: ";
        cin.getline(buffer, 1500);
        mname = copyString(buffer);

        cout << "Enter birth date (day month year): ";
        cin >> birthDate.day >> birthDate.month >> birthDate.year;
        cin.ignore();

        cout << "Enter phone: ";
        cin.getline(buffer, 16);
        phone = copyString(buffer);

        cout << "Enter city: ";
        cin.getline(buffer, 168);
        city = copyString(buffer);

        cout << "Enter country: ";
        cin.getline(buffer, 63);
        country = copyString(buffer);

        cout << "Enter university: ";
        cin.getline(buffer, 6035);
        university = copyString(buffer);

        cout << "Enter university city: ";
        cin.getline(buffer, 168);
        uniCity = copyString(buffer);

        cout << "Enter university country: ";
        cin.getline(buffer, 63);
        uniCountry = copyString(buffer);

        cout << "Enter group: ";
        cin.getline(buffer, 9999);
        group = copyString(buffer);
    }

    void output() {
        cout << "\n===== Student Information =====\n";
        cout << "Last name: " << lname << endl;
        cout << "First name: " << name << endl;
        cout << "Middle name: " << mname << endl;
        cout << "Birth date: "
            << birthDate.day << "." << birthDate.month << "." << birthDate.year << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "University: " << university << endl;
        cout << "University city: " << uniCity << endl;
        cout << "University country: " << uniCountry << endl;
        cout << "Group: " << group << endl;
    }

    char* getUniversity() {
        return university;
    }
};

int Student::count = 0;

int main() {
    cout << "Students count (before): " << Student::getCount() << endl;

    Student st;
    st.input();
    st.output();

    cout << "Students count (now): " << Student::getCount() << endl;

    Student st2("name1", "name2", "name", { 1,1,2000 },
        "0678288586", "KryvyiRih", "Ukraine",
        "ITSTEP", "KryvyiRih", "Ukraine", "P42");
    st2.output();

    cout << "Students count (final): " << Student::getCount() << endl;
}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
        
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file