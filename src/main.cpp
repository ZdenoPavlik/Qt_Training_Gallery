#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

#include "AlbumModel.h"
#include "PictureModel.h"
#include "PictureImageProvider.h"

int main(int argc, char *argv[])
{
    AlbumModel albumModel;
    PictureModel pictureModel(albumModel);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("thumbnailSize", PictureImageProvider::THUMBNAIL_SIZE.width());
    context->setContextProperty("albumModel", &albumModel);
    context->setContextProperty("pictureModel", &pictureModel);

    engine.addImageProvider("pictures", new PictureImageProvider(&pictureModel));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
