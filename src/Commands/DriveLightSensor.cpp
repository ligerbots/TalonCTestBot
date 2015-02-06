// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveLightSensor.h"

DriveLightSensor::DriveLightSensor(int _ticks) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveSubsystem);
	ticks = _ticks;
	currentTime=0;
	isFinished=false;
}

// Called just before this Command runs the first time
void DriveLightSensor::Initialize() {
	SetTimeout(15);  // set 15 second timeout. Good enough?

}

// Called repeatedly when this Command is scheduled to run
void DriveLightSensor::Execute(){
	Robot::driveSubsystem->robotDrive->ArcadeDrive(0,0,true);

	//RobotMap::colorSensor;


}

// Make this return true when this Command no longer needs to run execute()
bool DriveLightSensor::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void DriveLightSensor::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLightSensor::Interrupted() {
	End();
}
