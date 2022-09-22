#ifndef MIDIController_H // include guard
#define MIDIController_H
#include <SoftwareSerial.h>

class MIDIController
{
public:
    int GetCommandOn();
    int GetCommandOff();
    void MIDIMessage(int command, int MIDINote, int MIDIVelocity, Stream* serial);
};

#endif
