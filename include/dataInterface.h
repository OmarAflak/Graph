#ifndef DATA_INTERFACE
#define DATA_INTERFACE

#include <functional>

struct DataInterface {
    std::function<void(void*)> mDestroy;
    std::function<void*(void*)> mCopy;

    DataInterface(){}

    DataInterface(std::function<void(void*)> destroy, std::function<void*(void*)> copy){
        mDestroy = destroy;
        mCopy = copy;
    }
};

#endif
