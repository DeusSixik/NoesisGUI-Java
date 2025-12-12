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
        src/NsGui/NSPanelJni.cpp
        src/NsGui/NSGridJni.cpp
        src/NsGui/NSBaseButtonJni.cpp
        src/NsGui/NSBrushJni.cpp
        src/NsGui/NSSolidColorBrushJni.cpp
        src/NsGui/NSBrushesJni.cpp
        src/NsGui/NSGradientBrushJni.cpp
        src/NsGui/NSLinearGradientBrushJni.cpp
        src/NsGui/NSRadialGradientBrushJni.cpp
        src/NsGui/NSTileBrushJni.cpp
        src/NsGui/NSVisualBrushJni.cpp
        src/NsGui/NSImageBrushJni.cpp
        src/Render/NSGLRenderUtil.h
        NoesisSDK/Packages/Render/GLRenderContext/Src/GLRenderContext.h
        NoesisSDK/Packages/Render/GLRenderDevice/Src/GLRenderDevice.cpp
        src/NsGui/NSGradientStopCollectionJni.cpp
        src/NsGui/NSGradientStopJni.cpp
        src/NsGui/NSButtonJni.cpp
        src/NsGui/NSUIElementCollectionJni.cpp
        src/NsGui/NSToggleButtonJni.cpp
        src/NsGui/NSRadioButtonJni.cpp
        src/NsGui/NSCheckBoxJni.cpp
        src/NsGui/NSRepeatButtonJni.cpp
        src/NsGui/NSGridViewColumnHeaderJni.cpp
        src/NsGui/NSToolTipJni.cpp
        src/NsGui/NSLabelJni.cpp
        src/NsGui/NSUserControlJni.cpp
        src/NsGui/NSPageJni.cpp
        src/NsGui/NSStatusBarItemJni.cpp
        src/NsGui/NSBaseTextBoxJni.cpp
        src/NsGui/NSTypographyJni.cpp
        src/NsGui/NSTextBoxJni.cpp
        src/NsGui/NSRangeBaseJni.cpp
        src/NsGui/NSSliderJni.cpp
        src/NsGui/NSProgressBarJni.cpp
        src/NsGui/NSScrollBarJni.cpp
        src/NsGui/NSTextBlockJni.cpp
        src/NsGui/NSPasswordBoxJni.cpp
        src/NsGui/NSTextElementJni.cpp
        src/NsGui/NSInlineJni.cpp
        src/NsGui/NSSpanJni.cpp
        src/NsGui/NSItalicJni.cpp
        src/NsGui/NSBoldJni.cpp
        src/NsGui/NSUnderlineJni.cpp
        src/NsGui/NSHyperlinkJni.cpp
        src/NsGui/NSInlineCollectionJni.cpp
        src/NsGui/NSColumnDefinitionCollectionJni.cpp
        src/NsGui/NSCommandBindingCollectionJni.cpp
        src/NsGui/NSInputBindingCollectionJni.cpp
        src/NsGui/NSRowDefinitionCollectionJni.cpp
        src/NsGui/NSTriggerCollectionJni.cpp
        src/NsGui/NSRunJni.cpp
        src/NsGui/NSInlineUIContainerJni.cpp
        src/NsGui/NSLineBreakJni.cpp
        src/NsGui/NSItemsControlJni.cpp
        src/NsGui/NSTreeViewJni.cpp
        src/NsGui/NSContextMenuJni.cpp
        src/NsGui/NSMenuJni.cpp
        src/NsGui/NSToolBarOverflowPanelJni.cpp
        src/NsGui/NSCanvasJni.cpp
        src/NsGui/NSStackPanelJni.cpp
        src/NsGui/NSToolBarPanelJni.cpp
        src/NsGui/NSUniformGridJni.cpp
        src/NsGui/NSDockPanelJni.cpp
        src/NsGui/NSWrapPanelJni.cpp
        src/NsGui/NSTabPanelJni.cpp
        src/NsGui/NSVirtualizingStackPanelJni.cpp
        src/NsGui/NSVirtualizingWrapPanelJni.cpp
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/NotifyPropertyChangedBase.h
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/ApplicationLauncherApi.h
        src/NsApp/JavaNotifyPropertyChangedBase.cpp
        src/NsApp/JavaNotifyPropertyChangedBase.h
        src/NsApp/NsNotifyPropertyChangedBaseJni.cpp
        NoesisSDK/Packages/App/Display/Include/NsApp/Display.h
        NoesisSDK/Packages/App/DisplayLauncher/Include/NsApp/DisplayLauncher.h
        NoesisSDK/Packages/App/DisplayLauncher/Include/NsApp/DisplayLauncherApi.h
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/Application.h
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/ApplicationLauncher.h
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/DelegateCommand.h
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/LocExtension.h
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/MessageBox.h
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/RichText.h
        NoesisSDK/Packages/App/ApplicationLauncher/Include/NsApp/Window.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/AttachableCollection.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/AttachableCollection.inl
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/AttachableObject.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/BackgroundEffectBehavior.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/Behavior.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/BehaviorCollection.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/ChangePropertyAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/CollectionFilterBehavior.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/CollectionSortBehavior.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/ComparisonCondition.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/ConditionalExpression.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/ConditionBehavior.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/ControlStoryboardAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/DataEventTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/DataTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/EventTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/EventTriggerBase.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/FilterPredicate.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/GamepadTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/GoToStateAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/IAttachedObject.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/Interaction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/InteractivityApi.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/InvokeCommandAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/KeyTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/LaunchUriOrFileAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/LineDecorationBehavior.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/LoadContentAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/MediaActions.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/MouseDragElementBehavior.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/MoveFocusAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/PlaySoundAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/PropertyChangedTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/RemoveElementAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/SelectAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/SelectAllAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/SetFocusAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/SortComparer.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/StoryboardAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/StoryboardCompletedTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/StoryboardTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/StringFilterPredicate.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/StringSortComparer.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/StyleInteraction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/TargetedTriggerAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/TimerTrigger.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/TranslateZoomRotateBehavior.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/TriggerAction.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/TriggerActionCollection.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/TriggerBase.h
        NoesisSDK/Packages/App/Interactivity/Include/NsApp/TriggerCollection.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/EmbeddedFontProvider.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/EmbeddedTextureProvider.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/EmbeddedXamlProvider.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/FastLZ.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/FileSystemWatcher.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/FileTextureProvider.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/Find.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/LocalFontProvider.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/LocalTextureProvider.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/LocalXamlProvider.h
        NoesisSDK/Packages/App/Providers/Include/NsApp/ProvidersApi.h
        NoesisSDK/Packages/App/Rive/Include/NsApp/RiveApi.h
        NoesisSDK/Packages/App/Rive/Include/NsApp/RiveTriggerAction.h
        NoesisSDK/Packages/App/RiveBase/Include/NsApp/RiveBaseApi.h
        NoesisSDK/Packages/App/RiveBase/Include/NsApp/RiveControl.h
        NoesisSDK/Packages/App/RiveBase/Include/NsApp/RiveInput.h
        NoesisSDK/Packages/App/RiveBase/Include/NsApp/RiveRun.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/BoxShadow.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/ConicGradientBrush.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/CrossFadeBrush.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/DirectionalBlurEffect.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/MonochromeBrush.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/PinchEffect.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/PixelateEffect.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/PlasmaBrush.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/SaturationEffect.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/ShadersApi.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/TintEffect.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/VignetteEffect.h
        NoesisSDK/Packages/App/Shaders/Include/NsApp/WavesBrush.h
        NoesisSDK/Packages/App/Display/Include/NsApp/DisplayApi.h
        NoesisSDK/Packages/App/MediaElement/Include/NsApp/MediaElement.h
        NoesisSDK/Packages/App/MediaElement/Include/NsApp/MediaElementApi.h
        NoesisSDK/Packages/App/MediaElement/Include/NsApp/MediaPlayer.h
        NoesisSDK/Packages/App/LangServer/Include/NsApp/LangServer.h
        NoesisSDK/Packages/App/LangServer/Include/NsApp/LangServerApi.h
        NoesisSDK/Packages/App/LangServerHelpers/Include/NsApp/LangServerHelpersApi.h
        NoesisSDK/Packages/App/LangServerHelpers/Include/NsApp/PreviewRenderer.h
        NoesisSDK/Packages/App/Launcher/Include/NsApp/CommandLine.h
        NoesisSDK/Packages/App/Launcher/Include/NsApp/EntryPoint.h
        NoesisSDK/Packages/Render/RenderContext/Include/NsRender/Image.h
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