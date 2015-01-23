// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "Commands/Drive.h"
#include <iostream>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
DriveSubsystem* Robot::driveSubsystem = 0;
PickupSubsystem* Robot::pickupSubsystem = 0;
PneumaticSubsystem* Robot::pneumaticSubsystem = 0;
OI* Robot::oi = 0;
int Ticks = 0;
bool Once = false;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveSubsystem = new DriveSubsystem();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	printf("Ligerbots Init\n");

	oi = new OI();
	driveCommand = new Drive();
	//pneumaticSubsystem = new PneumaticSubsystem();
	lw = LiveWindow::GetInstance();

	lEncoder = RobotMap::driveSubsystemLEncoder;
	rEncoder = RobotMap::driveSubsystemREncoder;


	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
	UpdateDashboardPeriodic();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	UpdateDashboardPeriodic();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
	std::cout << "TeleopInit\n";
	driveCommand->Start();
//	pneumaticSubsystem->testSolenoid->InitSolenoid();

	SmartDashboard::PutString("TeleopInit", "Called");
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	driveCommand->Start();
	if (!Once) SmartDashboard::PutString("TeleopPeriodic", "Invoked");
	Once = true;
	UpdateDashboardPeriodic();
	//TODO: move to Drive command
	driveSubsystem->robotDrive->ArcadeDrive(oi->joystick, true);
	SmartDashboard::PutString("TeleopPeriodic", "Invoked");
}

void Robot::TestPeriodic() {
	lw->Run();
}

void Robot::UpdateDashboardPeriodic() {
	// Do this every 1/10th of a second, not more often for efficiency
	if (Ticks++%5==0) {
//		Compressor* wC = RobotMap::workingCompressor;
//		if (NULL!=wC) {
//			SmartDashboard::PutBoolean("CompEnabled", wC->Enabled());
//			SmartDashboard::PutBoolean("CompSwitch", wC->GetPressureSwitchValue());
//			SmartDashboard::PutNumber("CompCurrent", wC->GetCompressorCurrent());
//		}
		Encoder* enc = RobotMap::driveSubsystemREncoder;
		if (NULL!=enc) {
			SmartDashboard::PutNumber("EncoderDistance",enc->GetDistance());
			SmartDashboard::PutNumber("EncoderSpeed",enc->GetRate());
		}
		RobotMap::Ct->UpdateDashboard();

		SmartDashboard::PutNumber("EncoderValueR", rEncoder->GetRaw());
		SmartDashboard::PutNumber("EncoderValueL", lEncoder->GetRaw());

		if (NULL!=RobotMap::distanceSensor) {
			SmartDashboard::PutNumber("DistanceSensorVoltage", RobotMap::distanceSensor->GetVoltage());  // THIS IS THE LINE THAT IS FAILING!!
		} else {
			printf("distanceSensor pointer NULL\n");
		}
	}

}

START_ROBOT_CLASS(Robot);

