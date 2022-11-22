///////////////////////////////////////////////////////////////////////////////
// Circuit Playground Bike Light - The All Of Them
//
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>

// Define 10 colors here.
// Must be 10 entries.
// Use 0x000000 if you want a blank space.
uint32_t candycane[] = {
    0xFF0000,
    0xFF0000,
    0xFF0000,
    0xFFFFFF,
    0xFFFFFF,
    0xFF0000,
    0xFF0000,
    0xFF0000,
    0xFFFFFF,
    0xFFFFFF};

int startIndex, colorIndex;
///////////////////////////////////////////////////////////////////////////////
void setup()
{
    CircuitPlayground.begin();

    // Make it bright!
    CircuitPlayground.setBrightness(192);

    colorIndex = 0;
    startIndex = 0;
}
///////////////////////////////////////////////////////////////////////////////
void loop()
{
    // Loop through and set pixels
    colorIndex = startIndex;
    for (int pixel = 0; pixel < 10; pixel++)
    {
        CircuitPlayground.setPixelColor(pixel, candycane[colorIndex]);
        colorIndex++;
        if (colorIndex > 9)
            colorIndex = 0;
    }

    // Increment start index into color array
    startIndex++;

    // Check value and reset if necessary
    if (startIndex > 9)
        startIndex = 0;

    // Wait a little bit so we don't spin too fast
    delay(300);
}