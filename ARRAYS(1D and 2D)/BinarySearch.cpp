#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cin>>size;
    int arr[size];
    for(int i =1; i<=size;i++){
        cin>>arr[i];
    }
    int found =0;
	int loc=-1;
	int beg=1;
	int end=size;
	int item;
	cin>>item;
	while(beg<=end&&loc==-1){
	    int mid=(beg+end)/2;
	    if(arr[mid]==item){
	        loc=mid;
	        cout<<loc<<endl;
	        found=1;
	    }
	    else if(arr[mid]>item){
	        end=mid-1;
	}else if(arr[mid]<item){
	    beg=mid+1;
}}
if(found==1){
    cout<<"element found";
    }else{cout<<"element not found";}
return 0;
}
// binary search doesnt work for some edge cases 
// eg:  size 8
// arr 1 2 2 2 3 3 4 4 
// item 2
// because binary search is based on "mid", and this case breaks that concept as in a sorted array id an element occurs multiple times, the index return should be of first time it occurs.
// but it returns index of the repeated element at mid