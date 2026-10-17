project(use_logger_main)
include_directories(${COMMON_INCLUDE})
include_directories(../../thirdparty/json11/)
SET(CMAKE_CXX_STANDARD 20)
add_executable(use_logger ./use_logger_main.cpp 
${COMMON_SRC_DIR}/Logger.cpp 
${COMMON_SRC_DIR}/CommonFunction.cpp
../../thirdparty/json11/json11.cpp)