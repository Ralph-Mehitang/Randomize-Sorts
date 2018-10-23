#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "sort.cpp"
using namespace std;

//quick sort timme function
void quicksorttime(int *arr,int n){
int input;
cout<<"input 1 for array print and time, or input 2 for just the time"<<endl;
cin>>input;
if (input==1){
cout<<"sorted arrays:"<<endl;
auto start = std::chrono::system_clock::now();
quicksort(arr,0,n-1); // time takes for sorting code
auto end = std::chrono::system_clock::now();
printarr(arr,n);
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
else if (input==2){
	cout<<"time"<<endl;
	auto start = std::chrono::system_clock::now();
quicksort(arr,0,n-1); // time takes for sorting code
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
else
cout<<"wrong input please enter 1 or 2"<<endl;
}

//mergesort time function
void mergesorttime(int *arr, int n){

int input;
cout<<"input 1 for array print and time, or input 2 for just the time"<<endl;
cin>>input;
if (input==1){
cout<<"sorted arrays:"<<endl;
auto start = std::chrono::system_clock::now();
mergesort(arr,0,n-1); // time takes for sorting code
auto end = std::chrono::system_clock::now();
printarr(arr,n);
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
else if (input==2){
	cout<<"time"<<endl;
	auto start = std::chrono::system_clock::now();
mergesort(arr,0,n-1); // time takes for sorting code
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
else
cout<<"wrong input please enter 1 or 2"<<endl;
}
//randomquicksort time fucntion
void randomquicksorttime(int *arr, int n){
int input;
cout<<"input 1 for array print and time, or input 2 for just the time"<<endl;
cin>>input;
if (input==1){
cout<<"sorted arrays:"<<endl;
auto start = std::chrono::system_clock::now();
randomquicsort(arr,0,n-1); // time takes for sorting code
auto end = std::chrono::system_clock::now();
printarr(arr,n);
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
else if (input==2){
	cout<<"time"<<endl;
	auto start = std::chrono::system_clock::now();
randomquicsort(arr,0,n-1); // time takes for sorting code
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
else
cout<<"wrong input please enter 1 or 2"<<endl;
}
//heapsorttime function
void heapsorttime(int *arr, int n){
int input;
cout<<"input 1 for array print and time, or input 2 for just the time"<<endl;
cin>>input;
if (input==1){
cout<<"sorted arrays:"<<endl;
auto start = std::chrono::system_clock::now();
	heapsort(arr,n); //time takes for sorting
	printarr(arr,n);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "finished at " << std::ctime(&end_time)
	<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
else if (input==2){
	cout<<"time"<<endl;
auto start = std::chrono::system_clock::now();
	heapsort(arr,n); //time takes for sorting
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "finished at " << std::ctime(&end_time)
	<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
else
cout<<"wrong input please enter 1 or 2"<<endl;

}
int main(){
int n;
int sortin;
cout<<"how big do you want the array to be?"<<endl;
cin>>n;
int *arr=shuffle(n);
char b;
cout<<"Do you want to print original unsorted array?: (y or n)";
cin>>b;
if(b=='y'){
cout<<"Original unsorted Array"<<endl;
printarr(arr,n);
cout<<endl;
cout<<"Which Sort would you like to use? 1 for quicksort , 2 for randomizedquicksort, 3 for mergesort and 4 for heapsort"<<endl;
cin>>sortin;
switch(sortin){
case 1 :
quicksorttime(arr,n);
break;
case 2 :
randomquicksorttime(arr,n);
break;
case 3 :
mergesorttime(arr,n);
break;
case 4:
heapsorttime(arr,n);
break;
}
}
else if(b=='n'){
cout<<endl;
cout<<"Which Sort would you like to use? 1 for quicksort , 2 for randomizedquicksort, 3 for mergesort and 4 for heapsort"<<endl;
cin>>sortin;
switch(sortin){
case 1 :
quicksorttime(arr,n);
break;
case 2 :
randomquicksorttime(arr,n);
break;
case 3 :
mergesorttime(arr,n);
break;
case 4 :
heapsorttime(arr,n);
break;
}
}
else 
	cout<<"wrong input"<<endl;
return 0;


}