#include <iostream>
using namespace std;

void counting_stairs(int arr[], int number);
void find_min(int q, int w, int r);

int *arr;
int minimum; //최약체 판별기

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
    int counter = 0; //2가넘어가면 무조건합.
    int max = arr[0]; //일단 1번칸은 무조건 터치하기에.
    //시작은 일단 하고 시작함. 첫번째칸은 무조건 터치
    for(int i = number; i < 3; i--){ //끝에서두칸전까지
        int a, b, c ,d=0; //a b c로 본다.
        //뒤에서부터
        a = arr[i];
        b = arr[i - 1];
        c = arr[i - 2];
        d = arr[i - 3];
        find_min(a,b,c); // 가장 작은 수를 minimum에 저장.
        /*
        나올수 있는 경우의 수
        1번칸이 젤 작은경우
        2번칸이 젤 작은경우
        3번칸이 젤 작은경우
        */
        if(minimum == a && minimum >= d){ //a가 최약체인경우 면서 4번째 친구가 더 작을 경우
            max+=b;
            max+=c;
            continue; //무조건 두번 더했기에 다음계단은 무조건 스킵.
        }
        if(minimum == b){ //a가 최약체인경우 면서 4번째 친구가 더 작을 경우
            max+=a;
            //어짜피 b건너뛰니까 초기화 안해도 ㄱㅊ.
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
    else{ //q / w가 같을경우도 여기 들어감.
        temp = w;
        if(temp < r){
            minimum = temp;
        }
        else{ //temp / r이랑 같을경우도 여기 들어감.
            minimum = r;
        }
    }
}
