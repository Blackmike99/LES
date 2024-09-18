#pragma once
template <typename T>
struct Nodo {
    T data;
    Nodo* next;
    Nodo(T data) : data(data), next(nullptr) {}
};
