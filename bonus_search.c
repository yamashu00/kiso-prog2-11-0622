// 自分の名前: 木村優太

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int answer, guess, count = 1;

    srand(time(NULL));
    printf("起動しました。\n");
    answer = rand()%1000 + 1;
    printf("正解を設定しました。\n");
    printf("予想を入力してください: ");
    scanf("%d", &guess);
    
    while (guess != answer) {
        if (guess < 1 || guess > 1000) {
            printf("1から1000の範囲で予想してください。\n");
        } else if (guess < answer) {
            printf("大きい\n");
        } else {
            printf("小さい\n");
        }
        count++;
        printf("予想を入力してください: ");
        scanf("%d", &guess);
    }

    printf("正解 %d回で当てました\n", count);
    return 0;
}

//理論的に、中央を予想することが一番効率的で、log2(1000)より、10回以内に当てられるはず。