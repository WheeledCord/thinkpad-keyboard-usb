#include <Arduino.h>
#include <Keyboard.h>
#include <Mouse.h>

#define TRACK_DATA 1
#define TRACK_CLK 0
#define TOUCH_DATA 11
#define TOUCH_CLK 12
#define CAPS_LED 2
#define NUM_LED 3
#define BLINK_LED 13
#define HOTKEY 18

const byte rows_max = 17;
const byte cols_max = 8;

int normal[rows_max][cols_max] = {0};
int numlock[rows_max][cols_max] = {0};
int modifier[rows_max][cols_max] = {0};
int media[rows_max][cols_max] = {0};

boolean old_key[rows_max][cols_max] = {0};

int Row_IO[rows_max] = {0};
int Col_IO[cols_max] = {0};

void setup() {
    //gonna init pins and devices
}

void loop() {
    //main scan and USB HID logic
}
