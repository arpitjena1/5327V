#include "main.h"
#include "ARMS/config.h"
#include "pros/misc.hpp"

void initialize() {
	arms::init();
	triballcontrol::initialize();
	wings.set_value(false);
}

void disabled() {
}

void competition_initialize() {
}


void autonomous() {
	
	skills();

}

void opcontrol() {

	while (true) {
		if (master.get_digital(DIGITAL_LEFT) && !competition::is_connected())
			autonomous();

		arms::chassis::arcade(master.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
		                      master.get_analog(ANALOG_RIGHT_X) * (double)100 /
		                          127);

		pros::delay(10);



		// control the triball manipulator
        if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
            triballcontrol::fireCata();
           
        } else if (master.get_digital(E_CONTROLLER_DIGITAL_X)) {
            triballcontrol::intake();
        } else if(master.get_digital(E_CONTROLLER_DIGITAL_R1)){
			triballcontrol::intakewithoptical();
		}else if(master.get_digital(E_CONTROLLER_DIGITAL_R1)){
			triballcontrol::outtake();
		}else {
            triballcontrol::stop();
        }


	}
}

//record movement in sd card
//copy text from sd card after run to files here
//run the mapped auton
void otherdriver(){
	while(true){
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
			ofs.open("auto1.txt", std::ofstream::out);
      		int i = 0;

			arms::chassis::arcade(master.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
		                      master.get_analog(ANALOG_RIGHT_X) * (double)100 /
		                          127);
			ofs << "{";
          if(abs(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) > 17 || abs(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)) > 17){ // drive
            ofs << formatToString(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)+master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
            ofs << formatToString(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)-master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
            ofs << formatToString(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)+master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
            ofs << formatToString(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)-master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
        } else {
            ofs << formatToString(0); 
            ofs << formatToString(0);
            ofs << formatToString(0);
            ofs << formatToString(0);
        }

		pros::delay(20);
		i++;
		}
		ofs.close();
	}
}