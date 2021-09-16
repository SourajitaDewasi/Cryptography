//Keyless Cipher 
//Name: Sourajita Dewasi (191000050)

#include<iostream>
using namespace std;

int main(){
	string str;
	int i=0,len=0;int k=0;
	cout << "Enter Plaintext: " ;
	getline(cin,str);
	
	len = str.length();
	
	char Cipher[len];
	for(i=0;i<len;i++){
		if(i%2 == 0){
			Cipher[k] = str[i];
			k++;
		}
	}

	for(i=0;i<len;i++){
		if(i%2 != 0){
			Cipher[k] = str[i];
			k++;
		}
	}
	cout <<"\nThe Encrypted Text of the given plain text is: " << Cipher<<"\n";

	char Plain[len];
	
	if(len%2!=0){
	k=0;
	for(i=0;i<=len/2;i++){
		Plain[k] = Cipher[i]; k++;
		Plain[k] = Cipher[i+int(len/2)+1];k++;
	}}

	else if(len%2==0){
	k=0;
	for(i=0;i<len/2;i++){
		Plain[k] = Cipher[i]; k++;
		Plain[k] = Cipher[i+int(len/2)];	k++;
	}}

	cout <<"The Decrypted Text of the given cipher text is: "<< Plain;
	

}