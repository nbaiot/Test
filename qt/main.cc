//
// Created by nbaiot@126.com on 2020/3/1.
//

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <qdebug.h>

int main(int argc, char** argv) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication application(argc, argv);
  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/ui/test.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
      &application, [url](QObject *obj, const QUrl &objUrl){
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
  });
  engine.load(url);
  QGuiApplication::exec();
}