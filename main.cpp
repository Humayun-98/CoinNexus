#include <iostream>
#include <string>
#include <vector>

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

/** enum class*/
enum class orderBookType
{
    bid,
    ask
};

/** orderBookEntry Type*/
class orderBookEntry
{
public:
    orderBookEntry(double _price,
                   double _amount,
                   string _timestamp,
                   string _product,
                   orderBookType _orderType)
        : price(_price),
          amount(_amount),
          timestamp(_timestamp), // Clean way to write constructo.
          product(_product),     // Preferred way.
          orderType(_orderType)

    {
        // this->price = price;
        // this->amount = amount;                                  4th Modification
        // this->timestamp = timestamp;
        // this->product = product;
        // this->orderType = orderType;
    }

    double price;
    double amount;
    string timestamp;
    string product;
    orderBookType orderType;
};

int main()
{

    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();                          Main Function - for 1st and 2nd versios
    //     processUserOption(userOption);
    // }

    vector<orderBookEntry> orders;
    orders.push_back(orderBookEntry(5319.450228, 0.0020075, "2020/03/17 17:01:24.884492", "BTC/USDT", orderBookType::bid));
    orders.push_back(orderBookEntry(6000.450228, 0.00450075, "2020/03/17 17:01:24.884492", "BTC/USDT", orderBookType::ask));

    // Iterative Styel Loop
    // for (orderBookEntry order : orders) //it creates a copy of each orders' object to order variable
    // {                                   //then we process our data, to avoid that, use pass-by-reference
    //     cout << order.price << endl;    // as orderBookEntry& and it would directly access the object
    // }                                    //without creating its copy

    // Array style loop
    // for (unsigned int i = 0; i < orders.size(); ++i)     //unsigned int is used to save memory as
    // {                                                    //signed int stores a bit for sign each time
    //     cout << orders[i].price << endl;                 //and there are no negative indexes in vectors
    // }                                                    //++i is the best practice as i++ creates copy
    //                                                      // of i and there increase it by 1.
    //                                                      //++i avoids it.

    // Object Style Loop
    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        cout << orders.at(i).price << endl; //.at)() is useful for bound checking.
    }

    return 0;
}