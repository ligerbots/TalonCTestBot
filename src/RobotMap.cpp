// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANTalon* RobotMap::driveSubsystemMotorControllerFrontLeft = NULL;
CANTalon* RobotMap::driveSubsystemMotorControlleFrontRight = NULL;
CANTalon* RobotMap::driveSubsystemMotorControllerBackLeft = NULL;
CANTalon* RobotMap::driveSubsystemMotorControllerBackRight = NULL;
CANTalon* RobotMap::pickupMotorMain = NULL;
CANTalon* RobotMap::pickupMotorFollower = NULL;
RobotDrive* RobotMap::robotDrive = NULL;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
DoubleSolenoid* RobotMap::pneumaticSubsystemSolenoid = NULL;
//Compressor* RobotMap::workingCompressor = NULL;
CANTalons* RobotMap::Ct = NULL;
Encoder* RobotMap::driveSubsystemLEncoder = NULL;
Encoder* RobotMap::driveSubsystemREncoder = NULL;
AnalogInput* RobotMap::distanceSensor = NULL;
AnalogInput* RobotMap::colorSensor = NULL;


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// Front Talons:  1=right  3=left
	// Back  Talons:  2=right  4=left
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	//LiveWindow* lw = LiveWindow::GetInstance();
	Ct = new CANTalons();

	driveSubsystemMotorControllerFrontLeft = Ct->Init(3, (char *)"FrontLeft");
	//lw->AddActuator("DriveSubsystem", "motorControllerFrontLeft", (CANTalon*) driveSubsystemmotorControllerFrontLeft);
	driveSubsystemMotorControlleFrontRight =  Ct->Init(1, (char *)"FrontRight");
	//lw->AddActuator("DriveSubsystem", "motorControlleFrontRight", (CANTalon*) driveSubsystemmotorControlleFrontRight);
	driveSubsystemMotorControllerBackLeft  =  Ct->Init(4, (char *)"BackLeft");
	//lw->AddActuator("DriveSubsystem", "motorControllerBackLeft", (CANTalon*) driveSubsystemmotorControllerBackLeft);
	driveSubsystemMotorControllerBackRight =  Ct->Init(2, (char *)"BackRight");
	//lw->AddActuator("DriveSubsystem", "motorControllerBackRight", (CANTalon*) driveSubsystemmotorControllerBackRight);

	robotDrive = new RobotDrive(driveSubsystemMotorControllerFrontLeft,
			driveSubsystemMotorControllerBackLeft,
			driveSubsystemMotorControlleFrontRight,
			driveSubsystemMotorControllerBackRight);
	printf("Robot Drive initialized\n");
	
	robotDrive->SetSafetyEnabled(false);
    robotDrive->SetExpiration(0.1);
    robotDrive->SetSensitivity(0.5);
    robotDrive->SetMaxOutput(1.0);

    robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
    robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
    robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
    robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);

    printf("Motor controller parameters set\n");

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    pneumaticSubsystemSolenoid = new DoubleSolenoid(5, 0, 1);
    //workingCompressor = new Compressor(11);
    //workingCompressor->SetClosedLoopControl(true);
    //workingCompressor->Start();
    //printf("Compressor closed loop set to true, compressor is %s, compressor switch is %s, current=%f.\n", (workingCompressor->Enabled() ? "enabled" : "disabled"),
    //		(workingCompressor->GetPressureSwitchValue() ? "on" : "off"), workingCompressor->GetCompressorCurrent());

	driveSubsystemLEncoder = new Encoder(2, 3, true, Encoder::k4X);
	//lw->AddSensor("driveSubsystem", "LEncoder", driveSubsystemLEncoder);
	driveSubsystemLEncoder->SetDistancePerPulse(1.0);
    driveSubsystemLEncoder->SetPIDSourceParameter(Encoder::kRate);

	driveSubsystemREncoder = new Encoder(0, 1, false, Encoder::k4X);
	//lw->AddSensor("driveSubsystem", "REncoder", driveSubsystemREncoder);
	driveSubsystemREncoder->SetDistancePerPulse(1.0);
    driveSubsystemREncoder->SetPIDSourceParameter(Encoder::kRate);

    distanceSensor = new AnalogInput(0);

    colorSensor = new AnalogInput(1);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
