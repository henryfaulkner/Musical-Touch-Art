/**
 * @file main.ino
 * @author Henry Faulkner
 * @brief Here's the current plan:
 * We will take in capacitive human-input using the CapacitiveSensor library
 * from multiple input pins to our arduino. Each of those pins will have a
 * tone value associated with it, (note, pitch, velocity, etc. idk).
 *
 * Once a capasitive threshhold is passed (1000> [number could use refining]),
 * the arduino will send MIDI signal to a Libre computer board, hosting LMMS DAW,
 * producing the desired sound through auxilary speakers.
 * @version 0.1
 * @date 2022-09-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <CapacitiveSensor.h>

void setup()
{
}

void loop()
{
}
