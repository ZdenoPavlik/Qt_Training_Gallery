cmake_minimum_required(VERSION 3.5)

set(APPNAME "GalleryQml")
project(${APPNAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Qt5 COMPONENTS Core Quick Sql Svg REQUIRED)

include_directories(src/core)

set(SOURCES
src/core/Picture.cpp
  src/core/PictureDao.cpp   
  src/core/PictureModel.cpp
  
  src/core/Album.cpp
  src/core/AlbumDao.cpp
  src/core/AlbumModel.cpp

  src/core/DatabaseManager.cpp
  src/core/GalleryCore.cpp
  src/PictureImageProvider.cpp
  src/main.cpp
)

set(RESOURCES
    src/resources/main.qml
    src/resources/AlbumListPage.qml
    src/resources/qml.qrc
)

add_executable(${APPNAME}
      ${SOURCES}
      ${RESOURCES}
)


target_compile_definitions(${APPNAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${APPNAME}
  PRIVATE Qt5::Core Qt5::Quick Qt5::Sql Qt5::Svg)
