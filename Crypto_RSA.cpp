/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//This code is contributed by Sourajita Dewasi
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int modu(int b, unsigned int exp, unsigned int m)
{
    int x = 1;
    int i;
    int power = b % m;

    for (i = 0; i < sizeof(int) * 8; i++) {
        int least_bit = 0x00000001 & (exp >> i);
        if (least_bit)
            x = (x * power) % m;
        power = (power * power) % m;
    }    return x;
}

int modI(int a, int m) 
{   int temp = m; 
    int y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    {   int q = a / m; 
        int t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }  if (x < 0) 
       x += temp; 
    return x; 
} 

int gcd(int a, int b)  
 {  
   
    if (a == 0 || b == 0)  
        return 0;  
   
       
    if (a == b)  
        return a;  
   
   
    if (a > b)  
        return gcd(a-b, b);  
    return gcd(a, b-a);  
 } 
 
 int Prime(int num){
  int flag = 1;
  for(int i=2;i<=sqrt(num);i++)
  {
      if(num%i==0)
      {
          flag = 0;
          return flag;
      }
  }
  return flag;
}

int lcm(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  
 

int main(){
    int msg; char m;
    cout<<"\n Enter the character to be encrypted: ";
    cin>>m;
    msg = (int)m;
    cout<<"\n The corresponding ASCII value of the character is"<<msg;
    int p,q, random; int i=0; int a[2];
    srand (time(NULL));
    generate:
    while(i<2){
        random = rand() % 40 + 3;
        if(Prime(random)){
            a[i]=random;
            i++;
        }    }
    i=0;p=a[0];q=a[1];
    if(p==q){
        goto generate;
    }

    cout<<"\n The Random Prime Numbers are: "<<p<<" and "<<q;
    int n; n = p*q;
    int phi = (p-1)*(q-1);
    int lambda = lcm(p-1,q-1);
    int e;
    vector<int> tot;
    for(int i=3;i<lambda;i++)
    {   if(gcd(i,lambda) == 1){
            tot.push_back(i);
        }
    }
    int size = tot.size();
    int ran = rand() % size;
    e = tot[ran];
   
    cout<<"\n The modulus is: "<<n;
    cout<<"\n The phi(n) is: "<<phi;
    cout<<"\n The lambda(n) is:"<<lambda;
    cout<<"\n The toitient is: "<<e;
    cout<<"\n The public key is: ("<<n<<","<<e<<")";
    long long int encrypt;
    encrypt = modu(msg,e,n);
    cout<<"\n The Cipher text is: "<<(char)encrypt;
    cout<<"\n The ASCII value of Cipher Text is: "<<encrypt;
    long long int d = modI(e,lambda);
    if(d==e){
        cout<<"\n";
        goto generate;
    }
    cout<<"\n The private key is: "<<d;
    long long int decrypted;
    decrypted = modu(encrypt,d,n);
    cout<<"\n The Decrypted/Plain text is : "<<(char)decrypted;
    cout<<"\n The ASCII value of Plain text is: "<<decrypted;
return 0;
}
