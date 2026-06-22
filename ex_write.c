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
        {"大講堂", 25, 67.5}
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
