// TruncateNemesis.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include<iomanip>
#include<process.h>
#include<C:\Users\mukka\Desktop\documents-export-2015-11-18\library.cpp>
#include<C:\Users\mukka\Desktop\documents-export-2015-11-18\Stud.cpp>


#include<dos.h>

typedef char str;
using namespace std;
//int i, j, enter=0;
//char name[51]=" ";

//prototypes,
void header();
void header(int);
void line (char c, bool x );
void line (char c );
void header(char arr[], char ch);
void PlaceCursor(const int x, const int y);
void extras();
void home();
void home(int x);
void update();

class teacher
{
	char name[51];
	int cls[5];
	char sec[5];
	float perf;
	char pswrd[31];
	int acs;
	void in_cls()
	{
		for(i=0; i<5 ; ++i)	{	cls[i]=00;	sec[i]='*';	}
	}
public:
	char* get_name() {  return name; }
	char* get_pswrd() {  return pswrd; }
	int get_cls(int x) { return cls[x]; }
	char get_sec(int x) { return sec[x];}
	void get_pass(int x=0)
	{
		char ps[31];
		cout<<"\nEnter a new password( max 30): ";
		pswrd[0] = _getch();

		cout<<pswrd[0];
		Sleep(300);
		cout<<'\b'<<"*";

		for(i=1; (pswrd[i] = _getch()) != 13; ++i)
		{

			cout<<pswrd[i];
			Sleep(200);
			cout<<'\b'<<"*";

		} pswrd[i]=' ';
		cout<<"\nRenter password: ";
		cin.ignore();
		ps[0] = _getch();			cout<<"*";
		for(i=1; (ps[i] = _getch()) != 13; ++i)
			cout<<"*";
		cout<<endl;
		ps[i]= ' ';
		//cout<<pswrd<<"   "<<ps;			for debugging
		passchk(ps);
		return;
	}
	void passchk(char *y)
	{
		for(i=0; pswrd[i]!=' '; ++i);
		if (!(strncmp(pswrd, y, i )))
			cout<<"\nGood!! Passwords match...  "<<(char)1;
		else
		{	cout<<"\nPasswords dont match!!! Renter a new password\n";		get_pass();		}



	}
	void teac_details()
	{
		in_cls();
		perf = 0.0;
		//cout<<"\nWelcome to NEMESIS portal !!!! You hub to all your class needs.... \n\n\n";
		cout<<"Enter your name:";		cin>>name;
		cout<<"\nEnter the class and section you teach ( you can always add more in your profile "<<(char)1<<"):  ";				cin>>cls[0]>>sec[0];
		cout<<"\n\nGreat!! Now choose a password   ";			 get_pass();
		return;


	}
	void profile()
	{

		//PlaceCursor(25,25);
		cout<<"\nYour name:  "<< name;
		//PlaceCursor(25,25);
		cout<<"\n\nPassword ( :P) :   ";
		for(i=0; pswrd[i]!='\0'; ++i)		cout<<"*";
		cout<<"\n\nYour PI: ";		cout<<perf;
		cout<<"\n\nThe classes you teach:(zero/astriek implies classes not added) \n";
		for(i=0; i<5 ; ++i)
		{
			cout<<'\t'<<setw(10)<<cls[i]<<"  -  "<<sec[i]<<endl;
		}
	}
	void add_cls()
	{

		char ch='y';
		i=0;
		while(cls[i]!=00  && sec[i]!='*')			++i;		//loop to chek the already entries

		do
		{
			//while(cls[i]!=00  && sec[i]!='*')			++i;

			if(i==5)
			{
				cout<<"\n\nClass Limit reached(of 5 classes)!!!! Exiting...... ";
				break;
			}

			cout<<"\nEnter the class as class...section:......\n";
			cin>>cls[i]>>sec[i];
			cout<<"\nClasses updated....";
			cout<<"\nDo you want to enter more classes??? [Y | N].....   ";
			cin>>ch;

			++i;

		}while(ch=='y' && i<=6);

		cout<<"\nYor account will be updated later!!";
	}

	void modify()
	{
		cout<<"\n\n\t1.Name  \n\t2.Password\n";
		cout<<"\nEnter the option you want to modify: " ;
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the new name : ";			cin>>name;
				cout<<"\nName Sucessfully changed!!\n\n";
				break;

			case 2:
				cout<<"\nRedirecting........\n\n\n";
				cout<<"\nEnter your old password: ";
				char chk[31];
				cin>>chk;
				for(i=0; pswrd[i]!=' '; ++i);
				if ( ! strncmp(pswrd, chk,i) )
				{	cout<<"\nGood!! Passwords match...  "<<(char)1<<endl;
					Sleep(290);
					get_pass();
					cout<<"\n\aPassword Changed !!!\n\n"	;
				}
				else
				{	cout<<"\nPasswords dont match!!!\n";		}
				Sleep(290);

				break;

			default: return;
		}
		//system("pause");
	}


}t,ti;
class student_trunc
{
	int rno;
	int cls;
	char sec;

	char name[31];
	int marks[5];
	float perc;
	int total;
	char grade[3][5];

	void grd()
	{

		for(i=0; i<5; ++i)
		{
				if(marks[i]> 90)
				strcpy_s(grade[i] , "A1")  ;
			else if(marks[i] > 81)
				 strcpy_s(grade[i] , "A2")  ;
			else if(marks[i] > 72)
				  strcpy_s(grade[i] , "B1")  ;
			else if(marks[i] > 63)
				 strcpy_s(grade[i] , "B2")  ;
			else if(marks[i] > 55)
				  strcpy_s(grade[i] , "C1")  ;
			else if(marks[i] > 42)
				  strcpy_s(grade[i] , "C2")  ;
			else if(marks[i] > 33)
				  strcpy_s(grade[i] , "D")  ;
			else if(marks[i] > 22)
				   strcpy_s(grade[i] , "E1")  ;
			else if(marks[i] < 10)
				   strcpy_s(grade[i] , "E2")  ;
		}
	}
	void tot()
	{
		for ( i=0 ; i<5; ++i)
			total += marks[i];
		perc = (total/5.0) ;
	}

	void calc()
	{
		tot( );
		grd( );

	}


public:
	student_trunc() {}
	void read()
	{
		cout<<"\nEnter Rno: " ; 		cin>>rno;
		cout<<"\nEnter Name: ";		cin>>name;
		cout<<"\nClass & Sec: ";		cin>>cls>>sec;
		cout<<"\nMarks in 5 sub: "	;
		for( i=0 ; i<5; ++i)
			cin>> marks[i];
		void clac( );
	}
	void display()
	{
		cout<<"\nDetails:\n\n ";
		cout<<"\nEnter Rno: " ; 		cout<<rno;
		cout<<"\nEnter Name: ";		cout<<name;
		cout<<"\nClass & Sec: ";	      cout<<cls<<sec;
		cout<<"\nMarks and Grades in 5 sub:\n "	;
		for( i=0 ; i<5; ++i)
			cout<<marks[i]<<'\t'<<grade[i];
		cout<<"\nTotal:"<<total<<"\nPercentage: "<<perc;
	}

	int getr(){ return rno ; }
	float getp() { return perc; }
	int getc() { return cls; }


}s[50],s_1;


char* setcls()
{
	cout<<"\n\nSelect the class to which you want to add students...\n\n";
	for(i=0; i<5; ++i)
		cout<<"["<<i<<"]  " <<ti.get_cls(i) <<ti.get_sec(i) <<endl;
	cout<<"(zero/astriek implies classes not added)";

	char ctr[1];
	cin>>ctr;

	char str[31];
	//itoa(ti.get_cls(atoi(ctr)), str,4);
	strchr(str,ti.get_cls(atoi(ctr)));
	strchr(str,ti.get_sec(atoi(ctr)));
	Sleep(350);
	system("cls");
	return str;

}




void add_stud()
{
	system("cls");
	header();
	header("Add Students", (char) 167);
	student si;

	char str[71], tstr ;
	strcat_s(str, ti.get_name());
	strcat_s(str, " ");
	strcat_s(str , setcls());






}

void stud()
{
	system("cls");
	header();
	header("Student Functions", (char) 176);
	char chk='y';

	cout<<"\n\n\n\t\t\t 1.Add Students \n\t\t\t  2.Construction \n\t\t\t 3.Return";
	int ctr=3;
	cin>>ctr;

	switch(ctr)
	{
	case 1:
		add_stud();
		Sleep(500);
		break;

	default:
		Sleep(500);
		home();
		break;

	}




}







void mod_cls()
{
	system("cls");
	header();
	header("Add/Modify Classes You Teach", (char) 167);
	cout<<"\n\nHere You can add more classes you teach to your account!!! So lets go ahead... \n\n";
	ti.add_cls();
	update();
	system("pause");
	Sleep(350);
	home();
}
void mod_details()
{
	system("cls");
	header();
	header("Modify Details", (char) 159);
	ti.modify();
	update();
	Sleep(290);
	cout<<"\n\n\n";
	system("pause");
	home();
}
void update()
{
	teacher tu;
	fstream fin;
	fin.open("teacher_data.txt",  ios::beg | ios::binary| ios::in | ios::out);
	ofstream fout;
	fout.open("temp.txt",ios::beg | ios::binary | ios::ate);

	while(fin.read((char*)&tu, sizeof(tu)))
	{
		if(  (!strncmp(name,tu.get_name(), strlen(name)) ))
			fin.write((char*)&ti, sizeof(teacher));

		else
			continue;
	}

	//fout.write((char*)&ti, sizeof(ti));
	fin.close();
	fout.close();
	//rename("teacher_data.txt","rtemp.txt");
	//rename("temp.txt","teacher_data.txt");
	//if(re==0)
		cout<<"\n\nDone!!\n";

}




void profile()
{
	system("cls");
	header();
	header("Profile", (char) 183);

	if(enter!=1)
		home();

	cout<<"\n\n\n";
	ti.profile();

	char ch[2];
	cout<<"\n\nEnter 1 to modify your details else any key to return home....";
	cin>>ch;

	if(atoi(ch)==1)
	{
		cout<<"\n\n\t\t1.Modify classes \n\t\t2.Modify user Details\n";
		cout<<"\n\nEnter Your Choice :  ";
		char ch[2];
		cin>>ch;
		switch(atoi(ch))
		{
		case 1:
			mod_cls();
			break;

		case 2:
			mod_details();
			break;

		}


	}
	else
	{
		cout<<"\n\n";
		system("pause");
		home();
	}

	cout<<"\n\n";
	system("pause");
	home();
}

void logout()
{
	system("cls");
	header();
	header("Logout", (char) 169);
	cout<<"\n\n\nDo you really want to logout...[Y | N]??  ";
	char ch='y';
	cin>>ch;
	if(ch=='n'| ch=='N' )
	{	home(); return;  }

	else
	{
		cout<<"\n\nThank You!!! "<<(char)1<<"\n\n";
		enter=0;
		home();
	}
}


void txt()
{
	str disp[]="Welcome";
	for(i=0; disp[i]!='/0'; ++i)
	{
		for(j=0;j<=i; ++j)
			cout<"    ";

		for(int k=0; k<=i; ++k)
			cout<<disp[k];
		Sleep(250);
		system("cls");

	}

}

/*void usr()
{
	if(enter!=0){
		cout<<setw(70);
		cout<<"User :  "<<name<<endl;
	}

	char title[100]="title Truncuate Nemesis  ";
	strcat_s(title, name);
	system(title);
}
void line( char ch , bool slp)
{
		for(i=0; i < 80; ++i)
		{

			cout<<ch;

			if (slp)		Sleep(20);


	}
	return;

}
void line( char ch )
{
		for(i=0; i < 80; ++i)
		{

			cout<<ch;

			//if (slp)		Sleep(20);
		}
	return;

}*/
void chgcolor()
{
	system("cls");
	header();
	header("Change Colors!!", (char) 240);
	/*system("cls");
	header(false);*/
	cout<<"\nSelect the color combination you want:\n(for example F0 for black on white bg)\n\n ";
	cout<<"\n\t0 = Black\n\t1 = Blue\n\t2 = Green\n\t3 = Aqua\n\t4 = Red\n\t5 = Purple\n\t6 = Yellow\n\t7 = White\n\t8 = Gray\n\t"
		<<"9 = Light Blue\n\tA = Light Green\n\tB = Light Aqua\n\tC = Light Red\n\tD = Light Purple\n\tE = Light Yellow\n\tF = Bright White\n";
	str ch[3]="07", cat[51]="color ";
	cout<<"\nEnter your choice...(x for original)  ";			cin>>ch;
	if (ch != "x")
		strcat_s(cat, ch);
	system(cat);
	cout<<"\n\nClours Changed!!!";
	Sleep(500);
	system("cls");
	extras();
}


/*void header()
{
	char ch=176;
	line(ch);

	char arr[100] = {"....Truncate  Nemesis...."};
	cout<<endl;
	cout<<setw(25);

	for(i=0; arr[i]!=0; ++i)
	{

		cout<<arr[i];

		//Sleep(100);

	}
	cout<<endl;


	usr();

	cout<<endl;

	line(ch);
	cout<<endl;


}
void header(int srt)
{
	bool ctr= true;
	char ch=176;
	line(ch,ctr);

	char arr[100] = {"....Truncate  Nemesis...."};
	cout<<endl;
	cout<<setw(25);

	for(i=0; arr[i]!=0; ++i)
	{

		cout<<arr[i];

		if (ctr)	Sleep(100);

	}

	cout<<endl;
	usr();
	cout<<endl;
	line(ch,ctr);
	cout<<endl;



}
void header(char arr[], char ch='*')
{

	//line(chi);


	cout<<setw((26+strlen(arr)));

	for(i=0; arr[i]!=0; ++i)
	{

		cout<<arr[i];

	}

	cout<<endl;

	line(ch);



}*/


void login()
{
	system("cls");
	header();
	header("Login!!!", (char) 134);

	ifstream fin;
	fin.open("teacher_data.txt",  ios::beg | ios::binary);
	char pswrd[31];
	cin.clear();
	cout<<"\n\nEnter name: ";
	cin>>name;
	cout<<"\n\nEnter psword: ";
	cin>>pswrd;
	strcat_s(pswrd, " ");
	int chk_stat=0;
	while(fin.read((char*)&ti, sizeof(ti)))
	{
		if(  (!strncmp(name,ti.get_name(), strlen(name)) ) && ( !strncmp(pswrd, ti.get_pswrd(), strlen(pswrd))))
		{
			enter=1;
			chk_stat=1;
			cout<<"Welcome !!!!";
			Sleep(1000);
			break;
		}
	}

	if(!chk_stat)
	{
		cout<<"\n\nUser instance not found!!!";
		cout<<"\nEnter any key to retry else 1 to go home...... .";
		int ch=10;
		cin>>ch;
		if(ch==1)
			home();
		else
			login();

	}
	fin.close();

}

void rgstr()
{
	system("cls");
	header();
	header("Register!!!", (char) 175);
	teacher ts;
	ofstream fout;
	fout.open("teacher_data.txt", ios::app | ios::binary);
	cout<<"\n\n\nWelcome to the registration page of the most trusted app for all the teachers database needs!!!! You will be Redirected to our registration page\n\n";
	ts.teac_details();
	fout.write((char*)&ts, sizeof(teacher));
	fout.close();
	cout<<"\n\n\nThank you for registering!!! You will now be redirected to our home page, where you can login.....\n";
	system("pause");

	Sleep(500);
	system("cls");
	home();


}


void extras()
{
	system("cls");
	int ch=-1;
	header();
	header("Extras!!!", (char) 240);
	cout<<"\n\n\n\t\t\t 1.Calculator  \n\t\t\t 2.Change App Color\n\t\t\t 3.About \n\t\t\t 4.Email and Contact\n\t\t\t 5.Help!!!\n\t\t\t 6.Bibliography"
		<<"\n\t\t\t 25.Return Home\n\nEnter Choice:";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"Opening.....";
		Sleep(500);
		system("calc");
		break;

	case 2:
		chgcolor();
		Sleep(500);
		break;
	case 25:
		Sleep(500);
		system("cls");
		home();
		break;

	default:
		extras();
	}
	cout<<"\nPress any key to return to extras page.... ";
	_getch();
	extras();
}

void home()
{
	if(enter==1)
		home(1);

	system("cls");
	header();
	int ch= -1;
	header("Home Page", (char)196);
	cout<<"\n\n\n\t\t\t 1.Login  \n\t\t\t 2.Register \n\t\t\t 3.Extras \n\t\t\t 4.Exit\n\n";
	cout<<"  Enter your choice (1...3) :  ";			cin>>ch;
	switch(ch)
	{
	case 1:
		login();
		Sleep(500);
		system("cls");
		header();
		home();
		break;

	case 2:
		rgstr();
		home();
		break;

	case 3:
		extras();
		break;

	case 4:
		library();

	default:
		system("cls");
		header();
		home();

	}



}
void home(int x)
{
	system("cls");
	header();
	int ch= -1;
	header("Home Page", (char)196);
	cout<<"\n\n\n\t\t\t 1.Logout  \n\t\t\t 2.Profile \n\t\t\t 3.Add/Modify Classes You teach \n\t\t\t 4.Extras \n\t\t\t 5.Exit\n\n";
	cout<<"  Enter your choice (1...3) :  ";			cin>>ch;
	switch(ch)
	{
	case 1:
		logout();
		Sleep(500);
		/*system("cls");
		header();
		home();*/
		break;

	case 2:
		profile();
		home();
		break;

	case 3:
		mod_cls();
		break;

	case 4:
		extras();

	case 5:
		library();

	default:
		system("cls");
		header();
		home();

	}



}


void PlaceCursor(const int x, const int y) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;

    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    return;
}

void welcome()
   {
	   //header("Welcome");
    cout<<"\n\n";

	     cout<<"\t%%      %%      ";
       cout<<"\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
       cout<<"\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
       cout<<"\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
       cout<<"\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
       cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
       cout<<"\n\n\t\t\t        $$$$$$$$  $$$$$        ";
       cout<<"\n\t\t\t           $$     $   $      ";
       cout<<"\n\t\t\t           $$     $$$$$    ";


       cout<<"\n\n\n\tCOMPUTER   PROJECT  (********  ON CLASS MANAGEMENT  *******)";
       cout<<"\n\n\t\t\t\t       BY  :-";
       cout<<"\n\n\t\t\t*  M.V.S.CHAITANYA"<<"\t  XII - C\n\n\t\t ";

	 system("pause");
	 system("cls");
	return;
    // getch();
    } //Refernced



int _tmain(int argc, _TCHAR* argv[])
{
	system("color F0");
	system("title TruncateNemesis ");
	welcome();
	header(1);
	home();
																					/*t.teac_details();
																					system("pause");
																					system("cls");
																					t.profile();
																					t.modify();
																					//chgcolor();*/

	system("pause");

	return 0;
}


