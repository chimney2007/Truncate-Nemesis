
//#include "stdafx.h"

#include<iostream>

#include<fstream>

#include<conio.h>

#include<string.h>

#include<stdlib.h>

#include<iomanip>

#include<stdio.h>

#include<Windows.h>
#include<C:\Users\mukka\Desktop\documents-export-2015-11-18\gui.h>

using namespace std;

fstream fin,fout;






// **********************************************************************************

// CLASS OF BOOK

// **********************************************************************************


class book

{

    char book_no[7],book_name[40],author_name[25];


public:



    void book_entry()

    {

        cout<<" NEW BOOK ENTRY.....\n";

        cout<<"Enter the book no.   ";

        cin>>book_no;

        cout<<"Enter the book name   ";

        cin>>book_name;

        cout<<"Enter the author name   ";

        cin>>author_name;

        cout<<" BOOK ENTRY CREATED.....\n";

    }


    void show_book()

    {

        cout<<"The book no is   ";

        puts(book_no);

        cout<<"The book name is   ";

        puts(book_name);

        cout<<"The author name is   ";

        puts(author_name);

    }



    void modify_book()

    {

        cout<<"The book no    ";

        cout<<book_no<<endl;

        cout<<"Enter the modified book name   ";

        cin>>book_name;

        cout<<"Enter the modified author name   ";

        cin>>author_name;

    }


    char* get_bookno()

    {

        return book_no;

    }


    void show_allbook()

    {

        cout<<" Book no.  : ";

        puts(book_no);

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

    char name[35], clas_sec[4],stdbno[6];

    int book_issue, admn_no;


public:


    void Student_entry()

    {

        cout<<" NEW STUDENT ENTRY....\n";

        cout<<"Enter the student admission no   ";

        cin>>admn_no;

        cout<<"Enter the student name   ";

        cin>>name;

        cout<<"Enter the class and section   ";

        cin>>clas_sec;

        cout<<" STUDENT ENTRY CREATED...\n";

    }


    void show_student_details()

    {

        cout<<"The student admission no is   ";

        cout<<(admn_no);

        cout<<"The name of the student is   ";

        puts(name);

        cout<<"The class and section of the student is    ";

        puts(clas_sec);

        cout<<"no. book issued   "<<book_issue<<endl;

        if(book_issue==1)

        {    cout<<" The book no. is    ";

            puts(stdbno);

        }


    }


    void modify_student()

    {

        cout<<"The admission no  ";

        cout<<admn_no<<endl;

        cout<<"Modified student name ";

        cin>>name;

        cout<<"Modified class and section";

        cin>>clas_sec;


    }


    int get_admn()

    {

        return admn_no;

    }


    char* get_stdbno()

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

        cout<<(admn_no);

        cout<<" Student name  : ";

        puts(name);

        cout<<" Class and section   : ";

        puts(clas_sec);

        cout<<" no. Book issue : ";

        cout<<book_issue;

        cout<<endl<<endl;

    }


    void setbno(char A[])

    {

        strcpy_s(stdbno,A);

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

    fout.open("student.txt",ios::binary|ios::app|ios::out);

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

    fout.open("books.txt",ios::binary|ios::app|ios::out);

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

    fin.open("books.txt",ios::binary|ios::app|ios::in);



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

    fin.open("student.txt",ios::binary|ios::app|ios::in);


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

    char bno[7];

    int found=0;

    cout<<"Enter the book no of the book whose details you want to know ";

    cin>>bno;


    fin.open(" books.txt",ios::binary|ios::app|ios::in);

    while(fin.read((char*)&b1,sizeof(b1)))

    {

        if(strcmp(b1.get_bookno(),bno)==0)

        {    b1.show_book();

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


    fin.open(" student.txt",ios::binary|ios::app|ios::in);

    while(fin.read((char*)&s1,sizeof(s1)))

    {

        if(s1.get_admn() == ad_no)

        {    s1.show_student_details();

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
	fstream file;
	file.open("student.txt", ios::binary | ios :: ate| ios:: in| ios :: out );
	student s;
	long int vadmo, pos=0, admo=0;
	bool yes = false;

	cout<<"\nEnter the adno to modify: ";
	cin>>vadmo;

	while(!file.eof())
	{
		pos = file.tellg();

		file.read( (char*) &s, sizeof(student));
		admo = s.get_admn();
		if(admo == vadmo)
		{
			cout<<"\nPresent details: \n ";
			s.show_student_details();

			cout<<"\n\nEnter to modify: \n\n";

			s.modify_student();

			file.seekg((unsigned)pos);
			file.write((char*) &s, sizeof(student));
			yes = true;
			break;
		}

	}

	if(!yes)
		cout<<"\nNot found!!";

	file.seekg(0);
	file.close();
    return;

}


// **********************************************************************************

// Modify book details

// **********************************************************************************


void modify_book()

{

    char bkno[6];

    int flag=0;

    cout<<"Enter the book number of the book whose details is to be modified  ";

    cin>>bkno;

    fout.open(" books.txt",ios::binary|ios::app|ios::in|ios::out);

    while(!fout.eof())

    {

        fout.read((char*)&b1,sizeof(b1));

        if(strcmp(b1.get_bookno(),bkno)==0)

        {

            b1.show_book();

            cout<<" Enter the modified details \n\n";

            b1.modify_book();

            fout.seekp(-1*((signed)sizeof(s1)),ios::cur);

            fout.write((char*)&b1,sizeof(b1));

            cout<<" The record is modified \n\n";

            flag=flag+1;

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

    char bno[6]; int adno;

    int f1=0,f2=0;

    cout<<"enter the student's Admission no   ";

    cin>>adno;

    fin.open(" student.txt",ios::binary|ios::app|ios::in|ios::out);

    fout.open("books.txt",ios::binary|ios::app|ios::in|ios::out);

    while(fin.read((char*)&s1,sizeof(s1)) && f1==0)

    {

        if(s1.get_admn() ==adno)

        {

            f1=1;

            if(s1.get_book_issue()==0)

            {

                cout<<"Enter the book no   ";

                cin>>bno;

                while(fout.read((char*)&b1,sizeof(b1))  && f2==0)

                {

                    if((strcmp(b1.get_bookno(),bno))==0)

                    {

                        b1.show_book();

                        f2=1;

                        s1.set_book_issue();

                        s1.setbno(b1.get_bookno());

                        int pos=-1*((signed)sizeof(s1));

                        fin.seekp(pos,ios::cur);

                        fin.write((char*)&s1,sizeof(s1));

                    }

                }

                if(f2==0)

                    cout<<"Book doesn't exist";


            }

            else

                cout<<" You have not returned the last book ";


        }

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

    return;

}


// **********************************************************************************

// Administrator menu function

// **********************************************************************************


void Admin_menu()

{

	system("cls");
	header();
	header("Admin Menu", (char)196);


    int choice1;

    cout<<" 1: Create New Student Entry \n\n";

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

    case 4: modify_student();

            break;

    case 5: record_book();

            break;

    case 6: system("cls");

            show_allbooks();

            break;

    case 7: system("cls");

            specific_book();

            break;

    case 8: modify_book();

            break;

    case 9:return;

    default: cout<<" WRONG CHOICE ...........\n\n RENTER THE CHOICE ";

    }

}






//***********************************************************************************

//MAIN FUNCTION

//***********************************************************************************




void library()

{

	system("cls");
	header();
	header("Library Management", (char)196);
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



    return ;

}



