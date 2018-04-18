#include "../include/utils.h"

std::string genUid(size_t length){
    static const std::string::value_type allowed_chars[] {"123456789ABCDFGHJKLMNPQRSTVWXZabcdfghjklmnpqrstvwxz"};

    static thread_local std::default_random_engine randomEngine(std::random_device{}());
    static thread_local std::uniform_int_distribution<int> randomDistribution(0, sizeof(allowed_chars) - 1);

    std::string id(length ? length : 16, '\0');

    for (std::string::value_type& c : id) {
        c = allowed_chars[randomDistribution(randomEngine)];
    }

    return id;
}

int toInt(std::string str){
    std::stringstream ss(str);
    int n;
    ss >> n;
    return n;
}
