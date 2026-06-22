/* debug_quiz.c — バグを3つ直してコンパイル・実行できるようにしよう */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  location[32];
    int   temperature;
    float humidity;
} SensorData;

int main(void) {
    FILE *fp = fopen("sensor.csv", "w");

    /* バグ1: fopen が失敗したときの処理 */
    if (fp == NULL) {
        printf("ファイルを開けませんでした。\n");
        return 1;
    }

    SensorData data = {"教室", 25, 60.5};

    /* バグ2: humidity は float なので %f を使う */
    fprintf(fp, "%s,%d,%.1f\n",
            data.location,
            data.temperature,
            data.humidity);

    /* バグ3: ファイルを閉じる */
    fclose(fp);

    printf("書き込み完了\n");
    return 0;
}