# Robot Arm & Conveyor Belt Automation System
This project is an autonomous mechatronic system designed to simulate industrial production lines, capable of color-based object sorting.


Technical Specifications Controller: Arduino (C++) 


Sensor: TCS3200 


Color Sensor Actuators: 4 x Servo Motors (Robot Arm) + 1 x DC Motor (Conveyor Belt) 


Algorithm: Real-time color frequency analysis and synchronized motor control.


Working PrincipleSensing: The system continuously analyzes Red, Black, and White color components via the TCS3200 sensor. 


Decision: When a red object is detected (based on threshold analysis), the conveyor belt is automatically stopped using the stopBelt() function. 


Action: The pickRedCube() function is triggered, moving the robot arm to predefined coordinates to handle the object. 


Continuity: After the sorting task is completed, the system returns to its initial position and restarts the belt. 
