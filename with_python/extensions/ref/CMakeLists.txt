aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCES)

pybind11_add_module(
        ref
        ${SOURCES}
)

target_include_directories(
        ref PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        "utils/"
)

install(
        TARGETS ref # combinatorial_auctions
        #        DESTINATION ${CMAKE_SOURCE_DIR}/tests/
        DESTINATION ${CMAKE_BINARY_DIR}
)