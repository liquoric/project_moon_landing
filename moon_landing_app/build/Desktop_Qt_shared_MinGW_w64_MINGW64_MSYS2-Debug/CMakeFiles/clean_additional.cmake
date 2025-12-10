# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\moon_landing_app_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\moon_landing_app_autogen.dir\\ParseCache.txt"
  "moon_landing_app_autogen"
  )
endif()
