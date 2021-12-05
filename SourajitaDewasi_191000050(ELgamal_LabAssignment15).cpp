/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<math.h>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
	int n,p; int LHS[2][n],RHS[2][n],a,b,i,j; 	
	vector <int> arr_x;
	vector <int> arr_y;
	cout<<"Simulation of ELgamal Crypto System";
	cout<<"\n Enter the value of P: ";
	cin>>p;
	n = p;
	cout<<"\n Enter the Value of a: ";
	cin>>a;
	cout<<"\n Enter the Value of b: ";
	cin>>b;
	cout<<"\n Current Elliptic Curve";
	cout<<"\n y^2 mod "<<p<<" = (x^3  + "<<a<<"*x + "<<b<<") mod p";


	for(int i=0; i<n; i++)
	{
		LHS[0][i] = i;
		RHS[0][i] = i;
		LHS[1][i] = ((i*i*i) + a*i + b) % p;
		RHS[1][i] = (i*i) % p;
	}


int in_c = 0;
	for(i = 0; i < n; i ++)
	{

		for(j = 0; j < n; j++)
		{
			if(LHS[1][i] == RHS[1][j])
			{
						in_c++;
					arr_x.push_back(LHS[0][i]);
					arr_y.push_back(RHS[0][j]);
			}
		}
	}

	cout<<"\n The Generated Points are: \n";
	for(i =0; i < in_c; i++)
	{
		cout<<i+1<<"\t( "<<arr_x[i]<<" , "<<arr_y[i]<<" )"<<"\n";
	}
	cout<<"Base Points are: ("<<arr_x[0]<<","<<arr_y[0]<<")"<<"\n";
	int k,d,M;
	cout<<"Enter the random number 'd' i.e. Private key of Sender  (d<n)\n";
	cin>>d;
	int Qx=d*arr_x[0];
	int Qy=d*arr_y[0];

    cout<<"Enter the random number 'k' (k<n)\n";
	cin>>k;

    cout<<"Enter the message to be sent:\n";
	cin>>M;
	cout<<"The message to be sent is:\n"<<M<<"\n";

	int c1x=k*arr_x[0];
	int c1y=k*arr_y[0];
	cout<<"Value of C1: ("<<c1x<<","<<c1y<<")"<<"\n";

	int c2x=k*Qx+M;
	int c2y=k*Qy+M;
	cout<<"Value of C2: ("<<c2x<<","<<c2y<<")"<<"\n";

	cout<<"\nThe message received is:\n";
	int Mx=c2x-d*c1x;
	int My=c2y-d*c1y;
	cout<<Mx;
}