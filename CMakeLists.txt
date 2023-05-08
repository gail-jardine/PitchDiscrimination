# CMakeList.txt : CMake project for PitchDiscrimination, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PitchDiscrimination")

# Add source to this project's executable.
add_executable (PitchDiscrimination "PitchDiscrimination.c" "PitchDiscrimination.h" "AudioBasics.c" "AudioBasics.h" "stdafx.h" "SynthsBasic.h" "SynthsBasic.c" "Testing.c")

# TODO: Add tests and install targets if needed.
