#include <iostream>

using namespace std;

// Function declarations
void displayMenu();
int findUser(int accountNumber, int accountNumbers[]);
void deposit(double balances[], int user);
void withdraw(double balances[], int user);
void sendCash(double balances[], int accountNumbers[], int user);
void checkBalance(double balances[], int user);

int main()
{
    // Store information for 3 customers
    string names[3];
    int accountNumbers[3];
    int pins[3];
    double balances[3];

    int accountNumber, pin;
    int user = -1;
    int choice;

    cout << "==============================" << endl;
    cout << "          GCC BANK            " << endl;
    cout << "==============================" << endl;

    // Register customers
    cout << "REGISTER THREE CUSTOMERS" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Customer " << i + 1 << endl;

        cout << "Enter name: ";
        cin >> ws;
        getline(cin, names[i]);

        cout << "Enter account number: ";
        cin >> accountNumbers[i];

        cout << "Enter PIN: ";
        cin >> pins[i];

        cout << "Enter opening balance: R";
        cin >> balances[i];

        // Check that balance is not negative
        while (balances[i] < 0)
        {
            cout << "Invalid balance. Enter again: R";
            cin >> balances[i];
        }
    }

    // Customer login
    cout << "========== LOGIN ==========" << endl;

    do
    {
        cout << "Enter account number: ";
        cin >> accountNumber;

        user = findUser(accountNumber, accountNumbers);

        if (user == -1)
        {
            cout << "Account not found. Try again." << endl;
        }

    } while (user == -1);

    do
    {
        cout << "Enter PIN: ";
        cin >> pin;

        if (pin != pins[user])
        {
            cout << "Incorrect PIN. Try again." << endl;
        }

    } while (pin != pins[user]);

    cout << "Welcome to GCC Bank, " << names[user] << "!" << endl;

    // Banking menu
    do
    {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            deposit(balances, user);
        }
        else if (choice == 2)
        {
            withdraw(balances, user);
        }
        else if (choice == 3)
        {
            sendCash(balances, accountNumbers, user);
        }
        else if (choice == 4)
        {
            checkBalance(balances, user);
        }
        else if (choice == 5)
        {
            cout << "Thank you for banking with GCC Bank!" << endl;
        }
        else
        {
            cout << "Invalid choice. Select 1 to 5." << endl;
        }

    } while (choice != 5);

    return 0;
}

// Display banking menu
void displayMenu()
{
    cout << "==============================" << endl;
    cout << "          GCC BANK            " << endl;
    cout << "==============================" << endl;
    cout << "1. Deposit Money" << endl;
    cout << "2. Withdraw Money" << endl;
    cout << "3. Send Cash" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Exit" << endl;
    cout << "==============================" << endl;
}

// Find customer account
int findUser(int accountNumber, int accountNumbers[])
{
    for (int i = 0; i < 3; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            return i;
        }
    }

    return -1;
}

// Deposit money
void deposit(double balances[], int user)
{
    double amount;

    cout << "Enter amount to deposit: R";
    cin >> amount;

    if (amount > 0)
    {
        balances[user] = balances[user] + amount;

        cout << "Deposit successful!" << endl;
        cout << "New balance: R" << balances[user] << endl;
    }
    else
    {
        cout << "Invalid amount." << endl;
    }
}

// Withdraw money
void withdraw(double balances[], int user)
{
    double amount;

    cout << "Enter amount to withdraw: R";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount." << endl;
    }
    else if (amount > balances[user])
    {
        cout << "Insufficient funds." << endl;
    }
    else
    {
        balances[user] = balances[user] - amount;

        cout << "Withdrawal successful!" << endl;
        cout << "New balance: R" << balances << endl;
    }
}

// Send money to another customer
void sendCash(double balances[], int accountNumbers[], int user)
{
    int receiverAccount;
    int receiver = -1;
    double amount;

    cout << "Enter receiver account number: ";
    cin >> receiverAccount;

    receiver = findUser(receiverAccount, accountNumbers);

    if (receiver == -1)
    {
        cout << "Account does not exist." << endl;
    }
    else if (receiver == user)
    {
        cout << "You cannot send money to yourself." << endl;
    }
    else
    {
        cout << "Enter amount to send: R";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount." << endl;
        }
        else if (amount > balances[user])
        {
            cout << "Insufficient funds." << endl;
        }
        else
        {
            balances[user] = balances[user] - amount;

            balances[user] = balances[user] + amount;

            cout << "Money sent successfully!" << endl;
            cout << "Your new balance: R" << balances << endl;
        }
    }
}

// Check account balance
void checkBalance(double balances[], int user)
{
    cout << "Your current balance is: R";
    cout << balances << endl;
}
