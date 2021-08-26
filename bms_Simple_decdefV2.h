// BMS 2.0

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int counter = 0;

class open_account
{
    string fname, lname, occ, add;
    long int mno;
    char gndr;
    int pin;
    float bucks;

    vector<long int> AccountNumber = {666000001, 666000002, 666000003, 666000004, 666000005};
    // AccountNumber.reserve(5);
    vector<string> FirstName;
    // FirstName.reserve(5);
    vector<string> LastName;
    // LastName.reserve(5);
    vector<long int> MobileNumber;
    // MobileNumber.reserve(5);
    vector<char> Gender;
    // Gender.reserve(5);
    vector<string> Occupation;
    // Occupation.reserve(5);
    vector<string> Address;
    // Address.reserve(5);
    vector<int> PassKey;
    // PassKey.reserve(5);
    vector<float> Money = {0.0, 0.0, 0.0, 0.0, 0.0};
    // Money.reserve(5);
    string admin_user_name;
    int admin_pass_key;

public:
    void admin_account(void);
    void open_new_account(void);
    void account_created(void);
    void deposit_money(void);
    void see_updated_account_details(int);
    void update_account_details(void);
    void withdraw_money(void);
    void close_account(void);
    void see_all_account_details(void);
};

void open_account::admin_account(void)
{
    int choice_OpenClose;
    int choice_AdnAcc_Ser;
    cout << endl
         << "---Admin Portal---" << endl
         << endl;
    cout << "Note: ";
    cout << "Admin Account Needed, for Accessing following Service's" << endl;
    cout << "--> Open Account" << endl;
    cout << "--> Close Account" << endl;
    cout << "--> See All Detail's" << endl
         << endl;
    while (1)
    {

        cout << "1. Create Admin Account" << endl;
        cout << "2. Access Admin Service's" << endl;
        cout << "3. To Exit" << endl;
        cout << "Enter [1 - 3] to Access Service: ";
        cin >> choice_AdnAcc_Ser;
        if (choice_AdnAcc_Ser == 1)
        {
            cout << endl
                 << "---Create Admin Account---" << endl
                 << endl;
            cout << "Enter Admin User Name: ";
            cin >> admin_user_name;
            cout << "Enter Admin Pin: ";
            cin >> admin_pass_key;
            cout << endl
                 << "---Admin Account Created Successfuly---" << endl
                 << endl;
        }
        if (choice_AdnAcc_Ser == 2)
        {
            string take_admin_username;
            int take_admin_pin;
            int cmpr;
            cout << endl
                 << "---Login As Admin---" << endl
                 << endl;
            cout << "Enter Admin User Name: ";
            cin >> take_admin_username;
            cout << "Enter Admin Pin: ";
            cin >> take_admin_pin;
            cmpr = take_admin_username.compare(admin_user_name);
            if ((cmpr == 0) && (take_admin_pin == admin_pass_key))
            {
                cout
                    << endl
                    << "---Admin Service's Portal---" << endl
                    << endl;
                cout << "1. Open Account" << endl;
                cout << "2. Close Account" << endl;
                cout << "3. See all Detail's" << endl;
                cout << "Enter [1 - 3] to Access Service: ";
                cin >> choice_OpenClose;
                if (choice_OpenClose == 1)
                {
                    open_new_account();
                }
                if (choice_OpenClose == 2)
                {
                    close_account();
                }
                if (choice_OpenClose == 3)
                {
                    see_all_account_details();
                }
            }
            else
            {
                cout << endl
                     << "You Are Not Admin!" << endl;
                break;
            }
        }

        if (choice_AdnAcc_Ser == 3)
        {
            break;
        }
    }
}

void open_account::open_new_account(void)
{
    char y_n;
    for (int i = counter; i <= counter; i++)
    {
        // cout << counter << endl;
        cout << endl;
        cout << "---OPEN NEW ACCOUNT---" << endl
             << endl;
        cout << "Enter First Name: ";
        cin >> ws;
        getline(cin, fname);
        FirstName.push_back(fname);
        cout << "Enter Last Name: ";
        getline(cin, lname);
        LastName.push_back(lname);
        cout << "Enter Mobile Number: ";
        cin >> mno;
        MobileNumber.push_back(mno);
        cout << "Enter Gender [M | F]: ";
        cin >> gndr;
        Gender.push_back(gndr);
        cout << "Enter Occupation: ";
        cin >> ws;
        getline(cin, occ);
        Occupation.push_back(occ);
        cout << "Enter Address: ";
        getline(cin, add);
        Address.push_back(add);
        cout << "Enter PIN: ";
        cin >> pin;
        PassKey.push_back(pin);
        account_created();
        if (counter <= 4)
        {
            cout << endl
                 << "Do you Want to Add Another Account Press [Y|y] for Yes OR [N|n] for No: ";
            cin >> y_n;
            if ((y_n == 'Y') || (y_n == 'y'))
                counter++;
            else
            {
                counter++;
                break;
            }
        }
    }
}

void open_account::account_created(void)
{
    for (int i = counter; i <= counter; i++)
    {
        cout << endl
             << endl;
        cout << "---Account Created Successfuly---" << endl
             << endl;
        cout << "Account Number: " << AccountNumber.at(i);
        cout.width(35);
        cout << "Pin: " << PassKey.at(i) << endl;
        cout << "Name: " << FirstName.at(i) << " " << LastName.at(i);
        cout.width(55);
        cout << "Mobile Number: " << MobileNumber.at(i) << endl;
        cout << "Gender: " << Gender.at(i);
        cout.width(55);
        cout << "Occupation: " << Occupation.at(i) << endl;
        cout << "Address: " << Address.at(i);
        cout << endl
             << endl;
    }
}

void open_account::deposit_money(void)
{
    long int accno;
    int pin;
    float cash;
    cout << endl
         << "---Deposit Money---" << endl
         << endl;
    cout << "Enter Account Number: ";
    cin >> accno;
    for (int i = 0; i < 5; i++)
    {
        if (accno == AccountNumber.at(i))
        {
            cout << "Enter Pin: ";
            cin >> pin;
            if (pin == PassKey.at(i))
            {
                cout << "Enter Amount: $";
                cin >> ws;
                cin >> cash;
                Money.at(i) = cash + Money.at(i);
                cout << "Current Balance: $" << Money.at(i) << endl
                     << endl;
            }
            break;
        }
        if (i == 4)
        {
            cout << "Account doesn't Exist!" << endl
                 << endl;
            break;
        }
    }
}

void open_account::see_updated_account_details(int X)
{
    cout << endl
         << endl;
    cout << "---Account Detail's---" << endl
         << endl;
    cout << "Account Number: " << AccountNumber.at(X) << endl;
    cout << "Name: " << FirstName.at(X) << " " << LastName.at(X);
    cout.width(55);
    cout << "Mobile Number: " << MobileNumber.at(X) << endl;
    cout << "Gender: " << Gender.at(X);
    cout.width(55);
    cout << "Occupation: " << Occupation.at(X) << endl;
    cout << "Address: " << Address.at(X);
    cout << endl
         << endl;
}

void open_account::update_account_details(void)
{
    int choice_UAD = 0;
    long int accno;
    int pin;
    cout << endl
         << "---Update Information---" << endl
         << endl;

    cout << "Enter Account Number: ";
    cin >> accno;
    for (int i = 0; i < 5; i++)
    {
        if (accno == AccountNumber.at(i))
        {
            cout << "Enter Pin: ";
            cin >> pin;
            if (pin == PassKey.at(i))
            {
                cout << endl
                     << "Press 1 to Update First Name" << endl;
                cout << "Press 2 to Update Last Name" << endl;
                cout << "Press 3 to Update Mobile Number" << endl;
                cout << "Press 4 to Update Occupation " << endl;
                cout << "Press 5 to Update Address " << endl;
                cout << "Press 6 to Update Pin " << endl
                     << endl;
                cout << "Enter [1-6] to Access Service: ";
                cin >> choice_UAD;
                cout << "Choice UAD: " << choice_UAD;
                if (choice_UAD == 1)
                {
                    cout << endl
                         << "---Update First Name---" << endl
                         << endl;
                    cout << "Enter New First Name: ";
                    cin >> ws;
                    getline(cin, fname);
                    FirstName.at(i) = fname;
                    cout << "New First Name: " << FirstName.at(i);
                    see_updated_account_details(i);
                }
                if (choice_UAD == 2)
                {
                    cout << endl
                         << "---Update Last Name---" << endl
                         << endl;
                    cout << "Enter New Last Name: ";
                    cin >> ws;
                    getline(cin, lname);
                    LastName.at(i) = lname;
                    cout << "New Last Name: " << LastName.at(i);
                    see_updated_account_details(i);
                }
                if (choice_UAD == 3)
                {
                    cout << endl
                         << "---Update Mobile Number---" << endl
                         << endl;
                    cout << "Enter New Mobile Number: ";
                    cin >> mno;
                    MobileNumber.at(i) = mno;
                    cout << "New Mobile Number: " << MobileNumber.at(i);
                    see_updated_account_details(i);
                }
                if (choice_UAD == 4)
                {
                    cout << endl
                         << "---Update Occupation---" << endl
                         << endl;
                    cout << "Enter New Occupation: ";
                    cin >> ws;
                    getline(cin, occ);
                    Occupation.at(i) = occ;
                    cout << "New Occupation: " << Occupation.at(i);
                    see_updated_account_details(i);
                }
                if (choice_UAD == 5)
                {
                    cout << endl
                         << "---Update Address---" << endl
                         << endl;
                    cout << "Enter New Address: ";
                    cin >> ws;
                    getline(cin, add);
                    Address.at(i) = add;
                    cout << "New Address: " << Address.at(i);
                    see_updated_account_details(i);
                }
                if (choice_UAD == 6)
                {
                    cout << endl
                         << "---Update Pin---" << endl
                         << endl;
                    cout << "Enter New Pin: ";
                    cin >> pin;
                    PassKey.at(i) = pin;
                    cout << "New Pin: " << PassKey.at(i);
                    see_updated_account_details(i);
                }
            }
        }
        if (i == 4)
        {
            cout << "Account doesn't Exist!";
            break;
        }
    }
}

void open_account::withdraw_money(void)
{
    long int accno;
    int pin;
    float cash = 0;
    cout << endl
         << "---Withdraw Money---" << endl
         << endl;
    cout << "Enter Account Number: ";
    cin >> accno;
    for (int i = 0; i < 5; i++)
    {
        if (accno == AccountNumber.at(i))
        {
            cout << "Enter Pin: ";
            cin >> pin;
            if (pin == PassKey.at(i))
            {
                cout << "Enter Amount: $";
                cin >> cash;
                Money.at(i) = Money.at(i) - cash;
                cout << "Current Balance: $" << Money.at(i) << endl
                     << endl;
            }
            break;
        }
        if (i == 4)
        {
            cout << "Account doesn't Exist!";
            break;
        }
    }
}

void open_account::see_all_account_details(void)
{
    ofstream file_show;
    file_show.open("bms_SimpleV2.txt", ios::out);
    file_show.width(60);
    file_show << " ______________________" << endl
              << endl;
    file_show.width(61);
    file_show << "  Royal Bank of Canada  " << endl;
    file_show.width(60);
    file_show << " ______________________" << endl
              << endl;
    file_show.width(60);
    file_show << endl
              << "---Customers Detail---" << endl
              << endl
              << endl;

    file_show << "S.No";
    file_show.width(18);
    file_show << "Account Number";
    file_show.width(13);
    file_show << "First Name";
    file_show.width(13);
    file_show << "Last Name";
    file_show.width(10);
    file_show << "Gender";
    file_show.width(20);
    file_show << "Occupation";
    file_show.width(20);
    file_show << " Mobile Number";
    file_show.width(23);
    file_show << "Address";
    file_show.width(34);
    file_show << "Balance";

    file_show << endl;

    for (int i = 0; i < counter; i++)
    {
        file_show << i + 1;
        file_show.width(18);
        file_show << AccountNumber.at(i);
        file_show.width(13);
        file_show << FirstName.at(i);
        file_show.width(13);
        file_show << LastName.at(i);
        file_show.width(10);
        file_show << Gender.at(i);
        file_show.width(23);
        file_show << Occupation.at(i);
        file_show.width(20);
        file_show << MobileNumber.at(i);
        file_show.width(27);
        file_show << Address.at(i);
        file_show.width(25);
        file_show << "$" << Money.at(i);
        file_show << endl;
    }
    file_show.close();
}

void open_account::close_account(void)
{
    long int accno;
    char choice_close_account;
    cout << endl
         << "---Close Account---" << endl
         << endl;
    cout << "Enter Account Number: ";
    cin >> accno;
    cout << endl
         << "Do you Really want to Delete Account?" << endl;
    cout << "Press [Y | y] for Yes OR [N | n] for No" << endl;
    cout << endl
         << "Enter your Choice: ";
    cin >> choice_close_account;
    if ((choice_close_account == 'Y') || (choice_close_account == 'y'))
    {
        for (int i = 0; i < counter; i++)
        {
            cout << "Counter: " << counter << endl;
            if (accno == AccountNumber.at(i))
            {

                AccountNumber.erase(AccountNumber.begin() + i);
                FirstName.erase(FirstName.begin() + i);
                LastName.erase(LastName.begin() + i);
                MobileNumber.erase(MobileNumber.begin() + i);
                Gender.erase(Gender.begin() + i);
                Occupation.erase(Occupation.begin() + i);
                Address.erase(Address.begin() + i);
                PassKey.erase(PassKey.begin() + i);
                Money.erase(Money.begin() + i);
                counter--;
            }
        }
    }
    else
    {
        cout << endl
             << "You Discard to Delete Account!" << endl
             << endl;
    }
}
