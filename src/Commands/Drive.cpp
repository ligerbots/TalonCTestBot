// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drive.h"

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveSubsystem);
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	if (RobotMap::distanceSensor->GetVoltage() <= 0.6) {
//		On an XBox controller, RawAxis4 is the X axis of the right stick
//		We will use this for the left/right control only
//		Drive(a,b) where a is the magnitude and b is the curve of it
		int y = Robot::oi->joystick->GetY();
		int x = Robot::oi->joystick->GetRawAxis(4);
		Robot::driveSubsystem->robotDrive->Drive(y,x);
//		Robot::driveSubsystem->robotDrive->ArcadeDrive(Robot::oi->joystick, true);
	}
	else if (RobotMap::distanceSensor->GetVoltage() >0.6) {
		Robot::driveSubsystem->robotDrive->ArcadeDrive(0,0,true);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
