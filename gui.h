//#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include<iomanip>
#include<process.h>
#include<dos.h>

using namespace std;

int i, j, enter=0;
char name[51]=" ";


// **********************************************************************************

// GUI Functions

// **********************************************************************************

void usr()
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

}
void header()
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



}
