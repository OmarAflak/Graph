#ifndef DATA_INTERFACE
#define DATA_INTERFACE

struct DataInterface {
    void (*mDestroy)(void*);
    void* (*mCopy)(void*);

    DataInterface(){
        mDestroy = nullptr;
        mCopy = nullptr;
    }
};

#endif
