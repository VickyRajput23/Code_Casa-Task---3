#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout<<"\t\t\t_____________________________________________________________________________\n\n\n";
    cout<<"\t\t\t|                                                                            |\n\n\n";
    cout<<"\t\t\t|                           WELCOME TO THE LOGIN PAGE                        |\n\n\n";
    cout<<"\t\t\t|                                                                            |\n\n\n";
    cout<<"\t\t\t______________________________________________________________________________\n\n";
    cout<<"\t\t\t__________________________           MENU          ___________________________\n\n\n";
    cout<<"\t\t\t|                           Press 1 to LOGIN                                |"<<endl;
    cout<<"\t\t\t|                           Press 2 to REGISTER                             |"<<endl;
    cout<<"\t\t\t|                           Press 3 if FORGOT PASSWORD                      |"<<endl;
    cout<<"\t\t\t|                           Press 4 to EXIT                                 |"<<endl;
    cout<<"\t\t\t|                                                                           |\n\n\n";
    cout<<"\t\t\t_____________________________________________________________________________\n\n\n";
    cout<<"\n\t\t\t                          Please Enter Your Choice : ";
    cin>>c;
    cout<<endl;

    switch(c)
    {
        case 1:
        login();
        break;

        case 2:
        registration();
        break;

        case 3:
        forgot();
        break;

        case 4:
        cout<<"\t\t\t  THANK YOU!!  \n\n";

        default:
        system("cls");
        cout<<"\t\t\t Please Select From The Options given above \n "<<endl;
        main();

    }
}
void login()
{
    int count;
    string userId, password, id , pass;
    system("cls");
    cout<<"\t\t\t  Please Enter The Username And Password : "<<endl;
    cout<<"\t\t\t  USERNAME : ";
    cin>>userId;
    cout<<"\t\t\t  PASSWORD : ";
    cin>>password;

    // this function checks that inside the file if that login password is exist or not
    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {

        cout<<"\t"<<userId<<"\t\n  Your Login Is Successful  \n\n  Thanks For Logging In !  \n";
        main();
    }
    else
    {
        cout<<"\n LOGIN ERROR \n  Please Check You Username and Password \n";
        main();
    }

}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout<<"\t\t\t    Enter The Username : ";
    cin>>ruserId;
    cout<<"\t\t\t    Enter The Password : ";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n \t\t\t  REGISTRTION IS SUCCESSFUL  \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t  You Forgot The Password ? No Worries \n";
    cout<<"\t\t\t  Press 1 to Search Id By Usernaame "<<endl;
    cout<<"\t\t\t  Press 2 To Go Back To The Main Menu "<<endl;
    cout<<"\t\t\t  Enter Your Choice :";
    cin>>option;
    switch(option)
    {
      case 1 :
      {
        int count = 0;
        string suserId, sId, spass;
        cout<<"\n \t\t\t  Enter the username Which You Remebered : ";
        cin>>suserId;



        // Checking Inside the file if the Id and password there and If that ID is there then we'll asign 1 to the count
        ifstream f2("records.txt");
        while(f2>>sId>>spass)
        {
            if(sId==suserId)
            {
                count = 1;
            }

        }
        f2.close();
        if(count==1)
        {
            cout<<"\n\n Your Account is Found! :) \n";
            cout<<"\n\n Your Password is :"<<spass<<endl;
            main();

        }

        else
        {
            cout<<"\n\t  Sorry! Your Account Is Not Found :( \n";
            main();

        }
        break;
      }

      case 2 :

       {
        main();
       }
       default:
       cout<<"\t\t\t  Wrong Choice! Pleas Try Again"<<endl;
       forgot();



    }

}

