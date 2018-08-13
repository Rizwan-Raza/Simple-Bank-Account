#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int search_no(char[]);
class account
{
    private:
        int age;
        char name[25],address[50],account_no[17];
        float balance;
        static int account_created;
    public:
        void create_new()
        {
            account_created++;
            cout<<"Enter Your Name: ";
            cin>>name;
            cout<<"Enter Your Age: ";
            cin>>age;
            cout<<"Enter Your Address: ";
            cin>>address;
            cout<<"Enter Your Desired Account No: ";
            cin>>account_no;
            cout<<"Enter Your Initial Balance: ";
            cin>>balance;
        }
        void deposit()
        {
            float deposit_amount;
            cout<<"Enter Your Deposit Amount: ";
            cin>>deposit_amount;
            balance+=deposit_amount;
            cout<<"Amount has been Successfully deposited.\nCurrent Balance is "<<balance<<endl;
        }
        void withdraw()
        {
            bool successfully_withdraw=false;
            float withdraw_amount;
            cout<<"Enter Your Withdraw Amount: ";
            cin>>withdraw_amount;
            do
            {
                if(balance>=withdraw_amount)
                {
                    balance-=withdraw_amount;
                    cout<<"Amount has been Successfully withdrawn.\nCurrent Balance is "<<balance;
                    successfully_withdraw=true;
                }
                else
                {
                    cout<<"Sorry You dont't have sufficient balance";
                }
            }
            while(!successfully_withdraw);
        }
        void status()
        {
            cout<<"Name: "<<name<<endl<<"Account No: "<<account_no<<endl;
            cout<<"Current Balance: "<<balance<<endl;
        }
        static int get_count()
        {
            return account_created;
        }
        char* get_no()
        {
            return account_no;
        }
};
int account::account_created=0;
account *a;
int main()
{
    char no[17];
    int capacity;
    int choice;
    cout<<"Enter No of Storing Capacity of Accounts: "<<endl;
    cin>>capacity;
    a=(account *)malloc(capacity*sizeof(account));
    cout<<"1. Create New Account"<<endl;
    cout<<"2. Deposit Balance"<<endl;
    cout<<"3. Withdraw Balance"<<endl;
    cout<<"4. Check Current Status"<<endl;
    cout<<"5. Exit"<<endl;
    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            a[account::get_count()].create_new();
            break;
        case 2:
            cout<<"Enter Account No: ";
            cin>>no;
            a[search_no(no)].deposit();
            break;
        case 3:
            cout<<"Enter Account No: ";
            cin>>no;
            a[search_no(no)].withdraw();
            break;
        case 4:
            cout<<"Enter Account No: ";
            cin>>no;
            a[search_no(no)].status();
        }
    }
    while(choice!=5);
    return 0;
}
int search_no(char n0[17])
{
    for(int i=0;i<account::get_count();i++)
    {
        if(!strcmp(a[i].get_no(),n0))
            return i;
    }
}
