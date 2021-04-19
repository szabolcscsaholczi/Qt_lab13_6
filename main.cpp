#include <QGuiApplication>
#include <QQmlApplicationEngine>

//fel
#include <QQmlEngine>
#include <QQmlContext>
#include "mousememory.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    //fel
    QScopedPointer<MouseMemory> mouse(new MouseMemory);
    //
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //fel
    engine.rootContext()->setContextProperty("mouse", mouse.data());

    return app.exec();
}
