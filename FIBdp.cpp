#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

long long fib(int n){
	static long long temp[100];
	temp[0] = temp[1] = 1;
	
	if (temp[n] == 0) temp[n] = fib(n-1) + fib(n-2);
	
	return temp[n];
}

int main(){
	int n;cin>>n;
	
	srand(time(0));
	time_t start,end;
	
	start = clock();
	cout<<fib(n);
	end = clock();
	
	cout<<endl;
	double time_taken = double(end - start)/CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << fixed << time_taken*1000 << setprecision(15) << " milisecond " << endl;
}
