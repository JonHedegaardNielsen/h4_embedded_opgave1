# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/jon/Projects/Programming/Embedded/opgave1/out/opgave1/default.cmf"
  "/home/jon/Projects/Programming/Embedded/opgave1/out/opgave1/default.hex"
  "/home/jon/Projects/Programming/Embedded/opgave1/out/opgave1/default.hxl"
  "/home/jon/Projects/Programming/Embedded/opgave1/out/opgave1/default.mum"
  "/home/jon/Projects/Programming/Embedded/opgave1/out/opgave1/default.o"
  "/home/jon/Projects/Programming/Embedded/opgave1/out/opgave1/default.sdb"
  "/home/jon/Projects/Programming/Embedded/opgave1/out/opgave1/default.sym"
  )
endif()
