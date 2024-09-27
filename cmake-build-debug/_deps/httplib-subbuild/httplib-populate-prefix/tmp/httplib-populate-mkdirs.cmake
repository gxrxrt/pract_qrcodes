# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-src"
  "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-build"
  "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-subbuild/httplib-populate-prefix"
  "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-subbuild/httplib-populate-prefix/tmp"
  "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-subbuild/httplib-populate-prefix/src/httplib-populate-stamp"
  "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-subbuild/httplib-populate-prefix/src"
  "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-subbuild/httplib-populate-prefix/src/httplib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-subbuild/httplib-populate-prefix/src/httplib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/garar/Desktop/cpp development/pract_qr_codes/cmake-build-debug/_deps/httplib-subbuild/httplib-populate-prefix/src/httplib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
