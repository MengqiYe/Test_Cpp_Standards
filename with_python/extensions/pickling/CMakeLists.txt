aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCES)

pybind11_add_module(
        pickling
        ${SOURCES}
)

target_include_directories(
        pickling PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/inc
        "utils/"
)

install(
        TARGETS pickling
        #        DESTINATION ${CMAKE_SOURCE_DIR}/tests/
        DESTINATION ${CMAKE_BINARY_DIR}
)



link_libraries(python3.8)
add_executable(p ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

target_include_directories(
        p PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/inc
        "utils/"
)

