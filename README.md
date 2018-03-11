# fastserv
A lightweight implementation of TensorRT and ONNX model serving.

# Dependencies required
* CMake 3.0 or greater.

# Build instructions
```bash
mkdir build && cd build
cmake ..
make -j $(nproc)
```

# Run instructions
```bash
./fastserve
```
By default this will log all info or higher level events to a fastserv file in /tmp.  Critical events will be echoed 
to stderr.

To run with all events logged to stderr:
```bash
GLOG_logtostderr=1 ./fastserv
```