#Bank Management System
This is a simple Bank Management System implemented in C++ that allows users to create, view, update, search, transact, and delete bank account records.

#Features
Create New Account: Add a new customer with their name, ID, address, contact number, and initial deposit.
View Customers List: Display the details of all the customers in the system.
Update Existing Account: Modify the details of an existing customer using their ID.
Search Account: Search for a specific customer's details using their ID.
Transactions: Deposit or withdraw money from an account.
Delete Account: Remove a specific account or delete all records.

#Requirements
A C++ compiler (e.g., g++, clang++)
A Windows environment (if using the Windows-specific headers like <conio.h> and <windows.h>) or equivalent setup on other OS.

#Key Functions
choice(): Displays the menu and handles user input to choose different operations.
perData(): Collects data to create a new account.
show(): Displays the list of all customers.
update(): Updates the information of an existing account.
search(): Searches for a customer's details using their ID.
transactions(): Handles deposits and withdrawals.
del(): Deletes a specific account or all accounts.

#Input Validation
The contact number must be exactly 10 digits long and contain only numeric characters.
The cash input must be a valid numeric value.

C++ code:-
