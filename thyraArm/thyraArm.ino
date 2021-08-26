/*
*      Continous Example Sketch!
*
* This example demonstrates how the library can be used to make the motorrun continously,
* in both directions and making it stop an ongoing movement.
* For more information, check out the documentation:
* http://ustepper.com/docs/usteppers/html/index.html
*/
#include <uStepperS.h>

uStepperS stepper;

void setup() {
  // put your setup code here, to run once:
  stepper.setup();
  stepper.checkOrientation(30.0);       //Check orientation of motor connector with +/- 30 microsteps movement
  stepper.setCurrent(50);
  Serial.begin(9600);
  //stepper.setRPM(20);
}

void loop() {
  //stepper.setRPM(20);
  stepper.moveToAngle(-90);
  while(stepper.getMotorState(POSITION_REACHED) == 1){
    Serial.println(stepper.angleMoved());
  }
  stepper.moveToAngle(-45);
  while(stepper.getMotorState(POSITION_REACHED) == 1){
    Serial.println(stepper.getMotorState(POSITION_REACHED));
  }

}
