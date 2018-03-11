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

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "thrift/gen-cpp/ModelServer.h"

using namespace std;
using namespace fastserv;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main(int argc, char *argv[]) {

  // Setup CLI and remove unused flags from input.
  gflags::SetUsageMessage("Hello World");
  gflags::SetVersionString("0.0.1");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // Initialize logging with the name of our executable.
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();

  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  ModelServerClient client(protocol);

  LOG(INFO) << "Fastserv client started.";

  try {
    transport->open();
  } catch (const std::exception& ex) {
    LOG(FATAL) << "Error occurred while connecting to service: " << ex.what();
  } catch (...) {
    LOG(FATAL) << "Unknown error occurred while connecting to service";
  }

  try {
    std::map<int32_t, double> return_value;
    const std::string& image = "Base64 encode image";
    client.infer(return_value, image);
  } catch (const std::exception& ex) {
    LOG(FATAL) << "Error occurred while calling service: " << ex.what();
  } catch (...) {
    LOG(FATAL) << "Unknown error occurred while calling service";
  }

  LOG(INFO) << "Fastserv client finished.";
  return 0;
}