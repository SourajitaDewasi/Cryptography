//Sourajita Dewasi
//Initial and Final Permutation of DES
//Here each character is assumed to be of 1 bit to make the crypto concept clear instead of 1 byte, which would mean converting the entire text to binary and then permuting it

#include <iostream>
using namespace std;


int main() {
    //Assuming each character is 1 bit instead of 1 byte
	char ch[64]= "This#is#a#plain#text#This#is#not#a#cipher#text#Hello#world#How#";
	int initial_perm[64] = {58, 50, 42, 34, 26, 18, 10, 2,
                60, 52, 44, 36, 28, 20, 12, 4,
                62, 54, 46, 38, 30, 22, 14, 6,
                64, 56, 48, 40, 32, 24, 16, 8,
                57, 49, 41, 33, 25, 17, 9, 1,
                59, 51, 43, 35, 27, 19, 11, 3,
                61, 53, 45, 37, 29, 21, 13, 5,
                63, 55, 47, 39, 31, 23, 15, 7};
                

int final_perm[64] = {40, 8, 48, 16, 56, 24, 64, 32,
               39, 7, 47, 15, 55, 23, 63, 31,
               38, 6, 46, 14, 54, 22, 62, 30,
               37, 5, 45, 13, 53, 21, 61, 29,
               36, 4, 44, 12, 52, 20, 60, 28,
               35, 3, 43, 11, 51, 19, 59, 27,
               34, 2, 42, 10, 50, 18, 58, 26,
               33, 1, 41, 9, 49, 17, 57, 25 };
	//Text to be Encrypted
	cout<<"Text to be Encrypted\n";
	for(int i=0; i<64; i++){
	    cout<<ch[i];
	}
	cout<<"\n";
	char Encrypt[64];
	for(int i=0;i<64;i++){
	    Encrypt[i]=ch[initial_perm[i]];
	    cout<<Encrypt[i];
	}cout<<"\n";
	char Encrypt1[64];
	for(int i=0;i<64;i++){
	    Encrypt1[i]=Encrypt[final_perm[i]];
	    cout<<Encrypt1[i];
	}
	return 0;
}
