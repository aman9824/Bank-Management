/*--------------------------------------------------------*/
/*	            Header files                              */
/*--------------------------------------------------------*/
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>

/*--------------------------------------------------------*/
/*                                Structure	                        */
/*--------------------------------------------------------*/

struct costumer
{
	int accno;
	char name[30];
	char sex[8];
	char address[100];
	char occupation[30];
	char designation[30];
	char ms[30];
	char acctype[10];
	int age;
	char mono[11];
	int bal;
};

struct employee
{
	int empno;
	char name[30];
	char sex[8];
	char address[100];
	char qualification[50];
	char ms[30];
	int age;
	char branch[30];
	char mono[11];
	char salary[10];
	int leave;
};

struct security
{	int accno;
	char name[30];
	char address[100];
	char mobile[11];
	int lockno;
	int pin;
};

struct loan
{
	int accno;
	char scheme[30];
	char name[30];
	char address[100];
	int pincode;
	char collateral[30];
	int deposit;
	char type[20];
	int rate;
	int down;
	int month;
	int year;
};

/*---------------------------------------------------------*/
/*                           Function Protoype             */
/*---------------------------------------------------------*/

void menuc(costumer c[5],int);
void createc(costumer c[5],int);
void deposit(costumer c[5],int);
void withdraw(costumer c[5],int);
void modify(costumer c[5],int);
void holder(costumer c[5],int);
void balance(costumer c[5],int);

void menue(employee e[5],int);
void createe(employee e[5],int);
void search(employee e[5],int);
void sort(employee e[5],int);
void modifye(employee e[5],int);
void holdere(employee e[5],int);
void leave(employee e[5],int);

void menus(security s[5],int);
void createlo(security s[5],int);
void holderlo(security s[5],int);
void locker(security s[5],int);
void pin(security s[5],int);

void menul(loan l[5],int);
void createl(loan l[5],int);
void holderl(loan l[5],int);
void scheme(loan l[5],int);
void information(loan l[5],int);
void doc(loan l[5],int);

void about();
void home();
void pass();


/*--------------------------------------------------------*/
/*	              Main   		     */
/*--------------------------------------------------------*/

main()
{
	clrscr();
	textcolor(14);
	cprintf("\n\n\n                                Introduction\n\n\n\n\n");
	cout<<"\n     Axis Bank Gold Loan portfolio is the largest in India as well as"<<endl;
	cout<<"\n     naround the globe. It is humbling to know that more than 2,53,000"<<endl;
	cout<<"\n     npeople avail our trusted services on a daily basis."<<endl;
	delay(1000);
	delay(1000);
	pass();				//to check the correct user
	getch();
	return 0;
}

/*---------------------------------------------------------*/
/*	            Functions                                   */
/*---------------------------------------------------------*/

void pass()		//to check right user
{
	int count=0;
	while(count<3)
	{
		clrscr();
		char us[]={"Admin"},user[10];
		char pass[10],ch,p[10]={"bank"};
		int k=0;
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tEnter Username :- ";
		cin.getline(user,10);
		cout<<"\t\t\tEnter Passcode :- ";
		while((ch=getch())!=13)
		{
			pass[k]=ch;
			k++;
			cout<<"*";
		}
		pass[k]='\0';
		if(strcmp(user,us)==0)
		{
			if(strcmp(p,pass)==0)
			{	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tloading";
				delay(300);
				cout<<".";
				delay(300);
				cout<<".";
				home();
			}
			else
			{       clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tIncorrect Password or Username";
				delay(1000);
				delay(1000);
				count++;
			}
		}
		else
		{       clrscr();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tIncorrect Passcode or Username";
			delay(1000);
				count++;
		}
	}
	exit(0);
}
//*********************************************************************************************************

void home()		       //to view main menu and perform further functions
{	clrscr();
	int n=3;
	costumer c[]={
			{101,"Aman","Male","Uma Bhavnai Soc.","Engineer","Apple","Single","Saving",22,"9824577699",8000},
			{102,"Naman","Female","Swagat Bunglows","-","-","Single","Saving",26,"9876543211",6489},
			{103,"Chirag","Male","Aditya Residency","Bussinessman","-","Single","Current",25,"9898337228",2000},
		    };
	loan l[]={
		{12,"ASL","Aman","Uma Bhavani Soc.",382470,"Land",15000,"Saving",21,2500,5,1},
		{11,"AML","Naman","Swagat Bunglows",382471,"Gold",10000,"Saving",24,2000,3,1},
		{19,"ASL","Chirag","Aditya Residency",383824,"Land",20000,"Current",20,5000,1,3},
		 };
	employee e[]={
			{101,"Aman","Male","Uma Bhavnai Soc.","MBA","Single",22,"Chandkheda","9824577699","80000",7},
			{102,"Naman","Female","Swagat Bunglows","CA","Single",26,"Chandkheda","9876543211","62489",4},
			{103,"Chirag","Male","Swagat Bunglows","MBA","Single",25,"Chandkheda","9898337228","200000",9},
	       };
	security s[]={
			{101,"Aman","Uma Bhavni soc.","9898337228",101,1234},
			{102,"Naman","Swagat Bunglows","9377172484",102,2345},
			{103,"Chirag","Aditya Residency","9377172894",103,3456},
		};
	int ch=0;
	cout<<"\n\n\t\t\t\tMAIN MENU";
	cout<<"\n\n\t01. COSTUMER";
	cout<<"\n\n\t02. EMPLOYES";
	cout<<"\n\n\t03. SECURITY";
	cout<<"\n\n\t04. Loan";
	cout<<"\n\n\t05. ABOUT US";
	cout<<"\n\n\t06. EXIT";
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-6) ";
	cin>>ch;
	switch(ch)
	{
		case 1 : menuc(c,n);		//to access customer menu
		       break;
		case 2 : menue(e,n);		//to access employee menu
		       break;
		case 3 : menus(s,n);		//to access security menu
		       break;
		case 4 : menul(l,n);		//to access loan menu
		       break;
		case 5 : about();
		       break;
		default : exit(0);		//to exit
	}
}


/*---------------------------------------------------------*/
/*	            Functions Costumer                 */
/*---------------------------------------------------------*/

void menuc(costumer c[5],int n)
{	clrscr();
	int ch=0;
	cout<<"\n\n\t\t\t\t Costumer MENU";
	cout<<"\n\n\t01. NEW ACCOUNT";
	cout<<"\n\n\t02. DEPOSIT AMOUNT";
	cout<<"\n\n\t03. WITHDRAW AMOUNT";
	cout<<"\n\n\t04. BALANCE ENQUIRY";
	cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
	cout<<"\n\n\t06. MODIFY AN ACCOUNT TYPE";
	cout<<"\n\n\t07. ABOUT US";
	cout<<"\n\n\t08. MAIN MENU";
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-8) ";
	cin>>ch;
	switch(ch)
	{
		case 1 : createc(c,n);		//to create new account
		       break;
		case 2 : deposit(c,n);		//to deposit money
		       break;
		case 3 : withdraw(c,n);		//to withraw money
		       break;
		case 4 : balance(c,n);		//to check balance of account
		       break;
		case 5 : holder(c,n);		//To check account holder
		       break;
		case 6 : modify(c,n);		//for modification of account
		       break;
		case 7 : about();		//Information of bank
		       break;
		case 8 : home();
		       break;
		default : 	{	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Option Selected.";
				delay(1000);
				delay(1000);
				exit(0);
			}
	}

}
//*********************************************************************************************************

void createc(costumer c[5],int n)		//To add new account
{
	clrscr();
	cout<<"\n\n\t\t\t\tCreate New Account"<<endl;
	char q,z;
	int r;
	for(int i=3;i<=n;i++)
	{
		cout<<"\n\nEnter Name :-"<<endl;
		gets(c[i].name);
		cout<<"Enter type of acc. you want to create"<<endl;
		gets(c[i].acctype);
		cout<<"Enter your address :-"<<endl;
		gets(c[i].address);
		cout<<"Enter your Sex :-"<<endl;
		gets(c[i].sex);
		cout<<"Enter your Account Number :-"<<endl;
		cin>>c[i].accno;
		cout<<"Enter your mobile no. :-"<<endl;
		gets(c[i].mono);
		cout<<"Enter your age :-"<<endl;
		cin>>c[i].age;
		cout<<"Your Marritial Status :- "<<endl;
		cin>>c[i].ms;
		cout<<"Your Occupation :-"<<endl;
		cin>>c[i].occupation;
		cout<<"Your Designation :-"<<endl;
		cin>>c[i].designation;
		cout<<"Your Account has been successfully created"<<endl;

		cout<<"==========================================="<<endl;

		cout<<"Account Number :-"<<c[i].accno<<endl;
		cout<<"Name :-"<<c[i].name<<endl;
		cout<<"Sex :-"<<c[i].sex<<endl;
		cout<<"Address :-"<<c[i].address<<endl;
		cout<<"Occupation :-"<<c[i].occupation<<endl;
		cout<<"Designation :-"<<c[i].designation<<endl;
		cout<<"Marritial Status :-"<<c[i].ms<<endl;
		cout<<"Mobile Number :-"<<c[i].mono<<endl;
		cout<<"Account Type :-"<<c[i].acctype<<endl;
		cout<<"Age :-"<<c[i].age<<endl;
		cout<<"Account Balance :-"<<c[i].bal<<endl;

		cout<<"==========================================="<<endl;
		cout<<"Do you want to continue y/n:-";	
		cin>>z;
		if(z=='y')
		{	n++;	}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menuc(c,3);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void withdraw(costumer c[5],int y)		//to withdraw money
{	clrscr();
	cout<<"\n\n\t\t\t\t Withdraw Money"<<endl;
	char q;
	int n,x,i;
	cout<<"\n\nEnter Account Number(101-103):-";
	cin>>n;
	for(i=0;i<y;i++)
	{
		if(c[i].accno==n)
		{
			cout<<"Name :-"<<c[i].name<<endl;
			cout<<"Sex :-"<<c[i].sex<<endl;
			cout<<"Address :-"<<c[i].address<<endl;
			cout<<"Occupation :-"<<c[i].occupation<<endl;
			cout<<"Designation :-"<<c[i].designation<<endl;
			cout<<"Marritial Status :-"<<c[i].ms<<endl;
			cout<<"Mobile Number :-"<<c[i].mono<<endl;
			cout<<"Account Type :-"<<c[i].acctype<<endl;
			cout<<"Age :-"<<c[i].age<<endl;
			cout<<"Account Balance :-"<<c[i].bal<<endl;
		}

	}
	cout<<"Enter Money to be withrawn"<<endl;
	cin>>x;
	for(i=0;i<y;i++)
	{
		if(c[i].accno==n)
		{
			if(c[i].bal>x)
				{	c[i].bal=c[i].bal-x;
					cout<<"The Remaning Balance is:"<<c[i].bal<<endl;
				}
			else
				{
					cout<<"\nNot Sufficent balance in your account";
				}

		}

	}
	cout<<"\nDo you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menuc(c,y);	}
	else
	{	exit(0);	}

}
//*********************************************************************************************************

void deposit(costumer c[5],int y)		//to deposit money
{	clrscr();
	cout<<"\n\n\t\t\t\t Deposit Money"<<endl;
	char q;
	int n,x,i;
	cout<<"\n\nEnter Account Number(101-103):-";
	cin>>n;
	for(i=0;i<y;i++)
	{
		if(c[i].accno==n)
		{
			cout<<"Name :-"<<c[i].name<<endl;
			cout<<"Sex :-"<<c[i].sex<<endl;
			cout<<"Address :-"<<c[i].address<<endl;
			cout<<"Occupation :-"<<c[i].occupation<<endl;
			cout<<"Designation :-"<<c[i].designation<<endl;
			cout<<"Marritial Status :-"<<c[i].ms<<endl;
			cout<<"Mobile Number :-"<<c[i].mono<<endl;
			cout<<"Account Type :-"<<c[i].acctype<<endl;
			cout<<"Age :-"<<c[i].age<<endl;
			cout<<"Account Balance :-"<<c[i].bal<<endl;
		}
	}
	cout<<"Enter Money to be Deposit";
	cin>>x;
	for(i=0;i<3;i++)
	{
		if(c[i].accno==n)
		{

				c[i].bal=c[i].bal+x;
				cout<<"The Remaning Balance is:-"<<c[i].bal<<endl;


		}

	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menuc(c,y);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void balance(costumer c[5],int y)		//to check balance
{	clrscr();
	cout<<"\n\n\t\t\t\tBalance Enquriey"<<endl;
	char q;
	int n;
	cout<<"\n\nEnter Account No. whose Information You Want to search :-";
	cin>>n;
	for(int i=0;i<y;i++)
	{
		if(c[i].accno==n)
		{
			cout<<"Name :-"<<c[i].name<<endl;
			cout<<"Sex :-"<<c[i].sex<<endl;
			cout<<"Address :-"<<c[i].address<<endl;
			cout<<"Occupation :-"<<c[i].occupation<<endl;
			cout<<"Designation :-"<<c[i].designation<<endl;
			cout<<"Marritial Status :-"<<c[i].ms<<endl;
			cout<<"Mobile Number :-"<<c[i].mono<<endl;
			cout<<"Account Type :-"<<c[i].acctype<<endl;
			cout<<"Age :-"<<c[i].age<<endl;
			cout<<"Account Balance :-"<<c[i].bal<<endl;
		}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menuc(c,n);	}
	else
	{	exit(0);	}

}
//*********************************************************************************************************

void modify(costumer c[5],int y)		//to modify account
{	clrscr();
	cout<<"\n\n\t\t\t\tChange Account Type"<<endl;
	char a[]={"Saving"},q;
	int n,x,i;
	cout<<"\n\nEnter Account Number (101-103) whose Type Is to be changed:-"<<endl;
	cin>>n;
	for(i=0;i<y;i++)
	{
		if(c[i].accno==n)
		{
			cout<<"Initial Account Type :-"<<c[i].acctype<<endl;
			if(strcmp(c[i].acctype,a)==0)
			{	strcpy(c[i].acctype,"current");	}
			else
			{	strcpy(c[i].acctype,"saving");	}
			cout<<"Name :-"<<c[i].name<<endl;
			cout<<"Sex :-"<<c[i].sex<<endl;
			cout<<"Address :-"<<c[i].address<<endl;
			cout<<"Occupation :-"<<c[i].occupation<<endl;
			cout<<"Designation :-"<<c[i].designation<<endl;
			cout<<"Marritial Status :-"<<c[i].ms<<endl;
			cout<<"Mobile Number :-"<<c[i].mono<<endl;
			cout<<"Account Type :-"<<c[i].acctype<<endl;
			cout<<"Age :-"<<c[i].age<<endl;
			cout<<"Account Balance :-"<<c[i].bal<<endl;
		}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menuc(c,n);	}
	else
	{	exit(0);	}

}
//*********************************************************************************************************

void holder(costumer c[5],int y)		//\to check account holders
{	clrscr();
	cout<<"\n\n\t\t\t\tAccount Holders"<<endl;
	char q;
	for(int i=0;i<y;i++)
	{
		cout<<"\n\n==========================================="<<endl;

		cout<<"Account Number :-"<<c[i].accno<<endl;
		cout<<"Name :-"<<c[i].name<<endl;
		cout<<"Sex :-"<<c[i].sex<<endl;
		cout<<"Address :-"<<c[i].address<<endl;
		cout<<"Occupation :-"<<c[i].occupation<<endl;
		cout<<"Designation :-"<<c[i].designation<<endl;
		cout<<"Marritial Status :-"<<c[i].ms<<endl;
		cout<<"Mobile Number :-"<<c[i].mono<<endl;
		cout<<"Account Type :-"<<c[i].acctype<<endl;
		cout<<"Age :-"<<c[i].age<<endl;
		cout<<"Account Balance :-"<<c[i].bal<<endl;

		cout<<"==========================================="<<endl;
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menuc(c,y);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void about()		//Inforamtion of bank
{	clrscr();
	cout<<"\n\n\t\t\t\tAbout Us";
	char q;
	cout<<"\n\n\tWelcom to the Axis Bank";
	cout<<"\n\n\tBranch Manager :- Aman Patel";
	cout<<"\n\n\tBranch :- Chandkehda";
	cout<<"\n\n\tContact Number :- 9512577699";
	cout<<"\n\n\tThank You For Visiting ";
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{      home();	}
	else
	{	exit(0);	}
}


/*---------------------------------------------------------*/
/*	            Functions Employee                 */
/*---------------------------------------------------------*/

void menue(employee e[5],int n)
{	clrscr();
	char q;
	int ch=0;
	cout<<"\n\n\t\t\t\tEmployee MENU";
	cout<<"\n\n\t01. NEW EMPLOYEE";
	cout<<"\n\n\t02. Search Employee";
	cout<<"\n\n\t03. Sort by name";
	cout<<"\n\n\t04. Apply for leave";
	cout<<"\n\n\t05. Employee List;";
	cout<<"\n\n\t06. SHIFT TO ANOTHER BRANCH";
	cout<<"\n\n\t07. About";
	cout<<"\n\n\t08. MAIN MENU";
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-8) ";
	cin>>ch;
	switch(ch)
	{
		case 1 : createe(e,n);		//to enter information of new employee
		       break;
		case 2 : search(e,n);		//to search employee inforamtion
		       break;
		case 3 : sort(e,n);		//to sort employee by name
		       break;
		case 4 : leave(e,n);		//to check number of leaves taken
		       break;
		case 5 : holdere(e,n);		//to check employees inforamtions
		       break;
		case 6 : modifye(e,n);		//to modify barnch from chand. to nav.
		       break;
		case 7 : about();		//Bank information
		       break;
		case 8 : home();
			break;
		default : 	{	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Option Selected.";
				delay(1000);
				delay(1000);
				exit(0);
			}
	}

}
//*********************************************************************************************************

void createe(employee e[5],int n)	  //to add new employee information
{	clrscr();
	cout<<"\n\n\t\t\t\tNew Employee"<<endl;
	char q,z;
	int r;
	for(int i=2;i<n;i++)
	{
		cout<<"\n\nEnter Your name :-";
		gets(e[i].name);
		cout<<"Enter your sex :-";
		gets(e[i].sex);
		cout<<"Enter your address:-";
		gets(e[i].address);
		cout<<"Enter your qualification :-";
		gets(e[i].qualification);
		cout<<"Your marritial Status";
		gets(e[i].ms);
		cout<<"Enter your age:-";
		cin>>e[i].age;
		cout<<"Enter Mobile Number:-";
		gets(e[i].mono);
		cout<<"Enter your salary:-";
		gets(e[i].salary);
		cout<<"You have successfuly become employee of Axis Bank"<<endl;
		cout<<"==========================================="<<endl;
		cout<<"Employee Number :-"<<e[i].empno<<endl;
		cout<<"Name :-"<<e[i].name<<endl;
		cout<<"Sex :-"<<e[i].sex<<endl;
		cout<<"Address :-"<<e[i].address<<endl;
		cout<<"Qualification"<<e[i].qualification<<endl;
		cout<<"Marritial Status :-"<<e[i].ms<<endl;
		cout<<"Branch :-"<<e[i].branch<<endl;
		cout<<"Mobile Number :-"<<e[i].mono<<endl;
		cout<<"Leave :-"<<e[i].leave<<endl;
		cout<<"Age :-"<<e[i].age<<endl;
		cout<<"Salary :-"<<e[i].salary<<endl;
		cout<<"Do you want to continue y/n:-";	
		cin>>z;
		if(z=='y')
		{	n++;	}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menue(e,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void sort(employee e[5],int n)		//To short employee by name
{	clrscr();
	cout<<"\n\n\t\t\t\tEmployee sort by Name"<<endl;
	char q;
	int j;
	char t[10];
	cout<<"\n\nName of Employee in  increasing order :-"<<endl;
	for(int i=0;i<n;i++)
	{	for(j=i+1;j<n;j++)
		{	if(strcmp(e[i].name,e[j].name)>0)
			{
				strcpy(t,e[i].name);
				strcpy(e[i].name,e[j].name);
				strcpy(e[j].name,t);
			}
		}
		cout<<i+1<<"."<<e[i].name<<endl;
	}

	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menue(e,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void search(employee e[5],int y)		//to search employee
{	clrscr();
	cout<<"\n\n\t\t\t\tSearch Employee"<<endl;
	int n;
	char q;
	cout<<"\n\nEnter Employee no. :-";
	cin>>n;
	for(int i=0;i<y;i++)
	{
		if(e[i].empno==n)
		{
			cout<<"\nEmployee Number :-"<<e[i].empno<<endl;
			cout<<"Name :-"<<e[i].name<<endl;
			cout<<"Sex :-"<<e[i].sex<<endl;
			cout<<"Address :-"<<e[i].address<<endl;
			cout<<"Qualification"<<e[i].qualification<<endl;
			cout<<"Marritial Status :-"<<e[i].ms<<endl;
			cout<<"Branch :-"<<e[i].branch<<endl;
			cout<<"Mobile Number :-"<<e[i].mono<<endl;
			cout<<"Leave :-"<<e[i].leave<<endl;
			cout<<"Age :-"<<e[i].age<<endl;
			cout<<"Salary :-"<<e[i].salary<<endl;
		}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menue(e,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void leave(employee e[5],int y)		//to check number of leaves
{	char q;
	int n,l;
	clrscr();
	cout<<"\n\n\t\t\t\tLeave Form"<<endl;
	cout<<"\n\nEnter Employee no. who has to take leave"<<endl;
	cin>>n;
	cout<<"Enter no. of leaves"<<endl;
	cin>>l;
	for(int i=0;i<y;i++)
	{
		if(e[i].empno==n)
		{
			e[i].leave+=e[i].leave+l;
			cout<<"Employee No.:-"<<e[i].empno;
			cout<<"Name :-"<<e[i].name<<endl;
			cout<<"Sex :-"<<e[i].sex<<endl;
			cout<<"Address :-"<<e[i].address<<endl;
			cout<<"Qualification"<<e[i].qualification<<endl;
			cout<<"Marritial Status :-"<<e[i].ms<<endl;
			cout<<"Branch :-"<<e[i].branch<<endl;
			cout<<"Mobile Number :-"<<e[i].mono<<endl;
			cout<<"Leave :-"<<e[i].leave<<endl;
			cout<<"Age :-"<<e[i].age<<endl;
			cout<<"Salary :-"<<e[i].salary<<endl;

		}

	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menue(e,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void modifye(employee e[5],int y)		//to change branch
{	clrscr();
	cout<<"\n\n\t\t\t\tChange Branch"<<endl;
	char q;
	int n;
	cout<<"\n\nEnter Employee no. whose branch is to be change";
	cin>>n;
	for(int i=0;i<y;i++)
	{
		cout<<"Initial Branch :"<<e[i].branch<<endl;
		if(e[i].empno==n)
		{
			strcpy(e[i].branch,"navrangpura");
			cout<<"\nEmployee No."<<e[i].empno;
			cout<<"Name :-"<<e[i].name<<endl;
			cout<<"Sex :-"<<e[i].sex<<endl;
			cout<<"Address :-"<<e[i].address<<endl;
			cout<<"Qualification"<<e[i].qualification<<endl;
			cout<<"Marritial Status :-"<<e[i].ms<<endl;
			cout<<"Branch :-"<<e[i].branch<<endl;
			cout<<"Mobile Number :-"<<e[i].mono<<endl;
			cout<<"Leave :-"<<e[i].leave<<endl;
			cout<<"Age :-"<<e[i].age<<endl;
			cout<<"Salary :-"<<e[i].salary<<endl;
		}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menue(e,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void holdere(employee e[5],int n)		//to check employees list
{	clrscr();
	cout<<"\n\n\t\t\t\tEmployee Records"<<endl;
	char q;
	for(int i=0;i<n;i++)
	{
		cout<<"\n\n==========================================="<<endl;
		cout<<"\nEmployee No.:-"<<e[i].empno<<endl;
		cout<<"Name :-"<<e[i].name<<endl;
		cout<<"Sex :-"<<e[i].sex<<endl;
		cout<<"Address :-"<<e[i].address<<endl;
		cout<<"Qualification"<<e[i].qualification<<endl;
		cout<<"Marritial Status :-"<<e[i].ms<<endl;
		cout<<"Branch :-"<<e[i].branch<<endl;
		cout<<"Mobile Number :-"<<e[i].mono<<endl;
		cout<<"Leave :-"<<e[i].leave<<endl;
		cout<<"Age :-"<<e[i].age<<endl;
		cout<<"Salary :-"<<e[i].salary<<endl;
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menue(e,n);	}
	else
	{	exit(0);	}
}

/*---------------------------------------------------------*/
/*	            Functions Loan                          */
/*---------------------------------------------------------*/


void menul(loan l[5],int n)
{	clrscr();
	char q;
	int ch=0;
	cout<<"\n\n\t\t\t\tLoan MENU";
	cout<<"\n\n\t01. Apply For New Loan";
	cout<<"\n\n\t02. Loan Holders";
	cout<<"\n\n\t03. Information";
	cout<<"\n\n\t04. Latest Schemes Avialabe";
	cout<<"\n\n\t05. Document Needed";
	cout<<"\n\n\t06. Contact Us";
	cout<<"\n\n\t07. MAIN MENU";
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-7):-";
	cin>>ch;
	switch(ch)
	{
		case 1 : createl(l,n);		//to apply for loan
		       break;
		case 2 : holderl(l,n);		//to check account holders
		       break;
		case 3 : information(l,n);	//\to check loan infromation
		       break;
		case 4 : scheme(l,n);	//to caheck avialable schemes
		       break;
		case 5 : doc(l,n);		//Documents Requirement
		       break;
		case 6 : about();
		       break;
		case 7 : home();
			break;
		default : {		clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Option Selected.";
				delay(1000);
				delay(1000);
				exit(0);
			}
	}
}
//*********************************************************************************************************

void doc(loan l[5],int n)		//Documents require
{	clrscr();
	cout<<"\n\n\t\t\t\tDocument Require for Loan"<<endl;
	char q;
	for(int i=2;i<n;i++)
	{
		cout<<"\n\nDocuments For The Loan"<<endl;
		cout<<"Your ID Proof"<<endl;
		cout<<"Address Proof"<<endl;
		cout<<"Two Evidence On Be half, Loan is To be signed"<<endl;
		cout<<"ID Proof of Two Evidence"<<endl;
		cout<<"Collateral* "<<endl;
		cout<<"Pan Card"<<endl;
		cout<<"Pass Book Zerox"<<endl;
		cout<<"For More Information Call on +919898337228"<<endl;
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menul(l,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void information(loan l[5],int n)		//to check loan inforamtion
{	clrscr();
	cout<<"\n\n\t\t\t\tTypes Of Loan"<<endl;
	char q;
	for(int i=2;i<n;i++)
	{
		cout<<"\n\nAxis Bestvalue Loan (ABL)"<<endl;
		cout<<"Upto 1 month	14% p.a.	14% p.a.	14% p.a."<<endl;
		cout<<">1 Upto 3 months	18% p.a.	18% p.a.	18% p.a."<<endl;
		cout<<">3 Upto 6 months	21% p.a.	21% p.a.	21% p.a."<<endl;
		cout<<">6 Upto 12 months	24% p.a.	24% p.a.	24% p.a."<<endl;
		cout<<endl;
		cout<<"Axis  Mahila Loan (AML)*"<<endl;
		cout<<"Upto 1 month	12% p.a.	12% p.a.	N.A."<<endl;
		cout<<">1 upto 3 months	15% p.a.	15% p.a.	N.A."<<endl;
		cout<<">3 upto 6 months	20% p.a.	20% p.a.	N.A."<<endl;
		cout<<">6 upto 12 months	24% p.a.	24% p.a.	N.A."<<endl;
		cout<<endl;
		cout<<"Axis Super Loan (ASL)"<<endl;
		cout<<"Upto 12 months	22% p.a.	23% p.a.	23.5% p.a."<<endl;
		cout<<"Muthoot Premier Loan (MPL)"<<endl;
		cout<<"Upto 12 months	21% p.a.	22% p.a.	22.5% p.a."<<endl;
		cout<<"Muthoot Advantage Loan (AAL)"<<endl;
		cout<<"upto 3 months	18% p.a.	18% p.a.	18% p.a."<<endl;
		cout<<">3 Upto 6 months	21% p.a.	21% p.a.	22% p.a."<<endl;
		cout<<">6 Upto 12 months	22% p.a.	22% p.a.	22% p.a."<<endl;
		cout<<endl;
		cout<<"Axis Highvalue Loan (AHL)"<<endl;
		cout<<"Upto 3 months	18% p.a.	18% p.a.	18% p.a."<<endl;
		cout<<">3 Upto 6 months	20% p.a.	20% p.a.	20% p.a."<<endl;
		cout<<">6 Upto 9 months	21% p.a.	21% p.a.	21% p.a."<<endl;
		cout<<">9 Upto 12 months	22% p.a.	22% p.a.	22% p.a."<<endl;
		cout<<"Above 12 months(Penal Interest -2% addnl)"<<endl;
	}
	cout<<"Do you want to continue y/n:-"<<endl;
	cin>>q;
	if(q=='y')
	{	menul(l,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void scheme(loan l[5],int n)		//Avialable Schemes
{	clrscr();
	cout<<"\n\n\t\t\t\tSchemes Aviable"<<endl;
	char q;
	for(int i=2;i<n;i++)
	{
		cout<<"\n\nAxis  Overdraft scheme (AOS)"<<endl;
		cout<<"12 months	19% p.a.	19% p.a.	19% p.a."<<endl;
		cout<<endl;
		cout<<"Axis EMI Scheme (AES)"<<endl;
		cout<<">6/12 instalments	21% p.a.	21% p.a.	21% p.a."<<endl;
		cout<<"MGL"<<endl;
		cout<<"upto 6 months "<<endl;
		cout<<"Rebate 2% for monthly payment"<<endl;
		cout<<"Above 6 months(Penal Interest-2%)	23% p.a.	24% p.a.	24% p.a."<<endl;
		cout<<"Interest Prepaid Loan ( IPL)"<<endl;
		cout<<"3 Months	16% p.a.(After 3 months ,22% p.a.)	16% p.a.(After 3 months ,22% p.a.)	N.A"<<endl;
		cout<<"6 Months	14% p.a.(After 6 months ,22% p.a.)	14% p.a.(After 6 months ,22% p.a.)	N.A"<<endl;
		cout<<"12 Months	12% p.a.(After 12 months ,22% p.a.)	12% p.a.(After 12 months ,22% p.a.)	N.A"<<endl;
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menul(l,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void holderl(loan l[5],int n)		//accounts holder
{	clrscr();
	cout<<"\n\n\t\t\t\tLoan Holders"<<endl;
	char q;
	for(int i=0;i<n;i++)
	{
		cout<<"\n\n==========================================="<<endl;
		cout<<"Accout Number:-"<<l[i].accno<<endl;
		cout<<"Name:-"<<l[i].name<<endl;
		cout<<"Address:-"<<l[i].address<<endl;
		cout<<"Pincode:-"<<l[i].pincode<<endl;
		cout<<"Scheme:-"<<l[i].scheme<<endl;
		cout<<"Collateral:-"<<l[i].collateral<<endl;
		cout<<"Account Type:-"<<l[i].type<<endl;
		cout<<"Rate Of Intrest:-"<<l[i].rate<<endl;
		cout<<"Down Payment done:-"<<l[i].down<<endl;
		cout<<"Months to pay:-"<<l[i].month<<endl;
		cout<<"Years to pay:-"<<l[i].year<<endl;
		cout<<endl;
	}
	cout<<"Do you want to continue y/n:-"<<endl;
	cin>>q;
	if(q=='y')
	{	menul(l,n);	}
	else
	{	exit(0);	}
}
//*********************************************************************************************************

void createl(loan l[5],int n)		//Apply for loan
{	clrscr();
	cout<<"\n\n\t\t\t\tApply For Loan"<<endl;
	char q,z;
	int r;
	for(int i=2;i<n;i++)
	{
		cout<<"\n\nAccout Number:-";
		cin>>l[i].accno;
		cout<<"Name:-";
		gets(l[i].name);
		cout<<"Address:-";
		gets(l[i].address);
		cout<<"Pincode:-";
		cin>>l[i].pincode;
		cout<<"Scheme:-";
		gets(l[i].scheme);
		cout<<"Collateral:-";
		gets(l[i].collateral);
		cout<<"Account Type:-";
		gets(l[i].type);
		cout<<"Rate Of Intrest:-";
		cin>>l[i].rate;
		cout<<"Down Payment done:-";
		cin>>l[i].down;
		cout<<"Months to pay:-";
		cin>>l[i].month;
		cout<<"Years to pay:-";
		cin>>l[i].year;
		cout<<"==========================================="<<endl;
		cout<<"Accout Number:-"<<l[i].accno<<endl;
		cout<<"Name:-"<<l[i].name<<endl;
		cout<<"Address:-"<<l[i].address<<endl;
		cout<<"Pincode:-"<<l[i].pincode<<endl;
		cout<<"Scheme:-"<<l[i].scheme<<endl;
		cout<<"Collateral:-"<<l[i].collateral<<endl;
		cout<<"Account Type:-"<<l[i].type<<endl;
		cout<<"Rate Of Intrest:-"<<l[i].rate<<endl;
		cout<<"Down Payment done:-"<<l[i].down<<endl;
		cout<<"Months to pay:-"<<l[i].month<<endl;
		cout<<"Years to pay:-"<<l[i].year<<endl;
		cout<<endl;
		cout<<"Do you want to continue y/n:-";	
		cin>>z;
		if(z=='y')
		{	n++;	}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menul(l,n);	}
	else
	{	exit(0);	}
}

/*---------------------------------------------------------*/
/*	            Functions Security                     */
/*---------------------------------------------------------*/

void menus(security s[5],int n)		//Security Menu
{	clrscr();
	int ch=0;
	cout<<"\n\n\t\t\t\tSecurity MENU";
	cout<<"\n\n\t01. Apply for Locker";
	cout<<"\n\n\t02. Locker Holders";
	cout<<"\n\n\t03. Locker Information";
	cout<<"\n\n\t04. Change Pin No.";
	cout<<"\n\n\t05. ABOUT US";
	cout<<"\n\n\t06. Main Menu";
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-6) ";
	cin>>ch;
	switch(ch)
	{
		case 1 : createlo(s,n);		//Apply for locker
		       break;
		case 2 : holderlo(s,n);		//Locker Holders	
		       break;
		case 3 : locker(s,n);			//Locker Info
		       break;
		case 4 : pin(s,n);			//change pin number
		       break;
		case 5 : about();
		       break;
		case 6 : home();
			break;
		default : 	{	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Option Selected.";
				delay(1000);
				delay(1000);
				exit(0);
			}
	}
}
//*********************************************************************************************************

void createlo(security s[5],int n)		//Apply for locker
{	clrscr();
	cout<<"\n\n\t\t\t\t Apply for Locker"<<endl;
	char q,z;
	for(int i=3;i<=n;i++)
	{
		cout<<"\n\nAccout Number:-"<<endl;
		cin>>s[i].accno;
		cout<<"\nName:-"<<endl;
		gets(s[i].name);
		cout<<"\nAddress:-"<<endl;
		gets(s[i].address);
		cout<<"Enter Mobile Number :-"<<endl;
		gets(s[i].mobile);
		cout<<"Enter Locker Number:-"<<endl;
		cin>>s[i].lockno;
		cout<<"Enter Pin Number:-"<<endl;
		cin>>s[i].pin;
		cout<<"==========================================="<<endl;
		cout<<"Accout Number:-"<<s[i].accno<<endl;
		cout<<"Name:-"<<s[i].name<<endl;
		cout<<"Address:-"<<s[i].address<<endl;
		cout<<"Enter Mobile Number :-"<<s[i].mobile<<endl;
		cout<<"Enter Locker Number:-"<<s[i].lockno<<endl;
		cout<<"Enter Pin Number:-"<<s[i].pin<<endl;
		cout<<"Do you want to continue y/n:-";	
		cin>>z;
		if(z=='y')
		{	n++;	}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menus(s,n);	}
	else
	{	exit(0);	}

}
//*********************************************************************************************************

void holderlo(security s[5],int n)		//Loacker Holders
{	clrscr();
	cout<<"\n\n\t\t\t\tLOCKER HOLDERS"<<endl;
	char q;
	for(int i=0;i<n;i++)
	{
		cout<<"\n\n==========================================="<<endl;
		cout<<"Accout Number:-"<<s[i].accno<<endl;
		cout<<"Name:-"<<s[i].name<<endl;
		cout<<"Address:-"<<s[i].address<<endl;
		cout<<"Enter Mobile Number :-"<<s[i].mobile<<endl;
		cout<<"Enter Locker Number:-"<<s[i].lockno<<endl;
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menus(s,n);	}
	else
	{	exit(0);	}

}
//*********************************************************************************************************

void locker(security s[5],int n)		//Locker Information
{	clrscr();
	cout<<"\n\n\t\t\t\tLOCKER INFORMATION"<<endl;
	char q;
	int x,pa;
	cout<<"\n\nEnter Acc. no. Whose Locker No. You Want"<<endl;
	cin>>x;
	cout<<"Enter Pin no. "<<endl;
	cin>>pa;
	for(int i=0;i<n;i++)
	{
		if(x==s[i].accno)
		{
			if(pa==s[i].pin)
			{
				cout<<"==========================================="<<endl;
				cout<<"Accout Number:-"<<s[i].accno<<endl;
				cout<<"Name:-"<<s[i].name<<endl;
				cout<<"Address:-"<<s[i].address<<endl;
				cout<<"Enter Mobile Number :-"<<s[i].mobile<<endl;
				cout<<"Enter Locker Number:-"<<s[i].lockno<<endl;
			}
		}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menus(s,n);	}
	else
	{	exit(0);	}

}
//*********************************************************************************************************

void pin(security s[5],int n)		//Change Pin number
{	clrscr();
	cout<<"\n\n\t\t\t\tCHANGE PIN NUMBER"<<endl;
	char q;
	int x,pa,b;
	cout<<"\n\nEnter Acc. no. Whose pin No. You Want to change"<<endl;
	cin>>x;
	cout<<"Enter old Pin no. "<<endl;
	cin>>pa;
	for(int i=0;i<n;i++)
	{
		if(x==s[i].accno)
		{
			if(pa==s[i].pin)
			{
				cout<<"Enter New Pin Number"<<endl;
				cin>>b;
				s[i].pin=b;
				cout<<"==========================================="<<endl;
				cout<<"Accout Number:-"<<s[i].accno<<endl;
				cout<<"Name:-"<<s[i].name<<endl;
				cout<<"Address:-"<<s[i].address<<endl;
				cout<<"Enter Mobile Number :-"<<s[i].mobile<<endl;
				cout<<"Enter Locker Number:-"<<s[i].lockno<<endl;
				cout<<"Your New Pin:-"<<s[i].pin<<endl;
			}
		}
	}
	cout<<"Do you want to continue y/n:-";
	cin>>q;
	if(q=='y')
	{	menus(s,n);	}
	else
	{	exit(0);	}

}