cmake_minimum_required(VERSION 3.8)
#project(coin_gecko_api)

set(-D CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread  -DSTACK_DIRECTION=1 -DGTEST_HAS_POSIX_RE=0  -lncurses -ltinfo -pthread -ldl -lcurl") 

find_package(OpenSSL REQUIRED)
find_package(ZLIB)

set(COIN_GECKO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gecko)
set(CPR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpr)
set(CURL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/curl)

include_directories(../include/gecko/headers)
include_directories(${CPR_DIR})
include_directories(${CURL_DIR})
include_directories(${CMAKE_DL_LIBS})



set(CURL_SOURCES ${CURL_DIR}/curl.h ${CURL_DIR}/curlver.h ${CURL_DIR}/easy.h ${CURL_DIR}/header.h ${CURL_DIR}/multi.h ${CURL_DIR}/options.h ${CURL_DIR}/stdcheaders.h ${CURL_DIR}/system.h ${CURL_DIR}/typecheck-gcc.h ${CURL_DIR}/urlapi.h)

set(CPR_SOURCES ${CPR_DIR}/auth.cpp ${CPR_DIR}/bearer.cpp ${CPR_DIR}/cookies.cpp ${CPR_DIR}/cprtypes.cpp ${CPR_DIR}/curl_container.cpp ${CPR_DIR}/curlholder.cpp ${CPR_DIR}/error.cpp ${CPR_DIR}/multipart.cpp ${CPR_DIR}/parameters.cpp ${CPR_DIR}/payload.cpp ${CPR_DIR}/proxies.cpp ${CPR_DIR}/proxyauth.cpp ${CPR_DIR}/redirect.cpp ${CPR_DIR}/response.cpp ${CPR_DIR}/session.cpp ${CPR_DIR}/timeout.cpp ${CPR_DIR}/unix_socket.cpp ${CPR_DIR}/util.cpp ${CPR_DIR}/bearer.cpp ${CPR_DIR}/cookies.cpp ${CPR_DIR}/cprtypes.cpp ${CPR_DIR}/curl_container.cpp ${CPR_DIR}/curlholder.cpp ${CPR_DIR}/error.cpp ${CPR_DIR}/multipart.cpp ${CPR_DIR}/parameters.cpp ${CPR_DIR}/payload.cpp ${CPR_DIR}/proxies.cpp ${CPR_DIR}/proxyauth.cpp ${CPR_DIR}/redirect.cpp ${CPR_DIR}/response.cpp ${CPR_DIR}/session.cpp ${CPR_DIR}/timeout.cpp ${CPR_DIR}/unix_socket.cpp ${CPR_DIR}/util.cpp ${CPR_DIR}/verbose.h ${CPR_DIR}/api.h ${CPR_DIR}/body.h ${CPR_DIR}/callback.h ${CPR_DIR}/connect_timeout.h ${CPR_DIR}/cpr.h ${CPR_DIR}/digest.h ${CPR_DIR}/http_version.h ${CPR_DIR}/interface.h ${CPR_DIR}/limit_rate.h ${CPR_DIR}/low_speed.h ${CPR_DIR}/ntlm.h ${CPR_DIR}/ssl_options.h ${CPR_DIR}/status_codes.h ${CPR_DIR}/user_agent.h ${CPR_DIR}/util.h ) # insert cpr cpp

set(COIN_GECKO_SOURCES  ${COIN_GECKO_DIR}/asset_platforms.cpp  ${COIN_GECKO_DIR}/categories.cpp  ${COIN_GECKO_DIR}/coins.cpp  ${COIN_GECKO_DIR}/companies.cpp  ${COIN_GECKO_DIR}/contract.cpp  ${COIN_GECKO_DIR}/derivatives.cpp  ${COIN_GECKO_DIR}/exchange_rates.cpp  ${COIN_GECKO_DIR}/exchanges.cpp  ${COIN_GECKO_DIR}/exchanges.cpp  ${COIN_GECKO_DIR}/exchanges.cpp  ${COIN_GECKO_DIR}/exchanges.cpp  ${COIN_GECKO_DIR}/finance.cpp  ${COIN_GECKO_DIR}/gecko.cpp  ${COIN_GECKO_DIR}/global.cpp  ${COIN_GECKO_DIR}/global.cpp  ${COIN_GECKO_DIR}/indexes.cpp  ${COIN_GECKO_DIR}/simple.cpp  ${COIN_GECKO_DIR}/status_updates.cpp  ${COIN_GECKO_DIR}/trending.cpp  ${COIN_GECKO_DIR}/web.cpp ${COIN_GECKO_DIR}/asset_platforms.h  ${COIN_GECKO_DIR}/categories.h  ${COIN_GECKO_DIR}/coins.h  ${COIN_GECKO_DIR}/companies.h  ${COIN_GECKO_DIR}/contract.h  ${COIN_GECKO_DIR}/derivatives.h  ${COIN_GECKO_DIR}/exchange_rates.h  ${COIN_GECKO_DIR}/exchanges.h  ${COIN_GECKO_DIR}/exchanges.h  ${COIN_GECKO_DIR}/exchanges.h  ${COIN_GECKO_DIR}/exchanges.h  ${COIN_GECKO_DIR}/finance.h  ${COIN_GECKO_DIR}/gecko.h  ${COIN_GECKO_DIR}/global.h  ${COIN_GECKO_DIR}/global.h  ${COIN_GECKO_DIR}/indexes.h  ${COIN_GECKO_DIR}/simple.h  ${COIN_GECKO_DIR}/status_updates.h  ${COIN_GECKO_DIR}/trending.h  ${COIN_GECKO_DIR}/web.h) #inert gecko cpp



add_library(coin_gecko_api ../empty/empty.cpp ${CURL_SOURCES}  ${CPR_SOURCES} ${COIN_GECKO_SOURCES})
target_link_libraries(coin_gecko_api OpenSSL::SSL ZLIB::ZLIB curl ${CMAKE_DL_LIBS}) 


target_include_directories(
    coin_gecko_api
    PUBLIC
    ${COIN_GECKO_DIR}
    ${CPR_DIR}
    ${CURL_DIR}
)

install(FILES  ${CURL_SOURCES} ${CPR_SOURCES} ${COIN_GECKO_SOURCES} coin_gecko_api DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/export)

install(TARGETS coin_gecko_api 
	EXPORT coin_gecko_api
	ARCHIVE DESTINATION export
	RUNTIME DESTINATION export
	LIBRARY DESTINATION export
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/build/CMakeFiles/Export/export/mariadbclient-config-noconfig.cmake"
	"${PROJECT_SOURCE_DIR}/build/CMakeFiles/Export/export/mariadbclient-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/build/CMakeFiles/Export/export/mariadbclientpp-targets-noconfig.cmake"
	"${PROJECT_SOURCE_DIR}/build/CMakeFiles/Export/export/mariadbclientpp-targets.cmake"
	DESTINATION export)


#set up test  
#include_directories(../source/headers)
#add_executable(demo ../test/test.cpp ../source/cgapi.cpp ../source/headers/cgapi.hpp) 
#target_link_libraries(demo  coin_gecko_api )