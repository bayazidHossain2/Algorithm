#include<iostream>
using namespace std;
int nn = 0;
void swap_(int &num1,int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void print(int arr[],int l,int r){
    while(l<r){
        cout<<arr[l]<<' ';
        l++;
    }cout<<endl;
}
int paertition(int arr[],int l,int r){
    int last_minimum_index = l;
    //cout<<"pevot = "<<arr[l]<<endl;
    for(int i = l+1;i<r;i++){
        nn++;
        //cout<<arr[i]<<endl;
        if(arr[l]>arr[i]){
            if(last_minimum_index+1 != i){
                swap_(arr[last_minimum_index+1],arr[i]);
            }last_minimum_index++;
        }//print(arr,l,r);
    }swap_(arr[last_minimum_index],arr[l]);
    //print(arr,l,r);
    return last_minimum_index;
}
void quick_sort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int pivot = paertition(arr,l,r);
    quick_sort(arr,l,pivot);
    quick_sort(arr,pivot+1,r);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n);
    print(arr,0,n);
    cout<<nn<<endl;
}
