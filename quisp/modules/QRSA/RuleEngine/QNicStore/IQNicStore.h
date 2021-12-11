#pragma once
#include "modules/QNIC.h"

namespace quisp::modules::qnic_store {

class IQNicStore {
 public:
  virtual ~IQNicStore(){};
  virtual int countNumFreeQubits(QNIC_type type, int qnic_index) = 0;
  virtual int takeFreeQubitIndex(QNIC_type type, int qnic_index) = 0;
  virtual void setQubitBusy(QNIC_type type, int qnic_index, int qubit_index, bool is_busy) = 0;
};
}  // namespace quisp::modules::qnic_store
