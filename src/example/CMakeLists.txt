project(use_logger_main)
include_directories(${COMMON_INCLUDE})
SET(CMAKE_CXX_STANDARD 20)
add_executable(use_logger ./use_logger_main.cpp ${COMMON_SRC_DIR}/Logger.cpp)