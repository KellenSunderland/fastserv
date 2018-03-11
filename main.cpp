#include <gflags/gflags.h>
#include <glog/logging.h>

int main(int argc, char *argv[]) {

  // Setup CLI and remove unused flags from input.
  gflags::SetUsageMessage("Hello World");
  gflags::SetVersionString("0.0.1");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  // Initialize logging with the name of our executable.
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();

  LOG(INFO) << "Fastserv started.";

  // TODO: model serving

  LOG(INFO) << "Fastserv shutting down.";
  return 0;
}