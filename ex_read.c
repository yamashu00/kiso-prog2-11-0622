#include <stdio.h>
#include <string.h>

typedef struct {
    char  location[32];
    int   temperature;
    float humidity;
} SensorData;

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

            printf("%s : %d°C / %.0f%%\n",
                   data.location, data.temperature, data.humidity);
            count++;
        }
    }
    printf("=== 読み込んだデータ件数: %d 件 ===\n", count);

    fclose(fp);
    fp = NULL;
    return 0;
}
