#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std; 

struct Patient {
    string name;
    int priority;
    
    bool operator>(const Patient& other) const {
        return priority < other.priority;
    }
};    

int main (){
   
   priority_queue<Patient, vector<Patient>, greater<Patient>> patients;
    char nextPatient;
   
   do {
       string name;
       int priority;
       
       cout << "Enter name of the patient: " ;
       cin >> name;
       
       cout << "Enter the priority between the numbers 1-5 (5 being highest) : ";
       cin>> priority;
       
       patients.push({name, priority});
       cout << "Patient: "<< name <<"  Priority: " << priority << endl;
       
       cout << "Would you like to add another patient? (y/n): ";
       cin >> nextPatient;
   } 
   while(tolower(nextPatient) == 'y');
    
    cout << "Patient in order of priority (5 being the highest priority): " << endl;
    
     while (!patients.empty()) {
        Patient currentPatient = patients.top();
        std::cout << currentPatient.name << " (Priority: " << currentPatient.priority << ")\n";
        patients.pop();
    }

    return 0;
}