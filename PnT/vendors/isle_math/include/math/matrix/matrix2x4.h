//
// Created by Eniola Olawale on 9/7/2024.
//

#pragma once

#include "vector2.h"
#include "vector4.h"
#include "core.h"

namespace isle_engine::math
{

    template<typename T>
    class Matrix2;

    template<typename T>
    class Matrix2x3;

    template<typename T>
    class Matrix4;

    template<typename T>
    class Matrix4x2;

    template<typename T>
    class Matrix4x3;

    template<typename T>
    class ISLE_API Matrix2x4
    {
    private:
        T m_data[2][4];
    public:
        Matrix2x4();
        explicit Matrix2x4(const T &value);
        explicit Matrix2x4(const T (&data)[8]);
        Matrix2x4(const T &r00, const T &r01, const T &r02, const T &r03, const T &r10, const T &r11, const T &r12, const T &r13);
        explicit Matrix2x4(const T (&data)[2][4]);
        Matrix2x4(const Matrix2x4<T> &matrix);
        Matrix2x4(const Vector4<T> &r1, const Vector4<T> &r2);
        explicit Matrix2x4(const Vector4<T> &vector);
        ~Matrix2x4();

        // Operator overloads----------------------------------------------
        T *operator[](int index);
        const T *operator[](int index) const;

        Matrix2x4<T> operator+(const Matrix2x4<T> &matrix) const;
        Matrix2x4<T> operator+(const T &value) const;
        Matrix2x4<T> &operator+=(const Matrix2x4<T> &matrix);
        Matrix2x4<T> &operator+=(const T &value);

        Matrix2x4<T> operator-(const Matrix2x4<T> &matrix) const;
        Matrix2x4<T> operator-(const T &value) const;
        Matrix2x4<T> &operator-=(const Matrix2x4<T> &matrix);
        Matrix2x4<T> &operator-=(const T &value);

        Matrix2x4<T> operator*(const T &value) const;
        Matrix2x4<T> &operator*=(const T &value);

        // Matrix Multiplication
        Vector2<T> operator*(const Vector4<T> &vector) const;
        Matrix2<T> operator*(const Matrix4x2<T> &matrix) const;
        Matrix2x3<T> operator*(const Matrix4x3<T> &matrix) const;
        Matrix2x4<T> operator*(const Matrix4<T> &matrix) const;

        Matrix2x4<T> operator/(const T &value) const;
        Matrix2x4<T> &operator/=(const T &value);

        Matrix4x2<T> transpose() const;
    };

    template<typename T>
    Matrix4x2<T> Matrix2x4<T>::transpose() const {
        return Matrix4x2<T>(
                m_data[0][0],
                m_data[1][0],
                m_data[0][1],
                m_data[1][1],
                m_data[0][2],
                m_data[1][2],
                m_data[0][3],
                m_data[1][3]
        );
    }

    template<typename T>
    Matrix2x4<T>::Matrix2x4(): m_data{{}}
    {

    }

    template<typename T>
    Matrix2x4<T>::Matrix2x4(const T &value) : m_data{value, value, value, value, value, value, value, value}
    {
    }

    template<typename T>
    Matrix2x4<T>::Matrix2x4(const T (&data)[8]): m_data{data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]}
    {
    }

    template<typename T>
    Matrix2x4<T>::Matrix2x4(const T &r00, const T &r01, const T &r02, const T &r03, const T &r10, const T &r11, const T &r12, const T &r13): m_data{r00, r01, r02, r03, r10, r11, r12, r13}
    {
    }

    template<typename T>
    Matrix2x4<T>::Matrix2x4(const T (&data)[2][4]): m_data{data[0][0], data[0][1], data[0][2], data[0][3], data[1][0], data[1][1], data[1][2], data[1][3]}
    {
    }

    template<typename T>
    Matrix2x4<T>::Matrix2x4(const Matrix2x4<T> &matrix): m_data{matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3], matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3]}
    {
    }

    template<typename T>
    Matrix2x4<T>::Matrix2x4(const Vector4<T> &r1, const Vector4<T> &r2): m_data{r1.x, r1.y, r1.z, r1.w, r2.x, r2.y, r2.z, r2.w}
    {
    }

    template<typename T>
    Matrix2x4<T>::Matrix2x4(const Vector4<T> &vector): m_data{vector.x, vector.y, vector.z, vector.w, vector.x, vector.y, vector.z, vector.w}
    {
    }

    template<typename T>
    Matrix2x4<T>::~Matrix2x4() = default;

    // Operator overloads----------------------------------------------
    template<typename T>
    T *Matrix2x4<T>::operator[](int index) {
        try{
            return m_data[index];
        }
        catch(...){
            std::cout << "Index out of Bounds!"<< std::endl;
        }
    }

    template<typename T>
    const T *Matrix2x4<T>::operator[](int index) const {
        try{
            return m_data[index];
        }
        catch(...){
            std::cout << "Index out of Bounds!"<< std::endl;
        }
    }

    template<typename T>
    Matrix2x4<T> Matrix2x4<T>::operator+(const Matrix2x4<T> &matrix) const {

        return Matrix2x4<T>(
                matrix[0][0] + (*this)[0][0],
                matrix[0][1] + (*this)[0][1],
                matrix[0][2] + (*this)[0][2],
                matrix[0][3] + (*this)[0][3],
                matrix[1][0] + (*this)[1][0],
                matrix[1][1] + (*this)[1][1],
                matrix[1][2] + (*this)[1][2],
                matrix[1][3] + (*this)[1][3]
        );
    }

    template<typename T>
    Matrix2x4<T> Matrix2x4<T>::operator+(const T &value) const {
        return Matrix2x4<T>(
                (*this)[0][0] + value,
                (*this)[0][1] + value,
                (*this)[0][2] + value,
                (*this)[0][3] + value,
                (*this)[1][0] + value,
                (*this)[1][1] + value,
                (*this)[1][2] + value,
                (*this)[1][3] + value
        );
    }

    template<typename T>
    Matrix2x4<T> &Matrix2x4<T>::operator+=(const Matrix2x4<T> &matrix) {
        (*this)[0][0] += matrix[0][0];
        (*this)[0][1] += matrix[0][1];
        (*this)[0][2] += matrix[0][2];
        (*this)[0][3] += matrix[0][4];
        (*this)[1][0] += matrix[1][0];
        (*this)[1][1] += matrix[1][1];
        (*this)[1][2] += matrix[1][2];
        (*this)[1][3] += matrix[1][3];
        return *this;
    }

    template<typename T>
    Matrix2x4<T> &Matrix2x4<T>::operator+=(const T &value) {
        (*this)[0][0] += value;
        (*this)[0][1] += value;
        (*this)[0][2] += value;
        (*this)[0][3] += value;
        (*this)[1][0] += value;
        (*this)[1][1] += value;
        (*this)[1][2] += value;
        (*this)[1][3] += value;
        return *this;
    }

    template<typename T>
    Matrix2x4<T> Matrix2x4<T>::operator-(const Matrix2x4<T> &matrix) const {
        return Matrix2x4<T>(
                (*this)[0][0] - matrix[0][0],
                (*this)[0][1] - matrix[0][1],
                (*this)[0][2] - matrix[0][2],
                (*this)[0][3] - matrix[0][3],
                (*this)[1][0] - matrix[1][0],
                (*this)[1][1] - matrix[1][1],
                (*this)[1][2] - matrix[1][2],
                (*this)[1][3] - matrix[1][3]
        );
    }

    template<typename T>
    Matrix2x4<T> Matrix2x4<T>::operator-(const T &value) const {
        return Matrix2x4<T>(
                (*this)[0][0] - value,
                (*this)[0][1] - value,
                (*this)[0][2] - value,
                (*this)[0][3] - value,
                (*this)[1][0] - value,
                (*this)[1][1] - value,
                (*this)[1][2] - value,
                (*this)[1][3] - value
        );
    }

    template<typename T>
    Matrix2x4<T> &Matrix2x4<T>::operator-=(const Matrix2x4<T> &matrix) {
        (*this)[0][0] -= matrix[0][0];
        (*this)[0][1] -= matrix[0][1];
        (*this)[0][2] -= matrix[0][2];
        (*this)[0][3] -= matrix[0][3];
        (*this)[1][0] -= matrix[1][0];
        (*this)[1][1] -= matrix[1][1];
        (*this)[1][2] -= matrix[1][2];
        (*this)[1][3] -= matrix[1][3];
        return *this;
    }

    template<typename T>
    Matrix2x4<T> &Matrix2x4<T>::operator-=(const T &value) {
        (*this)[0][0] -= value;
        (*this)[0][1] -= value;
        (*this)[0][2] -= value;
        (*this)[0][3] -= value;
        (*this)[1][0] -= value;
        (*this)[1][1] -= value;
        (*this)[1][2] -= value;
        (*this)[1][3] -= value;
        return *this;
    }

    template<typename T>
    Matrix2x4<T> Matrix2x4<T>::operator*(const T &value) const {
        return Matrix2x4<T>(
                (*this)[0][0] * value,
                (*this)[0][1] * value,
                (*this)[0][2] * value,
                (*this)[0][3] * value,
                (*this)[1][0] * value,
                (*this)[1][1] * value,
                (*this)[1][2] * value,
                (*this)[1][3] * value
        );
    }

    template<typename T>
    Matrix2x4<T> &Matrix2x4<T>::operator*=(const T &value) {
        (*this)[0][0] *= value;
        (*this)[0][1] *= value;
        (*this)[0][2] *= value;
        (*this)[0][3] *= value;
        (*this)[1][0] *= value;
        (*this)[1][1] *= value;
        (*this)[1][2] *= value;
        (*this)[1][3] *= value;
        return *this;
    }

    template<typename T>
    Vector2<T> Matrix2x4<T>::operator*(const Vector4<T> &vector) const {
        return Vector2<T>(
                ((*this)[0][0] * vector.x) + ((*this)[0][1] * vector.y) + ((*this)[0][2] * vector.z) + ((*this)[0][3] * vector.w),
                ((*this)[1][0] * vector.x) + ((*this)[1][1] * vector.y) + ((*this)[1][2] * vector.z) + ((*this)[1][3] * vector.w)
        );
    }

    template<typename T>
    Matrix2x4<T> Matrix2x4<T>::operator*(const Matrix4<T> &matrix) const {
        return Matrix2x4<T>(
                ((*this)[0][0] * matrix[0][0]) + ((*this)[0][1] * matrix[1][0]) + ((*this)[0][2] * matrix[2][0]) + ((*this)[0][3] * matrix[3][0]),
                ((*this)[0][0] * matrix[0][1]) + ((*this)[0][1] * matrix[1][1]) + ((*this)[0][2] * matrix[2][1]) + ((*this)[0][3] * matrix[3][1]),
                ((*this)[0][0] * matrix[0][2]) + ((*this)[0][1] * matrix[1][2]) + ((*this)[0][2] * matrix[2][2]) + ((*this)[0][3] * matrix[3][2]),
                ((*this)[0][0] * matrix[0][3]) + ((*this)[0][1] * matrix[1][3]) + ((*this)[0][2] * matrix[2][3]) + ((*this)[0][3] * matrix[3][3]),
                ((*this)[1][0] * matrix[0][0]) + ((*this)[1][1] * matrix[1][0]) + ((*this)[1][2] * matrix[2][0]) + ((*this)[1][3] * matrix[3][0]),
                ((*this)[1][0] * matrix[0][1]) + ((*this)[1][1] * matrix[1][1]) + ((*this)[1][2] * matrix[2][1]) + ((*this)[1][3] * matrix[3][1]),
                ((*this)[1][0] * matrix[0][2]) + ((*this)[1][1] * matrix[1][2]) + ((*this)[1][2] * matrix[2][2]) + ((*this)[1][3] * matrix[3][2]),
                ((*this)[1][0] * matrix[0][3]) + ((*this)[1][1] * matrix[1][3]) + ((*this)[1][2] * matrix[2][3]) + ((*this)[1][3] * matrix[3][3])
                );
    }

    template<typename T>
    Matrix2x3<T> Matrix2x4<T>::operator*(const Matrix4x3<T> &matrix) const {
        return Matrix2x3<T>(
                ((*this)[0][0] * matrix[0][0]) + ((*this)[0][1] * matrix[1][0]) + ((*this)[0][2] * matrix[2][0]) + ((*this)[0][3] * matrix[3][0]),
                ((*this)[0][0] * matrix[0][1]) + ((*this)[0][1] * matrix[1][1]) + ((*this)[0][2] * matrix[2][1]) + ((*this)[0][3] * matrix[3][1]),
                ((*this)[0][0] * matrix[0][2]) + ((*this)[0][1] * matrix[1][2]) + ((*this)[0][2] * matrix[2][2]) + ((*this)[0][3] * matrix[3][2]),
                ((*this)[1][0] * matrix[0][0]) + ((*this)[1][1] * matrix[1][0]) + ((*this)[1][2] * matrix[2][0]) + ((*this)[1][3] * matrix[3][0]),
                ((*this)[1][0] * matrix[0][1]) + ((*this)[1][1] * matrix[1][1]) + ((*this)[1][2] * matrix[2][1]) + ((*this)[1][3] * matrix[3][1]),
                ((*this)[1][0] * matrix[0][2]) + ((*this)[1][1] * matrix[1][2]) + ((*this)[1][2] * matrix[2][2]) + ((*this)[1][3] * matrix[3][2])
        );
    }

    template<typename T>
    Matrix2<T> Matrix2x4<T>::operator*(const Matrix4x2<T> &matrix) const {
        return Matrix2<T>(
                ((*this)[0][0] * matrix[0][0]) + ((*this)[0][1] * matrix[1][0]) + ((*this)[0][2] * matrix[2][0]) + ((*this)[0][3] * matrix[3][0]),
                ((*this)[0][0] * matrix[0][1]) + ((*this)[0][1] * matrix[1][1]) + ((*this)[0][2] * matrix[2][1]) + ((*this)[0][3] * matrix[3][1]),
                ((*this)[1][0] * matrix[0][0]) + ((*this)[1][1] * matrix[1][0]) + ((*this)[1][2] * matrix[2][0]) + ((*this)[1][3] * matrix[3][0]),
                ((*this)[1][0] * matrix[0][1]) + ((*this)[1][1] * matrix[1][1]) + ((*this)[1][2] * matrix[2][1]) + ((*this)[1][3] * matrix[3][1])
        );
    }

    template<typename T>
    Matrix2x4<T> Matrix2x4<T>::operator/(const T &value) const {
        return Matrix2x4<T>(
                (*this)[0][0] / value,
                (*this)[0][1] / value,
                (*this)[0][2] / value,
                (*this)[0][3] / value,
                (*this)[1][0] / value,
                (*this)[1][1] / value,
                (*this)[1][2] / value,
                (*this)[1][3] / value
        );
    }

    template<typename T>
    Matrix2x4<T> &Matrix2x4<T>::operator/=(const T &value) {
        (*this)[0][0] /= value;
        (*this)[0][1] /= value;
        (*this)[0][2] /= value;
        (*this)[0][3] /= value;
        (*this)[1][0] /= value;
        (*this)[1][1] /= value;
        (*this)[1][2] /= value;
        (*this)[1][3] /= value;
        return *this;
    }
}

