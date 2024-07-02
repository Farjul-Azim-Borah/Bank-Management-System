#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

class Account
{
private:
    string AccountNo, Password;
    int Balance;

public:
    Account() : AccountNo(""), Password(""), Balance(0) {}

    int setAccountNo(string id)
    {
        AccountNo = id;
    }

    int setPassword(string pw)
    {
        Password = pw;
    }

    int setBalance(int balance)
    {
        Balance = balance;
    }

    string getAccountNo()
    {
        return AccountNo;
    }

    string getPassword()
    {
        return Password;
    }

    int getBalance()
    {
        return Balance;
    }
};

int openAccount(Account user)
{
    system("cls");
    string id, pw;

    cout << "\tEnter Account No: ";
    cin >> id;
    user.setAccountNo(id);

    cout << "\tEnter A Strong Password: ";
    cin >> pw;
    user.setPassword(pw);

    user.setBalance(0);

    ofstream outfile("D:/Account.txt", ios::app);
    if (!outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }
    else
    {
        outfile << "\t" << user.getAccountNo() << " : " << user.getPassword() << " : " << user.getBalance() << endl
                << endl;
        cout << "\tYour account has been created successfully!!" << endl;
    }
    outfile.close();
    Sleep(3000);
}


int checkCash()
{
    system("cls");
    string id;
    cout<<endl;
    cout << "\tEnter Account No: ";
    cin >> id;

    ifstream infile("D:/Account.txt");
    ofstream outfile("D:/Account Temp.txt");
    if (!infile || !outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }

    string line;
    bool found = false;

    while (getline(infile, line))
    {
        stringstream ss;
        ss << line;
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;
        if (id == userID)
        {
            found = true;
            int cash;
            cout << "\tYour bank balance is "<<userBalance <<" Rs"<<endl;
            cout << "\t***********Thank You************" << endl;
        }
        else
        {
            outfile << line << endl;
        }
    }
    if (!found)
    {
        cout << "\tEnter Valid Account No!" << endl;
    }
    outfile.close();
    infile.close();
    remove("D:/Account.txt");
    rename("D:/Account Temp.txt", "D:/Account.txt");
    Sleep(3000);
}

int addCash()
{
    system("cls");
    string id;
    cout << "\tEnter Account No: ";
    cin >> id;

    ifstream infile("D:/Account.txt");
    ofstream outfile("D:/Account Temp.txt");
    if (!infile || !outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }

    string line;
    bool found = false;

    while (getline(infile, line))
    {
        stringstream ss;
        ss << line;
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;
        if (id == userID)
        {
            found = true;
            int cash;
            cout << "\tEnter Cash: ";
            cin >> cash;

            int newBalance = userBalance + cash;
            userBalance = newBalance;
            outfile << "\t" << userID << " : " << userPW << " : " << userBalance << endl;
            cout << "\tNew Balance Is: " << userBalance << endl;
            cout << "\t***********Thank You************" << endl;
        }
        else
        {
            outfile << line << endl;
        }
    }
    if (!found)
    {
        cout << "\tEnter Valid Account No!" << endl;
    }
    outfile.close();
    infile.close();
    remove("D:/Account.txt");
    rename("D:/Account Temp.txt", "D:/Account.txt");
    Sleep(3000);
}

int withdraw()
{
    system("cls");
    string id, pw;
    cout << "\tEnter Account No: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;
    ifstream infile("D:/Account.txt");
    ofstream outfile("D:/Account Temp.txt");
    if (!infile || !outfile)
    {
        cout << "\tError: File Can't Open!" << endl;
    }

    string line;
    bool found = false;
    while (getline(infile, line))
    {
        stringstream ss;
        ss << line;
        string userID, userPW;
        int userBalance;
        char delimiter;

        ss >> userID >> delimiter >> userPW >> delimiter >> userBalance;

        if (id == userID && pw == userPW)
        {
            found = true;
            int cash;
            cout << "\tEnter Cash: ";
            cin >> cash;
            if (cash <= userBalance)
            {
                int newBalance = userBalance - cash;
                userBalance = newBalance;
                outfile << "\t" << userID << " : " << userPW << " : " << userBalance << endl;
                cout << "\tTransaction Was Successful!" << endl;
                cout << "\tRemaining Balance: " << userBalance << endl;
                cout << "\t***********Thank You************" << endl;

            }
            else
            {
                cout << "\tLow Balance!" << endl;
                outfile << "\t" << userID << " : " << userPW << " : " << userBalance << endl;
            }
        }
        else
        {
            outfile << line << endl;
        }
    }
    if (!found)
    {
        cout << "\tInvalid Account No or Password!" << endl;
    }
    outfile.close();
    infile.close();
    remove("D:/Account.txt");
    rename("D:/Account Temp.txt", "D:/Account.txt");
    Sleep(3000);
}

int main()
{
    Account user;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;
        cout << "\tWelcome To Bank Account Management System" << endl;
        cout << "*********************************************************" << endl;
        cout << "\tEnter 1 to create to New Account." << endl;
        cout << "\tEnter 2 to Add Cash." << endl;
        cout << "\tEnter 3 to Withdraw Cash." << endl;
        cout << "\tEnter 4 to Check Bank Balance." << endl;
        cout << "\tEnter 5 to Exit from the system." << endl;
        cout<<endl;
        cout << "\tPlease Enter Your Choice: ";
        cin >> val;

        if (val == 1)
        {
            openAccount(user);
        }

        else if (val == 2)
        {
            addCash();
        }
        else if (val == 3)
        {
            withdraw();
        }
        else if (val == 5)
        {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(5000);
        }else if(val == 4){
            checkCash();
        }
        Sleep(5000);
    }
}