#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
// different sorting algorithms

void swap(int *a, int *b){
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}
/* Function to print an arr */
void printarr(int *arr, int size)
	{
		//while i is less than size of array goes through and prints out each index.
		int i;
		for (i=0; i < size; i++)
			cout<<(arr[i])<<" ";
	}
void merge (int *arr, int left, int mid, int right){ //subroutin- e of merge operation that combines lengths m+n
int *temp=new int [right-left+1]; // creation of temporary merge array
int i=left; //left hand of array
int j=mid+1; // right hand of array
int k=0; // for the temporary array`
while (i<=mid && j<=right){
	if(arr[i]<=arr[j])
		temp[k++] = arr[i++];
	else 
		temp[k++] = arr[j++];
}
//left hand
while (i<= mid)
	temp[k++] = arr[i++];
// right hand
while (j<=right)
	temp[k++] = arr[j++];
// copies the temporary array that has been merged into the original array.
for (k = 0, i=left;i<=right; ++i, ++k)	
{
	arr[i]=temp[k];
}
delete []temp; // free up to avoid any mem leaks
}



size_t mergesort(int *arr, int left, int right)// merge sort function
{
int mid;
if(left<right){
	mid=(left+right)/2;
	mergesort(arr,left,mid);//first half of the array sort
	mergesort(arr,mid+1,right); //second half sort
	merge(arr,left,mid,right); //merges the two arrays back together
}
}

int partition(int *arr, int start, int end){
int pivot=arr[end];  //sets the pivot 
int index=(start-1);   //the index of the smaller element
for (int i = start; i <= end-1; i++)
{
	if (arr[i]<=pivot)
	{
		index++;    //moves the index of the smaller element
		swap(arr[index],arr[i]);  //swaps the smaller element and larger element
	}
}
swap(arr[index+1],arr[end]);
	return (index+1);
}

int randomizedpartition(int *arr,int low,int high){
	//generates a random number that is between low to high
	srand(time(NULL));
	int random=low +rand() %(high-low);
	//then swaps the random value with the high value`
	swap(arr[random], arr[high]);
	return partition(arr,low,high);
}
// quick sort function 
size_t quicksort(int *arr, int start, int end){
int pivot; //partitioning index
if (start<end)
{
pivot=partition(arr,start,end);
//pivot=randomizedpartition(arr,start,end);
quicksort(arr,start,pivot-1);	
quicksort(arr,pivot+1,end);

}
}
size_t randomquicsort(int *arr, int start, int end){
int pivot; //partitioning index
if (start<end)
{
pivot=randomizedpartition(arr,start,end);
//pivot=randomizedpartition(arr,start,end);
quicksort(arr,start,pivot-1);	
quicksort(arr,pivot+1,end);

}
}
//generates randomly shuffled array
int * shuffle(int n){
int * arr=new int [n];
//srand((unsigned)time(0));
for (int i = 1; i <n; i++)
{
	arr[i]=i;
}
return arr;
}


void maxheapify(int arr[],int n, int i){
int largenode=i; // sets largenode as root node
int l=2*i+1; //sets left node
int r=2*i+2; //sets right node
//if left child is greater than root
if(l<n && arr[l]>arr[largenode]){
	largenode=l;
}
//if right child is greater than the root
if (r<n && arr[r]>arr[largenode])
{
	largenode=r;
}
//swap and continue heapifying if largenode is not the root
if (largenode != i)
{
	swap(arr[i],arr[largenode]);
	//recursively heapify the affected subtree.
	maxheapify(arr,n,largenode);
}


}
//build maxheap
void buildmaxheap(int arr[],int n){

	for (int i = (n / 2)-1; i >= 0; i--)
    maxheapify(arr,n,i);

}
//heapsort
size_t heapsort(int arr[], int n){
buildmaxheap(arr,n); // call buildmaxheap
//heapsort algorithm
for (int k = n-1; k >=0;k--)
{	
swap(arr[0],arr[k]);
//heapify root element to get highest element
maxheapify(arr,k,0);

}

}