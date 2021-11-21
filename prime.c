#include <stdio.h>
#include <string.h>
#define MAX 100000

void removeArray0(int arr[], int size) {
    int new[] = {0};
    int in = 0;
    int len = 0;

    for (int i = 0; i < size; i++) {
        int val = arr[in];
        if (val != 0) {
            printf("[%d] ", len, val);
            new[len] = val;
            len++;
        }
        in++;
    }
    printf("\n");
}

int main() {
    int arr[MAX] = {0};
    int len = 0;
    int slen = 1;

    for (int i = 1; i < MAX +1; i += 1) {
        arr[i-1] = i;
        len++;
        slen++;
    }

    arr[0] = 0; // 1은 소수도, 합성수도 아니다

    for (int i = 0; i < len; i++) {
        int val = arr[i];
        if (val==0) continue; // 0으로 나눌 수는 없다
        int rem = len % val; // 나머지
        int count = len / (val - rem);
        // (소수계산 안한 몫) = (대상) / {(나눌 수) - (나머지)}
        for (int l = 2; l < count +1; l++) {
            int mul = val * l;
            if (mul <= MAX) {
                printf("Removed %d, because %d, arr is %d\n", mul, val, arr[mul-1]);
                arr[mul - 1] = 0;
            }
        }
    }

    removeArray0(arr, MAX);

    return 0;
}
