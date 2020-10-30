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
int partition(int arr[],int l,int r){
    int lmi = l;
    int pivot = l+(rand()%(r-l));
    //cout<<"pivot = "<<pivot<<' '<<arr[pivot]<<endl;
    for(int i = pivot+1;i<r;i++){
        nn++;
        if(arr[i]<=arr[pivot]){
            int temp = arr[pivot];
            arr[pivot] = arr[i];
            arr[i] = arr[pivot+1];
            arr[pivot+1] = temp;
            pivot++;
        }
    }
    for(int i=pivot-1;i>=l;i--){
        nn++;
        if(arr[i]>arr[pivot]){
            int temp = arr[pivot];
            arr[pivot] = arr[i];
            arr[i] = arr[pivot-1];
            arr[pivot-1] = temp;
            pivot--;
        }
    }return pivot;
}
void quick_sort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int pivot = partition(arr,l,r);
    //cout<<"your pivot = "<<pivot<<' '<<arr[pivot]<<endl;
    quick_sort(arr,l,pivot);
    quick_sort(arr,pivot+1,r);
}
int main(){
    int arr[]={5,2,3,7,4,2,8,1,0,0};
    int arr2[]={0,1,2,3,4,5,6,7,8,9};
    int arr3[]={1,2,3,0,1,0,1,2,2,0};
    print(arr3,0,10);
    quick_sort(arr3,0,10);
    print(arr3,0,10);
    cout<<nn<<endl;
    /*int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n);
    print(arr,0,n);*/
    return 0;
}

