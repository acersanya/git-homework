#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <math.h>
using namespace std;

bool checker (double a, double b  , double c) {  // function which checks ��(�� ��� ��) � (�� ���2 ��) // 

	if(  (!( (int) a || (int) b) && (  ((int)a + (int)c)%2))!=0){
		return true; // Function returns Real_number
	}
	else 
		return false; // otherwise returns Integer

}

void Calcute_func (double X_start , double X_end , double dx , double a, double b, double c , bool checker){ // if FALSE - Integer if TRUE - Real number
	int counter =1; // counter
	double tmp=0; //����� �� ����������� ������ ����������

	for(double i = X_start; i< X_end; i=i+dx){ 
		cout<<counter<<")";

		if( (i<3) && (b!=0)){  // ������ �������  
			cout<<"ax^2-bx+c:  \t";  
			tmp = a* pow(i,2)-b*i+c; 
			if( checker == true) { // ���� ������� ������� true �� ��������� ĳ���� ����� 
				cout<<tmp <<" \t";
				cout<<"TRUE"<<endl;}
			else {  // ���� � �� ���� �������
				cout<<(int)tmp<<" \t";
				cout<<"FALSE"<<endl;}} 


		else if( (i>3) && b==0 ){ // ������ �������
			cout<<"x-a/x-c:  \t";

			if(i-c ==0){ // Divizion by zero
				continue;}


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

			if(c==0){
				cout<<"Divizion by zero"; // ������ �� ����
				break;}

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


		counter++; // �������� ���� ������� � ��������
	}

}


int main(){

	setlocale( LC_CTYPE,"Russian" ); 
	double X_start =0 , X_end=0, dx=0; //��������� ����������� ������
	double a=0,b=0,c=0;
	string answer; // � ���� do - while ���� ���������� ������ ���, ���������� �� ����� ���� � �� �����
	bool check_answer;

	do {


one:

		cout<<"Enter X_start , X_end , dx:"<<endl;

		while(!((cin >> X_start) && (cin>> X_end) && (cin>>dx))){ // �������� �� ��������, ���� ������� �������� ��������
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. ONLY DIGITS ARE ALLOWED ";
    }
		if(X_end<X_start) { cout<<"try again X_end > X_start"<<endl; goto one;} // ����� ������ ����������� ����� , X_start > X_end

		

		cout<<"Enter: a,b,c"<<endl;
	
		while(!((cin >> a) && (cin>> b) && (cin>>c))){ // �������� �� �������� �����.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. ONLY DIGITS ARE ALLOWED ";
    }



		bool check_in  = checker(a,b,c); // calculates the task  HE(Ac or Bc) and (Ac mod2 Bc) ��� �� ���������� ���� �����. ���� FALSE - ���� ������� ����  TRUE �� ����� ������� �����

		cout<<check_in<<endl;
		Calcute_func(X_start, X_end, dx , a ,b,c , check_in);	 // �������� ������� �� ������ ��������

		cout<<"You want to continue?"; // ���� ���������� ���� ���������� ���� yes ���� � - no

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