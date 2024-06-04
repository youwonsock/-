#include <iostream>
#include <vector>
using namespace std;

int N, M, B;
int house[500][500];
int t1 = 2, t2 = 1; // ������� : 2��, ��Ͻױ� : 1��
int t = 99999999, line = 99999999; // �ð�, �ִ� ����

int main(int argc, char **argv){ //���Ʈ���� �˰���
    scanf("%d %d %d",&N,&M,&B); // ���� ũ��� ��� ����

    int max = 0, min = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> house[i][j]; // �� �Է� �ޱ�
            if(max < house[i][j]){
                max = house[i][j];
            } else if(min > house[i][j]){
                min = house[i][j];
            } // ���� �ּ�, �ִ밪 ã��
        }
    }

    for(int i=min; i<=max; i++){ // �ش� ���� ����
        int remove = 0; // ��� �ٷ� ���� ���� ����� ���� �����ϴ� ��츦 ������� ���Ѵ�.
        int stack = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(house[j][k] > i){
                    remove += (house[j][k] - i); // ���
                } else if(house[j][k] < i){
                    stack += (i - house[j][k]); // ä���
                }
            }
        }

        if(stack <= remove + B){ // ��Ƴ� ���� ä��� �ͺ��� ���� ��
            int temp = remove * 2 + stack;
            if(t > temp){
                t = temp;
                line = i;
            } else if(t == temp){
                line = i; // i�� ��� �����ϹǷ� ���Ÿ� �����ָ� ��
            }
        }
    }   

    printf("%d %d", t, line); // �ð��� �ִ� ���� ���

    return 0;
}