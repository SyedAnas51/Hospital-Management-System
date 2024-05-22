//Fayaz Ahmed
//Syed Muhammad Anas 
//OOP final project

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class Staff
{
public:
    string name;
    int age;
    string gender;
    int id;

    Staff() : name(""), age(0), gender(""), id(0) {}

    Staff(string name, int age, string gender, int id)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->id = id;
    }

    virtual ~Staff() {}

    virtual void show_info()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }

    int getId() const { return id; }
};

class Doctor : public Staff
{
public:
    string specialization;

    Doctor() : Staff(), specialization("") {}

    Doctor(string name, int age, string gender, string specialization, int id)
        : Staff(name, age, gender, id), specialization(specialization) {}

    void show_info() override
    {
        Staff::show_info();
        cout << "Specialization: " << specialization << endl;
    }
};

class Surgeon : public Doctor
{
public:
    int num_of_operations;

    Surgeon() : Doctor(), num_of_operations(0) {}

    Surgeon(string name, int age, string gender, string specialization, int num_of_operations, int id)
        : Doctor(name, age, gender, specialization, id), num_of_operations(num_of_operations) {}

    void show_info() override
    {
        Doctor::show_info();
        cout << "Number of operations: " << num_of_operations << endl;
    }
};

class Dentist : public Staff
{
public:
    string specialization;
    string degree;

    Dentist() : Staff(), specialization(""), degree("") {}

    Dentist(string name, int age, string gender, string specialization, string degree, int id)
        : Staff(name, age, gender, id), specialization(specialization), degree(degree) {}

    void show_info() override
    {
        Staff::show_info();
        cout << "Specialization: " << specialization << endl;
        cout << "Degree: " << degree << endl;
    }
};

class Nurse : public Staff
{
public:
    int years_of_experience;

    Nurse() : Staff(), years_of_experience(0) {}

    Nurse(string name, int age, string gender, int years_of_experience, int id)
        : Staff(name, age, gender, id), years_of_experience(years_of_experience) {}

    void show_info() override
    {
        Staff::show_info();
        cout << "Years of experience: " << years_of_experience << endl;
    }
};

class Patient
{
private:
    static int nextId;

public:
    int id;
    string name;
    int age;
    string gender;
    string illness;

    Patient() : id(nextId++), name(""), age(0), gender(""), illness("") {}

    Patient(string name, int age, string gender, string illness)
        : id(nextId++), name(name), age(age), gender(gender), illness(illness) {}

    void show_info()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Illness: " << illness << endl;
    }

    int getId() const { return id; }
};

int Patient::nextId = 1;

class Hospital
{
private:
    Staff *staff[50];
    int staff_count;
    Patient patients[300];
    int patient_count;

public:
    Hospital() : staff_count(0), patient_count(0) {}

    ~Hospital()
    {
        for (int i = 0; i < staff_count; i++)
        {
            delete staff[i];
        }
    }

    void addStaffRecord()
    {
        cout << "Enter staff type (1. Doctor, 2. Surgeon, 3. Dentist, 4. Nurse): ";
        int type;
        cin >> type;
        cout << "Enter name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        int age;
        cin >> age;
        cout << "Enter gender: ";
        string gender;
        cin >> gender;
        int id = staff_count + 1;
        if (type == 1)
        {
            cout << "Enter specialization: ";
            string specialization;
            cin.ignore();
            getline(cin, specialization);
            staff[staff_count++] = new Doctor(name, age, gender, specialization, id);
        }
        else if (type == 2)
        {
            cout << "Enter specialization: ";
            string specialization;
            cin.ignore();
            getline(cin, specialization);
            cout << "Enter number of operations: ";
            int num_of_operations;
            cin >> num_of_operations;
            staff[staff_count++] = new Surgeon(name, age, gender, specialization, num_of_operations, id);
        }
        else if (type == 3)
        {
            cout << "Enter specialization: ";
            string specialization;
            cin.ignore();
            getline(cin, specialization);
            cout << "Enter degree: ";
            string degree;
            cin.ignore();
            getline(cin, degree);
            staff[staff_count++] = new Dentist(name, age, gender, specialization, degree, id);
        }
        else if (type == 4)
        {
            cout << "Enter years of experience: ";
            int years_of_experience;
            cin >> years_of_experience;
            staff[staff_count++] = new Nurse(name, age, gender, years_of_experience, id);
        }
    }

    void displayStaffRecords()
    {
        cout << "Enter staff ID to display: ";
        int id;
        cin >> id;
        bool found = false;
        for (int i = 0; i < staff_count; i++)
        {
            if (staff[i]->getId() == id)
            {
                found = true;
                cout << "Staff Record:" << endl;
                staff[i]->show_info();
            }
        }
        if (!found)
        {
            cout << "Staff record with ID " << id << " not found." << endl;
        }
    }

    void deleteStaffRecord()
    {
        cout << "Enter staff ID to delete: ";
        int id;
        cin >> id;
        bool found = false;
        for (int i = 0; i < staff_count; i++)
        {
            if (staff[i]->getId() == id)
            {
                delete staff[i];
                found = true;
                for (int j = i; j < staff_count - 1; j++)
                {
                    staff[j] = staff[j + 1];
                }
                staff_count--;
                cout << "Staff record with ID " << id << " has been deleted." << endl;
            }
        }
        if (!found)
        {
            cout << "Staff record with ID " << id << " not found." << endl;
        }
    }

    void addPatientRecord()
    {
        if (patient_count >= 300)
        {
            cout << "Maximum patient capacity reached." << endl;
        }
        else
        {
            cout << "Enter name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            cout << "Enter age: ";
            int age;
            cin >> age;
            cout << "Enter gender: ";
            string gender;
            cin >> gender;
            cout << "Enter illness: ";
            string illness;
            cin.ignore();
            getline(cin, illness);
            patients[patient_count++] = Patient(name, age, gender, illness);
            cout << "Patient record added successfully." << endl;
        }
    }

    void displayPatientRecords()
    {
        cout << "Enter patient ID to display: ";
        int id;
        cin >> id;
        bool found = false;
        for (int i = 0; i < patient_count; i++)
        {
            if (patients[i].getId() == id)
            {
                found = true;
                cout << "Patient Record:" << endl;
                cout << "ID: " << id << endl;
                patients[i].show_info();
            }
        }
        if (!found)
        {
            cout << "Patient record with ID " << id << " not found." << endl;
        }
    }

    void deletePatientRecord()
    {
        cout << "Enter patient ID to delete: ";
        int id;
        cin >> id;
        if (id >= 1 && id <= patient_count)
        {
            for (int i = id - 1; i < patient_count - 1; i++)
            {
                patients[i] = patients[i + 1];
            }
            patient_count--;
            cout << "Patient record with ID " << id << " has been deleted." << endl;
        }
        else
        {
            cout << "Invalid patient ID." << endl;
        }
    }

    void saveStaffRecords()
    {
        ofstream outFile("staff_records.txt");
        if (outFile.is_open())
        {
            for (int i = 0; i < staff_count; i++)
            {
                outFile << staff[i]->getId() << endl;
                outFile << staff[i]->name << endl;
                outFile << staff[i]->age << endl;
                outFile << staff[i]->gender << endl;

                Doctor *doctor = dynamic_cast<Doctor *>(staff[i]);
                if (doctor)
                {
                    outFile << "Doctor" << endl;
                    outFile << doctor->specialization << endl;
                }

                Surgeon *surgeon = dynamic_cast<Surgeon *>(staff[i]);
                if (surgeon)
                {
                    outFile << "Surgeon" << endl;
                    outFile << surgeon->specialization << endl;
                    outFile << surgeon->num_of_operations << endl;
                }

                Dentist *dentist = dynamic_cast<Dentist *>(staff[i]);
                if (dentist)
                {
                    outFile << "Dentist" << endl;
                    outFile << dentist->specialization << endl;
                    outFile << dentist->degree << endl;
                }

                Nurse *nurse = dynamic_cast<Nurse *>(staff[i]);
                if (nurse)
                {
                    outFile << "Nurse" << endl;
                    outFile << nurse->years_of_experience << endl;
                }
            }
            outFile.close();
            cout << "Staff records saved successfully." << endl;
        }
        else
        {
            cout << "Error: Unable to open staff_records.txt file for writing." << endl;
        }
    }

    void savePatientRecords()
    {
        ofstream outFile("patient_records.txt");
        if (outFile.is_open())
        {
            for (int i = 0; i < patient_count; i++)
            {
                outFile << patients[i].getId() << endl;
                outFile << patients[i].name << endl;
                outFile << patients[i].age << endl;
                outFile << patients[i].gender << endl;
                outFile << patients[i].illness << endl;
            }
            outFile.close();
            cout << "Patient records saved successfully." << endl;
        }
        else
        {
            cout << "Error: Unable to open patient_records.txt file for writing." << endl;
        }
    }

    void loadStaffRecords()
    {
        ifstream inFile("staff_records.txt");
        if (inFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                int id = stoi(line);
                string name, gender;
                int age;
                getline(inFile, name);
                inFile >> age >> ws;
                getline(inFile, gender);

                string type;
                getline(inFile, type);

                if (type == "Doctor")
                {
                    string specialization;
                    getline(inFile, specialization);
                    staff[staff_count++] = new Doctor(name, age, gender, specialization, id);
                }
                else if (type == "Surgeon")
                {
                    string specialization;
                    getline(inFile, specialization);
                    int num_of_operations;
                    inFile >> num_of_operations >> ws;
                    staff[staff_count++] = new Surgeon(name, age, gender, specialization, num_of_operations, id);
                }
                else if (type == "Dentist")
                {
                    string specialization, degree;
                    getline(inFile, specialization);
                    getline(inFile, degree);
                    staff[staff_count++] = new Dentist(name, age, gender, specialization, degree, id);
                }
                else if (type == "Nurse")
                {
                    int years_of_experience;
                    inFile >> years_of_experience >> ws;
                    staff[staff_count++] = new Nurse(name, age, gender, years_of_experience, id);
                }
            }
            inFile.close();
            cout << "Staff records loaded successfully." << endl;
        }
        else
        {
            cout << "Error: Unable to open staff_records.txt file for reading." << endl;
        }
    }

    void loadPatientRecords()
    {
        ifstream inFile("patient_records.txt");
        if (inFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                int id = stoi(line);
                string name, gender, illness;
                int age;
                getline(inFile, name);
                inFile >> age >> ws;
                getline(inFile, gender);
                getline(inFile, illness);
                patients[patient_count++] = Patient(name, age, gender, illness);
            }
            inFile.close();
            cout << "Patient records loaded successfully." << endl;
        }
        else
        {
            cout << "Error: Unable to open patient_records.txt file for reading." << endl;
        }
    }

    void menu()
    {
        bool quit = false;
        while (!quit)
        {
            cout << "Menu:" << endl;
            cout << "1. Add staff record" << endl;
            cout << "2. Display staff records" << endl;
            cout << "3. Delete staff record" << endl;
            cout << "4. Add patient record" << endl;
            cout << "5. Display patient records" << endl;
            cout << "6. Delete patient record" << endl;
            cout << "7. Save staff records" << endl;
            cout << "8. Save patient records" << endl;
            cout << "9. Load staff records" << endl;
            cout << "10. Load patient records" << endl;
            cout << "11. Quit" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                addStaffRecord();
                break;
            case 2:
                displayStaffRecords();
                break;
            case 3:
                deleteStaffRecord();
                break;
            case 4:
                addPatientRecord();
                break;
            case 5:
                displayPatientRecords();
                break;
            case 6:
                deletePatientRecord();
                break;
            case 7:
                saveStaffRecords();
                break;
            case 8:
                savePatientRecords();
                break;
            case 9:
                loadStaffRecords();
                break;
            case 10:
                loadPatientRecords();
                break;
            case 11:
                quit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            cout << endl;
        }
    }
};



int main()
{
    Hospital hospital;
    hospital.menu();
    return 0;
}

