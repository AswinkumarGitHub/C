#include<conio.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

struct tele
{
char name [50];
long int no;
char add[50];
char city[30];
long cust_id;
}T;

class telephone
{
public:
void input();
void display();
void insert();
void search();
void delete1();
void sort_num();
void modify();
void graphics();
}t;

int n;
int r=0;
void telephone::input()
{
fstream f;
f.open("Telephone.dat",ios::out|ios::binary);
gotoxy(4,5);
cout<<"Enter the size:-";
cin>>n;
cout<<"---------------------\n"<<endl;
	for(int i=0;i<n;i++)
	{
	cout<<"Enter the customer id:"<<endl;
	cin>>T.cust_id;
	cout<<"Enter the name:"<<endl;
	gets(T.name);
	cout<<"Enter the no:"<<endl;
	cin>>T.no;
	cout<<"Enter the address:"<<endl;
	gets(T.add);
	cout<<"Enter the city:"<<endl;
	gets(T.city);
	cout<<"---------------------\n";
	f.write((char*)&T,sizeof(T));
	}
f.close();
cleardevice();
}

void telephone::display()
{
int n=4,m=20;
cleardevice();
telephone t1;
int x=90,y=100;
t1.graphics();
fstream f1;
tele T1;
f1.open("Telephone.dat",ios::in|ios::binary);
while(!f1.eof())
{
char ch[25],ch1[25];
f1.read((char*)&T1,sizeof(T1));
gotoxy(n,m);
ultoa(T1.cust_id,ch,10);
ultoa(T1.no,ch1,10);
outtextxy(x-40,y,ch);
outtextxy(x+20,y,T1.name);
outtextxy(x+100,y,ch1);
outtextxy(x+245,y,T1.add);
outtextxy(x+430,y,T1.city);
m=m+6;
y=y+20;
}
f1.close();
getch();
}

void telephone::sort_num()
{
telephone t2;
gotoxy(4,5);
int x=90,y=100,n=4,m=5;
char ch[25],ch1[25];
fstream f7;
f7.open("Telephone.dat",ios::in|ios::binary);
tele T[50];
int i=0;
while(!f7.eof())
{
f7.read((char*)&T[i],sizeof(T[i]));
i++;
}
f7.close();
for(int j=0;j<i;j++)
{
	for(int k=0;k<i-j-1;k++)
	{
		if(T[k].cust_id>T[k+1].cust_id)
		{
		tele temp;
		temp=T[k];
		T[k]=T[k+1];
		T[k+1]=temp;
		}
	}
}
for(int h=0;h<i;h++)
{
gotoxy(n,m);
t2.graphics();
ultoa(T[h].cust_id,ch,10);
ultoa(T[h].no,ch1,10);
outtextxy(x-40,y,ch);
outtextxy(x+20,y,T[h].name);
outtextxy(x+100,y,ch1);
outtextxy(x+245,y,T[h].add);
outtextxy(x+430,y,T[h].city);
m=m+6;
y=y+20;
}
getch();
}

void telephone::insert()
{
 tele c5,T3;
 long int a;
gotoxy(4,5);
cout<<"Enter the new student info:"<<endl;
cout<<"Enter the New customer_id:";
cin>>c5.cust_id;
cout<<"New Name:";
 gets(c5.name);
cout<<"Enter the new Number:";
cin>>c5.no;
cout<<"Enter the new address:";
 gets(c5.add);
cout<<"Enter the new city:";
 gets(c5.city);
cout<<"Enter the Customer_id before which the new info must to inserted:";
cin>>a;
fstream f7("Telephone.dat",ios::binary|ios::in);
fstream f8("temp.dat",ios::binary|ios::app);

for(int i=0;i<n;i++)
{
 f7.read((char*)&T3,sizeof(T3));
 if((T3.cust_id!=a))
 {
 f8.write((char*)&T3,sizeof(T3));
 }
 else
 {
 f8.write((char*)&c5,sizeof(c5));
 f8.write((char*)&T3,sizeof(T3));
 }
}
f7.close();
f8.close();
n++;
remove("Telephone.dat");
rename("temp.dat","Telephone.dat");
}

void telephone::search()
{
telephone t2;
int a;
gotoxy(4,5);
cout<<"Enter the Customer id to be searched:";
cin>>a;
fstream fs;
tele T1;
int x=90,y=100,n=2,m=20;
int flag=0;
char ch[25];
char ch1[30];
fs.open("Telephone.dat",ios::in|ios::binary);
while(!fs.eof())
{
	fs.read((char*)&T1,sizeof(T1));
	if(T1.cust_id==a)
	{
	cleardevice();
	t2.graphics();
	gotoxy(n,m);
	ultoa(T1.cust_id,ch,10);
	ultoa(T1.no,ch1,10);
	outtextxy(x-40,y,ch);
	outtextxy(x+20,y,T1.name);
	outtextxy(x+100,y,ch1);
	outtextxy(x+245,y,T1.add);
	outtextxy(x+430,y,T1.city);
	flag=1;
	}
}
if(flag==0)
{
cout<<"Not found"<<endl;
}
fs.close();
getch();
}

void telephone::delete1()
{
tele T1;
int b;
gotoxy(4,5);
cout<<"Enter the Customer_id to be deleted:-";
cin>>b;
fstream f4,f5;
   f4.open("Telephone.dat",ios::in|ios::binary);
   f5.open("Telephone2.dat",ios::out|ios::binary);
int flag1=0;
while(!f4.eof())
{
	f4.read((char*)&T1,sizeof(T1));
	if(T1.cust_id!=b)
	{
	f5.write((char*)&T1,sizeof(T1));
	flag1=1;
	}
}
if(flag1==0)
{
cout<<"Not found"<<endl;
}
f4.close();
f5.close();
remove("Telephone.dat");
rename("Telephone2.dat","Telephone.dat");
}


void telephone::modify()
{
fstream f6;
int y;
gotoxy(4,5);
cout<<"Enter the position to be modified:-";
cin>>y;
char a[50];
char b[50];
char c[40];
int h;
int d;
cout<<"Enter the Customer id"<<endl;
cin>>d;
cout<<"Enter the name:"<<endl;
gets(a);
cout<<"Enter the number:"<<endl;
cin>>h;
cout<<"Enter the address:"<<endl;
gets(b);
cout<<"Enter the city:"<<endl;
gets(c);
cout<<"---------------------\n";
f6.open("Telephone.dat",ios::in|ios::out|ios::binary);
	while(!f6.eof())
	{
	int pos=f6.tellg();
	f6.read((char*)&T,sizeof(T));
		if(y==T.cust_id)
		{
		T.cust_id=d;
		strcpy(T.add,b);
		strcpy(T.name,a);
		 T.no=h;
		strcpy(T.city,c);
		 f6.seekg(pos);
		 f6.write((char*)&T,sizeof(T));
		 }
	}
f6.close();
}

void telephone::graphics()
{
   int a;
   int xmax, ymax;
setcolor(getmaxcolor());
xmax = getmaxx();
ymax = getmaxy();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
   line(0,0,getmaxx(),0);
outtextxy(100,10,"TELEPHONE DIRECTORY");
   line(0,60,getmaxx(), 60);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   outtextxy(0,70,"\tCUS_ID\t\tNAME\t\t\tNUMBER\t\t\t\tADDRESS\t\t\t\tCITY");
line(0,0,0,370);
line(100,60,100,370);
line(180,60,180,370);
line(310,60,310,370);
line(500,60,500,370);
line(0,100,xmax,100);
   line(xmax,0,xmax,370);
getch();

}

void main()
{
clrscr();
   int gdriver=DETECT,gmode;
initgraph(&gdriver, &gmode,"c://turboc3//bgi");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
outtextxy(80,10,"TELEPHONE DIRECTORY");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
outtextxy(380,300,"DONE BY:-");
outtextxy(440,330,"V.ASWIN KUMAR");
outtextxy(440,357,"M.HEMACHANDRIAN");
getch();
cleardevice();

int ch;
char ch1;
	do
	{
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	gotoxy(4,5);
	outtextxy(10,10,"MENU");
	outtextxy(10,33,"----");
	outtextxy(20,50,"1.To get data");
	outtextxy(20,80,"2.To display");
	outtextxy(20,110,"3.To insert ");
	outtextxy(20,140,"4.To search ");
	outtextxy(20,170,"5.To delete ");
	outtextxy(20,200,"6.To sort ");
	outtextxy(20,230,"7.To modify the data");
	outtextxy(20,260,"8.Exit");
	outtextxy(20,300,"Enter the choice(1-10)");
	gotoxy(4,23);
	cin>>ch;
		switch(ch)
		{
		case 1:
		cleardevice();
		t.input();
		break;

		case 2:
		cleardevice();
		t.display();
		break;

		case 3:
		cleardevice();
		t.insert();
		break;

		case 4:
		cleardevice();
		t.search();
		break;

		case 5:
		cleardevice();
		t.delete1();
		break;

		case 6:
		cleardevice();
		t.sort_num();
		break;

		case 7:
		cleardevice();
		t.modify();
		break;

		case 8:
		cleardevice();
		exit(0);
		break;

		default:
		cleardevice();
		cout<<"Invalid";
		break;
		}
	gotoxy(24,25);
	cleardevice();
	outtextxy(40,370,"press Y / y:-");
	cin>>ch1;
	cleardevice();
	}while (ch1=='Y'||ch1=='y');
	closegraph();
getch();
}
