/* ex_read.c -- 演習②: CSV を読んで集計する（約10分）          */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char location[32];
    int temperature;
    float humidity;
} SensorData;

/*
 * parseSensorLine: CSV の1行を SensorData 構造体に変換する。
 * 成功したら 1、失敗したら 0 を返す
 */
int parseSensorLine(const char *line, SensorData *out)
{
    return sscanf(line, "%31[^,],%d,%f",
                  out->location,
                  &out->temperature,
                  &out->humidity) == 3;
}

int main(void)
{
    FILE *fp = fopen("sensor_ex.csv", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "sensor_ex.csv が見つかりません（先に ex_write を実行してください）\n");
        return 1;
    }

    char line[256];
    SensorData data;
    int count = 0;

    printf("=== sensor_ex.csv の内容 ===\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (parseSensorLine(line, &data))
        {

            printf("%s: %dC / %.1f%%\n",
                   data.location,
                   data.temperature,
                   data.humidity);

            count++;
        }
    }

    printf("合計: %d 件\n", count);

    fclose(fp);
    fp = NULL;
    return 0;
}