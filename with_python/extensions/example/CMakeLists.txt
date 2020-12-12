aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCES)

pybind11_add_module(
        example
        ${SOURCES}
)

target_include_directories(
        example PRIVATE
        "utils/"
)

install(
        TARGETS example
        #        DESTINATION ${CMAKE_SOURCE_DIR}/tests/
        DESTINATION ${CMAKE_BINARY_DIR}
)