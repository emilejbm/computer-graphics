# Install script for directory: /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/doc/tiff/html/images/back.gif;/usr/local/share/doc/tiff/html/images/bali.jpg;/usr/local/share/doc/tiff/html/images/cat.gif;/usr/local/share/doc/tiff/html/images/cover.jpg;/usr/local/share/doc/tiff/html/images/cramps.gif;/usr/local/share/doc/tiff/html/images/dave.gif;/usr/local/share/doc/tiff/html/images/info.gif;/usr/local/share/doc/tiff/html/images/jello.jpg;/usr/local/share/doc/tiff/html/images/jim.gif;/usr/local/share/doc/tiff/html/images/note.gif;/usr/local/share/doc/tiff/html/images/oxford.gif;/usr/local/share/doc/tiff/html/images/quad.jpg;/usr/local/share/doc/tiff/html/images/ring.gif;/usr/local/share/doc/tiff/html/images/smallliz.jpg;/usr/local/share/doc/tiff/html/images/strike.gif;/usr/local/share/doc/tiff/html/images/warning.gif")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/doc/tiff/html/images" TYPE FILE FILES
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/back.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/bali.jpg"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/cat.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/cover.jpg"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/cramps.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/dave.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/info.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/jello.jpg"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/jim.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/note.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/oxford.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/quad.jpg"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/ring.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/smallliz.jpg"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/strike.gif"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images/warning.gif"
    )
endif()

