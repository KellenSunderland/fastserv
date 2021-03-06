/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ModelServer_H
#define ModelServer_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "model_server_types.h"

namespace fastserv {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ModelServerIf {
 public:
  virtual ~ModelServerIf() {}
  virtual void infer(std::map<int32_t, double> & _return, const std::string& image) = 0;
};

class ModelServerIfFactory {
 public:
  typedef ModelServerIf Handler;

  virtual ~ModelServerIfFactory() {}

  virtual ModelServerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ModelServerIf* /* handler */) = 0;
};

class ModelServerIfSingletonFactory : virtual public ModelServerIfFactory {
 public:
  ModelServerIfSingletonFactory(const boost::shared_ptr<ModelServerIf>& iface) : iface_(iface) {}
  virtual ~ModelServerIfSingletonFactory() {}

  virtual ModelServerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ModelServerIf* /* handler */) {}

 protected:
  boost::shared_ptr<ModelServerIf> iface_;
};

class ModelServerNull : virtual public ModelServerIf {
 public:
  virtual ~ModelServerNull() {}
  void infer(std::map<int32_t, double> & /* _return */, const std::string& /* image */) {
    return;
  }
};

typedef struct _ModelServer_infer_args__isset {
  _ModelServer_infer_args__isset() : image(false) {}
  bool image :1;
} _ModelServer_infer_args__isset;

class ModelServer_infer_args {
 public:

  ModelServer_infer_args(const ModelServer_infer_args&);
  ModelServer_infer_args& operator=(const ModelServer_infer_args&);
  ModelServer_infer_args() : image() {
  }

  virtual ~ModelServer_infer_args() throw();
  std::string image;

  _ModelServer_infer_args__isset __isset;

  void __set_image(const std::string& val);

  bool operator == (const ModelServer_infer_args & rhs) const
  {
    if (!(image == rhs.image))
      return false;
    return true;
  }
  bool operator != (const ModelServer_infer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ModelServer_infer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ModelServer_infer_pargs {
 public:


  virtual ~ModelServer_infer_pargs() throw();
  const std::string* image;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ModelServer_infer_result__isset {
  _ModelServer_infer_result__isset() : success(false) {}
  bool success :1;
} _ModelServer_infer_result__isset;

class ModelServer_infer_result {
 public:

  ModelServer_infer_result(const ModelServer_infer_result&);
  ModelServer_infer_result& operator=(const ModelServer_infer_result&);
  ModelServer_infer_result() {
  }

  virtual ~ModelServer_infer_result() throw();
  std::map<int32_t, double>  success;

  _ModelServer_infer_result__isset __isset;

  void __set_success(const std::map<int32_t, double> & val);

  bool operator == (const ModelServer_infer_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ModelServer_infer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ModelServer_infer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ModelServer_infer_presult__isset {
  _ModelServer_infer_presult__isset() : success(false) {}
  bool success :1;
} _ModelServer_infer_presult__isset;

class ModelServer_infer_presult {
 public:


  virtual ~ModelServer_infer_presult() throw();
  std::map<int32_t, double> * success;

  _ModelServer_infer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ModelServerClient : virtual public ModelServerIf {
 public:
  ModelServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ModelServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void infer(std::map<int32_t, double> & _return, const std::string& image);
  void send_infer(const std::string& image);
  void recv_infer(std::map<int32_t, double> & _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ModelServerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ModelServerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ModelServerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_infer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ModelServerProcessor(boost::shared_ptr<ModelServerIf> iface) :
    iface_(iface) {
    processMap_["infer"] = &ModelServerProcessor::process_infer;
  }

  virtual ~ModelServerProcessor() {}
};

class ModelServerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ModelServerProcessorFactory(const ::boost::shared_ptr< ModelServerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ModelServerIfFactory > handlerFactory_;
};

class ModelServerMultiface : virtual public ModelServerIf {
 public:
  ModelServerMultiface(std::vector<boost::shared_ptr<ModelServerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ModelServerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ModelServerIf> > ifaces_;
  ModelServerMultiface() {}
  void add(boost::shared_ptr<ModelServerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void infer(std::map<int32_t, double> & _return, const std::string& image) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->infer(_return, image);
    }
    ifaces_[i]->infer(_return, image);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ModelServerConcurrentClient : virtual public ModelServerIf {
 public:
  ModelServerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ModelServerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void infer(std::map<int32_t, double> & _return, const std::string& image);
  int32_t send_infer(const std::string& image);
  void recv_infer(std::map<int32_t, double> & _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
