#include<stdio.h>
int main()
{
  char stringmsg[50];
  char c1; int i, k;  
  char stringmsg1[50];
  char c2; int i1, k1;
  printf("Enter the message to be encrypted: ");
  scanf("%s",stringmsg);
  printf("\nEnter the key: ");
  scanf("%d", &k);

// cipher text encryption
  for(i=0; stringmsg[i]!='\0'; i++){
    c1 = stringmsg[i];
    
    if(c1>='A' && c1 <='Z'){
        c1=c1+k;
        if(c1>'Z'){
            c1 = c1 - 'Z' + 'A' - 1;
        }
        stringmsg[i] = c1;
    }
    
    else if(c1>='a'&&c1<='z'){
        c1=c1+k;
        if(c1>'z'){
            c1=c1-'z'+'a'-1;
        }
        stringmsg[i] = c1;
    }
  }

  printf("\nThe Encrypted message is: %s", stringmsg);

  printf("\nEnter the message to be decrypted: ");
  scanf("%s",stringmsg1);
  printf("\nEnter the key: ");
  scanf("%d", &k1);


// cipher text decryption
   for(i1=0; stringmsg[i1]!='\0'; i1++){
    c2 = stringmsg1[i1];
    
    if(c2>='A' && c2 <='Z'){
        c2=c2-k1;
        if(c2<'A'){
            c2=c2+'Z'-'A'+1;
        }
        stringmsg1[i1] = c2;
    }
    
    else if(c2>='a'&&c2<='z'){
        c2=c2-k1;
        if(c2<'a'){
            c2=c2+'z'-'a'+1;
        }
        stringmsg1[i1] = c2;
    }
  }

  printf("\nThe Decrypted message is: %s", stringmsg1);
  return 0;
}