#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
# include<malloc.h>
# include<stdlib.h>
# include<windows.h>
#include<dos.h>
using namespace std;

class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{
		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nEnter The book no.";
		cin>>bno;
		cout<<"\n\nEnter The Name of The Book ";
		cin>>bname;
		gets(bname);
		cout<<"\n\nEnter The Author's Name ";
		gets(aname);
		cout<<"\n\n\nBook Created..";
	}

	void show_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nBook Name : ";
		cout<<bname;
		puts(bname);
		cout<<"Author Name : ";
		puts(aname);
	}

	void modify_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nModify Book Name : ";
		cin>>bname;
		gets(bname);
		cout<<"\nModify Author's Name of Book : ";
		gets(aname);
	}

	char* retbno()
	{
		return bno;
	}

	void report()
	{cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}


};         //class ends here




class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int token;
public:
	void create_student()
	{
		system("cls");;
	 	cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter The UID no.. ";
		cin>>admno;
		cout<<"\n\nEnter The Name of The Student ";
		cin>>name;
		gets(name);
		token=0;
		stbno[0]='/0';
		cout<<"\n\nStudent Record Created..";
	}

	void show_student()
	{
		cout<<"\nUID no.. : "<<admno;
		cout<<"\nStudent Name : ";
		cout<<name;
		puts(name);
		cout<<"\nNo of Book issued : "<<token;
		if(token==1)
			cout<<"\nBook No "<<stbno;
	}

	void modify_student()
	{
		cout<<"\nUID no.. : "<<admno;
		cout<<"\nModify Student Name : ";
		gets(name);
	}

	char* retadmno()
	{
		return admno;
	}

	char* retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token=1;}

	void resettoken()
	{token=0;}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{cout<<"\t\t\t\t\t\t\t*\t"<<admno<<setw(20)<<name<<setw(10)<<token<<"\t\t*"<<endl;}

};
fstream fp,fp1;
book bk;
student st;
void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		system("cls");;
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void write_student()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);
	do
	{
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void display_spb(char n[])
{
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
		 	flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nBook does not exist";
	getch();
}

void display_sps(char n[])
{
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retadmno(),n)==0))
		{
			st.show_student();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
    		cout<<"\n\nStudent does not exist";
 	getch();
}

void modify_book()
{
	char n[6];
	int found=0;
	system("cls");;
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. of The book";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			cout<<"\nEnter The New Details of book"<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&bk,sizeof(book));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	fp.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}


void modify_student()
{
	char n[6];
	int found=0;
	system("cls");;
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The UID no.. of The student";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),n)==0)
		{
			st.show_student();
			cout<<"\nEnter The New Details of student"<<endl;
			st.modify_student();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}
void delete_student()
{
	char n[6];
	int flag=0;
	system("cls");;
    	cout<<"\n\n\n\tDELETE STUDENT...";
    	cout<<"\n\nEnter The UID no.. of the Student You Want To Delete : ";
    	cin>>n;
    	fp.open("student.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmno(),n)!=0)
	     		fp2.write((char*)&st,sizeof(student));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("student.dat");
    	rename("Temp.dat","student.dat");
    	if(flag==1)
     		cout<<"\n\n\tRecord Deleted ..";
    	else
     		cout<<"\n\nRecord not found";
    	getch();
}


void delete_book()
{
	char n[6];
	system("cls");;
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
	}

	fp2.close();
    	fp.close();
    	remove("book.dat");
    	rename("Temp.dat","book.dat");
    	cout<<"\n\n\tRecord Deleted ..";
    	getch();
}

void display_alls()
{
	system("cls");;
     	fp.open("student.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\t\t\t\t\t\t\t\t\t\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSTUDENT LIST\n\n";
	cout<<"\t\t\t\t\t\t\==================================================================\n";
	cout<<"\t\t\t\t\t\t\t|\tUID no.."<<setw(10)<<""<<setw(20)<<"Book Issued\t|\n";
	cout<<"\t\t\t\t\t\t\==================================================================\n";

	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}
    cout<<"\t\t\t\t\t\t\==================================================================\n";
	fp.close();
	getch();
}

void display_allb()
{
	system("cls");;
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"Book Number"<<setw(20)<<""<<setw(25)<<"Book Name\n";
	cout<<"=========================================================================\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
     	fp.close();
     	getch();
}



void book_issue()
{
	char sn[6],bn[6];
	int found=0,flag=0;
	system("cls");;
	cout<<"\n\nBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's UID no..";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
    	fp1.open("book.dat",ios::in|ios::out);
    	while(fp.read((char*)&st,sizeof(student)) && found==0)
       	{
		if(strcmpi(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()==0)
			{
		      		cout<<"\n\n\tEnter the book no. ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
			   		if(strcmpi(bk.retbno(),bn)==0)
					{
						bk.show_book();
						flag=1;
						st.addtoken();
						st.getstbno(bk.retbno());
       						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t BOOK ISSUED SUCCESFULLY\n\nPLEASE NOTE: Write current date in backside of book and submit within 15 days fine Rs. 1 for each day after 15 days period";
					}
		    		}
		  		if(flag==0)
		    			cout<<"Book no does not exist";
			}
	    		else
		  		cout<<"YOU HAVE NOT RETURNED THE LAST BOOK!! KINDLY SUBMIT IT ";

		}
	}
      	if(found==0)
		cout<<"RECORD DOESN'T EXIST";
	getch();
  	fp.close();
  	fp1.close();
}

void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    system("cls");;
    cout<<"\n\n...........BOOK DEPOSIT.... ...";
    cout<<"\n\n\tEnter The student's UID.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
	    if(strcmpi(st.retadmno(),sn)==0)
	    {
		    found=1;
		    if(st.rettoken()==1)
		    {
			while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			{
			   if(strcmpi(bk.retbno(),st.retstbno())==0)
			{
				bk.show_book();
				flag=1;
				cout<<"\n\nBook deposited in no. of days";
				cin>>day;
				if(day>15)
				{
				   fine=(day-15)*1;
				   cout<<"\n\nFine has to deposited Rs. "<<fine;
				}
					st.resettoken();
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&st,sizeof(student));
					cout<<"\n\n\t Book deposited successfully";
			}
		    }
		  if(flag==0)
		    cout<<"Book no does not exist";
		      }
		 else
			cout<<"No book is issued..please check!!";
		}
	   }
      if(found==0)
	cout<<"Student record not exist...";
	getch();
  fp.close();
  fp1.close();
  }




//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
    system("cls");

	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t*********************************************************************************************\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                      _____________________________________		                  |@@\n";
cout<<"\t\t\t\t\t@@|                     |                      		      |                           |@@\n";
cout<<"\t\t\t\t\t@@|                     |                WELCOME              |                           |@@\n";
cout<<"\t\t\t\t\t@@|                     |                                     |                           |@@\n";
cout<<"\t\t\t\t\t@@|                     |      COLLEGE LIBRARY MANAGEMENT     |                           |@@\n";
cout<<"\t\t\t\t\t@@|                     |_____________________________________|                           |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t*********************************************************************************************\n\n\n\n\t\t\t\t\t";
system("pause");
system("cls");
}



//***************************************************************
//    	ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
	system("cls");;
	int ch2;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  LIBRARY MANAGEMENT SYSTEM \n\n";
cout<<"\n\n\t\t\t\t\t\tSELECT YOUR OPTION HERE!!!!!!!!\n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________\n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >>  ADMINISTRATOR MENU                           |\n";
cout<<"\t\t\t\t\t\t|             2  >> CREATE STUDENT RECORD                         |\n";
cout<<"\t\t\t\t\t\t|	      3  >> DISPLAY ALL STUDENTS RECORD                   |\n";
cout<<"\t\t\t\t\t\t|             4  >> DISPLAY SPECIFIC STUDENT RECORD               |\n";
cout<<"\t\t\t\t\t\t|             5  >> MODIFY STUDENT RECORD                         |\n";
cout<<"\t\t\t\t\t\t|             6  >> DELETE STUDENT RECORD                         |\n";
cout<<"\t\t\t\t\t\t|             7  >> CREATE BOOK                                   |\n";
cout<<"\t\t\t\t\t\t|	      8  >> DISPLAY ALL BOOKS                             |\n";
cout<<"\t\t\t\t\t\t|	      9  >> DISPLAY SPECIFIC BOOK                         |\n";
cout<<"\t\t\t\t\t\t|             10 >> MODIFY BOOK                                   |\n";
cout<<"\t\t\t\t\t\t|             11 >> DELETE BOOK                                   |\n";
cout<<"\t\t\t\t\t\t|             12 >>BACK TO MAIN MENU                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
	cin>>ch2;
	switch(ch2)
	{
    		case 2: system("cls");;
	    		write_student();break;
    		case 3: display_alls();break;
    		case 4:
	       		char num[6];
	       		system("cls");;
	       		cout<<"\n\n\tPlease Enter The UID no.. ";
	       		cin>>num;
	       		display_sps(num);
	       		break;
      		case 5: modify_student();break;
      		case 6: delete_student();break;
		case 7: system("cls");;
			write_book();break;
		case 8: display_allb();break;
		case 9: {
	       		char num[6];
	       		system("cls");;
	       		cout<<"\n\n\tPlease Enter The book No. ";
	       		cin>>num;
	       		display_spb(num);
	       		break;
			}
      		case 10: modify_book();break;
      		case 11: delete_book();break;
     		case 12: return;
      		default:cout<<"\a";
   	}
   	admin_menu();
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{  system("color 89");
	char ch;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t\t\t _________________________________________________________________\n";
		cout<<"\t\t\t\t\t\t|                             MAIN MENU                           |\n\n";
		cout<<"\t\t\t\t\t\t|              01. BOOK ISSUE                                     |\n\n";
		cout<<"\t\t\t\t\t\t|              02. BOOK DEPOSIT                                   |\n\n";
	  	cout<<"\t\t\t\t\t\t|              03. ADMINISTRATOR MENU                             |\n\n";
	  	cout<<"\t\t\t\t\t\t|              04. EXIT                                           |\n\n";
	  	cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	  	cout<<"\n\n\tPlease Select Your Option (1-4) ";
	  	ch=getche();
	  	switch(ch)
	  	{
			case '1':system("cls");;
				 book_issue();
			   	 break;
		  	case '2':book_deposit();
			    	 break;
		  	case '3':admin_menu();
				 break;
		  	case '4':exit(0);
		  	default :cout<<"\a";
		}
    	}while(ch!='4');
    	return 0;
}
