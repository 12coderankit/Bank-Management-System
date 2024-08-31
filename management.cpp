#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cctype>    // For isdigit()
#include <limits>    // For numeric_limits

using namespace std;

class Bank {
    private: 
        int total;
        string id;
        
        struct person {
            string name, ID, address, contact;  // Changed contact to string
            int cash;
        } person[100];

        // Helper function to validate contact number
        bool isValidContact(const string& contact) {
            if(contact.length() != 10) return false;
            for(char c : contact){
                if(!isdigit(c)) return false;
            }
            return true;
        }

    public:
        Bank(){
            total = 0;
        }

        void choice();
        void perData();
        void show();
        void update();
        void search();
        void transactions();
        void del();
};

// Function Prototypes
int main(){
    Bank b;
    b.choice();
    return 0;
}

void Bank::choice(){
    char ch;
    while(1){
        cout << "\n\nPRESS..!!" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. View customers list" << endl;
        cout << "3. Update information of existing account" << endl;
        cout << "4. Check the details of an existing account" << endl;
        cout << "5. For transactions" << endl;
        cout << "6. Remove existing account" << endl;
        cout << "7. Exit" << endl;
        
        ch = getch();
        system("CLS");
        
        switch(ch){
            case '1':
                Bank::perData();
                break;
            case '2':
                if(total == 0){
                    cout << "No data is entered" << endl;
                } else {
                    Bank::show();
                }
                break;
            case '3':
                if(total == 0){
                    cout << "No data is entered" << endl;
                } else {
                    Bank::update();
                }
                break;
            case '4':
                if(total == 0){
                    cout << "No data is entered" << endl;
                } else {
                    Bank::search();
                }
                break;
            case '5':
                if(total == 0){
                    cout << "No data is entered" << endl;
                } else {
                    Bank::transactions();
                }
                break;
            case '6':
                if(total == 0){
                    cout << "No data is entered" << endl;
                } else {
                    Bank::del();
                }
                break;
            case '7':
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}

void Bank::perData(){
    cout << "Enter data of person " << total + 1 << endl;
    
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
    getline(cin, person[total].name);
    
    
    cout << "ID: ";
    cin >> person[total].ID;
    
    cout << "Address: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
    getline(cin, person[total].address);
   
    
    // Validate contact number
    while (true) {
        cout << "Contact (10 digits): ";
        cin >> person[total].contact;
        
        if(isValidContact(person[total].contact)){
            break;
        } else {
            cout << "Invalid contact number. It must be exactly 10 digits. Please try again." << endl;
        }
    }
    
    cout << "Total Cash: ";
    while(!(cin >> person[total].cash)){
        cout << "Invalid input for cash. Please enter a numeric value." << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
    
    total++;
}

void Bank::show(){
    for(int i = 0; i < total; i++){
        cout << "Data of person " << i + 1 << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "ID: " << person[i].ID << endl;
        cout << "Address: " << person[i].address << endl;
        cout << "Contact: " << person[i].contact << endl;
        cout << "Cash: " << person[i].cash << endl;
        cout << "--------------------------" << endl;
    }
}

void Bank::update(){
    cout << "Enter ID of the account you want to update: ";
    cin >> id;
    
    bool found = false;
    for(int i = 0; i < total; i++){
        if(id == person[i].ID){
            found = true;
            cout << "Previous data:" << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;
            cout << "\nEnter new data:" << endl;
            
            cout << "Enter name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
            getline(cin, person[i].name);
            
            cout << "ID: ";
            cin >> person[i].ID;
            
            cout << "Address: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
            getline(cin, person[i].address);
            
            // Validate contact number
            while (true) {
                cout << "Contact (10 digits): ";
                cin >> person[i].contact;
                
                if(isValidContact(person[i].contact)){
                    break;
                } else {
                    cout << "Invalid contact number. It must be exactly 10 digits. Please try again." << endl;
                }
            }
            
            cout << "Total Cash: ";
            while(!(cin >> person[i].cash)){
                cout << "Invalid input for cash. Please enter a numeric value." << endl;
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }
            
            cout << "Account updated successfully." << endl;
            break;
        }
    }
    
    if(!found){
        cout << "No such record found" << endl;
    }
}

void Bank::search(){
    cout << "Enter ID of the account you want to search: ";
    cin >> id;
    
    bool found = false;
    for(int i = 0; i < total; i++){
        if(id == person[i].ID){
            found = true;
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;
            break;
        }
    }
    
    if(!found){
        cout << "No such record found" << endl;
    }
}

void Bank::transactions(){
    int cash;
    char ch;
    
    cout << "Enter ID of the account for transaction: ";
    cin >> id;
    
    bool found = false;
    for(int i = 0; i < total; i++){
        if(id == person[i].ID){
            found = true;
            cout << "Name: " << person[i].name << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "\nExisting Cash: " << person[i].cash << endl;
            cout << "Press 1 to deposit" << endl;
            cout << "Press 2 to withdraw" << endl;
            
            ch = getch();
            system("CLS");
            switch(ch){
                case '1':
                    cout << "How much cash do you want to deposit? ";
                    while(!(cin >> cash) || cash < 0){
                        cout << "Invalid input. Please enter a positive numeric value: ";
                        cin.clear(); // Clear error flags
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    }
                    person[i].cash += cash;
                    cout << "Your new cash balance is: " << person[i].cash << endl;
                    break;
                case '2':
                    while(true){
                        cout << "How much cash do you want to withdraw? ";
                        while(!(cin >> cash) || cash < 0){
                            cout << "Invalid input. Please enter a positive numeric value: ";
                            cin.clear(); // Clear error flags
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        }
                        if(cash > person[i].cash){
                            cout << "Your existing cash is only " << person[i].cash << ". Please enter a valid amount." << endl;
                            // Optionally, add a limit to the number of attempts
                        } else {
                            person[i].cash -= cash;
                            cout << "Your new cash balance is: " << person[i].cash << endl;
                            break;
                        }
                    }
                    break;
                default:
                    cout << "Invalid input" << endl;
                    break;
            }
            break;
        }
    }
    
    if(!found){
        cout << "No such record found" << endl;
    }
}

void Bank::del(){
    char ch;
    cout << "Press 1 to remove a specific record" << endl;
    cout << "Press 2 to remove all records" << endl;
    ch = getch();
    system("CLS");
    
    switch(ch){
        case '1': {
            cout << "Enter ID of the account you want to remove: ";
            cin >> id;
            
            bool found = false;
            for(int i = 0; i < total; i++){
                if(id == person[i].ID){
                    found = true;
                    // Shift all subsequent records up by one
                    for(int j = i; j < total - 1; j++){
                        person[j] = person[j + 1];
                    }
                    total--;
                    cout << "The record has been deleted successfully." << endl;
                    break;
                }
            }
            if(!found){
                cout << "No such record found" << endl;
            }
            break;
        }
        case '2':
            total = 0;
            cout << "All records have been deleted." << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
    }
}
