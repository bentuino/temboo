# This file is a makefile included from the top level makefile which
# defines the sources built for the target.

# Define the prefix to this directory. 
# Note: The name must be unique within this build and should be
#       based on the root of the project
TARGET_SRC_PATH = ../Temboo

# Add include to all objects built for this target
INCLUDE_DIRS += ../Temboo

# C source files included in this build.
CSRC += $(TARGET_SRC_PATH)/utility/TembooGlobal.c

# C++ source files included in this build.
#CPPSRC += $(subst ../,,$(wildcard $(SRC_PATH)/$(TARGET_SRC_PATH)/*.cpp)))
#CPPSRC += $(subst ../,,$(wildcard $(SRC_PATH)/$(TARGET_SRC_PATH)/utility/*.cpp)))
CPPSRC += $(TARGET_SRC_PATH)/Temboo.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/BaseFormatter.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/ChoreoInput.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/ChoreoInputFormatter.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/ChoreoInputSet.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/ChoreoOutput.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/ChoreoOutputFormatter.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/ChoreoOutputSet.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/ChoreoPreset.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/ChoreoPresetFormatter.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/DataFormatter.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/TembooSession.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/tmbhmac.cpp
CPPSRC += $(TARGET_SRC_PATH)/utility/tmbmd5.cpp

# ASM source files included in this build.
ASRC +=
