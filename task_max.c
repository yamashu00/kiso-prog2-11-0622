/* task_max.c — 発展：最高気温の場所を探す（約10分）                    */
/* sensor_ex.csv を読み込んで、最も気温が高いレコードを表示する。          */
/* TODO が2箇所あります。                                                */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  location[32];
    int   temperature;
    float humidity;
} SensorData;

/* parseSensorLine は完成済み — そのまま使ってよい */
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
    SensorData maxData;
    int found = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (parseSensorLine(line, &data)) {

            /* TODO 1: data.temperature が最大かどうか判定して maxData を更新する
             *
             *   考え方:
             *     - まだ1件も処理していないとき（found == 0）は無条件で maxData に入れる
             *     - 2件目以降は「今の data の気温 > これまでの最大気温」なら更新する
             *
             *   使う変数: found, data, maxData
             *   maxData = data;  で構造体をまるごとコピーできる               */

            if(found == 0){
                maxData = data;
                found++;
            }
            else if(maxData.temperature < data.temperature){
                maxData = data;
                found++;
            }

        }
    }

    fclose(fp);
    fp = NULL;

    /* TODO 2: 結果を表示する
     *   found が 1 なら → "最高気温: ○○ / ○○°C / ○○%" を表示
     *   found が 0 なら → "データがありません" を表示                          */
    if(found >= 1){
        printf("最高気温： %s / %d℃ / %.1f%%\n", maxData.location, maxData.temperature, maxData.humidity);
    }
    else{
        printf("データがありません");
    }

    return 0;
}
