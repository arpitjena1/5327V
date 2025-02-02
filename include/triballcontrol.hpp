#pragma once
#include "main.h"
#include "lemlib/pid.hpp"

namespace triballcontrol {
enum Mode {
    SwitchToCata = 0,
    Firing = 3,
    Loading = 4,
    Stop = 5,
    Intaking = 6,
    IntakingWithOptical = 7,
    outtaking = 8,
    outtakingwithoptical = 9,
    Idle = 10
};

void initialize();
void fireCata();
void intake();
void intakewithoptical();
void outtake();
void outtakewithoptical();
void stop();
Mode getMode();
}; // namespace discControl