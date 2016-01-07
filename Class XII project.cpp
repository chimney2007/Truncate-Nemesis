// Class XII project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<stdio.h>
using namespace std;
fstream fin,fout;






// **********************************************************************************
// CLASS OF BOOK
// **********************************************************************************

class book
{
	int Acc_no;
	char book_name[40],author_name[25];

public:
	
	void book_entry()
	{
		cout<<" NEW BOOK ENTRY.....\n";
		cout<<"Enter the Acc. no.   ";
		cin>>Acc_no;
		cout<<"Enter the book name   ";
		cin>>book_name;
		cout<<"Enter the author name   ";
		cin>>author_name;
		cout<<" BOOK ENTRY CREATED.....\n";
	}

	void show_book()
	{
		cout<<"The Acc. no is   ";
		cout<<Acc_no<<endl;
		cout<<"The book name is   ";
		puts(book_name);
		cout<<"The author name is   ";
		puts(author_name);
	}
	
	void modify_book()
	{
		cout<<"The Acc. no    ";
		cout<<Acc_no<<endl;
		cout<<"Enter the modified book name   ";
		cin>>book_name;
		cout<<"Enter the modified author name   ";
		cin>>author_name;
	}
	char* get_bookname()
	{
		return book_name;
	}

	char* get_authorname()
	{
		return author_name;
	}

	int get_bookno()
	{
		return Acc_no;
	}

	void show_allbook()
	{
		cout<<" Book no.  : ";
		cout<<Acc_no<<endl;
		cout<<" Book name  : ";
		puts(book_name);
		cout<<" Author name   : ";
		puts(author_name);
		cout<<endl;
	}
};


// **********************************************************************************
// CLASS OF STUDENT
// **********************************************************************************

class student
{
	char name[35], sec;
	int book_issue,admn_no,stdbno,clas;

public:

	void Student_entry()
	{
		cout<<" NEW STUDENT ENTRY....\n";
		cout<<"Enter the student admission no   ";
		cin>>admn_no;
		cout<<"Enter the student name   ";
		cin>>name;
		cout<<"Enter the class and section   ";
		cin>>clas>>sec;
		cout<<" STUDENT ENTRY CREATED...\n";
	}

	void show_student_details()
	{
		cout<<"The student admission no is   ";
		cout<<admn_no<<endl;
		cout<<"The name of the student is   ";
		puts(name);
		cout<<"The class and section of the student is    ";
		cout<<clas<<sec<<endl;
		cout<<"no. book issued   "<<book_issue<<endl;
		if(book_issue==1)
		{	cout<<" The Acc. no. is    ";
			cout<<stdbno<<endl;
		}
		system("date /T");
		system("pause");

	}

	void modify_student()
	{
		cout<<"The admission no  ";
		cout<<admn_no<<endl;
		cout<<"Modified student name ";
		cin>>name;
		cout<<"Modified class and section";
		cin>>clas>>sec;

	}

	char* get_name()
	{
		return name;
	}

	int get_class()
	{
		return clas;
	}

	char get_sec()
	{
		return sec;
	}

	int get_admn()
	{
		return admn_no;
	}

	int get_stdbno()
	{
		return stdbno;
	}

	int get_book_issue()
	{
		return book_issue;
	}

	void set_book_issue()
	{
		book_issue=1;
	}

	void reset_book_issue()
	{
		book_issue=0;
	}

	void show_allstudent()
	{
		cout<<" Admission no.  : ";
		cout<<admn_no<<endl;
		cout<<" Student name  : ";
		puts(name);
		cout<<" Class and section   : ";
		cout<<clas<<sec<<endl;
		cout<<" no. Book issue : ";
		cout<<book_issue;
		cout<<endl<<endl;
	}

	void setbno(int a)
	{
		stdbno=a;
	}
};

book b1;
student s1;
// **********************************************************************************
// Writing Student record to a file
// **********************************************************************************

void record_student()
{
	char ch;
	fout.open("d:\\student.dat",ios::app|ios::out);
	do
	{
		s1.Student_entry();
		fout.write((char*)&s1,sizeof(s1));	
		cout<<"Do you want to enter more record (y/n) ??   ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fout.close();
}	

// **********************************************************************************
// Writing Book record to a file
// **********************************************************************************

void record_book()
{
	char ch1;
	fout.open("d:\\books.dat",ios::app|ios::out);
	do{
		b1.book_entry();
		fout.write((char*)&b1,sizeof(b1));
		cout<<"Do you want to enter more record (y/n) ??   ";
		cin>>ch1;
	}while(ch1=='y'||ch1=='Y');
	fout.close();
}

// **********************************************************************************
//  All book details
// **********************************************************************************
void show_allbooks()
{
	fin.open("d:\\books.dat",ios::app|ios::in);
	
	cout<<" BOOKS LIST \n\n";
	while(fin.read((char*)&b1,sizeof(b1)))
	{
		b1.show_allbook();
	}
	fin.close();
}	


// **********************************************************************************
//  All Student details
// **********************************************************************************

void show_all()
{
	fin.open("d:\\student.dat",ios::app|ios::in);

	cout<<" STUDENTS LIST \n\n";
	while(fin.read((char*)&s1,sizeof(s1)))
	{
		s1.show_allstudent();
	}
	fin.close();
}	

// **********************************************************************************
// Specific book details
// **********************************************************************************

void specific_book()
{
	int bno;
	int found=0;
	cout<<"Enter the book no of the book whose details you want to know ";
	cin>>bno;

	fin.open("d:\\books.dat",ios::app|ios::in);
	while(fin.read((char*)&b1,sizeof(b1)))
	{
		if(b1.get_bookno()==bno)
		{	b1.show_book();
			++found;
		}
	}
	 if(found==0)
		cout<<"The book doesn't exist";
	 fin.close();
	return;
}


// **********************************************************************************
// Specific student details
// **********************************************************************************

void specific_student()
{
	int ad_no;
	int count=0;
	cout<<"Enter the admission no of the student whose details you want to know ";
	cin>>ad_no;

	fin.open("d:\\student.dat",ios::app|ios::in);
	while(fin.read((char*)&s1,sizeof(s1)))
	{
		if(s1.get_admn()==ad_no)
		{	s1.show_student_details();
			++count;
		}
	} 
	if(count==0)
		cout<<"The student entry doesn't exist";
	fin.close();
	return;
}

// **********************************************************************************
// Modify student details
// **********************************************************************************

 void modify_student()
{
	int adno;
	int flag=0;
	cout<<"Enter the admission number of the student whose details is to be modified  ";
	cin>>adno;
	fout.open("d:\\student.dat",ios::in|ios::out|ios::binary);
	while(!fout.eof())
	{
		int pos=fout.tellg();
		fout.read((char*)&s1,sizeof(s1));
		if(s1.get_admn()==adno)
		{

			s1.show_student_details();
			cout<<" Enter the modified details \n\n";
			s1.modify_student();
			fout.seekg(pos);
			fout.write((char*)&s1,sizeof(student));
			cout<<" The record is modified \n\n";
			flag=1;
			break;
		}
		

	}
	fout.close();
	if(flag==0)
		cout<<"The record doesn't exist";
	
	return;
} 

 
// **********************************************************************************
// Modify book details
// **********************************************************************************

void modify_book()
{

	int bkno;
	int flag=0;
	cout<<"Enter the Acc. number of the book whose details is to be modified  ";
	cin>>bkno;
	fout.open("d:\\books.dat",ios::in|ios::out|ios::binary);
	while(!fout.eof())
	{
		int pos=fout.tellg();
		fout.read((char*)&b1,sizeof(b1));
		if(b1.get_bookno()==bkno)
		{
			b1.show_book();
			cout<<" Enter the modified details \n\n";
			b1.modify_book();
			fout.seekg(pos);
			fout.write((char*)&b1,sizeof(b1));
			cout<<" The record is modified \n\n";
			flag=flag+1;
			break;
		}
	}
	fout.close();
	if(flag==0)
		cout<<"The record doesn't exist"; 
	
	return;
}

// **********************************************************************************
// BOOK ISSUE
// **********************************************************************************

void Book_issue()
{
	fstream print;
	char ch1;
	int bno;
	int f1=0,f2=0,adno;
	cout<<"enter the student's Admission no   ";
	cin>>adno;
	fin.open("d:\\student.dat",ios::in|ios::out|ios::binary);
	fout.open("d:\\books.dat",ios::in|ios::out|ios::binary);
	while(!fin.eof() && f1==0)
	{
		int pos=fin.tellg();
		fin.read((char*)&s1,sizeof(s1));
		if(s1.get_admn()==adno)
		{
			f1=1;
			if(s1.get_book_issue()==0)
			{
				cout<<"Enter the Acc. no   ";
				cin>>bno;
				while((!fout.eof()) && f2==0)
				{
					fout.read((char*)&b1,sizeof(b1));
					if(b1.get_bookno()==bno)
					{
						b1.show_book();
						f2=1;
						s1.set_book_issue();
						s1.setbno(b1.get_bookno());
						fin.seekg(pos);
						fin.write((char*)&s1,sizeof(s1));
						cout<<" the book is issued \n\n";
						system("date /T");
						system("pause");
						cout<<" Remember the date and appropriately Return the book next week or re-issue it OTHERWISE fine will be taken \n\n";
						cout<<"Do you want to Print Receipt (y/n) ??? \n";
						cin>>ch1;
						if(ch1=='y'||ch1=='Y')
						{
							print.open("d:\\Print.txt",ios::out);
							print<<" THE STUDENT'S DETAILS ARE "<<endl<<endl;
							print<<" ----------------------------------------------------------------------------------------------------------- \n\n";
							print<<"  Admission number : "<<s1.get_admn()<<endl<<endl;
							print<<"  Name : "<<s1.get_name()<<endl<<endl;
							print<<"  Class : "<<s1.get_class()<<endl<<endl;
							print<<" Section : "<<s1.get_sec()<<endl<<endl;
							print<<" ISSUED BOOK DETAILS "<<endl<<endl;
							print<<" ----------------------------------------------------------------------------------------------------------- \n\n";
							print<<" Acc No. : "<<s1.get_stdbno()<<endl<<endl;
							print<<" Book Name : "<<b1.get_bookname()<<endl<<endl;
							print<<" Author Name : "<<b1.get_authorname()<<endl<<endl;
							print<<" ----------------------------------------------------------------------------------------------------------- \n\n";
							print.close();
							system("start d:\\Print.txt");
						}
						break;
					}
				}
				if(f2==0)
					cout<<"Book doesn't exist";

			}
			else
				cout<<" You have not returned the last book ";

		}
		break;
	}
	if(f1==0)
		cout<<"Student record doesn't exist ";
	fin.close();
	fout.close();
		
	return;
}

// **********************************************************************************
// BOOK DEPOSIT
// **********************************************************************************

void Book_deposit()
{
	int adno,accno,fine,day,flag=0,found=0;
	system("cls");
	cout<<" \t\t\t   BOOK DEPOSIT \n\n ";
	cout<<" Enter the student's admission number ";
	cin>>adno;
	fin.open("d:\\student.dat",ios::in|ios::out|ios::binary);
	fout.open("d:\\books.dat",ios::in|ios::out|ios::binary);
	while(!fin.eof() && found==0)
	{
		int pos=fin.tellg();
		fin.read((char*)&s1,sizeof(s1));
		if(s1.get_admn()==adno)
		{
			++found;
			if(s1.get_book_issue()==1)
			{
				while(fout.read((char*)&b1,sizeof(b1)) && flag==0)
				{
					if(b1.get_bookno()==s1.get_stdbno())
					{
						b1.show_book();
						++flag;
						cout<<" Enter the book deposited in number of days \n\n";
						cin>>day;
						if(day>7)
						{
							fine=(day-7)*2;
							cout<<" Fine to be deposited is Rs. "<<fine<<endl<<endl;
						}
						s1.reset_book_issue();
						fin.seekg(pos);
						fin.write((char*)&s1,sizeof(s1));
						cout<<" The Book is Deposited Successfully \n\n";
						system("date /T");
						system("pause");
						break;
					}
				}
				if(flag==0)
					cout<<" Book doesn't exist \n\n";
			}
			else
				cout<<" No book is Issued ....... Please Check \n\n";
		}
		break;
	}
	if(found==0)
		cout<<" Student Record doesn't exist \n\n";
	fin.close();
	fout.close();
	return;
}

// **********************************************************************************
// Administrator menu function
// **********************************************************************************

void Admin_menu()
{
	system("cls");
	int choice1;
	cout<<" 1: Register New Student  \n\n";
	cout<<" 2: Show all Student Record \n\n";
	cout<<" 3: Show Specific Student Record \n\n";
	cout<<" 4: Modify Student Record \n\n";
	cout<<" 5: Create New Book Entry \n\n";
	cout<<" 6: Show all Books Record \n\n";
	cout<<" 7: Show Specific Book Record \n\n";
	cout<<" 8: Modify Book Record \n\n";
	cout<<" 9: Back to Main Menu \n\n";
	cout<<" Enter your choice(1-9)";
	cin>>choice1;

	switch(choice1)
	{
	case 1: system("cls");
			record_student();
			break;
	case 2: system("cls");
			show_all();
			break;
	case 3: system("cls");
			specific_student();
			break;
	case 4: system("cls");
			modify_student();
			break;
	case 5: system("cls");
			record_book();
			break;
	case 6: system("cls");
			show_allbooks();
			break;
	case 7: system("cls");
			specific_book();
			break;
	case 8:	system("cls");
			modify_book();
			break;
	case 9:return;
	default: cout<<" WRONG CHOICE ...........\n\n RENTER THE CHOICE ";
	}
}

//***********************************************************************************
//MAIN FUNCTION
//***********************************************************************************

int main()
{
	int choice;
	do{
		cout<<" 1: Admin Menu \n\n";
		cout<<" 2: Book issue \n\n";
		cout<<" 3: Book deposit \n\n";
		cout<<" 4: Exit \n\n";
		cout<<"Enter your choice";
		cin>>choice;

		switch(choice)
		{
		case 1: Admin_menu();
				break;
		case 2: Book_issue();
				break;
		case 3: Book_deposit();
				break;
		case 4: exit(0);
		default : cout<<" WRONG CHOICE ...........\n\n RENTER THE CHOICE ";
		}
	}while(choice!=4);


	return 0;
}

