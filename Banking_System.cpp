#include<iostream>
#include<string>
#include<fstream>
using namespace std;


    void findacc(int n);
    void deposit(int num);


 class account{
     
    public:

    char name[30];
    int deposit;
    int acno;
    char type;

   void create_acc(){
         cout<<"Enter the name of the account holder : ";
         cin>>name;
         cout<<"Enter the account no. : ";
         cin>>acno;
         cout<<"Enter your account type (C/S): ";
         cin>>type;
         cout<<"Enter your initial deposit : (>=500 for savings and >=1000 for current) : ";
         cin>>deposit;
         cout<<"Acoount created.";
   }
    

    int giveacno() const{
       return acno;
    }

    void show() const{
       cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : "<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
    }

    void dep(int x){
       deposit+=x;
    }
    void wdr(int x){
       deposit-=x;
    }

};

int main(){
    cout<<"Welcome!!"<<endl;
    cout<<"Please enter the respected no. of what you want to do ."<<endl;
    int r=0,num;
    while(r!=6)
    {
    cout<<"1.Create an account.\t2.Deposit.\n3.Close the account.\t4.Withdraw.\n5.Close the account.\t6.Exit."<<endl;
    cout<<"Please enter here : ";
    cin>>r;

      switch(r){
        case 1:
               write_acc();
               break;
        case 2:
               cout<<"Enter your account no. : ";
               cin>>num;
               deposit_withdraw(num,1);
               break; 
        //case 3:close();
        //       break;              
        case 4:cout<<"Enter your account no. : ";
               cin>>num;
               deposit_withdraw(num,2);
               break; 
        /*case 5:closeacc();
               break; 
        case 6:exitfrom();
               break;*/
      }
          
    }
}


void write_acc(){
     account ac;
     ofstream file;
     file.open("student.txt",ios::app|ios::binary);
     ac.create_acc();
     file.write(reinterpret_cast<char*>(&ac),sizeof(account));
     file.close();
}


void findacc(int n){
       account ac;
       ifstream infile;
       infile.open("student.txt",ios::binary); 
       while(true){
              infile.read(reinterpret_cast<char*>(&ac),sizeof(account));
              if(ac.giveacno() == n){
                   ac.show();
              }
       }
       infile.close();
}

void deposit_withdraw(int num,int option){
       account ac;
       int amt;
       fstream file;
       file.open("student.txt", ios::binary|ios::in|ios::out);
       cout<<"Enter your amount : ";
       cin>>amt;
       while(!file.eof())
{
         file.read(reinterpret_cast<char *> (&ac), sizeof(account));
         if(ac.giveacno() == num){
                   ac.show();
                   if(option==1)
                   ac.dep(amt);
                   if(option==2)
                   ac.wdr(amt);
              }    
          
}
       
}

