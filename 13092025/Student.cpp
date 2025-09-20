#include "Student.h"


Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

char* Student::copyString(const char* src) {
    if (!src) return nullptr;
    char* dest = new char[strlen(src) + 1];
    strcpy(dest, src);
    return dest;
}

Student::Student()
    : lname(nullptr), name(nullptr), mname(nullptr),
    birthDate(), phone(nullptr), city(nullptr), country(nullptr),
    university(nullptr), uniCity(nullptr), uniCountry(nullptr),
    group(nullptr) {
}

Student::Student(const Student& other)
    : lname(copyString(other.lname)), name(copyString(other.name)), mname(copyString(other.mname)),
    birthDate(other.birthDate),
    phone(copyString(other.phone)), city(copyString(other.city)), country(copyString(other.country)),
    university(copyString(other.university)), uniCity(copyString(other.uniCity)), uniCountry(copyString(other.uniCountry)),
    group(copyString(other.group)) {
}

Student::~Student() {
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

void Student::input() {
    char buffer[1000];

    cout << "Enter last name: ";
    cin.getline(buffer, 1000);
    lname = copyString(buffer);

    cout << "Enter first name: ";
    cin.getline(buffer, 1000);
    name = copyString(buffer);

    cout << "Enter middle name: ";
    cin.getline(buffer, 1000);
    mname = copyString(buffer);

    cout << "Enter birth date (day month year): ";
    cin >> birthDate.day >> birthDate.month >> birthDate.year;
    cin.ignore();

    cout << "Enter phone: ";
    cin.getline(buffer, 1000);
    phone = copyString(buffer);

    cout << "Enter city: ";
    cin.getline(buffer, 1000);
    city = copyString(buffer);

    cout << "Enter country: ";
    cin.getline(buffer, 1000);
    country = copyString(buffer);

    cout << "Enter university: ";
    cin.getline(buffer, 1000);
    university = copyString(buffer);

    cout << "Enter university city: ";
    cin.getline(buffer, 1000);
    uniCity = copyString(buffer);

    cout << "Enter university country: ";
    cin.getline(buffer, 1000);
    uniCountry = copyString(buffer);

    cout << "Enter group: ";
    cin.getline(buffer, 1000);
    group = copyString(buffer);
}

void Student::output() const {
    cout << "\n===== Student Information =====\n";
    cout << "Last name: " << (lname ? lname : "") << endl;
    cout << "First name: " << (name ? name : "") << endl;
    cout << "Middle name: " << (mname ? mname : "") << endl;
    cout << "Birth date: " << birthDate.day << "." << birthDate.month << "." << birthDate.year << endl;
    cout << "Phone: " << (phone ? phone : "") << endl;
    cout << "City: " << (city ? city : "") << endl;
    cout << "Country: " << (country ? country : "") << endl;
    cout << "University: " << (university ? university : "") << endl;
    cout << "University city: " << (uniCity ? uniCity : "") << endl;
    cout << "University country: " << (uniCountry ? uniCountry : "") << endl;
    cout << "Group: " << (group ? group : "") << endl;
}
