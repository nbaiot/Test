//
// Created by nbaiot@126.com on 2020/3/1.
//

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <qdebug.h>

#include "action_dispatcher.h"

int main(int argc, char** argv) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication application(argc, argv);

  qmlRegisterSingletonInstance<ActionDispatcher>("ui.dispatcher", 1, 0,
      "ActionDispatcher", ActionDispatcher::Instance());

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