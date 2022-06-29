//https://www.acmicpc.net/problem/10815
#include <iostream>
using namespace std;
int *sorted;
int *answer;
int arr[500001]; //상근이 숫자카드
int n, m;

void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            sorted[k++] = arr[i++];
        }
        else{
            sorted[k++] = arr[j++];
        }
    }
    if(i > mid){
        for(int q = j; q <= right; q++){
            sorted[k++] = arr[q];
        }
    }
    else{
        for(int w = i; w<= mid; w++){
            sorted[k++] = arr[w];
        }
    }
    for(int x = left; x <=right; x++){
        arr[x] = sorted[x];
    }
}

void merge_sort(int arr[],int left,int right){
	if (left<right){
		int mid = (left+right)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

int search(int key){
    int first = 0;
    int end = n-1;
    int mid = 0;
    int ret = 0;

    while(first <= end){
        mid = (first + end)/2;
        if(key == arr[mid]){
            ret = 1;
            break;
        }
        else{
            if(key < arr[mid]){
                end = mid -1;
            }
            else{
                first = mid + 1;
            }
        }
    }
    return ret;
}

int main(){
    cin >> n;
    sorted = new int[n];

    int arrA[500001] = {0,};//문제의 숫자카드
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;
    answer = new int[m];
    for(int j = 0; j < m; j++){
        cin >> arrA[j];
    }
    merge_sort(arr, 0, n-1);

    for(int k = 0; k < m; k++){
        answer[k] = search(arrA[k]);
    }
    for(int q = 0; q < m; q++){
        cout << answer[q] << " ";
    }
    delete [] sorted;
    delete [] answer;
    return 0;
}
