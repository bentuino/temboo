Temboo Arduino Library with Spark support
=========================================

This repository holds a modified version of the Temboo Arduino library v1.2 with support for spark core. Instructions to build an application give here are for CLI mode. So please consult the spark.io web site for details how to install the CLI tools for the Spark Core.

Author: The Temboo Spark Core support was added by Karl N Kaiser. Please check-out my DYI IoT blog under http://bentuino.com

Installation
------------

1. Get the Spark Core firmware:

  %git clone https://github.com/spark/core-firmware.git
  
  %git clone https://github.com/spark/core-common-lib.git
  
  %git clone https://github.com/spark/core-communication-lib.git

2. Note: This step is only required with older firmware - Go to core-firmware/inc and uncomment the line 54 of file spark_wiring_ipaddress.h with your favorite editor

	// Overloaded cast operator to allow IPAddress objects to be used where a pointer
  
	// to a four-byte uint8_t array is expected
	
	//operator uint32_t() { return *((uint32_t*)_address); };
	
	**//bool operator==(const IPAddress& addr) { return (*((uint32_t*)_address)) == (*((uint32_t*)addr._address)); };**
	
	bool operator==(const uint8_t* addr);

3. Save your TembooAccount.h you generated with DeviceCoder to temboo-arduino-library-1.2\Temboo

4. Build application:

  %cd core-firmware/build
  
  %make -f makefile.temboo clean all 

5. Connect your Spark Core to your computer via a USB cable

6. Push both buttons, release Reset button and continue holding the other button until RGB-LED lights up yellow

7. Download application into Spark Core

  %make -f makefile.temboo program-dfu
  
Example
-------

Two simple Spark application examples are included: 

core-firmware/src/application_gxls.cpp - Example demonstrates the Temboo library with Google Spreadsheet

core-firmware/src/application_gmail.cpp - Example demonstrates the Temboo library with Gmail

to change the example that is compiled into the spark core edit the first line in the core-firmware/src/build.mk file:

CPPSRC += $(TARGET_SRC_PATH)/application.cpp => CPPSRC += $(TARGET_SRC_PATH)/application_gxls.cpp 

or 

CPPSRC += $(TARGET_SRC_PATH)/application_gmail.cpp


Testing
-------

Building this code was tested under Windows 8.1 using cygwin and the MINGW version of the ARM GCC compiler tool chain.
