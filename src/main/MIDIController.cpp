#include "MIDIController.h"

/**
 * @brief
 * https://www.instructables.com/Send-and-Receive-MIDI-with-Arduino/
 * https://www.instructables.com/What-is-MIDI/
 * https://www.makeuseof/tag/make-midi-controller-arduino
 */

// higher velocity might make the instrument louder

/**
 * @brief 10010000 in binary, command on
 * 
 * @return int 
 */
int MIDIController::GetCommandOn() {
    return 144;
}

/**
 * @brief 10000000 in binary, command off
 * 
 * @return int 
 */
int MIDIController::GetCommandOff() {
    return 128;
}

void MIDIController::MIDIMessage(int command, int MIDINote, int MIDIVelocity, Stream* serial) 
{
    serial->write(command); // send on or off command
    serial->write(MIDINote); // send pitch data
    serial->write(MIDIVelocity); // send velocity data
}
