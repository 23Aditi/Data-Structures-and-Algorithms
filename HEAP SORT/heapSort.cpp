//heap sort
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& arr){
	for(int i = 0 ; i < arr.size() ; i++){
		cout << "\033[93m" << arr[i] << "\033[0m , ";
	}
	cout << "\n";
}

void heapify(vector<int>& arr,int n,int i){
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	cout <<"\033[31m  left :" <<left << " right : " << right << " largest : " << largest <<"\033[0m\n";

	
	if(left < n && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < n && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != i){
		cout << "\033[32m new largest : " << largest << "\033[0m" << endl; 
		swap(arr[i],arr[largest]);
		cout << "\033[33m arr after swap \n \033[0m";
		print(arr);
		heapify(arr,n,largest);	
	}
}


void heapSort(vector<int>& arr){
	int n = arr.size();

	for(int i = (n/2) -1 ; i >=0 ; i--){
		heapify(arr,n,i);
	}
	cout << "print after first heapify" << endl;
	print(arr);
	for(int i = n-1 ; i > 0 ; i--){	
		swap(arr[0],arr[i]);

	cout << "\033[32m arr after swap with index " << i << endl;
	print(arr);

	heapify(arr,i,0);
	cout << "\033[33m post swap heapify with index " << i << endl;
	print(arr);
	}
	
	cout << "\033[34marr after second heapify" <<"\033[0m" <<endl;
	print(arr);
}



int main(){
	vector<int> arr = {14,56,7,13,87,32};
	
	cout << "\033[32m \t Original Array : \033[0m "<<endl;
	print(arr);
	int n = arr.size();
	for(int i = (n/2) -1 ; i >=0 ; i--){
		cout << "\033[34m i = " << i <<"\033[0m \n"<< endl;
		heapify(arr,n,i);
	}
	//heapSort(arr);
	//cout << "Sorted array : \n";
	//print(arr);	 
	return 0;
}





