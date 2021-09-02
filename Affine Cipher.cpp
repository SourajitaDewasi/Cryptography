//Affine Cipher 
#include <iostream>

using namespace std;

int main() {
	string plaintext; string ciphertext=" "; string plain_text;
	int key1, key2; int check; int inv;
	cout<<"Enter Plain Text to be encrypted ";
	cin>>plaintext;
	cout<<"\n Enter the key 1";
	cin>>key1;
	cout<<"\n Enter the key 2";
	cin>>key2;
	
	//Encryption
	for(int i=0; i<plaintext.size(); i++){
		if(plaintext[i]>='A' && plaintext[i]<='Z'){
			ciphertext+= char((key1* int(plaintext[i]-65)+ key2)%26 +65);
		}else{
			ciphertext+= char((key1* int(plaintext[i]-97)+ key2)%26 +97);
		}
	}
	
	cout<<"\n After Encryption";
	cout<<"\t Plain Text: "<<plaintext;
	cout<<"\t Cipher Text: "<<ciphertext;
	
	
	//Decryption
	for(int i=0; i<26; i++){
		check=(i*key1)%26;
		if(check==1){
			inv=i;
			break;
		}
	}
	if(check!=1)
	{
		cout<<"\n Inverse Key don't exist";
		return 0;
	}
	cout<<"\n Enter Cipher Text to be decrypted";
	cin>>ciphertext;
	for(int i=0; i<ciphertext.size(); i++){
		if(ciphertext[i]>='A' && ciphertext[i]<='Z'){
			plain_text+= char(((((ciphertext[i]-65- key2)%26+26)%26)*inv)%26+65);
		}else{
			plain_text+= char(((((ciphertext[i]-97- key2)%26+26)%26)*inv)%26+97);
		}
	}
    cout<<"\n After Decryption";
	cout<<"\t Cipher Text: "<<ciphertext;
	cout<<"\t Plain Text: "<<plain_text;

}

