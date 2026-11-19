# Banking-System
## **1. How the program works**

1. **Register customers**
When the program starts, it asks you to enter details for three customers:
   - Full name
   - Account number
   - PIN
   - Opening balance
     
2. **Customer login**
The customer enters their account number and PIN.
The system checks whether the account exists and whether the PIN is correct.

4. **Display the banking menu**
After logging in, the customer sees five options:
   ```
   ======== GCC BANK ========
   1. Deposit Money
   2. Withdraw Money
   3. Send Cash
   4. Check Balance
   5. Exit
   ```
5. **Deposit money**
The customer enters an amount to add to their account.
Example:
   - Previous balance: R1 000
   - Deposit: R500
   - New balance: R1 500
     
6. **Withdraw money**
The customer enters the amount they want to withdraw.
The system checks whether they have enough money.
Example:
   - Balance: R1 000
   - Withdrawal: R300
   - New balance: R700
     
7. **Send cash**
The customer enters another customer's account number and the amount to send.
The system checks whether the receiving account exists and whether the sender has enough money.
Example:
   - John's balance: R1 000
   - Mary receives: R200
   - John's new balance: R800
   - Mary's balance increases by R200.
     
8. **Check balance**
The customer can view how much money is currently in their account.

10. **Exit**
When the customer selects option 5, the program stops running.

## **2. Programming concepts used**
These are important because your assignment is about functions, decision-making, loops and arrays.

| C++ concept  | What it does                                          |
| ------------ | ----------------------------------------------------- |
| `string`     | Stores customer names.                                |
| `int`        | Stores account numbers and PINs.                      |
| `double`     | Stores money and balances.                            |
| `getline()`  | Reads full names, including spaces.                   |
| Arrays       | Store information for three customers.                |
| `if / else`  | Makes decisions, such as checking if money is enough. |
| `switch`     | Handles the menu options.                             |
| `for` loop   | Repeats customer registration three times.            |
| `while` loop | Keeps the menu and login running.                     |
| Functions    | Separate the different banking activities.            |

## **3. Example of how the banking system works**

**Example transaction**
John's starting balance
**R5 000**

Deposit
**+ R1 000**

Withdrawal
**− R500**

Cash sent to Mary
**− R200**

**Final balance**
# **R5 300**

## **4. How to explain your project to your lecturer**

"The GCC Banking System is a C++ program that allows customers to perform basic banking activities. The program stores three customers using arrays. Each customer has a name, account number, PIN and balance. Customers must log in before accessing the banking menu. They can deposit money, withdraw money, send cash to another customer and check their balance. I used functions to separate the banking activities, loops to repeat the menu and arrays to store customer information."
