/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/TToString.h>

#include <boost/make_shared.hpp>

#include "thrift/gen-cpp/ModelServer.h"

using namespace std;
using namespace fastserv;
using boost::shared_ptr;

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

class ModelServerHandler : public ModelServerIf {
 public:
  ModelServerHandler() = default;

  void infer(std::map<int32_t, double> &_return, const std::string &image) override {
    LOG(INFO) << "ping";
  }
};

class ModerServerCloneFactory : virtual public ModelServerIfFactory {
 public:
  ~ModerServerCloneFactory() override = default;
  ModelServerIf *getHandler(const ::apache::thrift::TConnectionInfo &connInfo) override {
    boost::shared_ptr<TSocket> sock = boost::dynamic_pointer_cast<TSocket>(connInfo.transport);
    LOG(INFO) << "Incoming connection\n";
    LOG(INFO) << "\tSocketInfo: " << sock->getSocketInfo();
    LOG(INFO) << "\tPeerHost: " << sock->getPeerHost();
    LOG(INFO) << "\tPeerAddress: " << sock->getPeerAddress();
    LOG(INFO) << "\tPeerPort: " << sock->getPeerPort();
    return new ModelServerHandler;
  }
  void releaseHandler(ModelServerIf *handler) override {
    delete handler;
  }
};

int main(int argc, char *argv[]) {

  // Setup CLI and remove unused flags from input.
  gflags::SetUsageMessage("Hello World");
  gflags::SetVersionString("0.0.1");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // Initialize logging with the name of our executable.
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();

  LOG(INFO) << "Fastserv server starting ...";

  // TODO: Make configurable.  Vary by the amount of GPU memory available.
  const int workerCount = 4;

  boost::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(workerCount);
  threadManager->threadFactory(boost::make_shared<PlatformThreadFactory>());
  threadManager->start();

  TThreadPoolServer server(
      boost::make_shared<ModelServerProcessorFactory>(boost::make_shared<ModerServerCloneFactory>()),
      boost::make_shared<TServerSocket>(9090),
      boost::make_shared<TBufferedTransportFactory>(),
      boost::make_shared<TBinaryProtocolFactory>(),
      threadManager);

  LOG(INFO) << "Fastserv server started.";
  server.serve();

  LOG(INFO) << "Fastserv server shutting down.";
  return 0;
}