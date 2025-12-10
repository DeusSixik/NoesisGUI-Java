cmake_minimum_required(VERSION 3.20)
project(noesis_jni LANGUAGES CXX)

# C++ стандарт
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(NATIVE_OUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../java/src/main/resources/native/win64")

set(NOESIS_SDK_DIR "${CMAKE_SOURCE_DIR}/NoesisSDK" CACHE PATH "Local Noesis SDK")
set(JAVA_HOME "C:/Program Files/Java/jdk-21" CACHE PATH "Path to JDK 21")

# ====== НАСТРОЙКИ ПУТЕЙ ======

# Проверяем, что есть include
if (NOT EXISTS "${NOESIS_SDK_DIR}/Include")
    message(FATAL_ERROR "NOESIS_SDK_DIR (${NOESIS_SDK_DIR}) is wrong: Include/ not found")
endif()

# Проверяем, что есть jni.h
if (NOT EXISTS "${JAVA_HOME}/include/jni.h")
    message(FATAL_ERROR "JAVA_HOME (${JAVA_HOME}) is wrong: include/jni.h not found")
endif()

# Пути к JNI и Noesis headers
include_directories(
        ${NOESIS_SDK_DIR}/Include
        ${NOESIS_SDK_DIR}/Packages
        ${JAVA_HOME}/include
)

if (WIN32)
    include_directories(${JAVA_HOME}/include/win32)
else()
    include_directories(${JAVA_HOME}/include/linux)
endif()

# Выбираем нужные подпапки для x64 Windows
if (WIN32 AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(NOESIS_BIN_DIR "${NOESIS_SDK_DIR}/Bin/windows_x86_64")
    set(NOESIS_LIB_DIR "${NOESIS_SDK_DIR}/Lib/windows_x86_64") # <-- проверь, что такая папка есть
endif()

add_library(noesis_jni SHARED
        src/NsDrawing/NSColorJni.cpp
        src/NsDrawing/NSCornerRadiusJni.cpp
        src/NsDrawing/NSInt32RectJni.cpp
        src/utils/NSJniUtils.cpp
        src/utils/NSJniUtils.h
        src/NsCore/NsSymbolJni.cpp
        src/NsCore/NsTypeJni.cpp
        src/NsCore/NsBaseComponentJni.cpp
        src/NsRender/NsRenderTargetJni.cpp
        src/NsRender/NsRenderDeviceJni.cpp
        src/Debug/NSDebugCpp.cpp
        src/NsApp/NsXamlProviderJni.cpp
        src/NsCore/NsStreamJni.cpp
        src/NsCore/NsDispatcherObjectJni.cpp
        src/NsCore/NsBaseObjectJni.cpp
        src/NsCore/NsBaseRefCountedJni.cpp
        src/NsCore/NsDependencyPropertyJni.cpp
        src/NsGui/NsVisualJni.cpp
        src/NsGui/NsUIElementJni.cpp
        src/NSNoesisGuiJni.cpp
        src/NsCore/NsInterfaceJni.cpp
        src/NsGui/NsIRendererJni.cpp
        src/NsGui/NSIViewJni.cpp
        src/Render/NsRenderContextJni.cpp
        src/Render/NsGLJni.cpp
        src/NsApp/NsThemeJni.cpp
        src/NsGui/NsFrameworkElementJni.cpp
        src/jni.cpp
        src/events/NsWidgetEvents.h
        src/jni.h
        src/NsCore/NsRoutedEventJni.cpp
        src/events/NsButtonEventJni.cpp
        src/events/NsFrameworkElementEventsJni.cpp
        src/utils/NSJavaUtils.h
        src/events/NsFrameworkElementEventsJni.cpp
        src/events/NsUIElementEventsJni.cpp
        src/NsGui/NsControlJni.cpp
        src/NsGui/NsContentControlJni.cpp
        src/NsGui/NSItemContainerGeneratorJni.cpp
        src/NsCore/NSPanelJni.cpp
)

# Линкуемся по .lib
if (NOESIS_LIB_DIR)
    target_link_directories(noesis_jni PRIVATE
            ${NOESIS_LIB_DIR}
    )
endif()

target_link_libraries(noesis_jni
        Noesis         # Noesis.lib
        NoesisApp      # NoesisApp.lib (если используешь App API)
)

# После сборки копируем DLL рядом с noesis_jni.dll
if (NOESIS_BIN_DIR)
    add_custom_command(TARGET noesis_jni POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${NOESIS_BIN_DIR}/Noesis.dll"
            "$<TARGET_FILE_DIR:noesis_jni>/Noesis.dll"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${NOESIS_BIN_DIR}/NoesisApp.dll"
            "$<TARGET_FILE_DIR:noesis_jni>/NoesisApp.dll"
    )
endif()

set_target_properties(noesis_jni PROPERTIES
        OUTPUT_NAME "noesis_jni"
        RUNTIME_OUTPUT_DIRECTORY "${NATIVE_OUT_DIR}"
)

# Для многоконфигурационных (Visual Studio, Xcode) лучше так:
foreach(cfg IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER "${cfg}" CFG_UPPER)
    set_target_properties(noesis_jni PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY_${CFG_UPPER} "${NATIVE_OUT_DIR}"
    )
endforeach()

# И копирование Noesis.dll / NoesisApp.dll уже в ЭТУ же папку:
if (NOESIS_BIN_DIR)
    add_custom_command(TARGET noesis_jni POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory "${NATIVE_OUT_DIR}"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${NOESIS_BIN_DIR}/Noesis.dll"
            "${NATIVE_OUT_DIR}/Noesis.dll"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${NOESIS_BIN_DIR}/NoesisApp.dll"
            "${NATIVE_OUT_DIR}/NoesisApp.dll"
    )
endif()