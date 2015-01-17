// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

/*Example bool coding
 * In some constructor:
 * if (freopwijore->Get() == kForward) {
 * 		trackerBool = true
 * 		}
 * else if (fnorgjwirmertun->Get() == kReverse) {
 * 		trackerBool = false
 * 		}
 * else {
 * 		fnaglethgwnoewoqmi->Set(DoubleSolenoid::Value.kReverse)
 * 		trackerBool = false
 * 		}
 *
 * To set given bool(off or on?):
 * if bool {
 * 		ghlepheth->Set(DoubleSolenoid.value.kForward)
 * 		trackerbool = true
 * 		}
 * 	else {
 * 		norlqewngroth->Set(DoubleSolenoid.value.kReverse)
 * 		trackerbool = false
 * 		}
 *
 *
 * To toggle:
 * if trackerbool {
 * 		kermwioore->Set(DoubleSolenoid.value.kReverse)
 * 		trackerbool = false
 * 		OR:
 * 		setSolenoid(false)
 * 		}
 * 	else {
 * 		ekofp->Set(DoubleSolenoid.value.kForward)
 * 		trackerbool = true
 * 		OR:
 * 		setSolenoid(true)
 * 		}
 */


#include "PneumaticSubsystem.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/ToggleSolenoidCommand.h"

PneumaticSubsystem::PneumaticSubsystem() : Subsystem("PneumaticSubsystem") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	testSolenoid = RobotMap::pneumaticSubsystemSolenoid;
	if (testSolenoid->Get() == DoubleSolenoid::kForward) {
		solenoidState = true;
	}
	else if (testSolenoid->Get() == DoubleSolenoid::kReverse) {
		solenoidState = false;
	}
	else {
		testSolenoid->Set(DoubleSolenoid::kReverse);
		solenoidState = false;
	}
}

void PneumaticSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
//	SetDefaultCommand(new ToggleSolenoidCommand());
}

void PneumaticSubsystem::Toggle() {
	SetSolenoidState(!solenoidState);
}

void PneumaticSubsystem::TurnOn() {
	SetSolenoidState(true);
}

void PneumaticSubsystem::TurnOff() {
	SetSolenoidState(false);
}

bool PneumaticSubsystem::GetSolenoidState() {
	return solenoidState;
}

void PneumaticSubsystem::SetSolenoidState(bool state) {
	std::cout << state << std::endl;
	solenoidState = state;
	//testSolenoid->Set(DoubleSolenoid::Value.kOff);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
