// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DrivePid.h"

DrivePid::DrivePid(int _ticks) {
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
void DrivePid::Initialize() {
	SetTimeout(15);  // set 15 second timeout. Good enough?
	double p = 1.0;
	double i = 0.0;
	double d = 0.0;
	double f = 1.0;

	//SO MANY API CALLS AAAAARGH
    RobotMap::driveSubsystemMotorControllerFrontLeft->SetControlMode(CANSpeedController::kPosition);
    RobotMap::driveSubsystemMotorControllerFrontLeft->SetPID(p,i,d);
    RobotMap::driveSubsystemMotorControllerFrontLeft->SetF(f);
    RobotMap::driveSubsystemMotorControllerFrontLeft->ClearIaccum();
    RobotMap::driveSubsystemMotorControllerFrontLeft->SetPosition(0.0);
    RobotMap::driveSubsystemMotorControllerFrontLeft->SetFeedbackDevice(CANTalon::QuadEncoder);
    //RobotMap::driveSubsystemMotorControllerFrontLeft->

    RobotMap::driveSubsystemMotorControllerFrontRight->SetControlMode(CANSpeedController::kPosition);
    RobotMap::driveSubsystemMotorControllerFrontRight->SetPID(p,i,d);
    RobotMap::driveSubsystemMotorControllerFrontRight->SetF(f);
    RobotMap::driveSubsystemMotorControllerFrontRight->ClearIaccum();
    RobotMap::driveSubsystemMotorControllerFrontRight->SetPosition(0.0);
    RobotMap::driveSubsystemMotorControllerFrontRight->SetFeedbackDevice(CANTalon::QuadEncoder);
    //RobotMap::driveSubsystemMotorControllerFrontRight->
}

// Called repeatedly when this Command is scheduled to run
void DrivePid::Execute(){
	RobotMap::driveSubsystemMotorControllerFrontLeft->Set(ticks);
	RobotMap::driveSubsystemMotorControllerFrontRight->Set(ticks);

	double currPos = RobotMap::driveSubsystemMotorControllerFrontLeft->GetPosition();
	double toGo = ticks-currPos;
	if(toGo < 0.02) isFinished=true;

	printf("Executing DrivePid!");
}

// Make this return true when this Command no longer needs to run execute()
bool DrivePid::IsFinished() {
	return isFinished;
}

// Called once after isFinished returns true
void DrivePid::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivePid::Interrupted() {
	End();
}