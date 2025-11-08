cmake_minimum_required(VERSION 3.16)

project(c-http-client VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Inclui apenas fontes de src/ (sem recurse)
file(GLOB SOURCES CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/src/*.c"
)

if (NOT SOURCES)
  message(FATAL_ERROR "Nenhum .c encontrado em src/. Coloque, por ex., src/main.c e src/http_client.c")
endif()

add_executable(${PROJECT_NAME} ${SOURCES}
        src/resolve_dns.c
        src/resolve_dns.h)

# Headers em include/
if (EXISTS "${CMAKE_SOURCE_DIR}/include")
  target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
endif()

# libcurl (opcional)
find_package(CURL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)
