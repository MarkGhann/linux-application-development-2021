cmake_minimum_required(VERSION 3.10)

project(10_I18n)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX /)

message("-- `make translate` -- to make the russian translation")
message("-- `make ru_100` -- to run program in russian")
message("-- `make update_100` -- to update the translation")

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/locale/ru/LC_MESSAGES)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/man/man1)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_custom_target( translate ALL
    COMMAND msgfmt -o ${CMAKE_CURRENT_BINARY_DIR}/share/locale/ru/LC_MESSAGES/100.mo ${CMAKE_SOURCE_DIR}/po/ru.po
)

add_executable(100 100.c)
add_dependencies(100 translate)

add_custom_target( update_100
    COMMAND xgettext --keyword=_ --add-comments ${CMAKE_SOURCE_DIR}/100.c -o ${CMAKE_CURRENT_BINARY_DIR}/100.pot
    COMMAND msgmerge -U ${CMAKE_SOURCE_DIR}/po/ru.po ${CMAKE_CURRENT_BINARY_DIR}/100.pot
    COMMAND rm -rf ${CMAKE_SOURCE_DIR}/po/ru.po~
    COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/100.pot
    COMMAND msgfmt -o ${CMAKE_CURRENT_BINARY_DIR}/share/locale/ru/LC_MESSAGES/100.mo ${CMAKE_SOURCE_DIR}/po/ru.po
    DEPENDS translate
)

add_custom_target( ru_100
    COMMAND LANGUAGE=ru_RU ${CMAKE_CURRENT_BINARY_DIR}/bin/100
    DEPENDS 100
)

add_custom_target( en_100
    COMMAND LANGUAGE=en_EN ${CMAKE_CURRENT_BINARY_DIR}/bin/100
    DEPENDS 100
)

add_custom_target( man ALL
    COMMAND help2man --no-info --output=${CMAKE_CURRENT_BINARY_DIR}/share/man/man1/100.l --name=${CMAKE_CURRENT_BINARY_DIR}/bin/100 ${CMAKE_CURRENT_BINARY_DIR}/bin/100
    DEPENDS 100
)

add_custom_target( man_goes
    COMMAND man ${CMAKE_CURRENT_BINARY_DIR}/share/man/man1/100.l
    DEPENDS man
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/share/locale/ru/LC_MESSAGES/100.mo DESTINATION usr/share/locale/ru/LC_MESSAGES/
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/share/man/man1/100.l DESTINATION usr/share/man/man1/
)

install(
    PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/bin/100 DESTINATION usr/bin/
)

add_custom_target( build_clean
        COMMAND echo "removing related files from build directory"
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/po
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/100
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/Makefile
        COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake
        COMMAND echo "build directory cleaned"
)