#include <iostream>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string>
#include <iomanip>
#include <vector>
#include <tuple>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

void printBoxedText(const std::string& text, int boxWidth) {
    int textLength = text.length();
    std::cout << "\t\t\t\t";
    for (int i = 0; i < boxWidth - 1; ++i) {
        cout << "*";
    }
    cout << "\n\t\t\t\t* " << text;
    int spaces = boxWidth - 3 - textLength; // Calculate spaces for centering
    for (int i = 0; i < spaces; ++i) {
        cout << " ";
    }
    cout << "*\n";
    cout << "\t\t\t\t";
    for (int i = 0; i < boxWidth - 1; ++i) {
        cout << "*";
    }
}

void animateWelcome() {
    system("cls");
    cout << "\n\n\n\n";
    cout << "                                                         _____        ____ ___ \n";
    cout << "                                      |\\  /| |   | |   |   |    /\\   /      |  |\\  /|\n";
    cout << "                                      | \\/ | |   | |---|   |   /--\\  \\----  |  | \\/ |\n";
    cout << "                                      |    |  \\_/  |   |   |  /    \\  ___/ _|_ |    |\n";
    cout << "\n\n";

    int boxWidth = 60;
    int boxHeight = 10;

    printBoxedText("        Welcome to Blood Bank Data Management System", boxWidth);
    cout << "\n\n\n";

    for (int i = 0; i < boxHeight; ++i) {
        if (i == boxHeight / 2) {
            cout << "\t\t\t\t*";
            int startMessage = (boxWidth - 24) / 2; // Position to start project message
            for (int j = 0; j < startMessage; ++j) {
                cout << " ";
            }
            cout << "Managing Blood Donors  ";
            int endMessage = boxWidth - 25 - startMessage; // Remaining space after message
            for (int j = 0; j < endMessage; ++j) {
                cout << " ";
            }
            cout << "*";
        } else {
            cout << "\t\t\t\t*";
            for (int j = 0; j < boxWidth - 2; ++j) {
                cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }

    cout << "\t\t\t\t";
    for (int i = 0; i < boxWidth; ++i) {
        cout << "*";
    }

    // Animation of "Loading" text followed by dots animation
    cout << "\n\n\t\t\t\tLoading";
    int dots = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < dots; ++j) {
            cout << ".";
        }
        for (int j = dots; j < 3; ++j) {
            cout << " ";
        }
        dots = (dots + 1) % 4; // Cycle through 0, 1, 2, 3 for animation effect
        Sleep(180); // Sleep for 180 milliseconds
        cout << "\b\b\b   \b\b\b"; // Clear previous dots
    }
    system("cls");
}


class blood
{
private:
    string name, phone, group, address;
    char c;
    int day, month, year, total_days, age;
    queue<pair<string, pair<string, int>>> appointmentQueue; // Queue to store appointment bookings with blood group and age

public:
    void display();
    void add();
    void search();
    void delet_();
    void viewAll();
    void sortByName();
    void sortByBloodGroup();
    void sortByAddressAndTime(); // New function for sorting by Address and Time
    void bookAppointment();
    void manageQueue();
    void displayQueue();
    string toUpper(string str);
    void bubbleSortByName(vector<pair<string, tuple<string, string, string, int>>> &data);
    void insertionSortByBloodGroup(vector<pair<string, tuple<string, string, string, int>>> &data);
};

// Function to display options
void blood::display()
{

    cout << "\n\n\n\t\t<------Please Choose Your Option------>";
    cout << "\n\n\t\t1) Add Data (For Donating Blood 1st Time)";
    cout << "\n\n\t\t2) Add Data (For Donating Blood More Than One Time)";
    cout << "\n\n\t\t3) Search Data";
    cout << "\n\n\t\t4) View All Donor Data";
    cout << "\n\n\t\t5) Sort by Name";
    cout << "\n\n\t\t6) Sort by Blood Group";
    cout << "\n\n\t\t7) Sort by Address and Time"; // New option
    cout << "\n\n\t\t8) Book Appointment";
    cout << "\n\n\t\t9) Queue Management";
    cout << "\n\n\t\t10) Exit";
}

// Function to add donor data
void blood::add()
{
    system("cls");
    ofstream contact("contact1.txt", ios::app);
    cout << "\n\n\t\tEnter the name:";
    cin.ignore();
    getline(cin, name);
    cout << "\n\n\t\tEnter the mobile number:";
    getline(cin, phone);
    cout << "\n\n\t\tEnter the Address:";
    getline(cin, address);
    cout << "\n\n\t\tEnter the blood group:";
    getline(cin, group);

    group = toUpper(group);

    cout << "\n\n\t\tEnter the Date:";
    cin >> month >> c >> day >> c >> year;
    total_days = day + (month * 30) + (year * 365);

    // Calculate age based on current year
    int currentYear = 2024; // Example: Current year
    age = currentYear - year;

    contact << name << " " << phone << " " << address << " " << group << " " << total_days << " " << age << endl;
    contact.close();
}

// Function to search donor data
void blood::search()
{
    system("cls");
    string group1;
    int t_days, c1 = 0;
    char c;
    ifstream myfile("contact1.txt");

    cout << "\n\n\t\tEnter The Blood You Want To Search:";
    cin >> group1;

    group1 = toUpper(group1);

    cout << "\n\n\t\tEnter The Date:";
    cin >> month >> c >> day >> c >> year;
    t_days = day + (month * 30) + (year * 365);
    system("cls");

    bool found = false;
    string line;
    while (getline(myfile, line))
    {
        istringstream iss(line);
        iss >> name >> phone >> address >> group >> total_days >> age;

        if (group1 == group && t_days - total_days >= 120)
        {
            if (c1 == 0)
            {
                cout << "\n\n\n\t\tContact details..";
                cout << "\n\n\t Name : " << name;
                cout << "\n\n\t Mobile : " << phone;
                cout << "\n\n\t Address : " << address;
                cout << "\n\n\t Blood Group : " << group;
                cout << "\n\n\t Age : " << age;
                c1++;
            }
            else
            {
                cout << "\n\t---------------------       ";
                cout << "\n\n\t Name : " << name;
                cout << "\n\n\t Mobile : " << phone;
                cout << "\n\n\t Address : " << address;
                cout << "\n\n\t Blood Group : " << group;
                cout << "\n\n\t Age : " << age;
            }

            found = true;
        }
    }

    if (!found)
    {
        cout << "\n\n\t Sorry We Don't have any available person";
    }

    myfile.close();
}

// Function to delete donor data
void blood::delet_()
{
    ifstream myfile("contact1.txt");
    ofstream temp("temp.txt");

    int total_days1;
    string phone1;
    bool found = false;

    cout << "\n\n\t\tEnter the phone number:";
    cin >> phone1;

    cout << "\n\n\t\tEnter the Date:";
    cin >> month >> c >> day >> c >> year;
    total_days1 = day + (month * 30) + (year * 365);

    while (myfile >> name >> phone >> address >> group >> total_days >> age)
    {
        if (phone1 == phone && total_days1 - total_days >= 120)
        {
            found = true;
            cout << "\n\tDeleting the following record:\n";
            cout << "\n\t Name : " << name;
            cout << "\n\t Mobile : " << phone;
            cout << "\n\t Address : " << address;
            cout << "\n\t Blood Group : " << group;
            cout << "\n\t Total Days Since Donation : " << total_days;
            cout << "\n\t Age : " << age;
            continue; // Skip writing this record to the new file
        }

        temp << name << " " << phone << " " << address << " " << group << " " << total_days << " " << age << endl;
    }

    myfile.close();
    temp.close();

    if (!found)
    {
        cout << "\n\n\t\tNo matching record found for deletion.\n";
    }
    else
    {
        remove("contact1.txt");
        rename("temp.txt", "contact1.txt");
        cout << "\n\n\t\tRecord deleted successfully.\n";
    }
}

// Function to view all donor data
void blood::viewAll()
{
    system("cls");
    ifstream myfile("contact1.txt");
    if (!myfile)
    {
        cout << "\n\n\t\tError opening file. No donor data available.\n";
        cin.ignore();
        return;
    }

    cout << "\n\n\t\tAll Donor Data:\n";
    string line;
    while (getline(myfile, line))
    {
        istringstream iss(line);
        iss >> name >> phone >> address >> group >> total_days >> age;

        cout << "\n\t---------------------       ";
        cout << "\n\n\t Name : " << name;
        cout << "\n\n\t Mobile : " << phone;
        cout << "\n\n\t Address : " << address;
        cout << "\n\n\t Blood Group : " << group;
        cout << "\n\n\t Total Days Since Donation : " << total_days;
        cout << "\n\n\t Age : " << age;
    }

    if (myfile.eof())
    {
        cout << "\n\n\t\tEnd of file reached.\n";
    }
    else if (myfile.fail())
    {
        cout << "\n\n\t\tError reading from file.\n";
    }

    myfile.close();
}

// Function to sort donor data by name using bubble sort
void blood::sortByName()
{
    system("cls");
    ifstream myfile("contact1.txt");
    vector<pair<string, tuple<string, string, string, int>>> donorData;
    string name, phone, address, group;
    int total_days;

    while (myfile >> name >> phone >> address >> group >> total_days)
    {
        donorData.push_back({name, make_tuple(phone, address, group, total_days)});
    }

    bubbleSortByName(donorData);

    cout << "\n\n\t\tAll Donor Data Sorted by Name:\n";
    for (const auto &donor : donorData)
    {
        cout << "\n\t---------------------       ";
        cout << "\n\n\t Name : " << donor.first;
        cout << "\n\n\t Mobile : " << get<0>(donor.second);
        cout << "\n\n\t Address : " << get<1>(donor.second);
        cout << "\n\n\t Blood Group : " << get<2>(donor.second);
        cout << "\n\n\t Total Days Since Donation : " << get<3>(donor.second);
    }

    myfile.close();
}

// Function to sort donor data by blood group using insertion sort
void blood::sortByBloodGroup()
{
    system("cls");
    ifstream myfile("contact1.txt");
    vector<pair<string, tuple<string, string, string, int>>> donorData;
    string name, phone, address, group;
    int total_days;

    while (myfile >> name >> phone >> address >> group >> total_days)
    {
        donorData.push_back({group, make_tuple(name, phone, address, total_days)});
    }

    insertionSortByBloodGroup(donorData);

    cout << "\n\n\t\tAll Donor Data Sorted by Blood Group:\n";
    for (const auto &donor : donorData)
    {
        cout << "\n\t---------------------       ";
        cout << "\n\n\t Name : " << get<0>(donor.second);
        cout << "\n\n\t Mobile : " << get<1>(donor.second);
        cout << "\n\n\t Address : " << get<2>(donor.second);
        cout << "\n\n\t Blood Group : " << donor.first;
        cout << "\n\n\t Total Days Since Donation : " << get<3>(donor.second);
    }

    myfile.close();
}

// Function to sort donor data by Address and Time using selection sort
void blood::sortByAddressAndTime()
{
    system("cls");
    ifstream myfile("contact1.txt");
    vector<pair<string, tuple<string, string, string, int>>> donorData;
    string name, phone, address, group;
    int total_days;

    while (myfile >> name >> phone >> address >> group >> total_days)
    {
        donorData.push_back({address, make_tuple(name, phone, group, total_days)});
    }

    // Perform selection sort by Address and Time
    int n = donorData.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (donorData[j].first < donorData[minIndex].first ||
                    (donorData[j].first == donorData[minIndex].first && get<3>(donorData[j].second) < get<3>(donorData[minIndex].second)))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(donorData[i], donorData[minIndex]);
        }
    }

    cout << "\n\n\t\tAll Donor Data Sorted by Address and Time:\n";
    for (const auto &donor : donorData)
    {
        cout << "\n\t---------------------       ";
        cout << "\n\n\t Name : " << get<0>(donor.second);
        cout << "\n\n\t Mobile : " << get<1>(donor.second);
        cout << "\n\n\t Address : " << donor.first;
        cout << "\n\n\t Blood Group : " << get<2>(donor.second);
        cout << "\n\n\t Total Days Since Donation : " << get<3>(donor.second);
    }

    myfile.close();
}


void blood::bookAppointment()
{
    system("cls");
    string name, group;
    int age;
    cout << "\n\n\t\tEnter your name:";
    cin.ignore();
    getline(cin, name);

    cout << "\n\n\t\tEnter the blood group:";
    getline(cin, group);

    group = toUpper(group);

    cout << "\n\n\t\tEnter your age:";
    cin >> age;

    appointmentQueue.push({group, {name, age}});

    cout << "\n\n\t\tAppointment booked successfully!\n";
}

// Function to manage the appointment queue
void blood::manageQueue()
{
    int choice;

    while (true)
    {
        displayQueue();

        cout << "\n\n\t\t1. Add Details to Queue";
        cout << "\n\n\t\t2. Remove Detail from Queue";
        cout << "\n\n\t\t3. Exit";
        cout << "\n\n\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookAppointment();
            break;
        case 2:
            if (!appointmentQueue.empty())
            {
                cout << "\n\n\t\tRemoving detail: " << appointmentQueue.front().second.first << "\n";
                appointmentQueue.pop();
                cout << "\n\n\t\tDetail removed successfully.\n";
            }
            else
            {
                cout << "\n\n\t\tAppointment queue is empty.\n";
            }
            cin.ignore();
            break;
        case 3:
            return;
        default:
            cout << "\n\n\t\tInvalid choice. Please try again.\n";
            cin.ignore();
            break;
        }
    }
}

// Function to display the appointment queue
void blood::displayQueue()
{
    system("cls");
    if (appointmentQueue.empty())
    {
        cout << "\n\n\t\tAppointment queue is empty.\n";
    }
    else
    {
        int i = 1;
        cout << "\n\n\t\tCurrent Appointment Queue:\n";
        queue<pair<string, pair<string, int>>> temp = appointmentQueue;

        while (!temp.empty())
        {
            auto appointment = temp.front();
            temp.pop();
            cout << "\n\t---------------------       ";
            cout << "\n\n\t Position : " << i++;
            cout << "\n\n\t Name : " << appointment.second.first;
            cout << "\n\n\t Blood Group : " << appointment.first;
            cout << "\n\n\t Age : " << appointment.second.second;
        }
    }

    cin.ignore();
}


// Utility function to convert a string to uppercase
string blood::toUpper(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Bubble sort implementation to sort donor data by name
void blood::bubbleSortByName(vector<pair<string, tuple<string, string, string, int>>> &data)
{
    int n = data.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (data[j].first > data[j + 1].first)
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

// Insertion sort implementation to sort donor data by blood group
void blood::insertionSortByBloodGroup(vector<pair<string, tuple<string, string, string, int>>> &data)
{
    int n = data.size();
    for (int i = 1; i < n; ++i)
    {
        pair<string, tuple<string, string, string, int>> key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j].first > key.first)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

int main()
{
    animateWelcome();
    blood s;
    int ch;
    while (true)
    {
        system("cls");
        s.display();
        cout << "\n\n\t\tEnter your choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            s.add();
            break;
        case 2:
            s.add();
            break;
        case 3:
            s.search();
            break;
        case 4:
            s.viewAll();
            break;
        case 5:
            s.sortByName();
            break;
        case 6:
            s.sortByBloodGroup();
            break;
        case 7:
            s.sortByAddressAndTime();
            break;
        case 8:
            s.bookAppointment();
            break;
        case 9:
            s.manageQueue();
            break;
        case 10:
            exit(0);
        default:
            cout << "\n\n\t\tInvalid choice!";
        }
        cin.ignore();
        cin.get();
    }
    return 0;
}


