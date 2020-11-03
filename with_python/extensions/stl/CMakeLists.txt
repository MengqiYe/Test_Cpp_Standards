aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCES)

pybind11_add_module(
        stl
        ${SOURCES}
)

target_include_directories(
        stl PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)
