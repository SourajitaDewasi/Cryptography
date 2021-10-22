/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<math.h>
using namespace std;



int main(){
    int i=0; int j=0; int k=0; int len=0; int m=0;
    float key[10][10];
	string plaintext;

	float det=0;
	cout<<"\n Implementation of Hill Cipher";
	cout << "\n Enter the text to be encrypted : ";
	cin >> plaintext;
	len = plaintext.length();
	
    float c[len][1],e[len][1];    float d[len][1];
	float textkeymatrix[len][1];
	
	cout << "\n Enter the dimension of the key: ";
	cin >> m;

	cout << "\n Enter elements of the key:";
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			cin >> key[i][j];
		}
	}
	
	cout << "\n Key: \n";
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			cout << key[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\nPlain Text Keyrix: \n";
	for(i=0;i<len;i++){
		if(isupper(plaintext[i])){
			textkeymatrix[i][0] = int(plaintext[i] - 65);
			cout << textkeymatrix[i][1] << "\n";
		}

		else{
			textkeymatrix[i][0] = int(plaintext[i] - 97);
			cout << textkeymatrix[i][1] << "\n";
		}

	}
	

	//keyrix multiplication key[m][m] x textkeyrix[len][1]
	cout << "\nKeyrix Multiplication: \n";


	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			c[i][j] = 0;

			for (k=0;k<3;k++){
				c[i][j] += key[i][k] * textkeymatrix[k][j];
			}
			e[i][j] = c[i][j];
			cout << c[i][j] << "\n";
		}
	}
	
	cout << "\nEncrypted key matrix: \n";
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			c[i][j] = int(c[i][j]) % 26;
			cout << c[i][j] << "\n";
		}
	}
	
	char ch;
	cout << "\nCipher Text/ Encrypted Text is:  ";
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			//cout << (c[i][j]+97) << "\n";
			if(isupper(plaintext[i])){
				ch = c[i][j]+65;
			}

			else{
				ch = c[i][j]+97;
			}
			
			cout << ch ;
		}
	}
	cout << endl;

	float inv[m][m];

	for(i = 0; i < 3; i++)
        det +=  (key[0][i] * (key[1][(i+1)%3] * key[2][(i+2)%3] - key[1][(i+2)%3] * key[2][(i+1)%3]));
    
    
	
	for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            inv[i][j] = ((key[(j+1)%3][(i+1)%3] * key[(j+2)%3][(i+2)%3]) - (key[(j+1)%3][(i+2)%3] * key[(j+2)%3][(i+1)%3]))/ det;
        cout << inv[i][j] << " ";
        }
        cout << endl;
    }




    char ch2;
    cout << "Decrypted Matrix: \n";
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			d[i][j] = 0;

			for (k=0;k<3;k++){
				d[i][j] += inv[i][k] * e[k][j];
			}
		
			cout << d[i][j] << "\n";
		}
	}


	cout << "Decrypted Text is: ";
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
		ch2 = (int(d[i][j]))+97;
		cout << ch2;
		
		}
	}
	cout << endl;

return 0;

}
