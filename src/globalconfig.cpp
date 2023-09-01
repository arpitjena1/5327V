#include "globalconfig.hpp"


pros::Rotation cataRot(19);
pros::Motor cata(7,true);
pros::Motor intake(8);
pros::Optical optical(13);
pros::Controller master(CONTROLLER_MASTER);
pros::ADIDigitalOut wings('D');
pros::ADIDigitalOut intakepist('F');


pros::Motor lb(-15,  pros::E_MOTOR_GEARSET_06);
pros::Motor lM(-1,  pros::E_MOTOR_GEARSET_06);
pros::Motor lF(-2,  pros::E_MOTOR_GEARSET_06);
pros::Motor rB(4,  pros::E_MOTOR_GEARSET_06);
pros::Motor rM(5,  pros::E_MOTOR_GEARSET_06);
pros::Motor rF(6,  pros::E_MOTOR_GEARSET_06);
