/*Author: Mantasha Abideen
Class: Diploma in Computer Engg. 2nd year, 3rd Semester
Serial No. 12
Date: 5th November 2015*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include"mantasha\grphcs.h"
#include<conio.h>
using namespace std;
bool flag=false;
class account;
account search_no(account obj);
int seek;
class account
{
    private:
        int age,account_no;
        char name[25],address[50];
        float balance;
    public:
        static int account_created;
        void create_new(account obj)
        {
			clrscr();
			drawBox(1,1,78,22,15,1);
			gotoxy(20,5);
            cout<<"Enter Your Name: ";
            fflush(stdin);
            gets(obj.name);
			gotoxy(20,8);
            cout<<"Enter Your Age: ";
            cin>>obj.age;
			gotoxy(20,11);
            cout<<"Enter Your Address: ";
            fflush(stdin);
            gets(obj.address);
			gotoxy(20,14);
            cout<<"Enter Your Initial Balance: ";
            cin>>obj.balance;
            obj.account_no=account_created+2015;
			gotoxy(20,17);
            cout<<"Your Account Number is: "<<obj.account_no;
            ofstream outf("Data\\data.txt",ios::app);
            outf.write((char*)&obj,sizeof(obj));
            outf.close();
            account_created++;
            outf.open("Data\\count.txt");
            outf<<account_created;
            outf.close();//saving 'Z' to file
        }
        void deposit(account obj)
        {
            float deposit_amount;
			clrscr();
			drawBox(1,1,78,22,15,1);
			gotoxy(20,8);
            cout<<"Enter Your Deposit Amount: ";
            cin>>deposit_amount;
            obj.balance+=deposit_amount;
			gotoxy(20,11);
            cout<<"Amount has been Successfully deposited";
			gotoxy(20,13);
			cout<<"Current Balance is "<<obj.balance;
			fstream ipf("Data\\data.txt",ios::out|ios::in);
            ipf.seekp(seek,ios::beg);
            ipf.write((char*)&obj,sizeof(account));
            ipf.close();
        }
        void withdraw(account obj)
        {
            bool successfully_withdraw=false;
            float withdraw_amount;
			clrscr();
			drawBox(1,1,78,22,15,1);
			gotoxy(20,8);
            cout<<"Enter Your Withdraw Amount: ";
            cin>>withdraw_amount;
            do
            {
                if(obj.balance>=withdraw_amount)
                {
                    obj.balance-=withdraw_amount;
					gotoxy(20,11);
                    cout<<"Amount has been Successfully withdrawn.";
					gotoxy(20,13);
					cout<<"Current Balance is "<<obj.balance;
                    successfully_withdraw=true;
                }
                else
                {
					gotoxy(20,13);
                    cout<<"Sorry You do not have sufficient balance";
					gotoxy(20,14);
                    cout<<"Enter some small amount less than "<<obj.balance;
                }
            }
            while(!successfully_withdraw);
            fstream ipf("Data\\data.txt",ios::out|ios::in);
            ipf.seekp(seek,ios::beg);
            ipf.write((char*)&obj,sizeof(account));
            ipf.close();
        }
        void status(account obj)
        {
			clrscr();
			drawBox(1,1,78,22,15,1);
			gotoxy(20,8);
            cout<<"Name: ";
			puts(obj.name);
			gotoxy(20,10);
			cout<<"Account No: "<<obj.account_no;
			gotoxy(20,12);
            cout<<"Current Balance: "<<obj.balance;
        }
        int get_no()
        {
            return account_no-2015;
        }
}a,b,x;
int account::account_created=0;
int main()
{
	BFColor('f','0');
	clrscr();
	setConSize(80,25);
	drawBox2(1,1,78,22,15,1);
    int choice,no;
    ifstream file("Data\\count.txt");
    if(!file)
    {
        system("mkdir Data");
        ifstream file("Data\\count.txt");
    }
    file>>account::account_created;
	file.close();
    do
    {
		clrscr();
		gotoxy(30,2);
		textcolor(3);
		cout<<"Simple Bank Account Program";
		drawXline111(29,3,27,15,2);
		textcolor(1);
		gotoxy(20,8);
	    cout<<"1. Create New Account.";
		gotoxy(20,10);
	    cout<<"2. Deposit Balance.";
		gotoxy(20,12);
	    cout<<"3. Withdraw Balance.";
		gotoxy(20,14);
	    cout<<"4. Check Current Status.";
		gotoxy(20,16);
	    cout<<"5. Exit.";
		gotoxy(20,19);
        cout<<"Enter Your Choice of Mainmenu...: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            a.create_new(b);
            break;
        case 2:
            x=search_no(b);
            if(flag)
                a.deposit(x);
            break;
        case 3:
            x=search_no(b);
            if(flag)
                a.withdraw(x);
            break;
        case 4:
            x=search_no(b);
            if(flag)
                a.status(x);
            break;
		case 5:
			return 0;
        default:
			gotoxy(20,20);
            cout<<"Sorry !!! Invalid Option Try Again";
        }
	getch();
    }
    while(choice!=5);
    return 0;
}
account search_no(account obj)
{
    int n0;
	ifstream inf("Data\\data.txt");
	int a=3;
    do
    {
		clrscr();
		drawBox(1,1,78,22,15,1);
		gotoxy(20,5);
        cout<<"Enter Account No: ";
        cin>>n0;
		n0-=2015;
		seek=0;
        if(!inf)
        {
            gotoxy(10,8);
            cout<<"Error: Can't proceed due to unavailability of the database";
            flag = false;
            return obj;
        }
        gotoxy(30,7);
        cout<<"Please Wait";
        if(n0>=0&&n0<account::account_created)
        {
            for(int i=0;i<account::account_created;i++)
            {
                seek=inf.tellg();
                inf.read((char*)&obj,sizeof(account));
                if(obj.get_no()==n0)
                {
                    flag = true;
                    inf.close();
                    return obj;
                }
                else
                {
                    gotoxy(20+i*10,8);
                    for(int j=0;j<10;j++)
                    {
                        cout<<".";
                        delay(20);
                    }
                }
            }
        }
        else
        {
			gotoxy(20,6);
            cout<<"Sorry Account Number is Invalid";
			gotoxy(20,7);
			cout<<"Please Try Again...";
			getch();
        }
        a--;
    }while(a);
    flag = false;
}
