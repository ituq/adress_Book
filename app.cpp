#include "date.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;
struct Entry{
    string first_name;
    string last_name;
    string phoneNumber;
    Date birthday;
};
void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
template<typename T>
T getInput(istream& s){
    T res;
    s>>res;
    return res;
}
void printMenu(){
    cout<<"1. Search\n2. Add Entry\n3. Quit\n";
    
}
const string version="Alpha";
int main(){
    void search();
    void addEntry();
    while(true){
        cout<<"Terminal "<<version<<"\n";
        printMenu();
        int action;
        cin>>action;
        switch (action)
        {
        case 1:
            search();
            break;
        case 2:
            addEntry();
            break;
        case 3:
            break;
        default:
            cout<<"";
        }
    }
}
void search(){

}
void addEntry(){
    string first_name,last_name, phone_number;
    cout<<"Enter first name:\n";
    cin >> first_name;
    clearScreen();
    cout<<"Enter last name:\n";
    cin>>last_name;
    clearScreen();
    cout<<"Enter phone number:\n";
    cin>>phone_number;
    clearScreen();
    cout<<"Enter Birthday as DD MM YYYY\n";
    Date birthday={getInput<int>(cin),getInput<int>(cin),getInput<int>(cin)};
    Entry e={first_name,last_name,phone_number,birthday};
    //TODO add duplicate checking and backend actually add entry
    cout<<"Successfully Added! Returning to main menu...";
    this_thread::sleep_for(chrono::milliseconds(500));
}