/* ex_write.c -- Enshuu 1: Kozo wo CSV ni kakidasu (yaku 10 pun) */
/* 演習①: 構造体を CSV に書き出す（約10分）                       */
/* TODO を埋めてコンパイル・実行してみよう。                       */
/* 今の状態でもコンパイルは通る。実行すると意図しない動作になる。  */

/* ex_write.c -- 演習①: 構造体を CSV に書き出す */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  location[32];
    int   temperature;
    float humidity;
} SensorData;

void writeSensorData(FILE *fp, SensorData data) {
    fprintf(fp, "%s,%d,%.1f\n",
            data.location,
            data.temperature,
            data.humidity);
}

int main(void) {
    FILE *fp = fopen("sensor_ex.csv", "w");
    if (fp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    SensorData records[] = {
        {"実験室", 23, 58.0},
        {"体育館", 31, 75.0},
        {"図書室", 20, 50.0},
        {"職員室", 26, 62.0},
        {"教室", 25, 60.5}
    };

    int n = sizeof(records) / sizeof(records[0]);

    for (int i = 0; i < n; i++) {
        writeSensorData(fp, records[i]);
    }

    fclose(fp);
    fp = NULL;

    printf("sensor_ex.csv に書き込みました（%d 件）\n", n);
    return 0;
}