#include "autons.hpp"


void skills(){
    using namespace arms::chassis;

	//fire cata for 44 triballs
	intakepist.set_value(true);
	for (int i; i < 44; i += 1) {
		triballcontrol::fireCata;
        pros::delay(10);
    }
	move({{-80, 0}}, 100, arms::NONE); //move through barrier
	move({{-70, 30, -180}}, 70, arms::REVERSE );//follow L shape barrier until get to middle- tune
	
	move({{-100, 30, -180}}, 100, arms::NONE | arms::ASYNC); //bash first layer of triballs
	wings.set_value(true);
	waitUntilFinished(2);

	move({{-70, 30, -180}}, 100, arms::NONE); //come back from first bash
	wings.set_value(false);

	turn({{-70,50}},arms::NONE);//turn

	move({{-70, 50, -150}}, 50, arms::NONE); //swing into second bash from the side
	
	move({{-90, 30, -180}}, 40, arms::NONE| arms::ASYNC); //roll triballs near goal
	wings.set_value(true);
	waitUntilFinished(2);

	//bash movement
	move({{-80, 30, -180}}, 100, arms::NONE); 
	move({{-100, 30, -180}}, 100, arms::NONE);

	//go to the side and bash triballs
	move({{-80, -10, -80}}, 100, arms::NONE);
	move({{-80, -30, -80}}, 100, arms::ASYNC | arms::NONE);
	wings.set_value(true);
	waitUntilFinished(2);
	
}


void leftsidehalfawp(){
    using namespace arms::chassis;

    //grab triball
    triballcontrol::intakewithoptical();
    intakepist.set_value(true);
    pros::delay(1000);

    //grab and come back
    move({{-50, 0, -45}}, 100, arms::REVERSE | arms::ASYNC);
    intakepist.set_value(false);
    waitUntilFinished(2);

    
    



}