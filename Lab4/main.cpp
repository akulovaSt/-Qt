#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <starlistsql.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;  // движок для QML

    QQmlContext *context = engine.rootContext();    // получить корневой контекст модели

    starListSQL viewModel(&app); // модель для приложения
    context->setContextObject(&viewModel);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
