//
// Created by nbaiot@126.com on 2020/3/2.
//

#include <thread>
#include <future>
#include <memory>
#include <glog/logging.h>
#include <boost/asio/io_context.hpp>
#include <boost/asio/executor_work_guard.hpp>
#include <boost/asio/post.hpp>

int main() {
  boost::asio::io_context ioc;
  boost::asio::executor_work_guard<boost::asio::io_context::executor_type> guard(ioc.get_executor());

  std::thread thread([&ioc](){
    LOG(INFO) << "ioc thread...";
    ioc.run();
  });

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::packaged_task<int()> task([](){
      LOG(INFO) << "exec task....";
      std::this_thread::sleep_for(std::chrono::seconds(2));
      return 1;
  });
  boost::asio::post(ioc, std::ref(task));
  auto future = task.get_future();


  std::promise<int> promise;
  auto future2 = promise.get_future();
  boost::asio::post(ioc, [&promise](){
      LOG(INFO) << "process promise....";
      promise.set_value(8);
  });

  LOG(INFO) << "wait future....";
  LOG(INFO) << ">>>>>>>>>>feature:" << future.get();
  LOG(INFO) << ">>>>>>>>>>future2:" << future2.get();
  LOG(INFO) << ">>>>>>>>>> test feature";
  ioc.run();
  return 0;
}