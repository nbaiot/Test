//
// Created by nbaiot@126.com on 2020/3/2.
//
#pragma once

#ifndef TEST_ACTION_DISPATHER_H
#define TEST_ACTION_DISPATHER_H

#include <memory>
#include <thread>
#include <QObject>
#include <QString>

#include <boost/asio/io_context.hpp>
#include <boost/asio/executor_work_guard.hpp>

class ActionDispatcher : public QObject {
  Q_OBJECT
public:

  static ActionDispatcher* Instance();

  Q_INVOKABLE void Dispatcher(const QString &request);

private:
  ActionDispatcher();
  void DispatcherInner(const QString &request);
private:
  boost::asio::io_context ioc_;
  boost::asio::executor_work_guard<boost::asio::io_context::executor_type> guard_{ioc_.get_executor()};
  std::shared_ptr<std::thread> thread_;
};


#endif //TEST_ACTION_DISPATHER_H
