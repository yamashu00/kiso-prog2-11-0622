/* task_max.c — 発展：最高気温の場所を探す（約10分）                    */
/* sensor_ex.csv を読み込んで、最も気温が高いレコードを表示する。          */
/* TODO が2箇所あります。                                                */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char location[32];
    int temperature;
    float humidity;
} SensorData;

/* parseSensorLine は完成済み — そのまま使ってよい */
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
    SensorData maxData;
    int found = 0;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (parseSensorLine(line, &data))
        {

            if (found == 0 || data.temperature > maxData.temperature)
            {
                maxData = data;
                found = 1;
            }
        }
    }

    fclose(fp);
    fp = NULL;

    if (found == 1)
    {
        printf("最高気温: %s / %d°C / %.1f%%\n",
               maxData.location,
               maxData.temperature,
               maxData.humidity);
    }
    else
    {
        printf("データがありません\n");
    }

    return 0;
}