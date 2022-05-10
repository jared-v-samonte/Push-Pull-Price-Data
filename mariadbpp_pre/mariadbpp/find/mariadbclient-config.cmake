# Get the directory containing this file.
get_filename_component(MARIADB_PP_CURRENT_CONFIG_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

include(CMakeFindDependencyMacro)

find_dependency(Threads REQUIRED)

list(INSERT CMAKE_MODULE_PATH 0 "${MARIADB_PP_CURRENT_CONFIG_DIR}/")
find_dependency(MariaDBClient REQUIRED)

# Import targets.
include("${MARIADB_PP_CURRENT_CONFIG_DIR}/mariadbclient-config.cmake")
