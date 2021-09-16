//Delfie-Hellmen Cipher 
#include <iostream>
using namespace std;

int Hellman(int a, int m1, int m2)
{	int r;
	int y = 1;

	while (m1 > 0)
	{	r = m1 % 2;
		if (r == 1){
		y = (y*a) % m2;
		}
		a = a*a % m2;
		m1 = m1 / 2;
	}
	return y;
}

int main()
{
	int p = 13;		
	int g = 5;
	int s1, s2, P1, P2;	
    s1=7; //Person A private key
    s2=10; //Person B private key

	P1 = Hellman(g, s1, p); //Person A public key to Person B
    P2 = Hellman(g, s2, p); //Person B public key to Person A

	int key1 = Hellman(P2, s1, p);
	int key2 = Hellman(P1, s2, p);
    cout<<"\n Person 1 Private Key "<<s1;
    cout<<"\n Person 1 Secret Key "<<key1;
    cout<<"\n Person 1 Public Key "<<P1;
    cout<<"\n Person 2 Private Key "<<s2;
    cout<<"\n Person 2 Secret Key "<<key2;
    cout<<"\n Person 1 Public Key "<<P2;
	return 0;
}
