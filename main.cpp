#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void shuffle(int n){
int arr[n];
srand((unsigned)time(0));
for (int i = 0; i <n; ++i)
{
	arr[i]=(rand()%100)+1;
}

}

void printarr(int n){
	int arr[n];
for (int i = 0; i <n; ++i)
{
	cout<<arr[i]<<" ";
	//cout<<endl;
}
}

int main(){
int n;
cout<<"how big do you want the array to be?"<<endl;
cin>>n;
shuffle(n);
printarr(n);

	return 0;
}