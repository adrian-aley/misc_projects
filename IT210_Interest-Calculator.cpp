//IT210 BUSINESS APPLICATIONS WITH C++
//PROGRAMMER:ADRIAN ALEY
//DATE:APRIL 11, 2014
//PROGRAM ASSIGNMENT 4

//Preprocessor directives
#include<iostream>
#include<iomanip>
using namespace std;

void headerfn();
void namefn(string &first, string &last);
int cardfn(int card);
void checkfn(int card);
void accountfn(float &netBalance, float &payment, int &d1, int &d2);
void adbfn(float &averageDailyBalance, float &payment, float &netBalance, int &d1, int &d2);
float APRfn(float &APR, float &averageDailyBalance);
void intfn(float &APR, float &averageDailyBalance, float &interest);
void outputfn(float &netBalance, float &payment, float &interest, float &APR, float &averageDailyBalance, int &d1, int &d2, string &first, string &last, int &card);

//function definitions
int main(){
    
    headerfn();
    
    //declarations
    float netBalance, payment,  interest, APR, averageDailyBalance;
    int d1, d2, card;
    
    string first, last;
    
	cout<<"This program calculates the interest on one or more customer's"<<endl; 
	cout<<"unpaid credit card balances using the average daily balance"<<endl<<endl;
    
    cout<<left<<fixed<<setprecision(0)<<left<<fixed;
    
    namefn(first, last);
    
    cardfn(card);
	    
    checkfn(card);
    
    accountfn(netBalance, payment, d1, d2);
    
    outputfn(netBalance, payment, interest, APR, averageDailyBalance, d1, d2, first, last, card);
    
    
	
	int exit=0; 
    cout<<"Please enter 0 to exit or 1 for another customer: ";
    cin>>exit;
    cout<<endl;
    while(exit!=0){//begin infinite while
    
    headerfn();
    
    cout<<"This program calculates the interest on one or more customer's"<<endl; 
	cout<<"unpaid credit card balances using the average daily balance"<<endl<<endl;
    
    cout<<left<<fixed<<setprecision(0)<<left<<fixed;
    
    namefn(first, last);
    
    cardfn(card);
	    
    checkfn(card);
    
    accountfn(netBalance, payment, d1, d2);
    
    outputfn(netBalance, payment, interest, APR, averageDailyBalance, d1, d2, first, last, card);
    
    cout<<"Please enter 0 to exit or 1 for another customer: ";
    cin>>exit;
    cout<<endl;
}
    	
    return 0;
}//end of main

void headerfn(){
    cout<<"=******************************************="<<endl;
    cout<<"*   IT210 Business Applications with C++   *"<<endl;
    cout<<"*   Programmer: Adrian Aley                *"<<endl;
    cout<<"*   Date: April 11, 2014                   *"<<endl;
    cout<<"*   Interest Calculator                    *"<<endl;
    cout<<"=******************************************="<<endl;
    cout<<endl;
}//end headerfn

void namefn(string &first, string &last){
	cout<<"Please enter first and last name on credit card: ";
    cin>>first>>last;
    cout<<endl;
    cout<<"You entered "<<first<<" "<<last<<endl<<endl;
}//end namefn

int cardfn(int card){
	cout<<"Please enter credit card number: ";
    cin>>card;
    cout<<endl;
    cout<<"You entered "<<card<<endl<<endl;
}

void checkfn(int card){
	int correct=0;
    cout<<"If this is correct, press 0 or 1 to try again: ";
    cin>>correct;
    cout<<endl;
    while(correct!=0){//start of while
    	cout<<"Please enter credit card number: ";
    	cin>>card;
    	cout<<endl;
    	cout<<"You entered "<<card<<endl<<endl;
    	cout<<"If this is correct, press 0 or 1 to try again: ";
    	cin>>correct;
    	cout<<endl;
    }//end of infinite while and checkfn
}

void accountfn(float &netBalance, float &payment, int &d1, int &d2){
	
	cout<<"Please enter the balance shown in the credit card bill: ";
    cin>>netBalance;
    cout<<endl;
    cout<<"You entered $"<<netBalance<<endl<<endl;
    
    cout<<"Please enter payment amount: ";
    cin>>payment;
    cout<<endl;
    cout<<"You entered $"<<payment<<endl<<endl;
    
    cout<<"Please enter number of days in billing cycle: ";
    cin>>d1;
    cout<<endl;
    cout<<"You entered "<<d1<<endl<<endl;
    
    cout<<"Please enter number of days payment is made before billing cycle: ";
    cin>>d2;
    cout<<endl;
    cout<<"You entered "<<d2<<endl<<endl;
}

void adbfn(float &averageDailyBalance, float &payment, float &netBalance, int &d1, int &d2){
	averageDailyBalance=(netBalance*d1-payment*d2)/d1;
}

float APRfn(float &APR, float &averageDailyBalance){
	if(averageDailyBalance<100){//begin if esle statement
    		APR=5;
    	}
    	
    	else if(100<averageDailyBalance<1000){
    		APR=10;
    	}
    	
    		else{
    		APR=15;
    	    }//end if else statement
}

void intfn(float &APR, float &averageDailyBalance, float &interest){
	interest=averageDailyBalance*APR/(100*12);
}

void outputfn(float &netBalance, float &payment, float &interest, float &APR, float &averageDailyBalance, int &d1, int &d2, string &first, string &last, int &card){
	cout<<setw(50)<<setfill('*')<<"*"<<endl;
    cout<<"12345678901234567890123456789012345678901234567890"<<endl;
    cout<<setw(50)<<setfill('*')<<"*"<<endl<<endl;
    
    cout<<left<<setw(15)<<setfill(' ')<<first;
    
	cout<<left<<setw(15)<<setfill(' ')<<last;
    
	cout<<left<<setw(15)<<setfill(' ')<<card<<endl;
    
	cout<<setw(50)<<setfill('-')<<"-"<<endl;
    cout<<left<<setw(15)<<setfill(' ')<<"FIRST NAME";
    cout<<left<<setw(15)<<setfill(' ')<<"LAST NAME";
    cout<<left<<setw(15)<<setfill(' ')<<"CARD NUMBER"<<endl;
    
	cout<<setw(50)<<setfill('=')<<"="<<endl<<endl;
    
    cout<<left<<setw(40)<<setfill('.')<<"Credit Card Balance"
        <<right<<setw(10)<<setfill(' ')<<setprecision(2)<<netBalance<<endl<<endl;
    
    adbfn(averageDailyBalance, payment, netBalance, d1, d2);
    
    APRfn(APR, averageDailyBalance);
    
    intfn(APR, averageDailyBalance, interest);
    		
    
	cout<<left<<setw(40)<<setfill('.')<<"Annual Interest Rate"
        <<right<<setw(10)<<setfill(' ')<<setprecision(2)<<APR<<endl<<endl;
    
	cout<<left<<setw(40)<<setfill('.')<<"Payment Made"    
        <<right<<setw(10)<<setfill(' ')<<setprecision(2)<<payment<<endl<<endl;
    
	cout<<left<<setw(40)<<setfill('.')<<"Number of Days in Billing Cycle"
        <<right<<setw(10)<<setfill(' ')<<setprecision(2)<<d1<<endl<<endl;
    
	cout<<left<<setw(40)<<setfill('.')<<"Number of Days Before Billing Cycle"
        <<right<<setw(10)<<setfill(' ')<<setprecision(2)<<d2<<endl<<endl;
	
	cout<<left<<setw(40)<<setfill('.')<<"Average Daily Balance"  
	    <<right<<setw(10)<<setfill(' ')<<setprecision(2)<<averageDailyBalance<<endl<<endl;
	
	cout<<left<<setw(40)<<setfill('.')<<"Interest on Unpaid Balance" 
	    <<right<<setw(10)<<setfill(' ')<<fixed<<setprecision(2)<<interest<<endl<<endl;
		
	 cout<<setw(50)<<setfill('*')<<"*"<<endl<<endl;
}
    
