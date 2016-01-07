//100% error full program good luck chaitanya!!!!!!


// student data.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include<fstream>

using namespace std;
class stud												//class construction..
{
	float cla,m1,m2,m3;
	float perc,tot;
	char grade,name[20],grade2,grade3,grade1;
	void calculate()									//function to calculate tota;,perc,grade..
	{


		tot=m1+m2+m3;
		perc= ((tot/300.0)*100);
		if(perc>90)
			grade='A';
		else
			if(perc>80)
				grade='B';
			else
					if(perc>65)
						grade='C';
					else
							if(perc>45)
								grade='D';
							else
								grade='E';


	}

	void cal_grade()
	{
		if(m1>90)
			grade1='A';
		else
			if(m1>80)
				grade1='B';
			else
					if(m1>65)
						grade1='C';
					else
							if(m1>45)
								grade1='D';
							else
								grade1='E';


		if(m2>90)
			grade2='A';
		else
			if(m2>80)
				grade2='B';
			else
					if(m2>65)
						grade2='C';
					else
							if(m2>45)
								grade2='D';
							else
								grade2='E';

		if(m3>90)
			grade3='A';
		else
			if(m3>80)
				grade3='B';
			else
					if(m3>65)
						grade3='C';
					else
							if(m3>45)
								grade3='D';
							else
								grade3='E';
	}
	float sml,small1;
	char x,y,z;
	 void calup()																		//calculation of upgraded marks...

	 {
		sml=m1;
		if(m2<=sml)
			sml=m2;
		else
			if(m3<=sml)
				sml=m3;
		cout<<"\n\n\nsmall"<<sml<<"\n";

		//upgradation of grade
		if(sml==m1)
			{
				if(grade1!='A')
					grade1--;
				if(m1<91)
					m1=m1+10;
				if(m1<40)
					m1=50;
				cout<<grade1;
			}
		else
			if(sml==m2)
			{
				if(grade2!='A')
					grade2--;
				if(m2<91)
					m2=m2+10;
				if(m2<40)
					m2=50;
				 cout<<"\n"<<grade2;
			}
			else
				if(sml==m3)
				{
					if(grade3!='A')
						grade3--;
					if(m2<91)
						m3=m3+10;
					if(m3<40)
					m3=50;

					cout<<"\n"<<grade3;
				}
				calculate();


	 }

public:
	int rno;
	float get_rno()
	{
		return rno;
	}


	 char get_grade()
	 {
		 return grade;

	 }															//accessor functions...
	 char get_grade1()
	 {
		 return grade1;

	 }
	 char get_grade2()
	 {
		 return grade2;

	 }//accesor function
	 char get_grade3()
	 {
		 return grade3;

	 }//accesor function
	 float get_class()
	 {
		 return cla;
	 }//accesor function

	  char get_small1()
	 {
		 return small1;
	 }//accesor function
	 void read()
	 {
		 cout<<"\n enter the roll no";
		 cin>>rno;
		 cout<<" \n enter the name";
		 cin>>name;
		 cout<<"\n enter the class ";
		 cin>>cla;
		 cout<<"\n enter the marks \n";
		 cin>>m1>>m2>>m3;
	 }

	 void display()
	 {
		 calculate();
		 cal_grade();
		 cout<<"\n"<<rno<<"\t"<<name<<"\t"<<cla<<"\t"<<m1<<"  "<<get_grade1()<<"\t"<<m2<<"  "<<get_grade2()<<"\t"<<m3<<"  "<<get_grade3()<<"\t"<<tot<<"\t"<<perc<<"  "<<get_grade();

	 }
	 void upgrade()
	 {
		 calup();
		  cout<<"\n"<<rno<<"\t"<<name<<"\t"<<cla<<"\t"<<m1<<"  "<<get_grade1()<<"\t"<<m2<<"  "<<get_grade2()<<"\t"<<m3<<"  "<<get_grade3()<<"\t"<<tot<<"\t"<<perc<<"  "<<get_grade();

	 }

	}mike,S[100];

void swap(stud &A,stud &B)
{
    stud temp = A;
    A=B;
    B=temp;
}
void selectsort(stud A[100],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(A[j].get_rno()<A[i].get_rno())
                swap(A[j],A[i]);
}





int main()
{
	fstream fin,fout;

	 system("color 2f");



	int ch,ch1, i=0,j=0;

	do{

			cout<<" enter 1: write to file\n enter 2: read into the file\n 3:ascending order\n 4: for upgraded marks";
			cin>>ch;

			int m;
			switch(ch)
			{

				case 1:

							cout<<"emetr the size of the array: ";
							cin>>m;
							fout.open("test.txt",ios::out|ios::binary| ios::app);
							for(int i=0;i<m;i++)
							{
								S[i].read();
								fout.write((char*)&S[i],sizeof(stud));
							}



							//fout.write((char*)&S,sizeof(S));

							fout.close();


							break;
				case 2:

							fin.open("test.txt",ios::in|ios::binary);
							cout<<"roll\t name\t class \t m1\t m2\t m3 \t \n\n";

							 while(fin.read((char*)&mike,sizeof(stud)))
							{

									  mike.display();

							 }
							fin.close();

							break;

				case 3:
					      //  int j,i=0;
							fin.open("test.txt", ios::binary|ios::in);
							cout<<"roll\tname\tclass\tm1\tgrade\tm2\tgrade\tm3\tgrade\ttot\tperc\tgrade\n\n";
							i=0;
							while(fin.read((char*)&S[i],sizeof(stud)))
							{


												//S[i]= mike;
												++i;

							}
							selectsort(S,i);

							for(j=0; j<i; ++j)
								S[i].display();

							fin.close();

							break;

				case 4:
							//int i,j;
							fin.open("g:\\test.txt",ios::app|ios::binary);
							cout<<"roll\t name\t class \t m1\t m2\t m3 \t \n\n";

							while(fin.read((char*)&S,sizeof(S)));
							{

										for(j=1;j<100;j++)
										{
											for(i=0;i<3;i++)
											{
												if(mike.rno==j)

												mike.upgrade();
											}
										}

							}
							fin.close();

							break;



			}

			cout<<" \n enter 1:to continue else press anyting;";
			cin>>ch1;
	}while(ch1==1);


	system("pause");
	return 0 ;
}



