/*
    This file is part of the Repetier-Firmware for RF devices from Conrad Electronic SE.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.
*/


/**
\mainpage Repetier-Firmware for Arduino based RepRaps
<CENTER>Copyright &copy; 2011-2016 by repetier and Conrad Electronic SE
</CENTER>

\section Intro Introduction


\section GCodes Implemented GCodes

 look here for descriptions of gcodes: http://linuxcnc.org/handbook/gcode/g-code.html
 and http://objects.reprap.org/wiki/Mendel_User_Manual:_RepRapGCodes

Implemented Codes

- G0   -> G1
- G1   - Coordinated Movement X Y Z E
- G2   - Clockwise Arc
- G3   - Counter-clockwise Arc
- G4   - Dwell S<seconds> or P<milliseconds>
- G20  - Units for G0/G1 are inches.
- G21  - Units for G0/G1 are mm.
- G28  - Home all axes or named axis.
- G80  - abort drilling cycle
- G81  - drill X Y R Z F (supports drilling but does not support drilling cycles)
- G90  - Use absolute coordinates
- G91  - Use relative coordinates
- G92  - Set current position to cordinates given

RepRap M Codes

- M104 - Set extruder target temp
- M105 - Read current temp
- M106 - Fan on
- M107 - Fan off
- M109 - Wait for extruder current temp to reach target temp.
- M114 - Display current position

Custom M Codes

- M20  - List SD card
- M21  - Init SD card
- M22  - Release SD card
- M23  - Select SD file (M23 filename.g)
- M24  - Start/resume SD print
- M25  - Pause SD print
- M26  - Set SD position in bytes (M26 S12345)
- M27  - Report SD print status
- M28  - Start SD write (M28 filename.g)
- M29  - Stop SD write
- M30 <filename> - Delete file on sd card
- M32 <dirname>  - Create subdirectory
- M42 P<pin number> S<value 0..255> - Change output of pin P to S. Does not work on most important pins.
- M80  - Turn on power supply
- M81  - Turn off power supply
- M82  - Set E codes absolute (default)
- M83  - Set E codes relative while in Absolute Coordinates (G90) mode
- M84  - Disable steppers until next move, or use S<seconds> to specify an inactivity timeout, after which the steppers will be disabled.  S0 to disable the timeout.
- M85  - Set inactivity shutdown timer with parameter S<seconds>. To disable set zero (default)
- M99 S<delayInSec> X0 Y0 Z0     - Disable motors for S seconds (default 10) for given axis.
- M104 S<temp> T<extruder> P1 F1 - Set temperature without wait. P1 = wait for moves to finish, F1 = beep when temp. reached first time
- M105 X0 - Get temperatures. If X0 is added, the raw analog values are also written.
- M112 - Emergency kill
- M115 - Capabilities string
- M116 - Wait for all temperatures in a +/- 1 degree range
- M117 <message> - Write message in status row on lcd
- M119 - Report endstop status
- M140 S<temp> F1 - Set bed target temp, F1 makes a beep when temperature is reached the first time
- M190 - Wait for bed current temp to reach target temp.
- M201 - Set max acceleration in units/s^2 for print moves (M201 X1000 Y1000)
- M202 - Set max acceleration in units/s^2 for travel moves (M202 X1000 Y1000)
- M203 - Set temperture monitor to Sx
- M204 - Set PID parameter X => Kp Y => Ki Z => Kd S<extruder> Default is current extruder. NUM_EXTRUDER=Heated bed
- M205 - Output EEPROM settings
- M206 - Set EEPROM value
- M207 X<XY jerk> Z<Z Jerk> E<ExtruderJerk>    - Changes current jerk values, but do not store them in eeprom.
- M220 S<Feedrate multiplier in percent>       - Increase/decrease given feedrate
- M221 S<Extrusion flow multiplier in percent> - Increase/decrease given flow rate
- M232 - Read and reset max. advance values
- M233 X<AdvanceK> Y<AdvanceL> - Set temporary advance K-value to X and linear term advanceL to Y
- M280 S<mode> - Set ditto printing mode. mode: 0 = off, 1 = on
- M300 S<Frequency> P<DurationMillis> - play frequency
- M303 P<extruder/bed> S<printTemperature> X0 - Autodetect pid values. Use P<NUM_EXTRUDER> for heated bed. X0 saves result in EEPROM.
- M340 P<servoId> S<pulseInUS> - servoID = 0..3, Servos are controlled by a pulse with normally between 500 and 2500 with 1500ms in center position. 0 turns servo off.
- M400 - Wait until move buffers empty.
- M401 - Store x, y and z position.
- M402 - Go to stored position. If X, Y or Z is specified, only these coordinates are used. F changes feedrate fo rthat move.
- M500 - Store settings to EEPROM
- M501 - Load settings from EEPROM
- M502 - Reset settings to the one in configuration.h. Does not store values in EEPROM!
- M908 P<address> S<value> - Set stepper current for digipot
*/

#include "Repetier.h"
#include <SPI.h>
#include <Wire.h>


void setup()
{
    Printer::setup();
	initRF();  

} // setup


void loop()
{
    Commands::commandLoop();

} // loop
