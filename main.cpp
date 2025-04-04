#include <iostream>
#include <string>
using namespace std;

/** Prints Menu */
void printMenu()
{
    cout << "====Crypto Exchange====" << endl;
    cout << "1- Help." << endl;
    cout << "2- MarketStats." << endl;
    cout << "3- Ask." << endl;
    cout << "4- Bid." << endl;
    cout << "5- Wallet." << endl;
    cout << "6- Exit." << endl;
}

/** Get User Option */
int getUserOption()
{

    int userOption;
    cout << "Enter user option: ";
    cin >> userOption;

    while (cin.fail() || userOption < 1 || userOption > 6)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> userOption;
    }

    return userOption;
}

/** Processess User Option*/
void processUserOption(int userOption)
{

    switch (userOption)
    {
    case 1:
        cout << "Select Option below: " << endl;
        break;
    case 2:
        cout << "Market is growing these days." << endl;
        cout << "Furthermore, stats are shown below." << endl;
        break;
    case 3:
        cout << "Enter your Ask: " << endl;
        break;
    case 4:
        cout << "Enter your bid : " << endl;
        break;
    case 5:
        cout << "Your current balance is : xyz" << endl;
        break;
    case 6:
        cout << "Exitig Program..." << endl;
        exit(0);
    default:
        cout << "Invalid Option, please select a valid option." << endl;
    }
}

int main()
{
    while (true)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
}