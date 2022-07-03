#pragma once
#include <exception>
#include <string>

using namespace std;

class ProdusValidationError : public exception{
private:
    string msg;
public:
    explicit ProdusValidationError(string msg);
    string what(){
        return  this->msg;
    }
};

class NonExistentCodeError : public exception{
private:
    string msg;
public:
    explicit NonExistentCodeError(string msg);
    string what(){
        return this->msg;
    }
};

class DublicateCodeError: public exception{
private:
    string msg;
public:
    explicit DublicateCodeError(string msg);
    string what(){
        return this->msg;
    }
};

class NegativeSumError: public exception{
};


