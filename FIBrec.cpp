#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

long long fib(int n){
	if (n==0) return 1;
	else if (n==1) return 1;
	else return fib(n-1) + fib(n-2);
}

int main(){
	int n;cin>>n;
	
	srand(time(0));
	time_t start,end;
	
	start = clock();
	fib(n);
	end = clock();
	
	cout<<endl;
	double time_taken = double(end - start)/CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << fixed << time_taken*1000 << setprecision(15) << " milisecond " << endl;
}
