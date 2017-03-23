# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget libobs)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target libobs
add_library(libobs SHARED IMPORTED)

set_target_properties(libobs PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "HAVE_OBSCONFIG_H"
  INTERFACE_INCLUDE_DIRECTORIES "D:/obs_studio/obs_studio_org/libobs;D:/obs_studio/config"
)

# Import target "libobs" for configuration "Debug"
set_property(TARGET libobs APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libobs PROPERTIES
  IMPORTED_IMPLIB_DEBUG "D:/obs_studio/libobs/Debug/obs.lib"
  IMPORTED_LOCATION_DEBUG "D:/obs_studio/libobs/Debug/obs.dll"
  )

# Import target "libobs" for configuration "Release"
set_property(TARGET libobs APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libobs PROPERTIES
  IMPORTED_IMPLIB_RELEASE "D:/obs_studio/libobs/Release/obs.lib"
  IMPORTED_LOCATION_RELEASE "D:/obs_studio/libobs/Release/obs.dll"
  )

# Import target "libobs" for configuration "MinSizeRel"
set_property(TARGET libobs APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(libobs PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "D:/obs_studio/libobs/MinSizeRel/obs.lib"
  IMPORTED_LOCATION_MINSIZEREL "D:/obs_studio/libobs/MinSizeRel/obs.dll"
  )

# Import target "libobs" for configuration "RelWithDebInfo"
set_property(TARGET libobs APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(libobs PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "D:/obs_studio/libobs/RelWithDebInfo/obs.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "D:/obs_studio/libobs/RelWithDebInfo/obs.dll"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
