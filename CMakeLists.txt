cmake_minimum_required(VERSION 3.16)

project(MrSteelRat_bot)

set(CMAKE_CXX_STANDARD 23)
set(Boost_USE_MULTITHREADED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_GENERATOR "Ninja" CACHE STRING "Ninja")

# Uncomment the lines below to adjust optimization levels
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0")  # Add -O0 optimization flag (No optimization)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O1")  # Add -O1 optimization flag (Optimize for speed)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")  # Add -O2 optimization flag (More aggressive optimization)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")  # Add -O3 optimization flag (Even more aggressive optimization)

# Add AddressSanitizer (ASan) and UndefinedBehaviorSanitizer (UBSan)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")

# Uncomment the lines below to print compiler timings
#set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time") 
#set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CMAKE_COMMAND} -E time")

enable_testing()

# GCC key -ftime-report to output timing
add_compile_options(-ftime-report)

# Specify paths to your project's header files
include_directories(/usr/local/include)

# Specify paths to libraries
set(CMAKE_PREFIX_PATH "/usr/local" ${CMAKE_PREFIX_PATH})

# Specify libraries to link against
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(GTest)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()

# Create an executable file
add_subdirectory(module)
# Get a list of all source files in the 'module' directory
file(GLOB MODULE_SOURCES module/*.cpp)
file(GLOB MODULE_HEADERS module/*.h)

# Create an executable file and add source files
add_executable(telegram_bot src/main.cpp ${MODULE_SOURCES} ${MODULE_HEADERS})

# Assuming your executable target is named "telegram_bot"
# Specify paths to header files from module
target_include_directories(telegram_bot PRIVATE module)

# Link libraries to your executable file
target_link_libraries(telegram_bot PRIVATE /usr/local/lib/libTgBot.a Boost::system ssl crypto pthread) 

# Add static linking with the C++ library
target_link_libraries(telegram_bot PRIVATE stdc++)

# Add tests using Google Test
#add_subdirectory(test)

# Add a target for testing
#add_test(NAME my_tests COMMAND telegram_bot_tests)
