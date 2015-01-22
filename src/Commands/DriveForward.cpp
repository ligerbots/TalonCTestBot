// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveForward.h"

DriveForward::DriveForward(int _ticks) {
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
void DriveForward::Initialize() {
	SetTimeout(15);  // set 15 second timeout. Good enough?
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute(){
	Robot::driveSubsystem->robotDrive->ArcadeDrive(1.0,0.0,false);
	//todo: get encoder
	currentTime++;
	if(currentTime > ticks){
		isFinished=true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return isFinished;
}

// Called once after isFinished returns true
void DriveForward::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {
	End();
}
