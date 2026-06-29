/* ex_read.c -- 演習②: CSV を読んで集計する（約10分）          */
/* TODO を埋めてコンパイル・実行してみよう。                     */
/* 今の状態でもコンパイルは通る。実行しても表示が不完全になる。  */
/* 事前に ex_write を実行して sensor_ex.csv を作成しておくこと   */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  location[32];
    int   temperature;
    float humidity;
} SensorData;

/*
 * parseSensorLine: CSV の1行を SensorData 構造体に変換する。
 * 成功したら 1、失敗したら 0 を返す。（実装済み、そのまま使う）
 */
int parseSensorLine(const char *line, SensorData *out) {
    return sscanf(line, "%31[^,],%d,%f",
                  out->location,
                  &out->temperature,
                  &out->humidity) == 3;
}

int main(void) {
    FILE *fp = fopen("sensor_ex.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "sensor_ex.csv が見つかりません（先に ex_write を実行してください）\n");
        return 1;
    }

    char line[256];
    SensorData data;
    int count = 0;

    printf("=== sensor_ex.csv の内容 ===\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (parseSensorLine(line, &data)) {

            /*
             * TODO 1: この printf を正しい表示に直す。
             *
             *   表示したい例:  実験室: 23C / 58.0%
             *
             *   フォーマット文字列: "%s: %dC / %.1f%%\n"
             *     %s    -> 文字列
             *     %d    -> 整数
             *     %.1f  -> 小数点1桁の実数
             *     %%    -> % を1文字表示するためのエスケープ
             *
             *   引数: data.location, data.temperature, data.humidity
             */
            printf("場所: %s / 気温: %d°C / 湿度: %.1f%%\n", data.location,data.temperature,
            data.humidity); /* TODO 1: この行を直す */

            count++;
        }
    }

    /*
     * TODO 2: ループが終わったら合計件数を表示する。
     *   表示したい例: "合計: 5 件"
     *   変数 count に読み込んだ件数が入っている。
     *   printf と count を使って1行書く。
     */
    /* TODO 2: ここに printf を1行書く */
    printf("合計: %d 件\n", count);
    fclose(fp);
    fp = NULL;
    return 0;
}
