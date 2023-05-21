#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void generateRandomValue(int *arr, int size, int min, int max) 
{
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int l, int h){
	int pivot = arr[h];
	int i = l-1;
	
	for (int j = l;j < h; j++){
		if (arr[j] <= pivot){
			int temp = 0;
			i++;
		   swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[h]);
	return (i+1);
}

void QuickSort(int arr[],int l, int h){
	if (l < h){
		int m = partition(arr,l,h);
		
		QuickSort(arr,l,m-1);
		QuickSort(arr,m+1,h);
	}
}

int main(){
	int n;cin>>n;
	int arr[n];
	generateRandomValue(arr,n,0,100);
	
	srand(time(0));
	time_t start,end;
	
	start = clock();
	QuickSort(arr,0,n-1);
	end = clock();
	
	cout<<endl;
	double time_taken = double(end - start)/CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << fixed << time_taken*1000 << setprecision(15) << " milisecond " << endl;
}
