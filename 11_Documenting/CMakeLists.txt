cmake_minimum_required(VERSION 3.10)

project(11_Documenting)

find_package(Doxygen REQUIRED)
find_package(Doxygen REQUIRED dot) # sudo apt install graphviz

add_executable(100 100.c)

message("-- `make translate` -- to make the russian translation")
message("-- `make ru_100` -- to run program in russian")
message("-- `make update_100` -- to update the translation")

add_custom_target( translate
    COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/po/ru/LC_MESSAGES
    COMMAND msgfmt -o ${CMAKE_CURRENT_BINARY_DIR}/po/ru/LC_MESSAGES/100.mo ${CMAKE_SOURCE_DIR}/po/ru.po
    DEPENDS 100
)

add_custom_target( ru_100
    COMMAND LANGUAGE=ru_RU ${CMAKE_CURRENT_BINARY_DIR}/100
    DEPENDS 100 translate
)

add_custom_target( ru_100_r
    COMMAND LANGUAGE=ru_RU ${CMAKE_CURRENT_BINARY_DIR}/100 --roman
    DEPENDS 100 translate
)

add_custom_target( ru_100_help
    COMMAND LANGUAGE=ru_RU ${CMAKE_CURRENT_BINARY_DIR}/100 --help
    DEPENDS 100 translate
)

add_custom_target( update_100
    COMMAND xgettext --keyword=_ --add-comments ${CMAKE_SOURCE_DIR}/100.c -o ${CMAKE_CURRENT_BINARY_DIR}/100.pot
    COMMAND msgmerge -U ${CMAKE_SOURCE_DIR}/po/ru.po ${CMAKE_CURRENT_BINARY_DIR}/100.pot
    COMMAND rm -rf ${CMAKE_SOURCE_DIR}/po/ru.po~
    COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/100.pot
    COMMAND msgfmt -o ${CMAKE_CURRENT_BINARY_DIR}/po/ru/LC_MESSAGES/100.mo ${CMAKE_SOURCE_DIR}/po/ru.po
    DEPENDS translate
)

add_custom_target( en_100
    COMMAND LANGUAGE=en_EN ${CMAKE_CURRENT_BINARY_DIR}/100
    DEPENDS 100
)

add_custom_target( en_100_r
    COMMAND LANGUAGE=en_EN ${CMAKE_CURRENT_BINARY_DIR}/100 --roman
    DEPENDS 100
)

add_custom_target( en_100_help
    COMMAND LANGUAGE=en_EN ${CMAKE_CURRENT_BINARY_DIR}/100 --help
    DEPENDS 100
)

add_custom_target( man
    COMMAND help2man --no-info --output=${CMAKE_BINARY_DIR}/100.l --name=${CMAKE_BINARY_DIR}/100 ${CMAKE_BINARY_DIR}/100
    COMMAND man ${CMAKE_BINARY_DIR}/100.l
    DEPENDS 100
)

configure_file(${CMAKE_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.conf)
add_custom_target( documentation
    COMMAND chmod +x  ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.conf
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.conf
    DEPENDS 100
)

add_custom_target( build_clean
        COMMAND echo "removing related files from build directory"
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/po
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/100
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/100.l
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/Makefile
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake
        COMMAND echo "build directory cleaned"
)