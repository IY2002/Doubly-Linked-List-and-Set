//---------------------------------------------------------------------
// Name: Ismael Youssef
// Email: IAY5011@psu.edu
// Class: CMPSC 122, Section 2
// Program 3.1
// Due Date: April 9, 2022, 11:59 PM
//
// Description:
//   Created a set class using a linked list
//
// Acknowledgements:
//
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>

#include "set.h"

using namespace std;

int main() {

    bool status = true;
    string input;
    string var1, var2;

    Set num1;
    Set num2;

    int set1_size;
    cout << "Enter starting size of Set #1: ";
    cin >> set1_size;
    cout << endl;

    int set2_size;
    cout << "Enter starting size of Set #2: ";
    cin >> set2_size;
    cout << endl;

    int tempVar;
    cout << "Enter " << set1_size << " values for Set #1: ";
    for(int i = 0; i < set1_size; i++){
        cin >> tempVar;
        num1.add(tempVar);
    }
    cout << endl;

    int tempVar1;
    cout << "Enter " << set2_size << " values for Set #2: ";
    for(int i = 0; i < set2_size; i++){
        cin >> tempVar1;
        num2.add(tempVar1);
    }
    cout << endl;

    // make sure to account for error messages that need to be put in class!!
    cout << endl << "Now accepting commands (quit to exit program)\n1 is for set 1, 2 is for set 2" << endl;
    string T;
    while(status){
        cout << ">";

        string test2;

        std::getline(cin, input);

        stringstream stream(input);

        std::getline(stream, test2, ' ');

        std::getline(stream, var1, ' '); // var1 is a string with the first number

        std::getline(stream, var2, ' '); // var2 is a string with second number if needed

        if(input.find("contains") != string::npos) {
            if(var2 == "1"){
                bool stat = num1.contains(stoi(var1));
                if(stat) cout << "true" << endl;

                if(!stat) cout << "false" << endl;
            }
            if(var2 == "2"){
                bool stat = num2.contains(stoi(var1));
                if(stat) cout << "true" << endl;

                if(!stat) cout << "false" << endl;
            }
        }
        if(input.find("add") != string::npos) {
            if(var2 == "1"){
                bool stat = num1.add(stoi(var1));
                if(stat) cout << "true" << endl;

                if(!stat) cout << "false" << endl;
            }
            if(var2 == "2"){
                bool stat = num2.add(stoi(var1));
                if(stat) cout << "true" << endl;

                if(!stat) cout << "false" << endl;
            }
        }
        if(input.find("remove") != string::npos) {
            if(var2 == "1"){
                bool stat = num1.remove(stoi(var1));
                if(stat) cout << "true" << endl;

                if(!stat) cout << "false" << endl;
            }
            if(var2 == "2"){
                bool stat = num2.remove(stoi(var1));
                if(stat) cout << "true" << endl;

                if(!stat) cout << "false" << endl;
            }
        }
        if(input.find("print") != string::npos) {

            if(var1 == "1"){
                cout << "elements(" << num1.size() << "): ";
                num1.print();
            }
            if(var1 == "2"){
                cout << "elements(" << num2.size() << "): ";
                num2.print();
            }
        }
        if(input.find("union") != string::npos) {
            Set* result;
            result = num1.set_union(num2);
            cout << "Union: ";
            result->print();
        }
        if(input.find("intersection") != string::npos) {
            Set* result;
            result = num1.intersection(num2);
            cout << "Intersection: ";
            result->print();
        }
        if(input.find("difference") != string::npos) {
            Set* res;
            res = num1.difference(num2);
            cout << "First - Second: ";
            res->print();

            Set* res2;
            res2 = num2.difference(num1);
            cout << "Second - First: ";
            res2 ->print();
        }
        if(input.find("quit") != string::npos) {
            status = false;
        }

    }
}
