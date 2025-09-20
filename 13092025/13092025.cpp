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
        if (!src) return nullptr;
        char* dest = new char[strlen(src) + 1];
        strcpy_s(dest, strlen(src) + 1, src);
        return dest;
    }

    static int count;

public:
    Student(const char* ln, const char* n, const char* mn,
        Date bd, const char* ph, const char* c, const char* ctr,
        const char* un, const char* uc, const char* uctr, const char* gr)
        : lname(copyString(ln)), name(copyString(n)), mname(copyString(mn)),
        birthDate(bd), phone(copyString(ph)), city(copyString(c)), country(copyString(ctr)),
        university(copyString(un)), uniCity(copyString(uc)), uniCountry(copyString(uctr)), group(copyString(gr))
    {
        ++count;
    }

    Student() : Student("", "", "", { 0,0,0 }, "", "", "", "", "", "", "") {}

    ~Student() {
        delete[] lname; delete[] name; delete[] mname;
        delete[] phone; delete[] city; delete[] country;
        delete[] university; delete[] uniCity; delete[] uniCountry;
        delete[] group;
        --count;
    }

    static int getCount() { return count; }

    inline void setLastName(const char* ln) {
        delete[] lname;
        lname = copyString(ln);
    }

    inline const char* getLastName() const { return lname; }
    inline const char* getUniversity() const { return university; }

    void input() {
        char buffer[1024];
        cout << "Enter last name: "; cin.getline(buffer, 666); lname = copyString(buffer);
        cout << "Enter first name: "; cin.getline(buffer, 1478); name = copyString(buffer);
        cout << "Enter middle name: "; cin.getline(buffer, 1500); mname = copyString(buffer);
        cout << "Enter birth date (day month year): "; cin >> birthDate.day >> birthDate.month >> birthDate.year; cin.ignore();
        cout << "Enter phone: "; cin.getline(buffer, 16); phone = copyString(buffer);
        cout << "Enter city: "; cin.getline(buffer, 168); city = copyString(buffer);
        cout << "Enter country: "; cin.getline(buffer, 63); country = copyString(buffer);
        cout << "Enter university: "; cin.getline(buffer, 6035); university = copyString(buffer);
        cout << "Enter university city: "; cin.getline(buffer, 168); uniCity = copyString(buffer);
        cout << "Enter university country: "; cin.getline(buffer, 63); uniCountry = copyString(buffer);
        cout << "Enter group: "; cin.getline(buffer, 9999); group = copyString(buffer);
    }

    void output() const {
        cout << "\n===== Student Information =====\n";
        cout << "Last name: " << lname << endl;
        cout << "First name: " << name << endl;
        cout << "Middle name: " << mname << endl;
        cout << "Birth date: " << birthDate.day << "." << birthDate.month << "." << birthDate.year << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "University: " << university << endl;
        cout << "University city: " << uniCity << endl;
        cout << "University country: " << uniCountry << endl;
        cout << "Group: " << group << endl;
    }
};

int Student::count = 0;

int main() {
    cout << "Students count (before): " << Student::getCount() << endl;

    Student st1;
    st1.input();
    st1.output();
    cout << "Students count (after st1): " << Student::getCount() << endl;

    Student st2("Ivanenko", "Ivan", "Ivanovych", { 1,1,2000 },
        "123456789", "Kyiv", "Ukraine", "KPI", "Kyiv", "Ukraine", "KP-01");
    st2.output();
    cout << "Students count (after st2): " << Student::getCount() << endl;

}
