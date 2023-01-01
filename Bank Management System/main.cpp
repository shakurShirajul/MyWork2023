/// Shirajul Islam Shakur
/// International Islamic University Chittagong


#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

int CNT=0,TA=0;
string aAC,aPA;

class transection{
public:
    int dd,mm,yy,acc,am;
    string cc;
    ///date, month, year, add/withdraw, account no

    time_t tmNow=time(NULL);;
    struct tm t=*localtime(&tmNow);

    void SET_TRAN(int CHECK, int ACCOUNT,int AMOUNT)
    {
        dd=t.tm_mday;
        mm=t.tm_mon+1;
        yy=t.tm_year+1900;
        if(CHECK==1)
            cc="Add";
        else if(CHECK==0)
            cc="Withdraw";
        acc=ACCOUNT;
        am=AMOUNT;
    }
    void GET_TRAN()
    {
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       "<<dd<<"-"<<mm<<"-"<<yy<<"         "<<cc<<"           "<<am<<"/="<<endl;
    }
};

transection TRAN[1000];

void WRITE_TRAN()   ///Write Transaction
{
    ofstream fout;
    fout.open("transaction.txt");
    for(int i=0;i<TA;i++)
    {
        fout<<TRAN[i].dd<<endl;
        fout<<TRAN[i].mm<<endl;
        fout<<TRAN[i].yy<<endl;
        fout<<TRAN[i].cc<<endl;
        fout<<TRAN[i].am<<endl;
        fout<<TRAN[i].acc<<endl;
    }
    fout.close();
}                   ///

void READ_TRAN()    ///Read Transaction
{
    int i=0;
    ifstream fin;
    fin.open("transaction.txt");
    while(fin)
    {
        fin>>TRAN[i].dd;
        fin>>TRAN[i].mm;
        fin>>TRAN[i].yy;
        fin>>TRAN[i].cc;
        fin>>TRAN[i].am;
        fin>>TRAN[i].acc;
        i++;
    }
    i--;
    TA=i;
    fin.close();
}                   ///


class account{
public:
    string na,fa,ma,date,num,em,add,gen,nat,pass;
    int acNO,balance,type;
    account *next;
    void set_info()
    {
        acNO=1000+CNT+1;
        ///cout<<endl<<endl<<endl<<endl;
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       Name                : ";cin>>na;
        cout<<"                                       Father Name         : ";cin>>fa;
        cout<<"                                       Mother Name         : ";cin>>ma;
        cout<<"                                       Gender              : ";cin>>gen;
        cout<<"                                       Nationality         : ";cin>>nat;
        cout<<"                                       Date of Birth       : ";cin>>date;
        cout<<"                                       Telephone Number    : ";cin>>num;
        cout<<"                                       Email Address       : ";cin>>em;
        cout<<"                                       Address             : ";cin>>add;
        cout<<"                                       Select Account Type"<<endl;
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       [1] Savings Account [2] Student Account"<<endl;
        cout<<"                                       Input: ";cin>>type;
        cout<<"                                       Password            : ";cin>>pass;
        cout<<"                                       Deposit Amount      : ";cin>>balance;
        READ_TRAN();
        TRAN[TA].SET_TRAN(1,acNO,balance);
        TA++;
        WRITE_TRAN();
    }
    void get_info()
    {
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       Account No          : "<<acNO<<endl;
        cout<<"                                       Account Balance     : "<<balance<<endl;
        cout<<"                                       Name                : "<<na<<endl;
        cout<<"                                       Father Name         : "<<fa<<endl;
        cout<<"                                       Mother Name         : "<<ma<<endl;
        cout<<"                                       Gender              : "<<gen<<endl;
        cout<<"                                       Nationality         : "<<nat<<endl;
        cout<<"                                       Date of Birth       : "<<date<<endl;
        cout<<"                                       Telephone Number    : "<<num<<endl;
        cout<<"                                       Email Address       : "<<em<<endl;
        cout<<"                                       Address             : "<<add<<endl;
        cout<<"                                       Password            : "<<pass<<endl;
        if(type==1)
            cout<<"                                       Account Type        : Savings Account"<<endl;
        else if(type==2)
            cout<<"                                       Account Type        : Student Account"<<endl;
    }
};

/// Linked List Work
account * start = new account, *ptr, *save;
/// Linked List Work



void WRITE_FILE()   /// Account Info Read
{
    ofstream fout;
    fout.open("account.txt");
    ptr = start;
    for(int i=0;i<CNT;i++)
    {
        fout<<ptr->na<<endl;
        fout<<ptr->fa<<endl;
        fout<<ptr->ma<<endl;
        fout<<ptr->gen<<endl;
        fout<<ptr->nat<<endl;
        fout<<ptr->date<<endl;
        fout<<ptr->num<<endl;
        fout<<ptr->em<<endl;
        fout<<ptr->add<<endl;
        fout<<ptr->acNO<<endl;
        fout<<ptr->pass<<endl;
        fout<<ptr->balance<<endl;
        ptr = ptr->next;
    }
    fout.close();
}

void READ_FILE()    /// Account Info Read
{
    int i=0;
    ifstream fin;
    fin.open("account.txt");
    ptr = start;
    while(fin)
    {
        fin>>ptr->na;
        fin>>ptr->fa;
        fin>>ptr->ma;
        fin>>ptr->gen;
        fin>>ptr->nat;
        fin>>ptr->date;
        fin>>ptr->num;
        fin>>ptr->em;
        fin>>ptr->add;
        fin>>ptr->acNO;
        fin>>ptr->pass;
        fin>>ptr->balance;
        ptr->next = new account;
        save=ptr;
        ptr = ptr->next;
        i++;
    }
    i--;
    ptr=save;
    CNT = i;
    fin.close();
}

int SEARCH(int check, int num)
{
    READ_FILE();
    WRITE_FILE();
    bool flag=false;
    ptr=start;
    for(int i=0;i<CNT;i++)
    {
        if(ptr->acNO==check)
        {
            flag=true;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==true && num==1)
    {
        int input; string str;
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       [0] Update Telephone Number"<<endl;
        cout<<"                                       [1] Update Email Address"<<endl;
        cout<<"                                       [2] Update Address"<<endl;
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       Input: ";cin>>input;
        if(input==0)
        {
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       [ ] Telephone Number"<<endl;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       Input: ";cin>>str;
            ptr->num=str;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       Operation Successful"<<endl;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       ";system("pause");

        }
        else if(input==1)
        {
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       [ ] Email Address"<<endl;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       Input: ";cin>>str;
            ptr->em=str;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       Operation Successful"<<endl;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       ";system("pause");
        }
        else if(input==2)
        {
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       [ ] Address"<<endl;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       Input: ";cin>>str;
            ptr->add=str;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       Operation Successful"<<endl;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       ";system("pause");
        }
        WRITE_FILE();
    }
    else if(flag==true && num==2)
    {
        int NN=ptr->acNO;
        if(NN==start->acNO)
        {
            start=ptr->next;
        }
        else{
            save=start;
            for(int i=0;i<CNT;i++)
            {
                if(NN==ptr->acNO)
                    save->next=ptr->next;
            }
            save=ptr;
            ptr=ptr->next;
        }
        WRITE_FILE();
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       Operation Successful"<<endl;
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       ";system("pause");
    }
    else if(flag==true && num==4)    /// Search Info
    {
        ptr->get_info();
        cout<<"                                       ";system("pause");
    }
    else if(flag==true && num==5)  /// Add Balance
    {
        int amn;
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       Enter Amount: ";cin>>amn;
        cout<<"                                       -------------------------------------------"<<endl;
        ptr->balance+=amn;
        cout<<"                                       Operation Successful"<<endl;
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       New Balance: "<<ptr->balance<<endl;

        READ_TRAN();
        TRAN[TA].SET_TRAN(1,ptr->acNO,amn);
        TA++;
        WRITE_TRAN();

        WRITE_FILE();
        cout<<"                                       ";system("pause");
    }
    else if(flag==true && num==6)   /// Withdraw
    {
        WITHDRAW:
            bool flag=false;
            int amn1;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       Enter Amount: ";cin>>amn1;
            cout<<"                                       -------------------------------------------"<<endl;
            if(amn1>ptr->balance)
            {
                int no;
                cout<<"                                       Not Enough Fund"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       [1] Enter New Amount"<<endl;
                cout<<"                                       [2] Admin Panel"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Input: ";cin>>no;
                if(no==1)
                {
                    system("cls");
                    goto WITHDRAW;
                }
            }
            else
            {
                flag=true;
                ptr->balance-=amn1;
                cout<<"                                       Operation Successful"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       New Balance: "<<ptr->balance<<endl;
                ///WRITE_FILE();
                cout<<"                                       ";system("pause");
            }
            if(flag==true)
            {
                READ_TRAN();
                TRAN[TA].SET_TRAN(0,ptr->acNO,amn1);
                TA++;
                WRITE_TRAN();
            }
            WRITE_FILE();
    }
    else if(flag==true && num==7)
    {
                cout<<"                                       Operation Successful"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Balance: "<<ptr->balance<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       ";system("pause");
    }
    else if(flag==true && num==8)   /// Transaction
    {
        READ_TRAN();
        int srs = ptr->acNO;
        cout<<"                                       -------------------------------------------"<<endl;
        cout<<"                                       "<<"DATE          "<<"     "<<"Details"<<"           "<<"Amount"<<endl;
        for(int i=0;i<TA;i++)
        {
            if(TRAN[i].acc==srs)
            {
                TRAN[i].GET_TRAN();
            }
        }
        system("pause");
    }
    else
        return -1;
}
void ADMIN_PANEL()
{
    while(1)
    {
        int input;
        system("cls");
        cout<<endl<<endl<<endl<<endl;
        cout<<"                                         Main Menu > Admin Panel"<<endl;
        cout<<"                                         --------------------------------------"<<endl;
        cout<<"                                         [0] Create An Account"<<endl;               /// Complete
        cout<<"                                         [1] Update An Account"<<endl;               /// Complete
        cout<<"                                         [2] Close An Account"<<endl;
        cout<<"                                         [3] Show All Account Information"<<endl;    /// Complete
        cout<<"                                         [4] Search Account Information"<<endl;      /// Complete
        cout<<"                                         [5] Add Balance"<<endl;                     /// Complete
        cout<<"                                         [6] Withdraw Balance"<<endl;                /// Complete
        cout<<"                                         [7] Check Balance"<<endl;                   /// Complete
        cout<<"                                         [8] Transaction History"<<endl;             /// Complete
        cout<<"                                         [9] Logout"<<endl;
        cout<<"                                         --------------------------------------"<<endl;
        cout<<"                                         Input: ";cin>>input;
        if(input==0)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl;
            cout<<"                                       Main Menu > Admin Panel > Create An Account"<<endl;
            READ_FILE();
            ptr->set_info();
            save = ptr;
            CNT++;
            WRITE_FILE();
            system("cls");
            cout<<endl<<endl<<endl<<endl;
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       Account Creation Successful"<<endl;
            cout<<"                                       -------------------------------------------"<<endl;
            save->get_info();
            cout<<"                                       -------------------------------------------"<<endl;
            cout<<"                                       ";system("pause");
        }
        else if(input==1)
        {
            ADMIN_UPDATE:
                system("cls");
                int check;
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                       Main Menu > Admin Panel > Update Account"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       [ ] Account Number"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Input: ";cin>>check;
                cout<<endl;
                int ret = SEARCH(check,1);
                if(ret==-1)
                {
                    int input;
                    system("cls");
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Account Information Not Found"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       [1] Try Again"<<endl;
                    cout<<"                                       [2] Admin Panel"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Input: ";cin>>input;
                    if(input==1)
                        goto ADMIN_UPDATE;
                }

        }
        else if(input==2)
        {
            ADMIN_CLOSE:
                system("cls");
                int check;
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                       Main Menu > Admin Panel > Close Account"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       [ ] Account Number"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Input: ";cin>>check;
                cout<<endl;
                int ret = SEARCH(check,2);
                if(ret==-1)
                {
                    int input;
                    system("cls");
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Account Information Not Found"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       [1] Try Again"<<endl;
                    cout<<"                                       [2] Admin Panel"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Input: ";cin>>input;
                    if(input==1)
                        goto ADMIN_CLOSE;
                }
        }
        else if(input==3)
        {
            system("cls");
            READ_FILE();
            cout<<endl<<endl<<endl<<endl;
            ptr=start;
            cout<<"                                       Main Menu > Admin Panel > Show All Account"<<endl;
            for(int i=0;i<CNT;i++)
            {
                if(i!=0)
                    cout<<endl<<endl;
                ptr->get_info();
                ptr = ptr->next;
            }
            cout<<endl;
            cout<<"                                       ";system("pause");
        }
        else if(input==4)   /// Search Account Information
        {
            ADMIN_SEARCH:
                int check;
                system("cls");
                READ_FILE();
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                       Main Menu > Admin Panel > Search Account"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       [ ] Account Number"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Input: ";cin>>check;
                cout<<endl;
                int ret = SEARCH(check,4);
                if(ret==-1)
                {
                    int input;
                    system("cls");
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Account Information Not Found"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       [1] Try Again"<<endl;
                    cout<<"                                       [2] Admin Panel"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Input: ";cin>>input;
                    if(input==1)
                        goto ADMIN_SEARCH;
                }
        }
        else if(input==5)
        {
            ADMIN_BALANCE:
                system("cls");
                int check;
                READ_FILE();
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                       Main Menu > Admin Panel > Add Balance"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       [ ] Enter Account Number"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Input: ";cin>>check;
                cout<<endl;
                int ret = SEARCH(check,5);
                if(ret==-1)
                {
                    int input;
                    system("cls");
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Account Information Not Found"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       [1] Try Again"<<endl;
                    cout<<"                                       [2] Admin Panel"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Input: ";cin>>input;
                    if(input==1)
                        goto ADMIN_BALANCE;
                }

        }
        else if(input==6)
        {
            ADMIN_WBALANCE:
                system("cls");
                int check;
                READ_FILE();
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                       Main Menu > Admin Panel > Withdraw Balance"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       [ ] Enter Account Number"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Input: ";cin>>check;
                cout<<endl;
                int ret = SEARCH(check,6);
                if(ret==-1)
                {
                    int input;
                    system("cls");
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Account Information Not Found"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       [1] Try Again"<<endl;
                    cout<<"                                       [2] Admin Panel"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Input: ";cin>>input;
                    if(input==1)
                        goto ADMIN_WBALANCE;
                }
        }
        else if(input==7)
        {
            ADMIN_CBALANCE:
                system("cls");
                int check;
                READ_FILE();
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                       Main Menu > Admin Panel > Check Balance"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       [ ] Enter Account Number"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Input: ";cin>>check;
                cout<<endl;
                int ret = SEARCH(check,7);
                if(ret==-1)
                {
                    int input;
                    system("cls");
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Account Information Not Found"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       [1] Try Again"<<endl;
                    cout<<"                                       [2] Admin Panel"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Input: ";cin>>input;
                    if(input==1)
                        goto ADMIN_CBALANCE;
                }
        }
        else if(input==8)
        {
            ADMIN_TRANSACTION:
                system("cls");
                int check;
                READ_FILE();
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                       Main Menu > Admin Panel > Transaction"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       [ ] Enter Account Number"<<endl;
                cout<<"                                       -------------------------------------------"<<endl;
                cout<<"                                       Input: ";cin>>check;
                cout<<endl;
                int ret = SEARCH(check,8);
                if(ret==-1)
                {
                    int input;
                    system("cls");
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Account Information Not Found"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       [1] Try Again"<<endl;
                    cout<<"                                       [2] Admin Panel"<<endl;
                    cout<<"                                       -------------------------------------------"<<endl;
                    cout<<"                                       Input: ";cin>>input;
                    if(input==1)
                        goto ADMIN_TRANSACTION;
                }
        }
        else if(input==9)
        {
            return;
        }
        else
        {
            system("cls");
                string user,pass;
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                         --------------------------------------"<<endl;
                cout<<"                                         Wrong Input"<<endl;
                cout<<"                                         --------------------------------------"<<endl;
                cout<<"                                         ";system("pause");
        }
    }
}
///
void WRITE_ADMIN()
{
    ofstream fout;
    fout.open("admin.txt");
    fout<<aAC<<endl;
    fout<<aPA<<endl;
    fout.close();
}
void READ_ADMIN()
{
    ifstream fin;
    fin.open("admin.txt");
    fin>>aAC;
    fin>>aPA;
    fin.close();
}
///
///
int USER_PANEL(int ACCOUNT_NO)
{
    while(1)
    {
        int input;
        system("cls");
        cout<<endl<<endl<<endl<<endl;
        cout<<"                                         Main Menu > Customer Panel"<<endl;
        cout<<"                                         --------------------------------------"<<endl;
        cout<<"                                         [0] Dashboard"<<endl;           /// Complete
        cout<<"                                         [1] Check Balance"<<endl;       /// Complete
        cout<<"                                         [2] Transaction History"<<endl; /// Complete
        cout<<"                                         [3] Change Password"<<endl;
        cout<<"                                         [4] Logout"<<endl;
        cout<<"                                         --------------------------------------"<<endl;
        cout<<"                                         Input: ";cin>>input;
        if(input==0)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl;
            cout<<"                                       Main Menu > User Panel > Dashboard"<<endl;
            READ_FILE();
            ptr=start;
            for(int i=0;i<CNT;i++)
            {
                if(ptr->acNO==ACCOUNT_NO)
                {
                    break;
                }
                ptr=ptr->next;
            }
            ptr->get_info();
            system("pause");
        }
        else if(input==1)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl;
            READ_FILE();
            ptr=start;
            for(int i=0;i<CNT;i++)
            {
                if(ptr->acNO==ACCOUNT_NO)
                {
                    break;
                }
                ptr=ptr->next;
            }
            cout<<"                                         Main Menu > Customer Panel > Check Balance"<<endl;
            cout<<"                                         --------------------------------------"<<endl;
            cout<<"                                         Balance:                     ";cout<<ptr->balance<<"/="<<endl;
            cout<<"                                         --------------------------------------"<<endl;
            cout<<"                                         ";system("Pause");
        }
        else if(input==2)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl;
            cout<<"                                       Main Menu > Customer Panel > Transaction history"<<endl;
            SEARCH(ACCOUNT_NO,8);
        }
        else if(input==3)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl;
            READ_FILE();
            ptr=start;
            for(int i=0;i<CNT;i++)
            {
                if(ptr->acNO==ACCOUNT_NO)
                {
                    break;
                }
                ptr=ptr->next;
            }
            cout<<"                                         Main Menu > Customer Panel > Change Password"<<endl;
            cout<<"                                         --------------------------------------------"<<endl;
            cout<<"                                         New Password:                     ";cin>>ptr->pass;cout<<endl;
            cout<<"                                         --------------------------------------------"<<endl;
            cout<<"                                         Operation Successful"<<endl;
            cout<<"                                         --------------------------------------------"<<endl;
            WRITE_FILE();
            cout<<"                                         ";system("Pause");
        }
        else
        {
            system("cls");
                string user,pass;
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                         --------------------------------------"<<endl;
                cout<<"                                         Wrong Input"<<endl;
                cout<<"                                         --------------------------------------"<<endl;
                cout<<"                                         ";system("pause");
        }
    }
}
///
int main()
{
    ptr = start;

    while(1)
    {
        MAIN_MENU:
            system("cls");
            int input;
            cout<<endl<<endl<<endl<<endl;
            cout<<"                                         Main Menu"<<endl;
            cout<<"                                         --------------------------------------"<<endl;
            cout<<"                                         [1] Admin Panel"<<endl;
            cout<<"                                         [2] Customer Panel"<<endl;
            cout<<"                                         [3] Close Program"<<endl;
            cout<<"                                         --------------------------------------"<<endl;
            cout<<"                                         Input: ";cin>>input;
            if(input==1)    ///Admin Panel
            {
                MAIN_ADMIN:
                    READ_ADMIN();
                    system("cls");
                    string user,pass;
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                         Main Menu > Admin Login"<<endl;
                    cout<<"                                         --------------------------------------"<<endl;
                    cout<<"                                         Username: ";cin>>user;
                    cout<<"                                         Password: ";cin>>pass;
                    if(user==aAC && pass==aPA)
                    {
                        ADMIN_PANEL();
                    }
                    else
                    {
                        system("cls");
                        int input;
                        cout<<endl<<endl<<endl<<endl;
                        cout<<"                                         Wrong Username Or Password"<<endl;
                        cout<<"                                         --------------------------------------"<<endl;
                        cout<<"                                         [0] Try Again"<<endl;
                        cout<<"                                         [1] Main Menu"<<endl;
                        cout<<"                                         --------------------------------------"<<endl;
                        cout<<"                                         Input: ";cin>>input;
                        if(input==0)
                            goto MAIN_ADMIN;
                        else if(input==1)
                            goto MAIN_MENU;
                    }
            }
            else if(input==2)
            {
                MAIN_USER:
                    system("cls");
                    string pass;
                    int user;
                    cout<<endl<<endl<<endl<<endl;
                    cout<<"                                         Main Menu > User Login"<<endl;
                    cout<<"                                         --------------------------------------"<<endl;
                    cout<<"                                         Account NO : ";cin>>user;
                    cout<<"                                         Password   : ";cin>>pass;
                    READ_FILE();
                    ptr=start;
                    bool flag = false;
                    for(int i=0;i<CNT;i++)
                    {
                        if(ptr->acNO == user && ptr->pass == pass)
                        {
                            flag = true;
                            break;
                        }
                        ptr=ptr->next;
                    }
                    if(flag==true)
                    {
                        USER_PANEL(user);
                    }
                    else
                    {
                        system("cls");
                        int input;
                        cout<<endl<<endl<<endl<<endl;
                        cout<<"                                         Wrong Username Or Password"<<endl;
                        cout<<"                                         --------------------------------------"<<endl;
                        cout<<"                                         [0] Try Again"<<endl;
                        cout<<"                                         [1] Main Menu"<<endl;
                        cout<<"                                         --------------------------------------"<<endl;
                        cout<<"                                         Input: ";cin>>input;
                        if(input==0)
                            goto MAIN_USER;
                        else if(input==1)
                            goto MAIN_MENU;
                    }
            }
            else if(input==3)
            {
                system("cls");
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                         --------------------------------------"<<endl;
                cout<<"                                         Thank You For Using This Program"<<endl;
                cout<<"                                         --------------------------------------"<<endl;
                return 0;
            }
            else
            {
                system("cls");
                string user,pass;
                cout<<endl<<endl<<endl<<endl;
                cout<<"                                         --------------------------------------"<<endl;
                cout<<"                                         Wrong Input"<<endl;
                cout<<"                                         --------------------------------------"<<endl;
                cout<<"                                         ";system("pause");
                cout<<"                                         --------------------------------------"<<endl;
            }
    }
}
