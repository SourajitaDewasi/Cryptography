#include <iostream>
using namespace std;

/*Function to left Rotate arr[] of
  size n by 1*/
void leftRotatebyOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
 
    arr[n-1] = temp;
}

/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n)
{
    for (int i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}

int main() {
	int key[64] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	int keydrop[56];int rotateKey[56];
	int left[28];
	int right[28];
	cout<<"Implementation of Round 1 to 16 of DES Key Generation \n";
	cout<<"Original Key :";
	for(int i=0; i<64; i++){
	    cout<<key[i];
	}
	
	cout<<"\nDropping Key :";
	for(int i=0,j=0; i<64,j<56; i++){
	    if(i%8 != 0 ){
	        keydrop[j]=key[i];
	        j++;
	    }
	}
	
	for(int i=0; i<56; i++){
	    cout<<keydrop[i];
	}
	

	
 
    //Splitting the array into left and right
	for(int i=0; i<28; i++){
	    left[i]=keydrop[i];
	}
	int j=0;
	for(int i=28, j=0; i<56; i++, j++){
	    right[j]=keydrop[i];
	}
	
	cout<<"\nLeft Array :";
	for(int i=0; i<28; i++){
	    cout<<left[i];
	}
	cout<<"\nRight Array :";
	for(int i=0; i<28; i++){
	    cout<<right[i];
	}
		//Looping it 16 times
    for(int loop=0; loop<16; loop++){   
    
	//shifting both the left and right array
	for(int i=1; i<=28; i++){
	    if((i==1)||(i == 2)||(i == 9)||(i == 16)){
	        leftRotate(left,1,28);
	        leftRotate(right,1,28);
	    }
	    else{
	        leftRotate(left,2,28);
	        leftRotate(right,2,28);
	    }
	}
    
    cout<<"\nLeft Array After Shift Operation :";
	for(int i=0; i<28; i++){
	    cout<<left[i];
	}
	cout<<"\nRight Array After Shift Operation :";
	for(int i=0; i<28; i++){
	    cout<<right[i];
	}
	
	//Merging the left and right array after bit rotation
    for(int i=0; i<28;i++){
        rotateKey[i]=left[i];
    }  
    for(int i=0, j = 28;i <28; i++, j++)
  	{
  		rotateKey[j] = right[i];
  	}
  	cout<<"\nMerging Key :";
  	for(int i=0; i<56; i++){
	    cout<<rotateKey[i];
	}

	int key_PBox[48] = {14,    17,   11,    24,     1,    5,
                  3,    28,   15,     6,    21,   10,
                 23,    19,   12,     4,    26,    8,
                 16,     7,   27,    20,    13,    2,
                 41,    52,   31,    37,    47,   55,
                 30,    40,   51,    45,    33,   48,
                 44,    49,   39,    56,    34,  53,
                 46,    42,   50,    36,    29,   32};
    
    
    int Round1[48];             
    //compression P_Box
    cout<<"\nAfter Round "<<loop+1<<" :";
    for(int i=0;i<48;i++){
	    Round1[i]=rotateKey[key_PBox[i]];
	    cout<<Round1[i];
	    keydrop[i]=Round1[i];
	} cout<<"\n\n";
}   cout<<"\n The round 16 will be the final key at DES Key Generation";
	return 0;
}
