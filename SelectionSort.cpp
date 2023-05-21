#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateRandomValue(int *arr, int size, int min, int max) 
{
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void SelectionSort(int arr[], int n){
	int temp = 0,temp2 = 0;
	
	for (int i=0;i<n;i++){
		temp = i;
		temp2 = arr[i];
		for (int j=i;j<n;j++){
			if (arr[j] < temp2){
				temp2 = arr[j];
				temp = j;
			}
		}
		arr[temp] = arr[i];
		arr[i] = temp2;
	}
}

int main(){
	int n;cin>>n;
	int arr[n];
	generateRandomValue(arr,n,1,100);
	
	srand(time(0));
	clock_t start,end;
	
	start = clock();
	SelectionSort(arr,n);
	end = clock();
	
	cout<<endl;
	double time_taken = double(end - start)/CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << fixed << time_taken*1000 << setprecision(15) << " milisecond " << endl;
}
