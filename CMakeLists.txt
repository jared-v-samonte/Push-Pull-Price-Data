cmake_minimum_required(VERSION 3.13.4)
project(Data_Push_Pull)
#

set(-D CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=1 -lpthread  -lncurses -ltinfo -pthread -ldl -lcurl") 


find_package(PkgConfig REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(OpenSSL COMPONENTS SSL REQUIRED)
find_package(ZLIB)
find_package(Threads REQUIRED)

set(libhttpserver_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libhttpserver_pre/find)
include_directories(${libhttpserver_DIR})




# Add additional cmake modules
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/mariadbpp_pre/mariadbpp/find")
set(MySQL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/mariadbpp_pre/mysql/find)
include_directories(${MySQL_DIR})


find_package(MySQL REQUIRED)
find_package(MariaDBClient REQUIRED)
find_package(Threads REQUIRED)
find_package(libhttpserver REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_search_module(OPENSSL REQUIRED openssl)
pkg_check_modules(MySQL REQUIRED libmariadb>=3.1.16)


set(SOURCE_DIR  ${CMAKE_SOURCE_DIR}/source/headers)

include_directories(include/gecko)
include_directories(/usr/include/mariadb)
include_directories(include/mariadbpp)
include_directories(include/curl)
include_directories(include/cpr)
include_directories(include/uint256_t) 
include_directories(include/uint128_t)  


include_directories(include/rapidjson)
include_directories(include/rapidjson/error)
include_directories(include/rapidjson/internal)


include_directories(${LIBHTTPSERVER_INCLUDE_DIRS})
include_directories(${SOURCE_DIR})
include_directories(${CMAKE_DL_LIBS})
include_directories(${Boost_INCLUDE_DIR}) 
include_directories(${Boost_FILESYSTEM_LIBRARY})
include_directories(${Boost_SYSTEM_LIBRARY})
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR}) 
include_directories(${Boost_FILESYSTEM_LIBRARY})
include_directories(${Boost_SYSTEM_LIBRARY})
include_directories(${GLIB_PKG_INCLUDE_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS}) 
include_directories(${GTKMM_LIBRARIES_DIRS})
link_libraries(${GTKMM_LIBRARIES})



set(SOURCE_CPP  source/daps.cpp source/global.cpp source/initial.cpp source/preferences.cpp source/basicfunctions.cpp source/databasefunctions.cpp source/cgapi.cpp source/deserialize.cpp source/cryptodata.cpp source/uint128_t.cpp source/uint256_t.cpp)

set(SOURCE_H  source/headers/daps.hpp source/headers/global.hpp source/headers/initial.hpp source/headers/preferences.hpp source/headers/basicfunctions.hpp source/headers/databasefunctions.hpp source/headers/cgapi.hpp)

add_library(MARIADB_PP empty/empty.cpp)
find_library(MARIADB_PP mariadb_pp ${CMAKE_SOURCE_DIR}/libraries)
link_libraries(MARIADB_PP ${CMAKE_DL_LIBS}  ${GTKMM3}  ${MYSQL_LIBRARIES} MariaDBClient::MariaDBClient Threads::Threads ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} curl) 
#add to link_libraries ${MYSQL_LIBRARIES}  MariaDBClient::MariaDBClient Threads::Threads curl
#add to executable ${MARIADB_PP} 

add_library(CG_API empty/empty.cpp)
find_library(CG_API coin_gecko_api ${CMAKE_SOURCE_DIR}/libraries)
link_libraries(CG_API ${CMAKE_DL_LIBS} ${MYSQL_LIBRARIES} OpenSSL::SSL ZLIB::ZLIB  ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} curl) 

add_library(SOURCE_LIB empty/empty.cpp)
target_link_libraries(SOURCE_LIB ${Boost_SYSTEM_LIBRARY}  ${Boost_FILESYSTEM_LIBRARY} curl) 

#--------------------------------------------------------
#       Main executable comment out to compile faster
#---------------------------------------------------------
add_executable(${PROJECT_NAME} source/main.cpp ${SOURCE_CPP})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS} ${GTKMM_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} ${CG_API} ${MARIADB_PP}  ${GTKMM3} ${CMAKE_DL_LIBS} ${MYSQL_LIBRARIES} MariaDBClient::MariaDBClient Threads::Threads Boost::filesystem ${Boost_SYSTEM_LIBRARY} ${GTKMM_LIBRARIES} ${GTKMM_CFLAGS_OTHER} ${Boost_FILESYSTEM_LIBRARY} curl)
#---------------------------------------------------------


#-------------------------------------------------------------------------
#                             Tests Executables
#-------------------------------------------------------------------------
# Tests
#enable_testing()
#add_executable(ping test/ping.cpp)
#add_executable(simple test/simpleFunction.cpp)
#add_executable(list test/coinList.cpp)
#add_executable(history test/history.cpp)
#add_executable(range test/historyRange.cpp)
add_executable(minute  test/min.cpp)
#add_executable(markets  test/markets.cpp)
#add_executable(specific_data test/specificData.cpp)
add_executable(mariadb_test ${SOURCE_CPP} test/mariadb_test.cpp)
#add_executable(commands test/sql_commands.cpp)
add_executable(query test/query.cpp)
#add_executable(tester ${SOURCE_CPP} test/test.cpp)
add_executable(5mins   ${SOURCE_CPP} test/5mins.cpp)
#add_executable(hello  test/hello_world.cpp)


#target_link_libraries(ping ${CG_API} curl)
#target_link_libraries(simple ${CG_API} curl)
#target_link_libraries(list ${CG_API} curl)
#target_link_libraries(history ${CG_API} curl)
#target_link_libraries(range ${CG_API} curl)
target_link_libraries(minute ${CG_API} curl)
#target_link_libraries(markets ${CG_API} curl)
#target_link_libraries(specific_data ${CG_API} curl)
target_link_libraries(mariadb_test ${CG_API} ${MARIADB_PP} ${SOURCE_LIB} curl)
#target_link_libraries(commands ${MARIADB_PP} curl)
target_link_libraries(query ${MARIADB_PP} curl)
#target_link_libraries(tester ${CG_API} ${MARIADB_PP} ${SOURCE_LIB} curl)
target_link_libraries(5mins ${CG_API} ${MARIADB_PP} ${SOURCE_LIB} curl)
#target_link_libraries(hello ${LIBHTTPSERVER_LIBRARIES} curl)

#add_test(gecko_test ping simple list history range minute markets quick_start specific_data mariadb_test alter_table commands query tester)
#-------------------------------------------------------------------------