#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void generateRandomValue(int *arr, int size, int min, int max) 
{
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void MergeSorted(int arr[],int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1],R[n2];
	
	for (int i = 0;i < n1; i++)L[i] = arr[l+i];
	for (int i = 0;i < n2; i++)R[i] = arr[m+1+i];
	
	int li,ri,i;
	li = 0;ri = 0;i = l;
	
	while (li < n1 && ri < n2){
		if (L[li] <= R[ri]){
			arr[i] = L[li];
			li++;
		} else {
			arr[i] = R[ri];
			ri++;
		}
		i++;
	}
	
	while (li < n1){
		arr[i] = L[li];
		li++;
		i++;
	}
	
	while (ri < n2){
		arr[i] = R[ri];
		ri++;
		i++;
	}
}

void MergeSort(int arr[],int l, int r){
	if (l < r){
		int m = l + (r-l)/2;
		
		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);
		
		MergeSorted(arr,l,m,r);
	}
}

int main(){
	int n;cin>>n;
	int arr[n];
	generateRandomValue(arr,n,1,100);
	
	srand(time(0));
	clock_t start,end;
	
	start = clock();
	MergeSort(arr,0,n);
	end = clock();
	
	cout<<endl;
	double time_taken = double(end - start)/CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << fixed << time_taken*1000 << setprecision(15) << " milisecond " << endl;
}
