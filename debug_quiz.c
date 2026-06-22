#include <stdio.h>
#include <string.h>

typedef struct {
    char  location[32];
    int   temperature;
    float humidity;
} SensorData;

int main(void) {
    FILE *fp = fopen("sensor.csv", "w");
    if (fp == NULL){
        printf("ファイルを開くことができませんでした");
        return 1;
    }

    SensorData data = {"教室", 25, 60.5};

    fprintf(fp, "%s,%d,%0.1f\n", data.location, data.temperature, data.humidity);

    fclose(fp);

    printf("書き込み完了\n");
    return 0;
}
