#include<bits/stdc++.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
using namespace std;

struct person //contact list entry structure
{
    char ph[10];
    string pname;
};
/////////////////////////////////////////////////
struct Log_list //call log entry structure
{
    string num,name,timelog;
    
};
/////////////////////////////////////////////////
class queue //main class whic contains all calling, logging and storage facilities
{
public:
  int n = 10, front = -1, rear = -1, c=0;
person P[10];
Log_list L[10];

  ///////////////////
  void Continue() //Encapsulates the "press-to-continue" procedure
  {
  int c;
  printf( "\nPress a key to continue back to menu" );
  c = getch();
  if (c == 0 || c == 224) getch();
  }
  ///////////////////
  void Update_Log(person t) //Updates call log after making a call
  {
    int val, i;
      front = 0;
    if (rear == n - 1)
      {
	for (i = 0; i < n - 1; i++)
	  {
	    L[i] = L[i + 1];
	  }
      }
    else
      {
	rear++;
      }
    L[rear].num=t.ph;
    L[rear].name=t.pname;
    time_t my_time = time(NULL); 
    L[rear].timelog=ctime(&my_time);
  }
  ///////////////////
  void call(person t) //Placeholder function for simulating placing a call
  {
      int i;
      cout<<"\n\n\n";
      cout<<"Calling "<<t.pname<<endl;
      for(i=0;i<4;i++)
      {
          Sleep(2000);
          cout<<".   ";
      }
      cout<<"\nCall not recieved, please try later";
  }
  ///////////////////
  void Disp_Log() //Displays call log
  {
    if (front == -1)
      {
          cout << "\nCall log is empty!";
      }
    else
      {
      	cout<<"CALL LOG\n____________________\n";
	    for (int i = rear; i>=front; i--)
	  	{
	    	cout<<endl<<L[i].name<<" - "<<L[i].num<<endl<<L[i].timelog<<endl;
	  	}
      }
  }
  ///////////////////
  void Add_Contact() //Adds contact to contact list
  {
      cout<<"\n\n\n";
      person t;
      int i;
      if(c==n)
      {
          cout<<"\nContact storage limit reached (up to 10)\nPlease free up storage to continue";
      }
      else
      {
      cout<<"\nEnter Phone no. : "; cin>>P[c].ph;
      cout<<"\nEnter Name      : "; cin>>P[c].pname;
      for(i=0;i<c;i++)
      {
          if(P[i].pname>P[c].pname)
          {
              t=P[i];
              P[i]=P[c];
              P[c]=t;
          }
      }
      if(c<n)
      {
          c++;
      }
      cout<<"\nContact Added\n";
      }
  }
  ///////////////////
  void Disp_Contacts() //Displays contact list
  {
      int i;
	  cout<<"\n\n\n";
      if(c==0)
      {
          cout<<"No contacts added";
      }
      else
      {
      	cout<<"CONTACT LIST\n____________________";
          for(i=0;i<c;i++)
          {
              cout<<endl<<endl<<i+1<<".\n"<<P[i].pname<<endl<<P[i].ph;
          }
      }
  }
  ///////////////////
  void Del_Contact() //Deletes specific contact from contact list
  {
      cout<<"\n\n\n";
      int ind, i;
      person T;
      if(c==0)
      {
          cout<<"No contacts added";
      }
      else
      {
          Disp_Contacts();
          cout<<"\nEnter the index no. of the contact to be deleted : ";
          cin>>ind;
          for(i=ind-1;i<c;i++)
          {     
              T=P[i+1];
              P[i+1]=P[i];
              P[i]=T;
          }
      cout<<"\n\n Contact Deleted";
      c--;
      }
  }
  ///////////////////
  void menu() //Main UI
{
    int a;
    cout<<"\n\nMain Menu\n____________________\n";
    cout<<"1) Make A Call\n2) View Call Log\n3) View Contacts\n4) Edit Contacts\n5) Exit\n\nEnter option no. : ";
    cin>>a;
    cout<<"\n\n\n";
    if(a==1)
    {
        if(c==0)
        {
            Disp_Contacts();
        }
        else
        {
            Disp_Contacts();
            cout<<"\nEnter index no. of contact to be called : ";
            cin>>a;
            call(P[a-1]);
            Update_Log(P[a-1]);
        }
    }
    else if(a==2)
    {
        Disp_Log();
    }
    else if(a==3)
    {
        Disp_Contacts();
    }
    else if(a==4)
    {
        cout<<"1) Add a contact\n2) Delete a contact\n\nEnter option no. : ";
        cin>>a;
        if(a==1)
        {
            Add_Contact();
        }
        else if(a==2)
        {
            Del_Contact();
        }
        else
        {
            cout<<"Invalid input";
  
        }
    }
    else if(a==5)
    {
    	exit(0);
	}
    else
    {
        cout<<"Invalid Input";
    
    }
    Continue();//menu_call();
    menu();
}
  
} temp; //"temp" declared as placeholder call log object
/////////////////////////////////////////////////
int main () //Driver Code
{
  temp.menu();
  return 0;
}

