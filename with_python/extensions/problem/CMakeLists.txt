aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCES)

pybind11_add_module(
        problem
        ${SOURCES}
)

target_include_directories(
        problem PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/inc
        "utils/"
)

install(
        TARGETS problem
        #        DESTINATION ${CMAKE_SOURCE_DIR}/tests/
        DESTINATION ${CMAKE_BINARY_DIR}
)