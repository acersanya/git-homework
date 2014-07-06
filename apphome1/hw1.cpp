#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <math.h>


using namespace std;

bool checker (double a, double b  , double c) {  // function which checks ÍÅ(Àö èëè ÁÖ) È (Àö ÌÎÄ2 Ñö) // 

	if(  (!( (int) a || (int) b) && (  ((int)a + (int)c)%2))!=0){
		return true; // Function returns Real_number
	}
	else 
		return false; // otherwise returns Integer

}


void Calcute_func (double X_start , double X_end , double dx , double a, double b, double c , bool checker){ // if FALSE - Integer if TRUE - Real number
	int counter =1; // counter
	double tmp=0;

	for(double i = X_start; i< X_end; i=i+dx){
		cout<<counter<<")";

		if( (i<3) && (b!=0)){
			cout<<"ax^2-bx+c:  \t";  
			tmp = a* pow(i,2)-b*i+c; 
			if( checker == true) {
				cout<<tmp <<" \t";
				cout<<"TRUE"<<endl;}
			else { 
				cout<<(int)tmp<<" \t";
				cout<<"FALSE"<<endl;}} 


		else if( (i>3) && b==0 ){
			cout<<"x-a/x-c:  \t";
			tmp= (i-a)/(i-c);
			if (checker==true){

				cout<<tmp<<" \t";
				cout<<"TRUE"<<endl;
			}

			else { 

				cout<<(int)tmp<<" \t";
				cout<<"FALSE"<<endl;
			}}


		else
		{   
			cout<<"x/c: \t";
			tmp=i/c;	
			if(checker==true){

				cout<<tmp<<" \t";
				cout<<"TRUE"<<endl;
			}
			else

			{
				cout<<(int)tmp<<" \t";
				cout<<"FALSE "<<endl;}
		}


		counter++;
	}

}






int main(){
	setlocale( LC_CTYPE,"Russian" ); 
	double X_start , X_end, dx;
	double a,b,c;
	string answer;
	bool check_answer;


	do {

next:


one:
		cout<<"Enter X_start:"<<endl;
		cin>>X_start; 
		if(isdigit(X_start)==true){
			goto one;}



		cout<<"Enter X_end:"<<endl;
		cin>>X_end;

		if(X_end<X_start){
			cout<<"X_end should be > X_start"<<endl;
			goto one;
		}

		cout<<"Enter step:"<<endl;
		cin>>dx;

		cout<<"Enter: a,b,c"<<endl;
		cin>>a>>b>>c;
		bool check_in  = checker(a,b,c);

		cout<<check_in<<endl;
		Calcute_func(X_start, X_end, dx , a ,b,c , check_in);	

		cout<<"You want to continue?";

once_again: // go to ^_^
		cin>>answer; 


		if(answer=="yes"){
			check_answer= true;
		}
		else if (answer=="no"){
			check_answer = false;}
		else
		{
			goto once_again;
		}}

	while (check_answer!=false);

}