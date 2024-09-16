#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<graphics.h>
using namespace std;

	void Login();
	void Registration();
	void Forgot();
	
void setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get console handle
    SetConsoleTextAttribute(hConsole, color); // Set text color
}
int main()
{
	int c;
	char n;		//c for choice
	
	setcolor(2);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t__________________________________________________________\n\n";
	cout<<"\t\t\t\t|                    	WELCOME                         |\n\n";
	cout<<"\t\t\t\t|                    	   TO                           |\n\n";
	cout<<"\t\t\t\t|                    	 LOGIN                          |\n\n";
	cout<<"\t\t\t\t|                    	   &                            |\n\n";
	cout<<"\t\t\t\t|                    REGISTRATION                       |\n\n";
	cout<<"\t\t\t\t|                    	  MENU                          |\n\n";
	cout<<"\t\t\t\t|_______________________________________________________|\n\n";
	setcolor(3);
	
	cout<<"\t\t\t\t\t\t\t\t\t Enter anything to go next : ";
	setcolor(4);
	cin>>n;
	
	system("cls");
	setcolor(3);
	cout<<"\n\n\n";
	cout << "\t\t\t|\t  Press 1 to LOGIN                     \t|" <<"\n\n";
    cout << "\t\t\t|\t  Press 2 to REGISTERATION             \t|" <<"\n\n";
    cout << "\t\t\t|\t  Press 3 if you forgot your PASSWORD  \t|" <<"\n\n";
    cout<<  "\t\t\t|\t  press 4 to go in MENU \n\n\n         \t|" <<"\n\n";
	cout << "\n\n\t\t \t  Please enter your choice : ";
    setcolor(4);
    cin >> c;
    cout <<"\n\n";
    switch(c)
    {
    	case 1:
    		Login();
    		break;
    	case 2:
		     Registration();
			 break;
		case 3:
		     Forgot();
			 break;	 	
			 case 4:
			 	system("cls");
			 	main();
			 	break;
    	default:
    		system("cls");
    		setcolor(4);
            cout<<"\t\t Invalid Selection...!\n";
            cout<<"\t\t please select the correct option...!\n";
            main();
    
	}
}
void Login()
{
	int count;
	string userid,password,id,pass;
	system("cls");
	setcolor(13);
	cout<<"\t\t_____________LOGIN____________\n\n";
	cout<<"\t\t Enter the USERNAME & PASSWORD :\n\n";
	cout<<"\t\t\t USERNAME : ";
	cin>>userid;
	cout<<"\n\t\t\t PASSWORD : ";
	cin>>password;
	ifstream input("records.txt");
	while(input>>id>>pass)
	{
		if(id==userid && pass==password)
	{
		count=1;
	}
	}
	input.close();
	if(count==1)
	{
		system("cls");
		setcolor(4);
		cout<<"\n\t\t LOGIN  successfull \n";
		main();
	}
	else
	{
		system("cls");
		setcolor(4);
		cout<<"\n LOGIN ERROR \n please check your userid and password\n";
		main();
	}
}
void Registration()
{
	string ruserid, rpassword, rid, rpass;
    system("cls");
    setcolor(14);
    cout << "\t\t\t Enter the username : ";
    cin >> ruserid;
    cout << "\n\t\t\t Enter the password : ";
    cin >> rpassword;
	ofstream f1("records.txt",ios::app);
	f1 << ruserid << " " << rpassword << endl;
    system("cls");
    setcolor(4);
    cout << "\n\t\t\t Registrationis succesfull! \n";
    main();
}
void Forgot()
{
	int option;
    system("cls");
    setcolor(11);
    cout << "\t\t\t You forgot the password? No Worries \n\n";
    cout << "Press 1 to search your id by username " << endl;
    cout << "press 2 to go to the main menu " << endl;
    cout << "\t\t\t Enter your choice :";
    setcolor(4);
    cin >> option;
    switch (option)
    {
    case 1:
    {
	
    	
        int count = 0;
        string suserid, sid, spass;
        
        setcolor(9);
        cout << "\n\t\t\t Enter the userid which you remembered :";
        setcolor(4);
        cin >> suserid;

        ifstream f2("records.txt");
        while (f2>>sid>>spass)
        {
            if (sid==suserid)
            {
                count =1;
            }
        }
        f2.close();
        
        if(count==1)
        {
        	system("cls");
        	setcolor(4);
            cout << "\n\n Your account is found \n\n";
            cout << "\nYour password is :" << spass;
            main();
    }
        else
        {
		system("cls");
            cout << "\n\t Sorry! your account is not found! \n";
            main();
    }

        break;
}
    case 2:
    system("cls");
    main();
    break;
    
    default:
    	
		system("cls");
    	setcolor(4);
       cout << "\t\t\t Wrong choice ! Please try again " << endl;
     main();
}
}
