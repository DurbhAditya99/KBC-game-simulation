/*Corrections to be done:
  LINE 78-NEEDS TO GO BACK TO THE MENU INSTEAD OF QUITTING
  LINE 288-LOGIC MIGHT OR MIGHT NOT BE CORRECT. NOT SURE
  LINE 538-THE LAST 'KBC' IN THE RED CIRCLE DOES NOT GET PRINTED
*/


#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
#include<fstream.h>
#include<ctype.h>


typedef char str[35];

int acc=0,age,ea=0,pf=0,j=0;;

float cash[]={0,1000,2000,5000,10000,20000,50000,160000,320000,640000,1000000,7000000};

char passwrd[10],yn;

char fname[10],lname[10],place[20],hobbies[20],r,name[3][10],phno[3][10],answer;

void graphics(str);

void intromusic();

class contestants
{
 public:

 char name[50];
 double cash;


 void read();
 void write(double);
 void clrscore();

}plyrs,t;

 void contestants::write(double x)
 {
  fstream win;
  win.open("score.dat",ios::binary|ios::app);
  strcpy(name,fname);
  cash=x;
  win.write((char*)&plyrs,sizeof(plyrs));
  win.close();
 }

 void contestants::read()
 {
   clrscr();
   fstream win;
   int i=0;
   win.open("score.dat",ios::binary|ios::in);

   if(!win)
   { cout<<"Nothing to see here!";
     getch();  }

   else
   {
   while(win.read((char*)&t,sizeof(t)))
  {  cout<<i+1<<">";
      cout<<"Player Name: ";
      puts(t.name);
      cout<<"Cash Won: "<<t.cash<<endl;
  }
  getch();
   }
  win.close();
  }

 void contestants::clrscore()
 {
  clrscr();
  remove("score.dat");
  cout<<"SCORES CLEARED!!\n";   //<-AFTER SCORES ARE CLEARED,
  cout<<"QUITTING......";       //  NEEDS TO GO BACK TO THE MENU
  getch();
 }

class GAME
{
  char ques[80],op1[30],op2[30],op3[30],op4[30],ans;
  public:
  void admin();
  void play();
  void menu();
  void viewques();
  void addques();
  void rules();
  void info();
  void paf();
}obj;

void GAME::addques()
{ clrscr();
  int i=0;
  fstream file;
  file.open("KBCQ.dat",ios::app|ios::binary);
  do
  {  clrscr();
     cout<<"Enter question: ";
     gets(obj.ques);
     cout<<"Option A: ";
     gets(obj.op1);
     cout<<"Option B: ";
     gets(obj.op2);
     cout<<"Option C: ";
     gets(obj.op3);
     cout<<"Option D: ";
     gets(obj.op4);
     cout<<"Answer: ";
     cin>>obj.ans;
     file.write((char*)&obj,sizeof(obj));
     i++;
     cout<<"Enter another question?"<<endl;
     cin>>r;
  }while(r=='Y' || r=='y');
  file.close();
}

void GAME::viewques()
{ int i=0;
  fstream file;
  file.open("KBCQ.dat",ios::in|ios::binary);
  while(file.read((char*)&obj,sizeof(obj)))
  {   clrscr();

      cout<<"Question "<<i+1<<": ";
      puts(obj.ques);
      cout<<"\n ";
      puts(obj.op1);
      cout<<"\n ";
      puts(obj.op2);
      cout<<"\n ";
      puts(obj.op3);
      cout<<"\n ";
      puts(obj.op4);
      cout<<"\nAnswer: "<<obj.ans<<endl;
      cout<<"(Press any key to continue)";
      i++;
      getch();
  }
  file.close();



}
// ADMIN
void GAME::admin()
{ clrscr();
  char a;
  int ch;
  P:
  cout<<"Enter Admin Password: ";
  gets(passwrd);
  if(strcmp("pwrd123",passwrd)!=0)
  {    cout<<"Incorrect password!"<<endl;
       cout<<"Try again?(y/n)\n";
       cin>>a;
       if(a=='y' || a=='Y')
       { goto P; }
			}
  else
 {  do
  {
    cout<<"\n\n\n********** Kbc Admin Menu ************"<<endl;
    cout<<"\n1> View questions\n2>Add new questions\n3>Go back to Main Menu\nEnter choice: ";
    cin>>ch;
    switch(ch)
   {   case 1: clrscr();
	       viewques();
	       break;
       case 2: clrscr();
	       addques();
	       break;
   }
   }while(ch!=3);
 }
}

// PHONE A FRIEND
void GAME::paf()
{
  cout<<"1. Name: ";
  gets(name[0]);
  cout<<" Phone Number: ";
  gets(phno[0]);
  cout<<"\n2. Name: ";
  gets(name[1]);
  cout<<" Phone Number: ";
  gets(phno[1]);
  cout<<"\n3. Name: ";
  gets(name[2]);
  cout<<" Phone Number: ";
  gets(phno[2]);
}

// RULES
void GAME::rules()
{  clrscr();
   cout<<"Rules of the game are as follows: \n";
   delay(1000);
   cout<<"1. There are a total of 15 multiple choice questions\n";
   delay(1000);
   cout<<"2. Answering the first question correct earns you a sum of Rs.1000\n";
   delay(1000);
   cout<<"3. The next question is worth twice the amount of the previous question\n";
   delay(1000);
   cout<<"4. Answering a question wrong will lead to elimination\n";
   delay(1000);
   cout<<"5. You will have 3 lifelines: \n* Phone a friend\n*50-50\n*Expert advice\n";
   cout<<"(Press D for details regarding lifelines or press C to continue)"<<endl;
   cin>>r;
   if(r=='D'|| r=='d')
   { clrscr();
     cout<<"************  PHONE A FRIEND ***********"<<endl;
     cout<<"The 'PHONE A FRIEND' lifeline enables you to contact your friends,relatives etc, seeking their help to answer the current question right\n"<<"(Press any key to continue)\n";
     getch();
     cout<<"************ 50-50 *************"<<endl;
     cout<<"The '50-50' lifeline removes 2 incorrect out of 4 options given,thereby leaving you with two options(one correct,one incorrect)\n"<<"(Press any key to continue)\n";
     getch();
     cout<<"************ Expert Advice ***********"<<endl;
     cout<<"The 'Expert Advice' lifeline allows you to use the intellectual advice given by experts present in the game\n"<<"(Press any key to continue)\n";
     getch();
    }
   else if(toupper(r)=='C')
   {     }
}

//PERSONAL INFO
void GAME::info()
{   clrscr();

    cout<<"                        Welcome to KBC!\n\n";

    cout<<"                        TELL US ABOUT YOURSELF!                      " <<endl;
    delay(500);
    cout<<"Your good name: ";
    gets(fname);
    cout<<endl;
    cout<<"Your Family name: ";
    gets(lname);
    cout<<endl;
    cout<<"You are from(city): ";
    gets(place);
    cout<<endl;
    cout<<"Your age: ";
    cin>>age;
    cout<<endl;
    cout<<endl;

    cout<<"WOW, YOU SOUND LIKE AN INTERESTING PERSON!"<<endl;
    getch();

    cout<<"Let me run you through the rules of the game!"<<endl;
    rules();
    clrscr();
    cout<<"I would now like you to enter the names and corresponding phone numbers to       activate the phone a friend lifeline\n";
    paf();
    clrscr();
    intromusic();
    graphics("Lets Play");
}
void quit()
{  closegraph();
   clrscr();
   cout<<"Are you sure you want to quit(YES-Y/NO-N)?";
   cin>>yn;
   if(toupper(yn)=='Y')
   { exit(0);  }
 }

int rv=0;

void right()
{

   closegraph();
   clrscr();
   cout<<"WOW! THAT'S THE RIGHT ANSWER!\n ";
   cout<<"YOU WIN Rs. "<<cash[++rv];
   j++;
   if(j==10)
   {
    intromusic();  //MIGHT OR MIGHT NOT BE CORRECT. NEEDS TO BE CHECKED
    cout<<"YOU ARE A WINNER OF KBC!!!\nYOU GET TO TAKE HOME Rs."<<cash[++rv]<<"\nCONGRATULATIONS!!!!\n";
   }
   getch();
}

void wrong(char x,int num)
{
  clrscr();
  plyrs.write(num);
  cout<<"Sorry ";
  puts(fname);
  cout<<"That is the wrong answer!\n ";
  cout<<"The correct answer is option "<<x<<endl;
  getch();
  cout<<"Amitabh: Thank You for playing KBC!!!! I had a wonderful time and I hope you did too!!! GOODBYE.....";
  delay(2000);
  exit(0);
}

void phoneafriend(char);
void eadvice(char);
int fif=0;

void lifelines(char x,char *o,char *t,char *th,char *f)
{  closegraph();
   clrscr();
   cout<<"Lifelines:\n";
   cout<<"1.Phone a friend\n2.50-50\n3.Expert Advice\n";
   cout<<"Which lifeline would you like to activate?";
   int ch;
   cin>>ch;
   switch(ch)
   {
      case 1: clrscr();
	      if(pf==0)
	      {   phoneafriend(x);  }
	      else
	      {  cout<<"Lifeline unavailable!\n(Press any key to continue)";
		 getch();   }
	      break;
      case 2: if(fif==0)
	     {  clrscr();
		cout<<"We will now remove two incorrect options\n(Press any key to continue)";
		getch();
	      if(x=='A')
     {    strcpy(t,NULL);
	  strcpy(f,NULL);
     }
     else if(x=='B')
     {    strcpy(th,NULL);
	  strcpy(o,NULL);
     }
     else if(x=='C')
     {    strcpy(o,NULL);
	  strcpy(f,NULL);
     }
     else if(x=='D')
     {    strcpy(t,NULL);
	  strcpy(th,NULL);
     }
	 fif++;		}
     else
     {  cout<<"Lifeline unavailable!\n(Press any key to continue)";
	getch();       }
	      break;
     case 3:  clrscr();
	      if(ea==0)
	      {   cout<<"Contacting expert.........\n";
	      eadvice(x); }
	      else
	      {  cout<<"Lifeline unavailable!";
		 getch();		   }
	      break;
   }
 }

int v1=0,v2=0;

// GAME
void GAME::play()
{
    info();
    clrscr();
    fstream file;
    file.open("KBCQ.dat",ios::in|ios::binary);
    closegraph();
    char answer;
    int i=0;
    while(file.read((char*)&obj,sizeof(obj)))
  { clrscr();
    A:

    int gd=DETECT,gm,midx,midy;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    midx=getmaxx()/2;
    midy=getmaxy()/2;

    if(i==0)
    { gotoxy(45,5);
    cout<<"Amount won: Rs."<<cash[v1++];
    gotoxy(45,6);
    cout<<"Playing for Rs."<<cash[++v2];
    }
    gotoxy(45,3);
    cout<<"(Press 'L' to access lifelines)";
    gotoxy(45,4);
    cout<<"(Press 'Q' to quit the game)";

    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    setcolor(3);
    outtextxy(midx-300,midy-100,obj.ques);
    delay(600);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    setcolor(RED);
    outtextxy(midx-300,midy,obj.op1);
    delay(600);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    setcolor(RED);
    outtextxy(midx+100,midy,obj.op2);
    delay(600);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    setcolor(RED);
    outtextxy(midx-300,midy+100,obj.op3);
    delay(600);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    setcolor(RED);
    outtextxy(midx+100,midy+100,obj.op4);
    outtextxy(midx-300,midy+150,"ANSWER(A/B/C/D/Q/L): ");
    gotoxy(25,25);

    cin>>answer;
    answer=toupper(answer);
    if(answer=='Q')
    {  quit();
    goto A;   }
    if(answer=='L')
    {  lifelines(obj.ans,obj.op1,obj.op2,obj.op3,obj.op4);
       i++;
       goto A;
		      }

    cout<<endl<<"Lock option"<<answer<<" ?(Y/N) ";
    cin>>yn;
    if(toupper(yn)=='Y')
    {

    if(answer==obj.ans)
    {   right();   }

    else
    {  wrong(obj.ans,cash[v1]);  }


    }

    else
    {
      goto A;   }

    if(i!=0)
    { i=0;   }

    }
   plyrs.write(cash[v1]);
}


// MAIN MENU
void GAME::menu()
{  int choice=0;
 do
  {
    cout<<"\n******* Welcome to the KBC menu ******** "<<endl;
    cout<<"1.ADMIN\n2.PLAY\n3.VIEW HIGHSCORES\n4.CLEAR HIGHSCORES\n5.QUIT\n";
    cout<<"What would you like to do?\nChoice:";
    cin>>choice;
    switch(choice)
    { case 1:  clrscr();
	       admin();
	       break;
      case 2:  clrscr();
	       play();
	       break;
      case 3:  plyrs.read();
	       break;
      case 4:  plyrs.clrscore();
	       break;
      case 5:  exit(0);

    }
   }while(choice!=4);
 }

// MUSIC
void intromusic()
{
  sound(300);
  delay(600);
  sound(335);
  delay(600);
  sound(355);
  delay(400);
  sound(300);
  delay(450);
  sound(335);
  delay(400);
  sound(355);
  delay(400);
  sound(400);
  delay(410);
  sound(445);
  delay(900);
  nosound();
}


void graphics(str text)
{
    int gd=DETECT,gm,midx,midy;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    midx=getmaxx()/2;
    midy=getmaxy()/2;
    if(acc==0)
    {
    setcolor(RED);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(midx,midy-80,"JIO PRESENTS...");
    delay(600);
    acc++;
    }
    for(int i=0;i<5;i++)
    {
    cleardevice();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,i);
    setcolor(i);
    if(i<2)
    ellipse(getmaxx()/2, getmaxy()/2, 0, 360, 100, 100);
    else if(i<3)
    ellipse(getmaxx()/2, getmaxy()/2, 0, 360, 200, 200);
    else if(i<5)
    ellipse(getmaxx()/2, getmaxy()/2, 0, 360, 300, 300);

    outtextxy(midx,midy+10,text);
    delay(800);
    cleardevice();
    }
    delay(1000);
    closegraph();
 }

void main()
{
  clrscr();
  intromusic();
  str txt;
  strcpy(txt,"KAUN BANEGA CROREPATI");
  graphics(txt);
  obj.menu();
  getch();
}

// LIFELINES



void eadvice(char x)
{
   cout<<"******************* Xpert Advice *****************\n";
   cout<<"Amitabh: Our expert today is Durbha Aditya\n Welcome Mr.Durbha to KBC\n";
   delay(1500);
   cout<<"Durbha : Thank you for having me on the show";
   delay(2500);
   cout<<"Hmm";
   for(int i=0;i<10;i++)
  { cout<<".";
    delay(100);   }
   cout<<"\nDurbha : My expertise tells me that the answer is option "<<x<<endl;
   delay(4000);
   ea++;

}

void phoneafriend(char x)
{
  clrscr();
  cout<<"********************* Phone a friend ***********************\n";
  cout<<"Who would you like to call?(1/2/3)\n";
  cout<<"1.";
  puts(name[0]);
  cout<<"2.";
  puts(name[1]);
  cout<<"3.";
  puts(name[2]);
  int v3;
  cin>>v3;
  cout<<"Calling..... ";
  puts(name[v3-1]);
  for(int i=0;i<10;i++)
  { cout<<".";
    delay(100);   }
  cout<<"\nAmitabh: Hello ";
  puts(name[v3-1]);
  cout<<" This is Amitabh Bachchan speaking from KBC\n\n";
  delay(2000);
  cout<<"Amitabh: We have ";
  puts(fname);
  cout<<"with us on the hot seat today!\n\n";
  delay(2000);
  cout<<"And we need your help to answer the question: .......\n";
  cout<<"...................................?\n\n";
  delay(2000);
  for(i=0;name[v3-1][i]!='\0';i++)
  { cout<<name[v3-1][i];   }
  cout<<" : I think the answer is option "<<x;
  delay(5000);
  pf++;
}

