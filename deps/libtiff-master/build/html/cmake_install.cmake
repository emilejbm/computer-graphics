# Install script for directory: /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html

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
   "/usr/local/share/doc/tiff/html/addingtags.html;/usr/local/share/doc/tiff/html/bugs.html;/usr/local/share/doc/tiff/html/build.html;/usr/local/share/doc/tiff/html/contrib.html;/usr/local/share/doc/tiff/html/document.html;/usr/local/share/doc/tiff/html/images.html;/usr/local/share/doc/tiff/html/index.html;/usr/local/share/doc/tiff/html/internals.html;/usr/local/share/doc/tiff/html/intro.html;/usr/local/share/doc/tiff/html/libtiff.html;/usr/local/share/doc/tiff/html/misc.html;/usr/local/share/doc/tiff/html/support.html;/usr/local/share/doc/tiff/html/TIFFTechNote2.html;/usr/local/share/doc/tiff/html/tools.html;/usr/local/share/doc/tiff/html/v3.4beta007.html;/usr/local/share/doc/tiff/html/v3.4beta016.html;/usr/local/share/doc/tiff/html/v3.4beta018.html;/usr/local/share/doc/tiff/html/v3.4beta024.html;/usr/local/share/doc/tiff/html/v3.4beta028.html;/usr/local/share/doc/tiff/html/v3.4beta029.html;/usr/local/share/doc/tiff/html/v3.4beta031.html;/usr/local/share/doc/tiff/html/v3.4beta032.html;/usr/local/share/doc/tiff/html/v3.4beta033.html;/usr/local/share/doc/tiff/html/v3.4beta034.html;/usr/local/share/doc/tiff/html/v3.4beta035.html;/usr/local/share/doc/tiff/html/v3.4beta036.html;/usr/local/share/doc/tiff/html/v3.5.1.html;/usr/local/share/doc/tiff/html/v3.5.2.html;/usr/local/share/doc/tiff/html/v3.5.3.html;/usr/local/share/doc/tiff/html/v3.5.4.html;/usr/local/share/doc/tiff/html/v3.5.5.html;/usr/local/share/doc/tiff/html/v3.5.6-beta.html;/usr/local/share/doc/tiff/html/v3.5.7.html;/usr/local/share/doc/tiff/html/v3.6.0.html;/usr/local/share/doc/tiff/html/v3.6.1.html;/usr/local/share/doc/tiff/html/v3.7.0alpha.html;/usr/local/share/doc/tiff/html/v3.7.0beta.html;/usr/local/share/doc/tiff/html/v3.7.0beta2.html;/usr/local/share/doc/tiff/html/v3.7.0.html;/usr/local/share/doc/tiff/html/v3.7.1.html;/usr/local/share/doc/tiff/html/v3.7.2.html;/usr/local/share/doc/tiff/html/v3.7.3.html;/usr/local/share/doc/tiff/html/v3.7.4.html;/usr/local/share/doc/tiff/html/v3.8.0.html;/usr/local/share/doc/tiff/html/v3.8.1.html;/usr/local/share/doc/tiff/html/v3.8.2.html;/usr/local/share/doc/tiff/html/v3.9.0beta.html;/usr/local/share/doc/tiff/html/v3.9.1.html;/usr/local/share/doc/tiff/html/v3.9.2.html;/usr/local/share/doc/tiff/html/v4.0.0.html;/usr/local/share/doc/tiff/html/v4.0.1.html;/usr/local/share/doc/tiff/html/v4.0.2.html;/usr/local/share/doc/tiff/html/v4.0.3.html;/usr/local/share/doc/tiff/html/v4.0.4beta.html")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/doc/tiff/html" TYPE FILE FILES
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/addingtags.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/bugs.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/build.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/contrib.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/document.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/images.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/index.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/internals.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/intro.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/libtiff.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/misc.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/support.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/TIFFTechNote2.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/tools.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta007.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta016.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta018.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta024.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta028.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta029.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta031.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta032.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta033.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta034.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta035.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.4beta036.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.5.1.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.5.2.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.5.3.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.5.4.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.5.5.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.5.6-beta.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.5.7.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.6.0.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.6.1.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.7.0alpha.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.7.0beta.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.7.0beta2.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.7.0.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.7.1.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.7.2.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.7.3.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.7.4.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.8.0.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.8.1.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.8.2.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.9.0beta.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.9.1.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v3.9.2.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v4.0.0.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v4.0.1.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v4.0.2.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v4.0.3.html"
    "/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/html/v4.0.4beta.html"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/html/images/cmake_install.cmake")
  include("/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/html/man/cmake_install.cmake")

endif()

