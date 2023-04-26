#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>

void admin()
{
int opt;
for(;;)
{
cleardevice();
settextstyle(4,0,5);

outtextxy(40,20," Admin");
settextstyle(7,0,2);
outtextxy(60,120," 1. Contracts");
outtextxy(60,150," 2. Workers");
outtextxy(60,180," 3. Product");
outtextxy(60,210," 4. Back to main menu");
outtextxy(60,240," Enter your option");
cin>>opt;
switch(opt)
{
 case 1:
   contract();
   break;
 case 2:
   doctor();
   break;
 case 3:
   product();
   break;
 case 4:
   first();
   break;
 }
 getch();

 }
}
void contract()
{
	cleardevice();
	int opt;
	settextstyle(4,0,7);
	outtextxy(130,10,"C O N T R A C T");
	settextstyle(7,0,2);
	outtextxy(30,90," 1. New entry ");
	outtextxy(30,120," 2. Modify ");
	outtextxy(30,150," 3. Delete");
	outtextxy(30,180," 4. Display");
	outtextxy(30,210," 5. Back to Main menu ");
	outtextxy(30,230," Enter Your option");
	gotoxy(45,10);
	cin>>opt;
	cleardevice();
	switch(opt)
	{
		case 1:
			concreate();
			break;
		case 2:
			conmodify();
			break;
		case 3:
			condelete();
			break;
		case 4:
			condisplay();
			break;
		case 5:
			admin();
			break;
	}
  getch();
}

void concreate()
{
	ofstream out;
	out.open("contract.dat",ios::binary|ios::app);
	contract n;
	n.ninput();
	out.write((char*)&n, sizeof(n));
	out.close();
}
void condisplay()
{
	ifstream in;
	in.open("contract.dat",ios::binary);
	contract n;
	while(in.read((char *)&n, sizeof(n)))
	{
		n.ndisplay();
		sal+=n.nsal;
		getch();
	}
	in.close();
}

void conmodify()
{
	ifstream in;
	ofstream out;
	char ch;
	out.open("temp.dat",ios::binary);
	contarct n;
	in.open("contract.dat",ios::binary);
	int id;
	outtextxy(30,90," Enter id ");
	gotoxy(45,7);
	cin>>id;
	while(in.read((char *)&n,sizeof(n)))
	{
		if(id==n.nid)
		{
			n.ndisplay();
			cout<<"Confirm to change";
			cin>>ch;
			if(ch=='y')
				n.ninput();
		}
   out.write((char *)&n, sizeof(n));
}
in.close();
out.close();
remove("contract.dat");
rename("temp.dat","contract.dat");
}

void nursedelete()
{
	ifstream in;
	ofstream out;
	char ch;
	out.open("temp.dat",ios::binary);
	contract n;
	in.open("contract.dat",ios::binary);
	int id;
	outtextxy(30,90," Enter id ");
	gotoxy(45,7);
	cin>>id;
	while(in.read((char *)&n,sizeof(n)))
	{
		if(id==n.nid)
		{
			n.ndisplay();
			cout<<"Confirm to Delete";
			cin>>ch;
			if(ch=='y')
				continue;
		}
   out.write((char *)&n, sizeof(n));
}
in.close();
out.close();
remove("contract.dat");
rename("temp.dat","contract.dat");
}
void worker()
{
cleardevice();
int opt;

settextstyle(4,0,7);
outtextxy(130,10,"W O R K E R S");
settextstyle(7,0,2);
outtextxy(30,90," 1. New Entry ");
outtextxy(30,120," 2. Modify ");
outtextxy(30,150," 3. Delete");
outtextxy(30,180," 4. Display");
outtextxy(30,210," 5. Back to Main menu ");
outtextxy(30,230," Enter Your option");
gotoxy(45,10);
cin>>opt;
switch(opt)
{
case 1:
   wocreate();
   break;
case 2:
	womodify();
	break;
case 3:
   wodelete();
   break;
case 4:
   wodisplay();
   break;
case 5:
  admin();
  break;
  }
  getch();
}
void wocreate()
{
ofstream out;
out.open("worker.dat",ios::binary|ios::app);
worker d;
d.dinput();
out.write((char*)&d, sizeof(d));
out.close();
}
void wodisplay()
{
ifstream in;
in.open("worker.dat",ios::binary);
worker d;
sal=0;
while(in.read((char *)&d, sizeof(d)))
{
  d.ddisplay();
  sal=sal+d.dsal;
  getch();
}
in.close();
}

void womodify()
{
ifstream in;
ofstream out;
char ch;
out.open("temp.dat",ios::binary);
worker d;
in.open("worker.dat",ios::binary);
int id;
outtextxy(30,90," Enter id ");
gotoxy(45,7);
cin>>id;
while(in.read((char *)&d,sizeof(d)))
{
if(id==d.did)
  {
   d.ddisplay();
   cout<<"Confirm to change";
   cin>>ch;
   if(ch=='y')
	d.dinput();
   }
   out.write((char *)&d, sizeof(d));
}
in.close();
out.close();
remove("worker.dat");
rename("temp.dat","worker.dat");
}
void wodelete()
{
ifstream in;
ofstream out;
char ch;
out.open("temp.dat",ios::binary);
worker d;
in.open("worker.dat",ios::binary);
int id;
outtextxy(30,90," Enter id ");
gotoxy(45,7);
cin>>id;
while(in.read((char *)&d,sizeof(d)))
{
if(id==d.did)
  {
   d.ddisplay();
   cout<<"Confirm to Delete";
   cin>>ch;
   if(ch=='y')
	continue;
   }
   out.write((char *)&d, sizeof(d));
}
in.close();
out.close();
remove("worker.dat");
rename("temp.dat","worker.dat");

}
class Product
{
public:
int pid;
char pname[30];
int qty;
float amt;
void pinsert();
void pdisplay();
};

void Product::pinsert()
{
int x=40, y=6;
y=y+2;
gotoxy(x,y);
cleardevice();
settextstyle(7,0,3);
outtextxy(40,100,"Enter product id");
cin>>pid;
y=y+2;
gotoxy(x,y);

outtextxy(40,130,"Enter product name");
gets(pname);

outtextxy(40,160,"Enter quantity");
y=y+2;
gotoxy(x,y);
cin>>qty;
outtextxy(40,190,"Enter amount");
y=y+2;
gotoxy(x,y);
cin>>amt;

}

void Product :: pdisplay()
{
cout<<pid <<"           " <<pname<<"             "<<qty<<"            "<<amt<<endl;
}


void productcreate()
{
ofstream out;
out.open("product.dat",ios::binary|ios::app);
Product p;
p.pinsert();
out.write((char*)&p, sizeof(p));
out.close();
}

void productmodify()
{
ifstream in;
ofstream out;
in.open("product.dat", ios::binary);
out.open("temp.dat",ios::binary);
cout<<"\\n Enter id ";
int id;
Product p;
cin>>id;
while(in.read((char*)&p, sizeof(p)))
{
if(id==p.pid)
	  {
	  p.pdisplay();
	  getch();
	  p.pinsert();
	  out.write((char*)&p, sizeof(p));
	  }
	  else
	  out.write((char *)&p, sizeof(p));
}
out.close();
in.close();
remove("product.dat");
rename("temp.dat", "product.dat");

}
void productdelete()
{
ifstream in;
ofstream out;
in.open("product.dat", ios::binary);
out.open("temp.dat",ios::binary);
cout<<"\\n Enter id ";
int id;
Product p;
cin>>id;
cleardevice();
while(in.read((char*)&p, sizeof(p)))
{
if(id!=p.pid)
   out.write((char *)&p, sizeof(p));
else
 cout<<"Deletion success";

}

out.close();
in.close();
remove("product.dat");
rename("temp.dat", "product.dat");
}

void productdisplay()
{
ifstream in;
in.open("product.dat", ios::binary);
Product p;
cleardevice();
cout<<"pid           Product name            Quantity	Amount\n";
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`\n\n";
float total=0;
while(in.read((char *)&p, sizeof(p)))
{
p.pdisplay();
total=total+p.amt;
}
in.close();
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"   Total= "<<total;
}
void product()
{
ifstream in;
int op;
Product p;
settextstyle(5,0,4);
in.open("product.dat",ios::binary);
outtextxy(40,40,"PRODUCT");
settextstyle(7,0,3);
cleardevice();
outtextxy(30,60,"1.New Product");
outtextxy(30,90,"2.Modify");
outtextxy(30,120,"3.Delete");
outtextxy(30,150,"4.Display");
outtextxy(30,180,"5. Back to menu");
outtextxy(30,210,"Enter Your choice");
cin>>op;
switch(op)
{
 case 1:
  productcreate();
  break;
 case 2:
  productmodify();
  break;
 case 3:
  productdelete();
  break;
 case 4:
  productdisplay();
  break;
 case 5:
  admin();
 }
}
class productbill
{
public:
  int billid;
  int rid;
  char fname[30],cname[30];
  int dd,mm,yy;
  char add[40];
  long int ph;
  int pid;
  char pname[30];
  int qty;
  float amt;
};

void productpurchase()
{
  ifstream in1,in2;
  ofstream out,out1;
  int tempr;
  int tdd,tmm,tyy,trid;
  char tfname[30], tadd[30];
  long int tph;
  float total=0;
  cleardevice();
  gotoxy(10,3);
  in2.open("baby.dat",ios::binary);
  out1.open("bill.dat", ios::binary|ios::app);
  productbill pb;
  char chh;
  baby b;
  int r;
  cout<<"Enter Bill id";
  cin>>pb.billid;
  int tempbillid=pb.billid;
  cout<<"Enter Record id";
  cin>>r;
  tempr=r;
  int flag=-1;
   struct date d;
   getdate(&d);
   pb.dd=d.da_day;
   pb.mm=d.da_mon;
   pb.yy=d.da_year;
   tdd=pb.dd;
   tmm=pb.mm;
   tyy=pb.yy;

 while(in2.read((char *)&b, sizeof(b)))
 {
  if(b.rid==r)
   {
	pb.rid=b.rid;
	strcpy(pb.fname, b.fname);
	strcpy(pb.cname,b.cname);
	strcpy(pb.add,b.add);
	pb.ph=b.ph;
	flag=1;
   }
  }
  if(flag==-1)
	{
	 cout<<"Enter New recordid";
	 cin>>pb.rid;
	 cout<<"Enter Fathers name";
	 gets(pb.fname);
	 cout<<"Enter Address";
	 gets(pb.add);
	 cout<<"Enter Phone number";
	 cin>>pb.ph;
	}
	 tdd=pb.dd;
	 tmm=pb.mm;
	 tyy=pb.yy;
	 trid=pb.rid;

	strcpy(tfname,pb.fname);
	strcpy(tadd, pb.add);
	tph=pb.ph;
	productdisplay();
 do
 {
	in1.open("product.dat",ios::binary);
	out.open("temp.dat",ios::binary|ios::app);

	cout<<"Enter Pid";
	int pp,q;
	Product p;
	cin>>pp;
	cout<<"Enter Qty";
	cin>>q;
	while(in1.read((char*)&p, sizeof(p)))
	{
	 if(pp==p.pid)
	 {
	p.pdisplay();
	pb.billid=tempbillid;
	pb.rid=trid;
	pb.dd=tdd;
	pb.mm=tmm;
	pb.yy=tyy;
	strcpy(pb.fname, tfname);
	strcpy(pb.add, tadd);
	pb.ph=tph;
	p.qty=p.qty-q;
	pb.pid=p.pid;
	strcpy(pb.pname,p.pname);
	pb.qty=q;
	pb.amt=q*p.amt;

	out1.write((char*)&pb,sizeof(pb));
	out.write((char *)&p, sizeof(p));

	 }
   else
	  out.write((char *)&p, sizeof(p));
  }
  in1.close();
  out.close();
  out1.close();
  remove("product.dat");
  rename("temp.dat","product.dat");
  remove("temp.dat");
  cout<<"Do you wish to continue ";
  cin>>chh;
  if(chh=='y')
  out1.open("bill.dat",ios::binary|ios::app);
 }while(chh=='y');
out1.close();
ifstream in;

in.open("bill.dat",ios::binary);
productbill pbill;
cout<<tempbillid<<"\t\t\t"<<pb.dd<<'/'<<pb.mm<<'/'<<pb.yy<<endl;
cout<<pb.fname<<"\t\tadd "<<pb.add<<endl;
cout<<"tempbillid"<<tempbillid<<endl;
total=0;
cleardevice();
clrscr();
cout<<"Bill no          Productname           Quantity           Amount"<<endl;
cout<<"____________________________________________________________"<<endl;
while(in.read((char*)&pbill, sizeof(pbill)))
{
  if(tempbillid==pbill.billid)
   {
	cout<<pbill.rid<<"            "<<pbill.pname<<"           "<<pbill.qty<<"          "<<pbill.amt<<endl;
	 total=total+pbill.amt;
	 }

	 }

cout<<"\n__________________________________________________________"<<endl;
cout<<"\n\nTotal amount                     "<<total;
cout<<" \n_________________________________________________________"<<endl;
cout<<"Press any key to print ...";
getch();

in.close();

}

void main()
{
 int opt;
 do
 {
  cleardevice();
  settextstyle(10,0,5);
  outtextxy(40,20," Child Care");
  settextstyle(5,0,3);
  outtextxy(60,120," 1.  Admin");
  outtextxy(60,150," 2.  Purchase");
  outtextxy(60,180," 3.  ");
  outtextxy(60,210," 4.  Bill");
  outtextxy(60,240," 5.  Exit");
  outtextxy(60,270," Enter Your option  ");
  gotoxy(10,20);
  cin>>opt;
  switch(opt)
  {
   case 1:admin();
		  break;
   case 2:
   case 3:
   case 4:
   case 5:exit(0);
  }
 getchar();
 }
 while(opt<=5);
}