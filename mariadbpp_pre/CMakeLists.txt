cmake_minimum_required(VERSION 3.8)
#project(MARIADB_PP)

set(-D CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=1 -lpthread  -lncurses -ltinfo -pthread -ldl -lcurl") 

#---------------------------------------------------------------------
#                       MariaDB++ Cmake
#---------------------------------------------------------------------
include_directories(/usr/include/mariadb)

set(CPR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpr/source)
set(CURL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/curl/headers)
set(MYSQL_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/mysql/headers)
set(MARIADB_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/mariadbpp/source)
include_directories(${CPR_DIR})
include_directories(${CURL_DIR})
include_directories(${MYSQL_HEADERS})
include_directories(${MARIADB_DIR})
include_directories(${CMAKE_DL_LIBS})
include_directories(${MySQL_DIR})



list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/mariadbpp/find")
set(MySQL_DIR  mysql/find)





set(CURL_SOURCES ${CURL_DIR}/curl.h ${CURL_DIR}/curlver.h ${CURL_DIR}/easy.h ${CURL_DIR}/header.h ${CURL_DIR}/multi.h ${CURL_DIR}/options.h ${CURL_DIR}/stdcheaders.h ${CURL_DIR}/system.h ${CURL_DIR}/typecheck-gcc.h ${CURL_DIR}/urlapi.h)

set(MARIADB_SOURCES ${MARIADB_DIR}/private.hpp ${MARIADB_DIR}/worker.hpp ${MARIADB_DIR}/account.cpp ${MARIADB_DIR}/bind.cpp ${MARIADB_DIR}/concurrency.cpp ${MARIADB_DIR}/connection.cpp ${MARIADB_DIR}/date_time.cpp ${MARIADB_DIR}/exceptions.cpp ${MARIADB_DIR}/last_error.cpp ${MARIADB_DIR}/result_set.cpp ${MARIADB_DIR}/save_point.cpp ${MARIADB_DIR}/statement.cpp ${MARIADB_DIR}/time_span.cpp ${MARIADB_DIR}/time.cpp ${MARIADB_DIR}/transaction.cpp ${MARIADB_DIR}/worker.cpp ${MARIADB_DIR}/account.hpp ${MARIADB_DIR}/bind.hpp ${MARIADB_DIR}/concurrency.hpp ${MARIADB_DIR}/connection.hpp ${MARIADB_DIR}/date_time.hpp ${MARIADB_DIR}/exceptions.hpp ${MARIADB_DIR}/last_error.hpp ${MARIADB_DIR}/result_set.hpp ${MARIADB_DIR}/save_point.hpp ${MARIADB_DIR}/statement.hpp ${MARIADB_DIR}/time_span.hpp ${MARIADB_DIR}/time.hpp ${MARIADB_DIR}/transaction.hpp ${MARIADB_DIR}/types.hpp)


set(CPR_SOURCES ${CPR_DIR}/auth.cpp ${CPR_DIR}/bearer.cpp ${CPR_DIR}/cookies.cpp ${CPR_DIR}/cprtypes.cpp ${CPR_DIR}/curl_container.cpp ${CPR_DIR}/curlholder.cpp ${CPR_DIR}/error.cpp ${CPR_DIR}/multipart.cpp ${CPR_DIR}/parameters.cpp ${CPR_DIR}/payload.cpp ${CPR_DIR}/proxies.cpp ${CPR_DIR}/proxyauth.cpp ${CPR_DIR}/redirect.cpp ${CPR_DIR}/response.cpp ${CPR_DIR}/session.cpp ${CPR_DIR}/timeout.cpp ${CPR_DIR}/unix_socket.cpp ${CPR_DIR}/util.cpp ${CPR_DIR}/bearer.cpp ${CPR_DIR}/cookies.cpp ${CPR_DIR}/cprtypes.cpp ${CPR_DIR}/curl_container.cpp ${CPR_DIR}/curlholder.cpp ${CPR_DIR}/error.cpp ${CPR_DIR}/multipart.cpp ${CPR_DIR}/parameters.cpp ${CPR_DIR}/payload.cpp ${CPR_DIR}/proxies.cpp ${CPR_DIR}/proxyauth.cpp ${CPR_DIR}/redirect.cpp ${CPR_DIR}/response.cpp ${CPR_DIR}/session.cpp ${CPR_DIR}/timeout.cpp ${CPR_DIR}/unix_socket.cpp ${CPR_DIR}/util.cpp ${CPR_DIR}/verbose.h ${CPR_DIR}/api.h ${CPR_DIR}/body.h ${CPR_DIR}/callback.h ${CPR_DIR}/connect_timeout.h ${CPR_DIR}/cpr.h ${CPR_DIR}/digest.h ${CPR_DIR}/http_version.h ${CPR_DIR}/interface.h ${CPR_DIR}/limit_rate.h ${CPR_DIR}/low_speed.h ${CPR_DIR}/ntlm.h ${CPR_DIR}/ssl_options.h ${CPR_DIR}/status_codes.h ${CPR_DIR}/user_agent.h ${CPR_DIR}/util.h ) # insert cpr cpp

set(MYSQL_SOURCES ${MYSQL_HEADERS}/auth_dialog_client.h ${MYSQL_HEADERS}/base64.h ${MYSQL_HEADERS}/big_endian.h ${MYSQL_HEADERS}/byte_order_generic.h ${MYSQL_HEADERS}/byte_order_generic_x86.h ${MYSQL_HEADERS}/byte_order_generic_x86_64.h ${MYSQL_HEADERS}/client_plugin.h ${MYSQL_HEADERS}/decimal.h ${MYSQL_HEADERS}/errmsg.h ${MYSQL_HEADERS}/ft_global.h ${MYSQL_HEADERS}/gcc_builtins.h ${MYSQL_HEADERS}/generic-msvc.h ${MYSQL_HEADERS}/handler_ername.h ${MYSQL_HEADERS}/handler_state.h ${MYSQL_HEADERS}/hash.h ${MYSQL_HEADERS}/heap.h ${MYSQL_HEADERS}/keycache.h ${MYSQL_HEADERS}/lf.h ${MYSQL_HEADERS}/little_endian.h ${MYSQL_HEADERS}/m_ctype.h ${MYSQL_HEADERS}/m_string.h ${MYSQL_HEADERS}/ma_dyncol.h ${MYSQL_HEADERS}/maria.h ${MYSQL_HEADERS}/my_aes.h ${MYSQL_HEADERS}/my_alarm.h ${MYSQL_HEADERS}/my_alloc.h ${MYSQL_HEADERS}/my_atomic.h ${MYSQL_HEADERS}/my_attribute.h ${MYSQL_HEADERS}/my_base.h ${MYSQL_HEADERS}/my_bit.h ${MYSQL_HEADERS}/my_bitmap.h ${MYSQL_HEADERS}/my_byteorder.h ${MYSQL_HEADERS}/my_check_opt.h ${MYSQL_HEADERS}/my_compare.h ${MYSQL_HEADERS}/my_compiler.h ${MYSQL_HEADERS}/my_context.h ${MYSQL_HEADERS}/my_crypt.h ${MYSQL_HEADERS}/my_crypt_key_management.h ${MYSQL_HEADERS}/my_dbug.h ${MYSQL_HEADERS}/my_decimal_limits.h ${MYSQL_HEADERS}/my_default.h ${MYSQL_HEADERS}/my_dir.h ${MYSQL_HEADERS}/my_getopt.h ${MYSQL_HEADERS}/my_global.h ${MYSQL_HEADERS}/my_handler_errors.h ${MYSQL_HEADERS}/my_libwrap.h ${MYSQL_HEADERS}/my_list.h ${MYSQL_HEADERS}/my_md5.h ${MYSQL_HEADERS}/my_net.h ${MYSQL_HEADERS}/my_nosys.h ${MYSQL_HEADERS}/my_pthread.h ${MYSQL_HEADERS}/my_rdtsc.h ${MYSQL_HEADERS}/my_rnd.h ${MYSQL_HEADERS}/my_stacktrace.h ${MYSQL_HEADERS}/my_sys.h ${MYSQL_HEADERS}/my_time.h ${MYSQL_HEADERS}/my_tree.h ${MYSQL_HEADERS}/my_uctype.h ${MYSQL_HEADERS}/my_user.h ${MYSQL_HEADERS}/my_xml.h ${MYSQL_HEADERS}/myisam.h ${MYSQL_HEADERS}/myisamchk.h ${MYSQL_HEADERS}/myisammrg.h ${MYSQL_HEADERS}/myisampack.h ${MYSQL_HEADERS}/mysql.h ${MYSQL_HEADERS}/mysql_async.h ${MYSQL_HEADERS}/mysql_com.h ${MYSQL_HEADERS}/mysql_com_server.h ${MYSQL_HEADERS}/mysql_embed.h ${MYSQL_HEADERS}/mysql_file.h ${MYSQL_HEADERS}/mysql_idle.h ${MYSQL_HEADERS}/mysql_socket.h ${MYSQL_HEADERS}/mysql_stage.h ${MYSQL_HEADERS}/mysql_statement.h ${MYSQL_HEADERS}/mysql_table.h ${MYSQL_HEADERS}/mysql_thread.h ${MYSQL_HEADERS}/mysql_time.h ${MYSQL_HEADERS}/mysql_version.h ${MYSQL_HEADERS}/mysqld_default_groups.h ${MYSQL_HEADERS}/mysys_err.h ${MYSQL_HEADERS}/nolock.h ${MYSQL_HEADERS}/password.h ${MYSQL_HEADERS}/plugin.h ${MYSQL_HEADERS}/plugin_audit.h ${MYSQL_HEADERS}/plugin_auth.h ${MYSQL_HEADERS}/plugin_auth_common.h ${MYSQL_HEADERS}/plugin_ftparser.h ${MYSQL_HEADERS}/probes_mysql.h ${MYSQL_HEADERS}/probes_mysql_nodtrace.h ${MYSQL_HEADERS}/psi.h ${MYSQL_HEADERS}/psi_abi_v0.h ${MYSQL_HEADERS}/psi_abi_v1.h ${MYSQL_HEADERS}/psi_abi_v2.h ${MYSQL_HEADERS}/queues.h ${MYSQL_HEADERS}/rijndael.h ${MYSQL_HEADERS}/rwlock.h ${MYSQL_HEADERS}/service_debug_sync.h ${MYSQL_HEADERS}/service_kill_statement.h ${MYSQL_HEADERS}/service_logger.h ${MYSQL_HEADERS}/service_my_plugin_log.h ${MYSQL_HEADERS}/service_my_snprintf.h ${MYSQL_HEADERS}/service_progress_report.h ${MYSQL_HEADERS}/service_sha1.h ${MYSQL_HEADERS}/service_thd_alloc.h ${MYSQL_HEADERS}/service_thd_autoinc.h ${MYSQL_HEADERS}/service_thd_error_context.h ${MYSQL_HEADERS}/service_thd_timezone.h ${MYSQL_HEADERS}/service_thd_wait.h ${MYSQL_HEADERS}/service_versions.h ${MYSQL_HEADERS}/services.h ${MYSQL_HEADERS}/sha1.h ${MYSQL_HEADERS}/sha2.h ${MYSQL_HEADERS}/solaris.h ${MYSQL_HEADERS}/sql_common.h ${MYSQL_HEADERS}/sslopt-case.h ${MYSQL_HEADERS}/sslopt-longopts.h ${MYSQL_HEADERS}/sslopt-vars.h ${MYSQL_HEADERS}/t_ctype.h ${MYSQL_HEADERS}/thr_alarm.h ${MYSQL_HEADERS}/thr_lock.h ${MYSQL_HEADERS}/thread_pool_priv.h ${MYSQL_HEADERS}/typelib.h ${MYSQL_HEADERS}/violite.h ${MYSQL_HEADERS}/waiting_threads.h ${MYSQL_HEADERS}/welcome_copyright_notice.h ${MYSQL_HEADERS}/wqueue.h ${MYSQL_HEADERS}/x86-gcc.h)




find_package(PkgConfig REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(OpenSSL COMPONENTS SSL REQUIRED)
find_package(ZLIB)
find_package(MySQL REQUIRED)
find_package(MariaDBClient REQUIRED)
find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_search_module(OPENSSL REQUIRED openssl)
pkg_check_modules(MySQL REQUIRED libmariadb>=3.1.16)



# set up target
add_library(mariadb_pp ../empty/empty.cpp  ${CURL_SOURCES}  ${CPR_SOURCES} ${MYSQL_SOURCES} ${MARIADB_SOURCES})

target_link_libraries(mariadb_pp  ${MYSQL_LIBRARIES}  MariaDBClient::MariaDBClient Threads::Threads curl) 



# install configuration
install(FILES  ${CURL_SOURCES}  ${CPR_SOURCES} ${MYSQL_SOURCES} ${MARIADB_SOURCES} mariadb_pp DESTINATION ${MARIADB_PP_CURRENT_CONFIG_DIR}/build)


install(TARGETS mariadb_pp 
	EXPORT mariadb_pp
	ARCHIVE DESTINATION build
	RUNTIME DESTINATION build
	LIBRARY DESTINATION build
)


install(
	EXPORT mariadb_pp
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/export"
	NAMESPACE "mariadb::"
	# In this CMake config file no dependencies are considered. But since we
	# do not use any `find_package` call here this approach is sufficient.
	FILE mariadbclient-config.cmake
)
install(FILES 
	mariadbpp/find/mariadbclientpp-config.cmake
	mariadbpp/external/FindMariaDBClient.cmake
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/export"
)

install(
	EXPORT mariadb_pp
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/export"
	NAMESPACE "mariadb_pp::"
	# In this CMake config file no dependencies are considered. But since we
	# do not use any `find_package` call here this approach is sufficient.
	FILE mariadbclientpp-targets.cmake
)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/build/CMakeFiles/Export/export/mariadbclient-config-noconfig.cmake"
	"${PROJECT_SOURCE_DIR}/build/CMakeFiles/Export/export/mariadbclient-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/build/CMakeFiles/Export/export/mariadbclientpp-targets-noconfig.cmake"
	"${PROJECT_SOURCE_DIR}/build/CMakeFiles/Export/export/mariadbclientpp-targets.cmake"
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/export")

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MariaDB++")
SET(CPACK_PACKAGE_VENDOR "ViaDuck")
SET(CPACK_PACKAGE_VERSION "1.0.0")
SET(CPACK_GENERATOR "RPM;DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Nobody")
INCLUDE(CPack)
#----------------------------------------------------------------------



#set up test   
#add_executable(demo ../test/test.cpp  ) 
#target_link_libraries(demo  mariadb_pp )


