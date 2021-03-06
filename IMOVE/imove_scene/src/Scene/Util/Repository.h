//
// Created by Wouter Posdijk on 17/05/16.
//

#ifndef IMOVE_REPOSITORY_H
#define IMOVE_REPOSITORY_H

#include <iterator>
#include <functional>
#include <memory>

template<typename T>
class Repository {
public:
    virtual void add(const std::shared_ptr<T> &item) = 0;

    virtual void scheduleForRemoval(const std::shared_ptr<T> &item) = 0;

    virtual void removeAll() = 0;

    virtual unsigned long size() = 0;

    virtual typename std::shared_ptr<T> &get(unsigned long id) = 0;

    virtual bool has(unsigned long id) = 0;

    typename std::shared_ptr<T> &operator[](unsigned long id) {
        return get(id);
    }

    virtual void for_each(const std::function<void(std::shared_ptr<T>)> &f) = 0;
};

#endif //IMOVE_REPOSITORY_H
