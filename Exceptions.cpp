#include "Exceptions.h"
#include <utility>

ProdusValidationError::ProdusValidationError(string msg) {
    this->msg = std::move(msg);
}


DublicateCodeError::DublicateCodeError(string msg) {
    this->msg = std::move(msg);
}

NonExistentCodeError::NonExistentCodeError(string msg) {
    this->msg = std::move(msg);
}
