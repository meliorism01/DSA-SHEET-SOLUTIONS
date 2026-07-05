#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> arr[n];
	for(int i=0; i< n; i++){
	    cin>>arr[i];
	}
	int min = INT_MAX;
    int max = INT_MIN;
    for(int i=0; i< n; i++){
        if(min>arr[i]){
            min=arr[i];
        }
        if(max<arr[i]){
            max=arr[i];
        }
    }
    cout<<max<<min;
}