/**
 * @file main.ino
 * @author Henry Faulkner
 * @brief Here's the current plan:
 * We will take in capacitive human-input using the CapacitiveSensor library
 * from multiple input pins to our arduino. Each of those pins will have a
 * tone value associated with it, (note, pitch, velocity, etc. idk).
 * Note: solder onto copper tape
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
#include "MIDIController.h"

// 4 is receiver, 1k ohm resister
// 8 is input, 1m ohm resister (video used 4.4m ohm)
// inactive capacitence = 300-400
// active capacitence = 800-1000
CapacitiveSensor cs_4_8 = CapacitiveSensor(4, 8); // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
MIDIController MC;

void setup()
{
  // cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
}

void loop()
{
  for (int i = 50; i < 70; i++)
  {
    MC.MIDIMessage(MC.GetCommandOn(), i, 100, &Serial);
    delay(100);
    MC.MIDIMessage(MC.GetCommandOff(), i, 100, &Serial);
    delay(200);
  }

  // long start = millis();
  // long total3 = cs_4_8.capacitiveSensor(30);
  // Serial.print(millis() - start); // check on performance in milliseconds
  // Serial.print("\t");
  // Serial.println(total3); // print sensor output 3
  // if(total3 > 400) {
  //   tone(9, 440, 10);
  // }
  // delay(10); // arbitrary delay to limit data to serial port
}
