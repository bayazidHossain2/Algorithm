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
pair<int,int> partition(int arr[],int l,int r){
    int lmi = l;
    int pivot1 = l+(rand()%(r-l));
    int pivot2 = pivot1;
    for(int i = pivot1+1;i<r;i++){
        nn++;
        if(arr[i] == arr[pivot1]){
            int temp = arr[pivot1+1];
            arr[pivot1+1] = arr[i];
            arr[i] = temp;
            pivot1++;
        }else if(arr[i]<arr[pivot1]){
            int temp = arr[pivot2];
            arr[pivot2] = arr[i];
            arr[i] = arr[pivot1+1];
            arr[pivot1+1] = temp;
            pivot1++;
            pivot2++;
        }
    }
    for(int i=pivot2-1;i>=l;i--){
        nn++;
        if(arr[i] == arr[pivot1]){
            int temp = arr[i];
            arr[i] = arr[pivot2-1];
            arr[pivot2-1] = temp;
            pivot2--;
        }
        else if(arr[i]>arr[pivot1]){
            int temp = arr[pivot1];
            arr[pivot1] = arr[i];
            arr[i] = arr[pivot2-1];
            arr[pivot2-1] = temp;
            pivot1--;
            pivot2--;
        }
    }return make_pair(pivot2,pivot1);
}
void quick_sort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    pair<int,int> pivot = partition(arr,l,r);
    quick_sort(arr,l,pivot.first);
    quick_sort(arr,pivot.second+1,r);
}
int main(){/*
    int arr[]={5,2,3,7,4,2,8,1,0,0};
    int arr2[]={0,1,2,3,4,5,6,7,8,9};
    int arr3[]={1,2,3,0,1,0,1,2,2,0};
    print(arr,0,10);
    quick_sort(arr,0,10);
    print(arr,0,10);
    cout<<nn<<endl;*/
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n);
    print(arr,0,n);
    return 0;
}


