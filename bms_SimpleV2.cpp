#include <iostream>
#include "bms_Simple_decdefV2.h"
using namespace std;

// Driver-Code

int main()
{
    open_account o;

    int choice;
    cout << "   ----Welcome To----" << endl;
    cout << " ______________________" << endl
         << endl;
    cout << "  Royal Bank of Canada    " << endl;
    cout << " ______________________" << endl
         << endl;
    while (1)
    {
        cout << endl;
        cout << "Our Services:  " << endl;
        cout << "1. Admin Account " << endl;          // done
        cout << "     (i)  Open New Account" << endl; // done
        cout << "     (ii) Close Account" << endl;
        cout << "     (iii) See All Account Details" << endl;
        cout << "2. Deposit Money" << endl;  // done
        cout << "3. Update Account" << endl; // done
        cout << "4. Withdraw Money" << endl; // done
        cout << "5. Exit" << endl;           // done
        cout << endl
             << "Enter [1-5] to Access Service: ";
        cin >> choice;

        if (choice == 1)
        {
            o.admin_account();
        }
        if (choice == 2)
        {
            o.deposit_money();
        }
        if (choice == 3)
        {
            o.update_account_details();
        }
        if (choice == 4)
        {
            o.withdraw_money();
        }
        if (choice == 5)
        {
            cout << endl
                 << "Thanks for using our Program!" << endl
                 << endl;
            break;
        }
    }
    return 0;
}