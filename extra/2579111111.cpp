#include <iostream>
using namespace std;

void counting_stairs(int arr[], int number);
void find_min(int q, int w, int r);

int *arr;
int minimum; //�־�ü �Ǻ���

int main(){
    int n;//number of stairs
    cout<<"enter how many stairs";
    cin>>n;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        cout<<"\nenter " << i <<"stair point\n";
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        cout<<" | "<<arr[i]<<" | ";
    }
    counting_stairs(arr, n);
    delete[] arr;
    return 0;
}

void couning_stairs(int arr[], int number){
    int counter = 0; //2���Ѿ�� ��������.
    int max = arr[0]; //�ϴ� 1��ĭ�� ������ ��ġ�ϱ⿡.
    //������ �ϴ� �ϰ� ������. ù��°ĭ�� ������ ��ġ
    for(int i = number; i < 3; i--){ //��������ĭ������
        int a, b, c ,d=0; //a b c�� ����.
        //�ڿ�������
        a = arr[i];
        b = arr[i - 1];
        c = arr[i - 2];
        d = arr[i - 3];
        find_min(a,b,c); // ���� ���� ���� minimum�� ����.
        /*
        ���ü� �ִ� ����� ��
        1��ĭ�� �� �������
        2��ĭ�� �� �������
        3��ĭ�� �� �������
        */
        if(minimum == a && minimum >= d){ //a�� �־�ü�ΰ�� �鼭 4��° ģ���� �� ���� ���
            max+=b;
            max+=c;
            continue; //������ �ι� ���߱⿡ ��������� ������ ��ŵ.
        }
        if(minimum == b){ //a�� �־�ü�ΰ�� �鼭 4��° ģ���� �� ���� ���
            max+=a;
            //��¥�� b�ǳʶٴϱ� �ʱ�ȭ ���ص� ����.
            max+=c;
            counter++;
        }
        if(minimum == c){
            max+=a;
            max+=b;
        }
    }
}

void find_min(int q, int w, int r){
    int temp =0;
    if(q<w){
        temp = q;
        if(temp < r){
            minimum = temp;
        }
        else{
            minimum = r;
        }
    }
    else{ //q / w�� ������쵵 ���� ��.
        temp = w;
        if(temp < r){
            minimum = temp;
        }
        else{ //temp / r�̶� ������쵵 ���� ��.
            minimum = r;
        }
    }
}
