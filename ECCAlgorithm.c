//This code is contributed by Sourajita Dewasi
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Enc[4]={0,0,0,0};
int a=3;
int b=20;
int p=19;
int points[1000][2];
int PrivKey=11;
int PubKey[2]={0,0};
int Rm = 11;
int Pbase[2]={0,0};

int * sclr_mult(int k,int point[2]);
int * add(int A[2],int B[2]);
int inverse(int num);
int * encode(int m,int Pb[2],int Rm,int Pbase[2]);
int * genKey(int X,int P[2]);
int decode(int Enc[4],int PrivKey);
void generate();

int main()
{
    int *temp;
    printf("Simulation of ECC Cryptography System");
    generate();
    Pbase[0]=points[5][0];
    Pbase[1]=points[5][1];
    temp=genKey(PrivKey,Pbase);
    PubKey[0]=*temp;
    PubKey[1]=*(temp+1);
    printf("\n\n The Public Keys are (%d,%d)\n",PubKey[0],PubKey[1]);

    int message[2];
    message[0]=points[5][0];
    message[1]=points[5][1];
    printf("The Message Points are (%d,%d)\n",message[0],message[1]);

    int P[2];
    temp=sclr_mult(Rm,Pbase);
    P[0]=*temp;
    P[1]=*(temp+1);
    int Q[2];
    temp=sclr_mult(Rm,PubKey);
    Q[0]=*temp;
    Q[1]=*(temp+1);
    int R[2];
    temp=add(message,Q);
    R[0]=*temp;
    R[1]=*(temp+1);

    printf("The Encryption Points are [(%d,%d),(%d,%d)]\n",P[0],P[1],R[0],R[1]);

    temp=sclr_mult(PrivKey,P);
    int O[2];
    O[0]=*temp;
    O[1]=p-*(temp+1);

    temp=add(R,O);
    O[0]=*temp;
    O[1]=*(temp+1);
    printf("The Message Points are (%d,%d)\n",O[0],O[1]);
    return 0;
}

int * sclr_mult(int k,int P[2])
{
    int *temp,i;
    int *Q = calloc(2,sizeof(int));
    Q[0]=0;
    Q[1]=0;
    for(i=31;i>=0;i--)
    {
        if((k>>i)&1)
            break;
    }
    for(int j=0;j<=i;j++)
    {
        if((k>>j)&1)
        {
            temp=add(Q,P);
            Q[0]=*temp;
            Q[1]=*(temp+1);
        }
        temp=add(P,P);
        P[0]=*temp;
        P[1]=*(temp+1);
    }
    return Q;
}

int * add(int A[2],int B[2])
{
    int *C = calloc(2,sizeof(int));
    int x=0;
    if (A[0]==0 || A[1]==0)
    {
        return B;
    }
    if (B[0]==0 || B[1]==0)
    {
        return A;
    }
    if (A[1]==(p-B[1]))
    {
        return C;
    }
    if ((A[0]==B[0]) && (A[1]==B[1]))
    {
        x=((3*(A[0]*A[0]))+a)*inverse(2*A[1]);
        C[0]=((x*x)-(2*A[0]))%p;
        C[1]=((x*(A[0]-C[0]))-A[1])%p;
        }
    else
    {
        x=(B[1]-A[1])*inverse(B[0]-A[0]);
        C[0]=((x*x)-(A[0]+B[0]))%p;
        C[1]=((x*(A[0]-C[0]))-A[1])%p;}
    if (C[0]<0)
        C[0]=p+C[0];
    if (C[1]<0)
        C[1]=p+C[1];
    return C;
}
int inverse(int num)
{
    int i=1;
    if (num<0)
        num=p+num;
    for (i=1;i<p;i++)
    {
        if(((num*i)%p)==1)
            break;
    }
    return i;
}

void generate()
{
    int rhs,lhs,i=0;
    for(int x=0;x<p;x++)
    {
        rhs=((x*x*x)+(a*x)+b)%p;
        for(int y=0;y<p;y++)
        {
            lhs=(y*y)%p;
            if (lhs==rhs)
            {
                points[i][0]=x;
                points[i][1]=y;
                i+=1;
            }
        }
    }
    printf("\nNumber of points found on the Curve are %d \n",i);
    for(int k=0;k<i;k++)
    {
        printf("%d(%d,%d)\n",(k),points[k][0],points[k][1]);
    }
}

int * genKey(int X,int P[2])
{
    int *temp;
    int *Q = calloc(2,sizeof(int));
    temp=sclr_mult(X,P);
    Q[0]=*temp;
    Q[1]=*(temp+1);
    return Q;
}
