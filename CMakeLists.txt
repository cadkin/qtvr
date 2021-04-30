cmake_minimum_required(VERSION 3.9)

project(qtvr)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Find the Qt libraries we need.
find_package(Qt5 REQUIRED COMPONENTS
  Core Gui Widgets Multimedia MultimediaWidgets
)

# Find all project files.
file(GLOB_RECURSE SOURCES "src/**.cpp")
file(GLOB_RECURSE HEADERS "include/**.h")

# Wrap Qt5 objects to generate usable code.
qt5_wrap_cpp(MOC_HEADERS ${HEADERS})

# Tell executable where to find headers.
include_directories(PUBLIC "include" ${CMAKE_BINARY_DIR})

# Make executable.
add_executable(${PROJECT_NAME} ${MOC_HEADERS} ${SOURCES} ${HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
# Tell executable which libraries are needed.
target_link_libraries( ${PROJECT_NAME}
    Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets
)
