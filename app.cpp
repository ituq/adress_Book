#include "date.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <thread>
using namespace std;
struct Entry {
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
template <typename T> T getInput(istream &s) {
  T res;
  s >> res;
  return res;
}
void printMenu() { cout << "1. Search\n2. Add Entry\n3. Quit\n"; }
const string version = "Alpha";
void search(const set<Entry, function<bool(Entry, Entry)>> &s) {}
void search(const set<Entry, function<bool(Entry, Entry)>> &s, Entry e){};
void addEntry(set<Entry, function<bool(Entry, Entry)>> &s) {
  string first_name, last_name, phone_number;
  cout << "Enter first name:\n";
  cin >> first_name;
  clearScreen();
  cout << "Enter last name:\n";
  cin >> last_name;
  clearScreen();
  cout << "Enter phone number:\n";
  cin >> phone_number;
  clearScreen();
  cout << "Enter Birthday as DD MM YYYY\n";
  Date birthday = {getInput<int>(cin), getInput<int>(cin), getInput<int>(cin)};
  Entry e = {first_name, last_name, phone_number, birthday};
  if (s.find(e) == s.end()) {
    // entry is present
    s.insert(e);
    cout << "Successfully Added! Returning to main menu...\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    clearScreen();
  } else {
    // entry is not present
    cout << "Entry already present. Would you like to view it? (y/n)\n";
    string choice{getInput<string>(cin)};
    if (choice == "y" || choice == "yes") {
      clearScreen();
      search(s, e);
    } else {
      cout << "Returning to main menu...\n";
      this_thread::sleep_for(chrono::milliseconds(1000));
      clearScreen();
    }
  }
}

int main() {
  auto compEntries = [](Entry a, Entry b) {
    return a.last_name < b.last_name ||
           (a.last_name == b.last_name && a.first_name < b.first_name);
  };
  set<Entry, function<bool(Entry, Entry)>> storage(compEntries);
  while (true) {
    cout << "Terminal " << version << "\n";
    printMenu();
    int action;
    cin >> action;
    switch (action) {
    case 1:
      clearScreen();
      search(storage);
      break;
    case 2:
      clearScreen();
      addEntry(storage);
      break;
    case 3:
      return 0;
    default:
      cout << "";
    }
  }
}
