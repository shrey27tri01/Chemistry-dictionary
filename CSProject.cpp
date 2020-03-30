#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<process.h>
#include<string.h>
#include<dos.h>
int x,y,i,n,t,j;
char a,z,ch[50];
void abc();
void main();
void chapter();
void chapter1();
void cde();
void delet();
void display();
void one();//1
void two();//2
void three();//3
void four();//4
void five();//5
void six();//6
void seven();//7
void eight();//8
void nine();//9
void ten();//10
void eleven();//11
void twelve();//12
void thirteen();//13
void fourteen();//14
void graphic();
void CH1_1();void CH1_2();void CH1_3();void CH1_4();void CH1_5();
void CH1_6();void CH1_7();void CH1_8();void CH1_9();
void CH2_1();void CH2_2();void CH2_3();void CH2_4();void CH2_5();
void CH2_6();void CH2_7();void CH2_8();void CH2_9();
void CH3_1();void CH3_2();
void CH4_1();void CH4_2();void CH4_3();void CH4_4();
void CH5_1();void CH5_2();void CH5_3();
void CH6_1();void CH6_2();void CH6_3();
void CH7_1();void CH7_2();void CH7_3();void CH7_4();
void CH8_1();void CH8_2();
void CH9_1();void CH9_2();void CH9_3();
void CH10_1();void CH10_2();void CH10_3();
void CH11_1();void CH11_2();void CH11_3();
void CH12_1();void CH12_2();void CH12_3();void CH12_4();
void CH13_1();void CH13_2();void CH13_3();
void CH14_1();void CH14_2();void CH14_3();
class history
{	char ch[50];
	public:
	void input(char bh[50])
	{	gets(ch);
		strcpy(ch,bh);
	}
	void display()
	{	cout<<ch<<"\n\n";	}
	char* search()
	{	return ch;	}
}obj;
void graphic1()
{	clrscr();
	int k=0;
	for(k=79,i=1;k>40,i<40;k--,i++)
	{	textcolor(3);  //aqua color
		gotoxy(i,1);
		cprintf
		("±");
		textcolor(4); //red color
		gotoxy(k,1);
		cprintf("±");
	 }
	textcolor(15);  // white color
	gotoxy(33,3);
	cprintf("CHEMISTRY APP");
	gotoxy(31,2);
	cprintf("É");
	gotoxy(47,2);
	cprintf("»");
	gotoxy(31,4);
	cprintf("È");
	gotoxy(47,4);
	cprintf("¼");
	textcolor(8); //grey color
	for(i=32;i<47;i++)
	{	gotoxy(i,2);
		cprintf("=");
		gotoxy(i,4);
		cprintf("=");
	}
	gotoxy(31,3);
	cprintf("|");
	gotoxy(47,3);
	cprintf("|");
}
void exit()
{	cout<<"ARE YOU SURE YOU WANT TO EXIT (Y/N) ? :- ";
	cin>>a;
	if(a=='y'||a=='Y')
	{	exit(1);	}
	else if(a=='n'||a=='N')
	{	main();		}
}
void search()
{	graphic();
	textcolor(18);
	gotoxy(1,5);
	char x[50];
	char pr;
	cin.get(pr);
	ofstream chem("histo.dat",ios::out|ios::app);
	cout<<"\n""ENTER THE CHAPTER NAME :- ""\n";
		gets(x);
		if(strcmpi(x,"SOME BASIC CONCEPTS OF CHEMISTRY")==0)
		{	one();		}
		if(strcmpi(x,"STRUCTURE OF ATOM")==0)
		{	two();		}
		if(strcmpi(x,"CLASSIFICATION OF ELEMENTS AND PERIODICITY")==0)
		{	three();	}
		if(strcmpi(x,"CHEMICAL BONDING AND MOLECULAR STRUCTURE")==0)
		{	four();		}
		if(strcmpi(x,"STATES OF MATTER")==0)
		{	five();		}
		if(strcmpi(x,"THERMODYNAMICS")==0)
		{	six();		}
		if(strcmpi(x,"EQUILIBRIUM")==0)
		{	seven();	}
		if(strcmpi(x,"REDOX REACTIONS")==0)
		{	eight();		}
		if(strcmpi(x,"HYDROGEN")==0)
		{	nine();		}
		if(strcmpi(x,"THE S-BLOCK ELEMENTS")==0)
		{	ten();		}
		if(strcmpi(x,"THE P-BLOCK ELEMENTS")==0)
		{	eleven();	}
		if(strcmpi(x,"ORGANIC CHEMISTRY")==0)
		{	twelve();	}
		if(strcmpi(x,"HYDROCARBONS")==0)
		{	thirteen();	}
		if(strcmpi(x,"ENVIRONMENTAL CHEMISTRY")==0)
		{	fourteen();	}
		else if(strcmpi(x,"0")==0)
		{	main();		}
		else
		{	cout<<"\n""SORRY , THERE IS NO SUCH CHAPTER";		}
		obj.input(x);
		chem.write((char*)&obj,sizeof(obj));
		chem.close();
}
void delet()
{	clrscr();
	graphic1();
	gotoxy(1,5);
	char ch[50],c[10],sh[10],i=0,j=0;
	cout<<"YOU NEED TO ENTER THE PASSWORD TO DELETE A CHAPTER";//PASSWORD
	cout<<"\n""Enter FIVE LETTER password :- ";
	strcpy(sh,"APSCOMP");
	lop:
	while(i<7)
	{	c[i]=getch();
		cout<<"*";
		if(c[i]!=sh[i])
		{	j=1;	}
		if(i>5)
		{	goto lop;	}
		i++;
	}
	if(j==1)
	{	char a;
		cout<<"\n""Incorrect password!!";
		cout<<"\n""Return to main menu ? (Y/N)";
		cin>>a;
		if(a=='y'||a=='Y')
		{	main();		}
		else if(a=='n'||a=='N')
		{	exit(1);		}
	}
	else
	{	cout<<"Enter the name of the chapter you want to delete :- ""\n";
		gets(ch);
		ifstream chem("histo.dat",ios::in);
		ofstream chem1("temp.dat",ios::out|ios::app);
		while(chem.read((char*)&obj,sizeof(obj)))
		{	if(strcmpi(obj.search(),ch)==0)
			{	//data found	}
			else
			{	chem1.write((char*)&obj,sizeof(obj));	}
		}
		remove("histo.dat");
		rename("temp.dat","histo.dat");
		chem.close();
		chem1.close();
		//data saved successfully
	}
	getch();
}
void display()
{	clrscr();
	graphic1();
	gotoxy(1,5);
	ifstream chem("histo.dat",ios::in);
	cout<<"Here are your last search results :- ""\n";
	int ww=1;
	while(ww<=5)
	{	while(chem.read((char*)&obj,sizeof(obj)))
	{	cout<<ww<<". ";
		obj.display();
		ww++;	}
	}
	chem.close();
	getch();
}	void graphic()
{	clrscr();
	textcolor(3);
	for(int l=1;l<26;l++)
	{	 if(l%2==0)
	  {	textcolor(3);
		gotoxy(78,l);
		cprintf("±±");
	  }
	  if(l%2!=0)
	  {	textcolor(4);   //red color
		gotoxy(78,l);
		cprintf("±±");		  }
}
	int k=0;
	for(k=79,i=1;k>40,i<40;k--,i++)
	{	textcolor(3);  //aqua color
		gotoxy(i,1);
		cprintf("þþ");
		textcolor(4);  //red color
		gotoxy(k,1);
		cprintf("þþ");		}
	textcolor(15);   //white color
	gotoxy(33,3);
	cprintf("CHEMISTRY APP");
	gotoxy(31,2);
	cprintf("É");
	gotoxy(47,2);
	cprintf("»");
	gotoxy(31,4);
	cprintf("È");
	gotoxy(47,4);
	cprintf("¼");
	textcolor(8);   //grey color
	for(i=32;i<47;i++)
	{	gotoxy(i,2);
		cprintf("=");
		gotoxy(i,4);
		cprintf("=");		}
	int j=0;
	for(i=1,j=48;i<32,j<78;i++,j++)
	{	 if(i<31)
	      {	gotoxy(i,3);
		cprintf("-");	  }
		gotoxy(j,3);
		cprintf("-");	}
	gotoxy(31,3);
	cprintf("|");
	gotoxy(47,3);
	cprintf("|");		}
void chapter()
{	graphic();
	textcolor(2);  //green color
	gotoxy(1,5);
	cout<<"(1) SOME BASIC CONCEPTS OF CHEMISTRY";
	cout<<"\n""(2) STRUCTURE OF ATOM";
	cout<<"\n""(3) CLASSIFICATION OF ELEMENTS AND PERIODICITY";
	cout<<"\n""(4) CHEMICAL BONDING AND MOLECULAR STRUCTURE";
	cout<<"\n""(5) STATES OF MATTER";
	cout<<"\n""(6) THERMODYNAMICS";
	cout<<"\n""(7) EQUILIBRIUM";
	cout<<"\n""0-MORE";
	cout<<"\n""99-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n\n\t""ENTER THE CHAPTER NUMBER IN WHICH YOU ARE INTERESTED:- ";
	cin>>x;
	if(x==7||x==6||x==5||x==4||x==3||x==2||x==1||x==0||x==22||x==99)
		{	if(x==1)
		{	one();		}
			else if(x==2)
			{	two();		}
			else if(x==3)
			{	three();	}
			else if(x==4)
			{	four();		}
			else if(x==5)
			{	five();		}
			else if(x==6)
			{	six();	}
			else if(x==7)
			{	seven();		}
			else if(x==0)
			{	chapter1();		}
			else if(x==99)
			{	 main();	}
			else if(x==22)
			{	cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
			  cin>>a;
			  if(a=='y'||a=='Y')
			   {	 exit(1);		  }
			  else if(a=='n'||a=='N')
			   {	  main();	 }
			  else
			   {	cout<<"Wrong Input";	}
			}
			else
			{	cout<<"!! INVALID INPUT !!";		}
		}
	else
	 {	cout<<"!! INVALID INPUT !!""\n""\n""Want to exit ? (Y/N) :- ";
		cin>>a;
		if(a=='y'||a=='Y')
		 {	 exit();	}
		else if(a=='n'||a=='N')
		 {	 main();	}
	 }
}
void chapter1()
{	clrscr();
	graphic();
	textcolor(2);
	gotoxy(1,5);
	cout<<"(8) REDOX REACTIONS";
	cout<<"\n""(9) HYDROGEN";
	cout<<"\n""(10) THE s-BLOCK ELEMENTS";
	cout<<"\n""(11) THE p-BLOCK EEMENTS";
	cout<<"\n""(12) ORGANIC CHEMISTRY";
	cout<<"\n""(13) HYDROCARBONS";
	cout<<"\n""(14) ENVIRONMENTAL CHEMISTRY";
	cout<<"\n""0-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE CHAPTER NUMBER IN WHICH YOU ARE INTERESTED:-""\n";
	cin>>i;
	if(i==14||i==13||i==12||i==11||i==10||i==9||i==8||i==0||i==22)
		{
			if(i==8)
			{	eight();		}
			else if(i==9)
			{	nine();	}
			else if(i==10)
			{	ten();	}
			else if(i==11)
			{	eleven();	}
			else if(i==12)
			{	twelve();	}
			else if(i==13)
			{	thirteen();	}
			else if(i==14)
			{	fourteen();	}
			else if(i==0)
			{	chapter();	}
			else if(i==22)
			{	cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
			  	cin>>a;
			  	if(a=='y'||a=='Y')
			  	 (	exit(1);		 }
			  	else if(a=='n'||a=='N')
			   	{	main();		}
			  	else
			  	 {	cout<<"Wrong Input";	}
			}
			else
			{	cout<<"!! INVALID INPUT !!"	}
}
	else
	 {	cout<<"!! INVALID INPUT !!""\n""\n""Want to exit ? (Y/N) :- ";
		cin>>a;
		if(a=='y'||a=='Y')
		 {	exit();	}
		else if(a=='n'||a=='N')
		 {	 main();	}
	 }
}
void one()         //chapter 1
(	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) IMPORTANCE OF CHEMISTRY";
	cout<<"\n""(2) NATURE OF MATTER";
	cout<<"\n""(3) STOICHIOMETRY";
	cout<<"\n""(4) MEASUREMENT";
	cout<<"\n""(5) ATOMIC AND MOLECULAR MASSES";
	cout<<"\n""(6) DALTON'S ATOMIC THEORY";
	cout<<"\n""(7) LAWS OF CHEMICAL COMBINATIONS";
	cout<<"\n""(8) MOLE CONCEPT AND MOLAR MASSES";
	cout<<"\n""(9) PERCENTAGE COMPOSITION";
	cout<<"\n""0-BACK TO MAIN MENU";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-";
	cin>>y;
	if(y==1)
	{ CH1_1();}
	if(y==2)
	{ CH1_2();}
	if(y==3)
	{ CH1_3();}
	if(y==4)
	{ CH1_4();}
	if(y==5)
	{ CH1_5();}
	if(y==6)
	{ CH1_6();}
	if(y==7)
	{ CH1_7();}
	if(y==8)
	{ CH1_8();}
	if(y==9)
	{ CH1_9();}
	else if(y==0)
	{	chapter();	}
	else if(y==22)
	{	cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	  cin>>a;
	  if(a=='y'||a=='Y')
	  {	exit(1);		}
	  else if(a=='n'||a=='N')
	  {	one();	}
	}
	else
	   cout<<"!! INVALID INPUT !!";
}
void two()//2
{	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) DISCOVERY OF PROTONS AND ELECTRONS";
	cout<<"\n""(2) ATOMIC NUMBER AND ATOMIC MASS";
	cout<<"\n""(3) ATOMIC ORBITALS";
	cout<<"\n""(4) ATOMIC RADIUS";
	cout<<"\n""(5) ATOMIC SPECTRA";
	cout<<"\n""(6) ATOMIC THEORY";
	cout<<"\n""(7) ATOMICITY";
	cout<<"\n""(8) CHARGE ON AN ELECTRON";
	cout<<"\n""(9) CHARGE TO MASS RATIO OF AN ELECTRON";
	cout<<"\n""0-BACK TO MAIN MENU";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{ CH2_1(); }
	if(y==2)
	{ CH2_2(); }
	if(y==3)
	{ CH2_3(); }
	if(y==4)
	{ CH2_4(); }
	if(y==5)
	{ CH2_5(); }
	if(y==6)
	{ CH2_6(); }
	if(y==7)
	{ CH2_7(); }
	if(y==8)
	{ CH2_8(); }
	if(y==9)
	{ CH2_9(); }
	else if(y==0)
	{ chapter(); }
	else if(y==22)
	{	cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	  cin>>a;
	  if(a=='y'||a=='Y')
	  {	exit(1);		}
	  else if(a=='n'||a=='N')
	  {	two();	}
	}
}
void three()   //3
{	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : INTRODUCTION TO THE PERIODIC TABLE";
	cout<<"\n""(2) PART 2 : PERIODIC TRENDS IN THE PERIODIC TABLE";
	cout<<"\n""0-BACK TO MAIN MENU";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{	 CH3_1();
	}
	else if(y==2)
	{
	 CH3_2();
	}
	else if(y==0)
	{
	 chapter();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	   exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  three();
	 }
	}

}
void four()      //4
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : INTRODUCTION";
	cout<<"\n""(2) PART 2 : VALENCE SHELL ELECTRON PAIR REPULSION THEORY";
	cout<<"\n""(3) PART 3 : VALENCE BOND THEORY";
	cout<<"\n""(4) PART 4 : MOLECULAR ORBITAL THEORY";
	cout<<"\n""0-BACK TO MAIN MENU";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH4_1();
	}
	else if(y==2)
	{
	 CH4_2();
	}
	else if(y==3)
	{
	 CH4_3();
	}
	else if(y==4)
	{
	 CH4_4();
	}

	else if(y==0)
	{
	 chapter();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  four();
	 }
	}

}
void five()      //5
{
 clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : INTRODUCTION";
	cout<<"\n""(2) PART 2 : THE LAWS";
	cout<<"\n""(3) PART 3 : PROPERTIES OF MATTER";
	cout<<"\n""0-BACK TO MAIN MENU";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH5_1();
	}
	else if(y==2)
	{
	 CH5_2();
	}
	else if(y==3)
	{
	 CH5_3();
	}
	else if(y==0)
	{
	 chapter();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  five();
	 }
	}

}
void six()      //6
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : INTRODUCTION AND THERMODYNAMIC LAW";
	cout<<"\n""(2) PART 2 : THE THERMODYNAMIC VARIABLES";
	cout<<"\n""(3) PART 3 : THERMOCHEMISTRY";
	cout<<"\n""0-BACK TO MAIN MENU";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH6_1();
	}
	else if(y==2)
	{
	 CH6_2();
	}
	else if(y==3)
	{
	 CH6_3();
	}
	else if(y==0)
	{
	 chapter();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  six();
	 }

	}
}

void seven()      //7
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : EQUILIBRIUM-INTRODUCTION";
	cout<<"\n""(2) PART 2 : EQUILIBRIUM CONSTANT AND ELECTROLYTES";
	cout<<"\n""(3) PART 3 : ACIDS AND BASES";
	cout<<"\n""(4) PART 4 : IONIZATION";
	cout<<"\n""0-BACK TO MAIN MENU";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH7_1();
	}
	else if(y==2)
	{
	 CH7_2();
	}
	else if(y==3)
	{
	 CH7_3();
	}
	else if(y==4)
	{
	 CH7_4();
	}
	else if(y==0)
	{
	 chapter();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  seven();
	 }
	}
}
void eight()      //8
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : REDOX REACTIONS - INTRODUCTION";
	cout<<"\n""(2) PART 2 : REDOX REACTIONS - PROPERTIES";
	cout<<"\n""99-BACK TO MAIN MENU";
	cout<<"\n""0-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH8_1();
	}
	else if(y==2)
	{
	 CH8_2();
	}
	else if(y==0)
	{
	 chapter1();
	}
	else if(y==99)
	{
	 main();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  eight();
	 }
	}
}
void nine()      //9
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : HYDROGEN - INTRODUCTION";
	cout<<"\n""(2) PART 2 : DIHYDROGEN";
	cout<<"\n""(3) PART 3 : WATER AND HYDROGEN PEROXIDE";
	cout<<"\n""99-BACK TO MAIN MENU";
	cout<<"\n""0-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH9_1();
	}
	else if(y==2)
	{
	 CH9_2();
	}
	else if(y==3)
	{
	 CH9_3();
	}
	else if(y==0)
	{
	 chapter1();
	}
	else if(y==99)
	{
	 main();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  nine();
	 }
	}
}
void ten()      //10
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : PHYSICAL PROPERTIES OF THE s-BLOCK ELEMENTS";
	cout<<"\n""(2) PART 2 : THE ALKALI METALS";
	cout<<"\n""(3) PART 3 : THE ALKALINE EARTH METALS";
	cout<<"\n""99-BACK TO MAIN MENU";
	cout<<"\n""0-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH10_1();
	}
	else if(y==2)
	{
	 CH10_2();
	}
	else if(y==3)
	{
	 CH10_3();
	}
	else if(y==0)
	{
	 chapter1();
	}
	else if(y==99)
	{
	 main();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  ten();
	 }
	}
}
void eleven()      //11
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : PHYSICAL PROPERTIES OF THE p-BLOCK ELEMENTS";
	cout<<"\n""(2) PART 2 : THE BORON FAMILY";
	cout<<"\n""(3) PART 3 : THE CARBON FAMILY";
	cout<<"\n""99-BACK TO MAIN MENU";
	cout<<"\n""0-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH11_1();
	}
	else if(y==2)
	{
	 CH11_2();
	}
	else if(y==3)
	{
	 CH11_3();
	}
	else if(y==0)
	{
	 chapter1();
	}
	else if(y==99)
	{
	 main();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  eleven();
	 }
	}
}
void twelve()      //12
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : ORGANIC CHEMISTRY - INTRODUCTION";
	cout<<"\n""(2) PART 2 : STRUCTURE AND NOMENCLATURE OF ORGANIC COMPOUNDS";
	cout<<"\n""(3) PART 3 : ORGANIC REACTION MECHANISMS";
	cout<<"\n""(4) PART 4 : PURIFICATION OF ORGANIC COMPOUNDS";
	cout<<"\n""99-BACK TO MAIN MENU";
	cout<<"\n""0-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH12_1();
	}
	else if(y==2)
	{
	 CH12_2();
	}
	else if(y==3)
	{
	 CH12_3();
	}
	else if(y==4)
	{
	 CH12_4();
	}
	else if(y==0)
	{
	 chapter1();
	}
	else if(y==99)
	{
	 main();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  twelve();
	 }
	}
}
void thirteen()      //13
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : HYDROCARBONS - INTRODUCTION";
	cout<<"\n""(2) PART 2 : ALKANES , ALKENES AND ALKYNES";
	cout<<"\n""(3) PART 3 : AROMATIC COMPOUNDS";
	cout<<"\n""99-BACK TO MAIN MENU";
	cout<<"\n""0-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH13_1();
	}
	else if(y==2)
	{
	 CH13_2();
	}
	else if(y==3)
	{
	 CH13_3();
	}
	else if(y==0)
	{
	 chapter1();
	}
	else if(y==99)
	{
	 main();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  thirteen();
	 }
	}
}
void fourteen()      //14
{
	clrscr();
	graphic();
	textcolor(18);
	gotoxy(1,5);
	cout<<"(1) PART 1 : ENVIROMENTAL CHEMISTRY - INTRODUCTION";
	cout<<"\n""(2) PART 2 : ATMOSPHERIC POLLUTION";
	cout<<"\n""(3) PART 3 : CONTROLLING POLLUTION";
	cout<<"\n""99-BACK TO MAIN MENU";
	cout<<"\n""0-BACK";
	cout<<"\n""22-EXIT";
	cout<<"\n""ENTER THE TOPIC NUMBER WHICH YOU WANT TO SEARCH:-""\n";
	cin>>y;
	if(y==1)
	{
	 CH14_1();
	}
	else if(y==2)
	{
	 CH14_2();
	}
	else if(y==3)
	{
	 CH14_3();
	}
	else if(y==0)
	{
	 chapter1();
	}
	else if(y==99)
	{
	 main();
	}
	else if(y==22)
	{
	 cout<<"ARE YOU SURE YOU WANT TO EXIT ? (Y/N) :- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
	  exit(1);
	 }
	 else if(a=='n'||a=='N')
	 {
	  fourteen();
	 }
	}
}



void CH1_1()    //importanceofchemistry(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-1.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH1_2()    //NATUREOFMATTER(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-2.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	   main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH1_3()    //stoichiometry(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-3.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	   main();
	}else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH1_4()    //measurement(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-4.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH1_5()    //atomicandmolecularmasses(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-5.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH1_6()    //daltonsatomictheory(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-6.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	   main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH1_7()    //lawsofchemicalcombination(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-7.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	   main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH1_8()    //moleconceptandmolarmasses(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-8.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	   main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH1_9()    //percentagecomposition(ch1)
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH1-9.txt",ios::in);
	while(!iff.eof())
	{
	  iff.getline(ch,50,'\n');
	  cout<<ch;
	  cout<<" ";
	  delay(500);
	}
	cout<<"\n\n\t""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	  one();
	}
	else if(z=='n'||z=='N')
	{
	   main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}

void CH2_1()     //DISCOVERYOFPRotonsandelectrons(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-1.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH2_2()  //atomicnumberandatomicmass(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-2.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N)";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();;
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH2_3()         //atomicorbitals(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-3.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N)";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH2_4()    //atomicradius(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-4.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N)";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH2_5()   //atomicspectra(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-5.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N)";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH2_6()  //atomictheory(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-6.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N)";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH2_7()  //atomicity(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-7.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N)";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH2_8()  //chargeonelectron(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-8.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N)";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}

void CH2_9()   //chargetomassratioofelectron(ch2)
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH2-9.txt",ios::in);
	while(!iff.eof())
	{
	iff.getline(ch,50,'\n');
	cout<<ch;
	cout<<" ";
	delay(500);
	}
	cout<<"\n\n""Want to see another topic in this chapter?(Y/N)";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 two();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH3_1()
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH3-1.txt",ios::in);
	while(!iff.eof())
	{
		iff>>ch;
		cout<<ch;
		cout<<" ";
		delay(500);
	}
	cout<<"\n""Want to see PART 2 of this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
		three();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH3_2()
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH3-2.txt",ios::in);
	while(!iff.eof())
	{
		iff.getline(ch,50,'\n');
		cout<<ch;
		cout<<" ";
		delay(500);
	}
	cout<<"\n""Want to see PART 1 of this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
		three();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}


void CH4_1()
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH4-1.txt",ios::in);
	while(!iff.eof())
	{
	    iff.getline(ch,50,'\n');
	    cout<<ch;
	    cout<<" ";
	    delay(500);
	}
	cout<<"\n""Want to see another topic in this chapter? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	     four();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH4_2()
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH4-2.txt",ios::in);
	while(!iff.eof())
	{
	    iff.getline(ch,50,'\n');
	    cout<<ch;
	    cout<<" ";
	    delay(500);
	}
	cout<<"\n""Want to see another topic in this chapter? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	     four();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH4_3()
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH4-3.txt",ios::in);
	while(!iff.eof())
	{
	    iff.getline(ch,50,'\n');
	    cout<<ch;
	    cout<<" ";
	    delay(500);
	}
	cout<<"\n""Want to see another topic in this chapter? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	     four();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH4_4()
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH4-4.txt",ios::in);
	while(!iff.eof())
	{
		iff.getline(ch,50,'\n');
		cout<<ch;
		cout<<" ";
		delay(500);
	}
	cout<<"\n""Want to see another topic in this chapter? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
		four();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}

void CH5_1()
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH5-1.txt",ios::in);
	while(!iff.eof())
	{
		iff.getline(ch,50,'\n');
		cout<<ch;
		cout<<" ";
		delay(500);
	}
	cout<<"\n""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
		five();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH5_2()
{

	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH5-2.txt",ios::in);
	while(!iff.eof())
	{
		iff.getline(ch,50,'\n');
		cout<<ch;
		cout<<" ";
		delay(500);
	}
	cout<<"\n""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
		five();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH5_3()
{
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH5-3.txt",ios::in);
	while(!iff.eof())
	{
		iff.getline(ch,50,'\n');
		cout<<ch;
		cout<<" ";
		delay(500);
	}
	cout<<"\n""Want to see another topic in this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
		five();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}

void CH6_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH6-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to continue?[y/n] : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 six();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH6_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH6-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to continue?[y/n] : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 six();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH6_3()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH6-3.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to continue?[y/n] : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 six();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH7_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH7-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to continue?[y/n] : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 seven();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH7_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH7-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to continue?[y/n] : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 seven();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH7_3()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH7-3.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to continue?[y/n] : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 seven();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH7_4()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH7-4.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to continue?[y/n] : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 seven();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH8_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH8-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 eight();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH8_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH8-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 eight();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH9_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH9-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 nine();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH9_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH9-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 nine();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH9_3()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH9-3.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 nine();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH10_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH10-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 ten();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH10_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH10-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 ten();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH10_3()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH10-3.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 ten();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}
void CH11_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH11-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 eleven();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH11_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH11-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 eleven();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH11_3()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH11-3.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 eleven();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH12_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH12-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 twelve();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH12_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH12-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 twelve();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH12_3()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH12-3.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 twelve();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH12_4()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH12-4.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 twelve();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH13_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH13-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 thirteen();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH13_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH13-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 thirteen();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
}void CH13_3()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH13-3.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 thirteen();
	}
	else if(z=='n'||z=='N')
	{
	  main();;
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH14_1()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH14-1.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 fourteen();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH14_2()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH14-2.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 fourteen();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}void CH14_3()
{
	clrscr();
	graphic1();
	textcolor(18);
	gotoxy(1,5);
	ifstream iff("CH14-3.txt",ios::in);
	while(!iff.eof())
	{
	 iff.getline(ch,50,'\n');
	 cout<<ch;
	 cout<<" ";
	 delay(500);
	}
	cout<<"\n""Want to see another topic i this chapter ? (Y/N) : ";
	cin>>z;
	if(z=='y'||z=='Y')
	{
	 fourteen();
	}
	else if(z=='n'||z=='N')
	{
	  main();
	}
	else
	{
	 cout<<"WRONG INPUT";
	}
}



void draw()
{
	int mm=3,r1=62,r2=7,yy=3,y1=69,y2=75,kk=20,cc=3,rr=61,a1=28;
	int p1=37,p2=46,ii=37,tt=52;
	clrscr();


	//for s
	textcolor(2);
	gotoxy(48,10);
	cprintf("º");
	gotoxy(47,10);
	cprintf("º");
	gotoxy(46,10);
	cprintf("º");
	gotoxy(49,10);
	cprintf("º");
	gotoxy(46,2);
	cprintf("º");
	gotoxy(47,2);
	cprintf("º");
	gotoxy(48,2);
	cprintf("º");
	gotoxy(49,2);
	cprintf("º");
	gotoxy(46,6);
	cprintf("º");
	gotoxy(47,6);
	cprintf("º");
	gotoxy(48,6);
	cprintf("º");
	gotoxy(49,6);
	cprintf("º");
	gotoxy(45,9);
	cprintf("º");
	gotoxy(50,3);
	cprintf("º");
	gotoxy(45,3);
	cprintf("º");
	gotoxy(45,4);
	cprintf("º");
	gotoxy(45,5);
	cprintf("º");
	gotoxy(50,7);
	cprintf("º");
	gotoxy(50,8);
	cprintf("º");
	gotoxy(50,9);
	cprintf("º");


	//FOR C
	textcolor(12);
	gotoxy(8,3);
	cprintf("º");
	gotoxy(8,9);
	cprintf("º");



	// for ||
	int aa=14;
	for(int i=2;i<11;i++)
	{

		//FOR C
		textcolor(12);
		gotoxy(2,i);
		cprintf("º");




		//for M
		textcolor(2);
		gotoxy(27,i);
		cprintf("º");
		gotoxy(35,i);
		cprintf("º");


		//for H
		textcolor(13);
		gotoxy(10,i);
		cprintf("º");
		gotoxy(17,i);
		cprintf("º");



		textcolor(9);
		//for t
		gotoxy(55,i);
		cprintf("º");

		//for E
		textcolor(9);
		gotoxy(19,i);
		cprintf("º");



		//for i
		textcolor(4);
		gotoxy(40,i);
		cprintf("º");

		//for a of next line
		textcolor(15);
		gotoxy(27,aa);
		cprintf("º");
		gotoxy(34,aa);
		cprintf("º");


		//for p1
		gotoxy(36,aa);
		cprintf("º");

		//for p2
		gotoxy(45,aa);
		cprintf("º");



		//FOR R

		textcolor(13);

		gotoxy(60,i);
		cprintf("º");
		if(i<7)
		{
			textcolor(13);
			gotoxy(66,i);
			cprintf("º");

			textcolor(15);
			//for p1
			gotoxy(43,aa);
			cprintf("º");

			//for p2
			gotoxy(52,aa);
			cprintf("º");
		}
		else
		{
			// FOR Y
			textcolor(12);
			gotoxy(72,i);
			cprintf("º");
			gotoxy(68,2);
			cprintf("º");
			gotoxy(76,2);
			cprintf("º");
		}
		aa++;
	}

	// for =


	for(i=11;i<17;i++)
	{
		//for C
		textcolor(12);
		gotoxy(cc,2);
		cprintf("º");
		gotoxy(cc,10);
		cprintf("º");

		//for h
		textcolor(13);

		gotoxy(i,6);
		cprintf("º");

		//FOR R
		gotoxy(rr,2);
		cprintf("º");
		gotoxy(rr,6);
		cprintf("º");

		textcolor(9);

		//for E
		gotoxy(kk,2);
		cprintf("º");
		gotoxy(kk,6);
		cprintf("º");
		gotoxy(kk,10);
		cprintf("º");
		kk++;

		textcolor(15);
		//for a of next line
		gotoxy(a1,14);
		cprintf("º");
		gotoxy(a1,18);
		cprintf("º");

		//for p1
		gotoxy(p1,14);
		cprintf("º");
		gotoxy(p1,18);
		cprintf("º");

		//for p2
		gotoxy(p2,14);
		cprintf("º");
		gotoxy(p2,18);
		cprintf("º");

		textcolor(4);
		//for i
		if(ii!=40)
		{
			gotoxy(ii,2);
			cprintf("º");
			gotoxy(ii,10);
			cprintf("º");
			if(tt!=55)
			{
				textcolor(9);
				gotoxy(tt,2);
				cprintf("º");
			}
			else
			{

				textcolor(9);
				tt++;
				gotoxy(tt,2);
				cprintf("º");

			}
		}
		else
		{
			ii++;
			gotoxy(ii,2);
			cprintf("º");
			gotoxy(ii,10);
			cprintf("º");
			if(tt!=55)
			{
				textcolor(9);
				gotoxy(tt,2);
				cprintf("º");
			}
			else
			{
				textcolor(9);
				tt++;
				gotoxy(tt,2);
				cprintf("º");

			}
		}
		ii++;
		tt++;
		cc++;
		rr++;
		a1++;
		p1++;
		p2++;
	}

	for(i=28,kk=34;i<31,kk>31;i++,kk--)
	{
		//for m
		textcolor(2);
		gotoxy(i,mm);
		cprintf("º");
		gotoxy(kk,mm);
		cprintf("º");

		//FOR Y
		textcolor(12);
		gotoxy(y1,yy);
		cprintf("º");
		gotoxy(y2,yy);
		cprintf("º");

		//FOR R
		textcolor(13);
		gotoxy(r1,r2);
		cprintf("º");

		r1++;
		r2++;
		mm++;
		yy++;
		y1++;
		y2--;
	}
	//FOR R
	gotoxy(r1,r2);
	cprintf("º");

	//FOR M
	textcolor(2);
	gotoxy(31,6);
	cprintf("é");

	//FOR Y
	textcolor(12);

	gotoxy(71,6);
	cprintf("Èº¼");

	for(i=2;i<77;i++)
	{
		textcolor(10);
		gotoxy(i,11);
		cprintf("Ü");
	}
	for(i=27;i<53;i++)
	{
		textcolor(10);
		gotoxy(i,23);
		cprintf("Ü");
	}


	delay(2000);
}



void main()
{
	int choice;
	draw();
	application:
	graphic();
	textcolor(18);  //green color
	gotoxy(1,5);
	cout<<"(1) SEARCH BY CHAPTER NAME";
	cout<<"\n""(2) CHAPTERWISE LEARNING";
	cout<<"\n""(3) DELETE CHAPTERS";
	cout<<"\n""(4) VIEW SEARCH HISTORY";
	cout<<"\n""(5) EXIT""\n\n\t";
	cout<<"Enter your choice :- ";
	cin>>choice;
	if(choice==1)
	{
		search();
	}
	else if(choice==2)
	{
		chapter();
	}
	else if(choice==3)
	{
		delet();
	}
	else if(choice==4)
	{
		display();
	}
	else if(choice==5)
	{
		exit();
	}
	else
	{
	 cout<<"\n\n\t""!! WRONG INPUT !!""\n""Would you like to enter again ? (Y/N):- ";
	 cin>>a;
	 if(a=='y'||a=='Y')
	 {
		goto application;
	 }
	 else
	 {
		exit();
	 }
	}
	getch();

}




