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
#include <iostream>
#include "Commands/DriveCommand.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
DriveSubsystem* Robot::driveSubsystem = 0;
PickupSubsystem* Robot::pickupSubsystem = 0;
PneumaticSubsystem* Robot::pneumaticSubsystem = 0;
DriveDistanceSubsystem* Robot::driveDistanceSubsystem = 0;
Command* Robot::driveCommand = 0;

OI* Robot::oi = 0;
int Ticks = 0;
bool Once = false;
double lastBusVoltage = 0.0;
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

	pneumaticSubsystem = new PneumaticSubsystem();
	oi = new OI();
	driveCommand = new DriveCommand();
	lw = LiveWindow::GetInstance();

	pdp = new PowerDistributionPanel();
	pdp->UpdateTable();
	printf("PDP voltage %f, engergy %f.\n",
		   pdp->GetVoltage(), pdp->GetTotalEnergy());


//	lEncoder = RobotMap::driveSubsystemLEncoder;
//	rEncoder = RobotMap::driveSubsystemREncoder;
//
//	colorSensor = new AnalogInput(1);


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
	// Reset the Talons to default modes
    RobotMap::driveFrontLeft->SetControlMode(CANSpeedController::kPercentVbus);
    RobotMap::driveFrontRight->SetControlMode(CANSpeedController::kPercentVbus);

	driveCommand->Start();
//	pneumaticSubsystem->testSolenoid->InitSolenoid();

	SmartDashboard::PutString("TeleopInit", "Called");
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
//	driveCommand->Start();
	if (!Once) SmartDashboard::PutString("TeleopPeriodic", "Invoked");
	Once = true;
	UpdateDashboardPeriodic();
	//TODO: move to Drive command
	SmartDashboard::PutString("TeleopPeriodic", "Invoked");
}

void Robot::TestPeriodic() {
	lw->Run();
}

void Robot::UpdateDashboardPeriodic() {
	// Do this every 1/10th of a second, not more often for efficiency
	if (Ticks++%2==0) {
//		Compressor* wC = RobotMap::workingCompressor;
//		if (NULL!=wC) {
//			SmartDashboard::PutBoolean("CompEnabled", wC->Enabled());
//			SmartDashboard::PutBoolean("CompSwitch", wC->GetPressureSwitchValue());
//			SmartDashboard::PutNumber("CompCurrent", wC->GetCompressorCurrent());
//		}
		CANTalon* canEncr = RobotMap::driveFrontRight;
		CANTalon* canEncl = RobotMap::driveFrontLeft;
		Encoder* enc = RobotMap::driveSubsystemLEncoder;
		if (NULL!=enc) {
			SmartDashboard::PutNumber("LEncoderSpeed",canEncl->GetSpeed());
			SmartDashboard::PutNumber("LEncoderPosition",canEncl->GetEncPosition());
			SmartDashboard::PutNumber("LEncoder Raw",enc->GetDistance());
		}
		enc = RobotMap::driveSubsystemREncoder;
		if (NULL!=enc) {
			SmartDashboard::PutNumber("REncoderSpeed",canEncr->GetSpeed());
			SmartDashboard::PutNumber("REncoderPosition",canEncr->GetEncPosition());
			SmartDashboard::PutNumber("REncoder Raw",enc->GetDistance());

		}
		SmartDashboard::PutNumber("CAN Front Left Fault", RobotMap::driveFrontLeft->GetFaults());
		double busVoltage = RobotMap::driveFrontLeft->GetBusVoltage();
		if (fabs(busVoltage-lastBusVoltage > 0.15)) {
			SmartDashboard::PutNumber("Bus Voltage", busVoltage);
			lastBusVoltage = busVoltage;
		}
		SmartDashboard::PutNumber("PID Error R", RobotMap::driveFrontRight->GetClosedLoopError());
		SmartDashboard::PutNumber("PID Error L", RobotMap::driveFrontLeft->GetClosedLoopError());

		RobotMap::Ct->UpdateDashboard();

//		if (NULL!=RobotMap::distanceSensor) {
//			SmartDashboard::PutNumber("DistanceSensorVoltage", RobotMap::distanceSensor->GetVoltage());  // THIS IS THE LINE THAT IS FAILING!!
//		} else {
//			printf("distanceSensor pointer NULL\n");
		}
		if (NULL!=RobotMap::colorSensor) {
			SmartDashboard::PutNumber("ColorSensorVoltage", RobotMap::colorSensor->Get());  // THIS IS THE LINE THAT IS FAILING!!
		} else {
			printf("colorSensor pointer NULL\n");
		}

		// Debugging Talons in Follower mode
		// They're not giving voltage or current readings, so check the PDP
		pdp->UpdateTable();
		//SmartDashboard::PutNumber("PDP Amps Talons 1 and 2", pdp->GetCurrent(0));
		//SmartDashboard::PutNumber("PDP Amps Talons 3 and 4", pdp->GetCurrent(2));
		//SmartDashboard::PutNumber("Total Watts", pdp->GetTotalPower());


}

START_ROBOT_CLASS(Robot);
