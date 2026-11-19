#include <stdio.h>

union Sensor {
    double temperature[3];
    float  humidity[3];
    int    pressure[3];
};

int main() {
    union Sensor s;
    int mode, i;
    int size_temp, size_hum, size_press, size_union, size_struct, diff;

    printf("Select mode (1-Temperature, 2-Humidity, 3-Pressure): ");
    scanf("%d", &mode);

    if (mode == 1) {
        printf("Enter 3 temperature readings: ");
        for (i = 0; i < 3; i++)
            scanf("%lf", &s.temperature[i]);

        printf("Temperature readings: ");
        for (i = 0; i < 3; i++)
            printf("%.1f ", s.temperature[i]);
    }
    else if (mode == 2) {
        printf("Enter 3 humidity readings: ");
        for (i = 0; i < 3; i++)
            scanf("%f", &s.humidity[i]);

        printf("Humidity readings: ");
        for (i = 0; i < 3; i++)
            printf("%.1f ", s.humidity[i]);
    }
    else if (mode == 3) {
        printf("Enter 3 pressure readings: ");
        for (i = 0; i < 3; i++)
            scanf("%d", &s.pressure[i]);

        printf("Pressure readings: ");
        for (i = 0; i < 3; i++)
            printf("%d ", s.pressure[i]);
    }
    else {
        printf("Invalid mode");
    }

    /* size calculation by math */
    size_temp  = 3 * sizeof(double);
    size_hum   = 3 * sizeof(float);
    size_press = 3 * sizeof(int);

    size_union  = sizeof(union Sensor);               /* largest member */
    size_struct = size_temp + size_hum + size_press;  /* sum of all members */
    diff        = size_struct - size_union;

    printf("\n\nTemperature array = %d bytes\n", size_temp);
    printf("Humidity array    = %d bytes\n", size_hum);
    printf("Pressure array    = %d bytes\n", size_press);
    printf("Size of union     = %d bytes\n", size_union);
    printf("Size if structure = %d bytes\n", size_struct);
    printf("Difference        = %d bytes\n", diff);

    return 0;
}
