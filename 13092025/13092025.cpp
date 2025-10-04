#include <iostream>
#include <cstring>

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

public:
    Student() 
        : lname(nullptr), name(nullptr), mname(nullptr), phone(nullptr), city(nullptr),
          country(nullptr), university(nullptr), uniCity(nullptr), uniCountry(nullptr), group(nullptr) {
        birthDate = {0, 0, 0};
    }


    Student(Student&& other) noexcept {
        lname = other.lname;
        name = other.name;
        mname = other.mname;
        birthDate = other.birthDate;
        phone = other.phone;
        city = other.city;
        country = other.country;
        university = other.university;
        uniCity = other.uniCity;
        uniCountry = other.uniCountry;
        group = other.group;

        other.lname = nullptr;
        other.name = nullptr;
        other.mname = nullptr;
        other.phone = nullptr;
        other.city = nullptr;
        other.country = nullptr;
        other.university = nullptr;
        other.uniCity = nullptr;
        other.uniCountry = nullptr;
        other.group = nullptr;
    }

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
    }

    void input() {
        char buffer[500];

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

        cout << "Enter university name: ";
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

    void output() const {
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

    };

    int main() {
        Student st;
        st.input();
        st.output();

        cout << "\nUsing move constructor to create a new student object...\n";
        Student mStudent = std::move(st);
        mStudent.output();

        return 0;
    }
};