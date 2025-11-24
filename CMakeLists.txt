cmake_minimum_required (VERSION 3.10)

project ("unitConvertion")

add_executable (unitConvertion "unitConvertion.cpp"   "test.h"        "info.h" "info.cpp" "parts.h" "parts.cpp")

add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)

target_include_directories(unitConvertion PUBLIC "C:\\Users\\Arturs\\OneDrive\\Desktop\\kursa darbs c++\\nana-master\\include")
target_link_directories(unitConvertion PUBLIC "C:\\Users\\Arturs\\OneDrive\\Desktop\\kursa darbs c++\\nana-master\\build\\bin")

add_subdirectory(
    "C:/Users/Arturs/OneDrive/Desktop/kursa darbs c++/SQLiteCpp-master"
    "${CMAKE_BINARY_DIR}/SQLiteCpp-build"
)


target_link_libraries(unitConvertion PRIVATE
    "nana_v142_Debug_x64.lib"
    SQLiteCpp
    sqlite3
)

