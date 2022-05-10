# Install script for directory: /mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/build" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES "/mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql/mysql_version.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/build" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES "/mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql/my_config.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/build" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES "/mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql/mysqld_ername.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/build" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES "/mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql/mysqld_error.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/build" TYPE FILE PERMISSIONS OWNER_READ GROUP_READ WORLD_READ FILES "/mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql/sql_state.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/build" TYPE DIRECTORY FILES "/mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql/mysql/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/build/private" TYPE DIRECTORY FILES "/mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql/." FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/CMakeFiles$" EXCLUDE REGEX "/mysql$" EXCLUDE REGEX "\\./(|mysql_version\\.h|my_config\\.h|mysqld_ername\\.h|mysqld_error\\.h|sql_state\\.h$)" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/mnt/c/Users/JAVSamonte/Documents/Github/Data_Push_Pull_Testing/include/mysql/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
