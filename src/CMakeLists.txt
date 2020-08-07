cmake_minimum_required(VERSION 3.2)

add_executable(gveditor 
                gveditor.cpp 
                version.cpp 
                gveditor_controller.cpp
                gveditor_doc.cpp
                gveditor_iobj.cpp
                gveditor_shapes.cpp
                )

set_target_properties(gveditor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(gveditor PRIVATE 
                            ${PROJECT_SOURCE_DIR}/include
                            "${CMAKE_BINARY_DIR}/include"
                            "/usr/include/c++/8/"
)

target_link_libraries( gveditor PRIVATE stdc++fs )

if (MSVC)
    target_compile_options(gveditor PRIVATE
        /W4
    )
else ()
    target_compile_options(gveditor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS gveditor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT solverdce@gmail.com)

include(CPack)
