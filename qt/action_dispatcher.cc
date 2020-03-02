//
// Created by nbaiot@126.com on 2020/3/2.
//

#include <qdebug.h>
#include <boost/asio/post.hpp>
#include "action_dispatcher.h"


ActionDispatcher::ActionDispatcher() {
  thread_ = std::make_shared<std::thread>([this]() {
    ioc_.run();
  });
}

void ActionDispatcher::Dispatcher(const QString &request) {
  boost::asio::post(ioc_, [this, request](){
    DispatcherInner(request);
  });
}

ActionDispatcher *ActionDispatcher::Instance() {
  static ActionDispatcher INSTANCE;
  return &INSTANCE;
}

void ActionDispatcher::DispatcherInner(const QString &request) {
  qDebug() << ">>>>>>>>>Dispatcher request:" << request;
}


