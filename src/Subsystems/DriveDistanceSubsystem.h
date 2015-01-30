/*
 * DriveDistanceSubsystem.h
 *
 *  Created on: Jan 30, 2015
 *      Author: Ligerbots
 */

#ifndef DRIVEDISTANCESUBSYSTEM_H
#define DRIVEDISTANCESUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveDistanceSubsystem: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SpeedController* lFront;
	SpeedController* lBack;
	SpeedController* rFront;
	SpeedController* rBack;
	RobotDrive* robotDrive;
	Encoder* lEncoder;
	Encoder* rEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DriveDistanceSubsystem();
	void InitDefaultCommand();
	void DriveDistance();
};



#endif /* SRC_SUBSYSTEMS_DRIVEDISTANCESUBSYSTEM_H_ */
