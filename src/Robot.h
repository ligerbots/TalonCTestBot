// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveCommand.h"
#include "Commands/DrivePid.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/PickupSubsystem.h"
#include "Subsystems/PneumaticSubsystem.h"
#include "Subsystems/DriveDistanceSubsystem.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"
#include "Subsystems/DriveSubsystem.h"
#include "PowerDistributionPanel.h"

class Robot : public IterativeRobot {
public:
	static OI *oi;
	static Command *driveCommand;
	CommandGroup *autonomousCommand;
	LiveWindow *lw;
//	Encoder* lEncoder;
//	Encoder* rEncoder;
//	AnalogInput* distanceSensor;
//	AnalogInput* colorSensor;

	PowerDistributionPanel* pdp;

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static DriveSubsystem* driveSubsystem;
	static PickupSubsystem* pickupSubsystem;
	static PneumaticSubsystem* pneumaticSubsystem;
	static DriveDistanceSubsystem* driveDistanceSubsystem;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	virtual void UpdateDashboardPeriodic();
};
#endif
