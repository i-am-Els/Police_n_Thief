//
// Created by AWA on 30/10/2023.
//
#pragma once//
// Created by AWA on 30/10/2023.
//

#pragma once

#include "vector2.h"
#include "vector4.h"
#include "core.h"

namespace isle_engine::math
{
    template<typename T>
    class Matrix4x2;

    template<typename T>
    class Matrix4x3;

    template<typename T>
    class ISLE_API Matrix4
    {
    private:
        T m_data[4][4];
    public:
        Matrix4();
        explicit Matrix4(const T &value);
        explicit Matrix4(const T (&data)[16]);
        Matrix4(const T &r00, const T &r01, const T &r02, const T &r03, const T &r10, const T &r11, const T &r12, const T &r13, const T &r20, const T &r21, const T &r22, const T &r23, const T &r30, const T &r31, const T &r32, const T &r33);
        explicit Matrix4(const T (&data)[4][4]);
        Matrix4(const Matrix4<T> &matrix);
        Matrix4(const Vector4<T> &r1, const Vector4<T> &r2, const Vector4<T> &r3, const Vector4<T> &r4);
        explicit Matrix4(const Vector4<T> &vector);
        ~Matrix4();

        static Matrix4<T> identity();

        // Operator overloads----------------------------------------------
        T *operator[](int index);
        const T *operator[](int index) const;

        Matrix4<T> operator+(const Matrix4<T> &matrix) const;
        Matrix4<T> operator+(const T &value) const;
        Matrix4<T> &operator+=(const Matrix4<T> &matrix);
        Matrix4<T> &operator+=(const T &value);

        Matrix4<T> operator-(const Matrix4<T> &matrix) const;
        Matrix4<T> operator-(const T &value) const;
        Matrix4<T> &operator-=(const Matrix4<T> &matrix);
        Matrix4<T> &operator-=(const T &value);

        Matrix4<T> operator*(const T &value) const;
        Matrix4<T> &operator*=(const T &value);

        Vector4<T> operator*(const Vector4<T> &vector) const;
        Matrix4x2<T> operator*(const Matrix4x2<T> &matrix) const;
        Matrix4x3<T> operator*(const Matrix4x3<T> &matrix) const;
        Matrix4<T> operator*(const Matrix4<T> &matrix) const;

        Matrix4<T> operator/(const T &value) const;
        Matrix4<T> &operator/=(const T &value);

        Matrix4<T> transpose() const;
    };

    template<typename T>
    Matrix4<T> Matrix4<T>::identity() {
        return Matrix4 <T> (
                1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f
                );
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::transpose() const {
        return Matrix4<T>(
                m_data[0][0],
                m_data[1][0],
                m_data[2][0],
                m_data[3][0],
                m_data[0][1],
                m_data[1][1],
                m_data[2][1],
                m_data[3][1],
                m_data[0][2],
                m_data[1][2],
                m_data[2][2],
                m_data[3][2],
                m_data[0][3],
                m_data[1][3],
                m_data[2][3],
                m_data[3][3]
        );
    }

    template<typename T>
    Matrix4<T>::Matrix4(): m_data{{}}
    {
    }

    template<typename T>
    Matrix4<T>::Matrix4(const T &value) : m_data{value, value, value, value, value, value, value, value, value, value, value, value, value, value, value, value}
    {
    }

    template<typename T>
    Matrix4<T>::Matrix4(const T (&data)[16]): m_data{data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]}
    {
    }

    template<typename T>
    Matrix4<T>::Matrix4(const T &r00, const T &r01, const T &r02, const T &r03, const T &r10, const T &r11, const T &r12, const T &r13, const T &r20, const T &r21, const T &r22, const T &r23, const T &r30, const T &r31, const T &r32, const T &r33)
            : m_data{r00, r01, r02, r03, r10, r11, r12, r13, r20, r21, r22, r23, r30, r31, r32, r33}
    {
    }

    template<typename T>
    Matrix4<T>::Matrix4(const T (&data)[4][4])
            : m_data{data[0][0], data[0][1], data[0][2], data[0][3],
                     data[1][0], data[1][1], data[1][2], data[1][3],
                     data[2][0], data[2][1], data[2][2], data[2][3],
                     data[3][0], data[3][1], data[3][2], data[3][3]}
    {
    }

    template<typename T>
    Matrix4<T>::Matrix4(const Matrix4<T> &matrix)
            : m_data{matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3],
                    matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3],
                    matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3],
                    matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3]}
    {
    }

    template<typename T>
    Matrix4<T>::Matrix4(const Vector4<T> &r1, const Vector4<T> &r2, const Vector4<T> &r3, const Vector4<T> &r4)
            : m_data{r1.x, r1.y, r1.z, r1.w, r2.x, r2.y. r2.z, r2.w, r3.x, r3.y. r3.z, r3.w, r4.x, r4.y. r4.z, r4.w}
    {
    }

    template<typename T>
    Matrix4<T>::Matrix4(const Vector4<T> &vector)
            : m_data{vector.x, vector.y, vector.z, vector.w, vector.x, vector.y, vector.z, vector.w, vector.x, vector.y, vector.z, vector.w, vector.x, vector.y, vector.z, vector.w}
    {
    }

    template<typename T>
    Matrix4<T>::~Matrix4() = default;

    // Operator overloads----------------------------------------------
    template<typename T>
    T *Matrix4<T>::operator[](int index) {
        try{
            return m_data[index];
        }
        catch(...){
            std::cout << "Index out of Bounds!"<< std::endl;
        }
    }

    template<typename T>
    const T *Matrix4<T>::operator[](int index) const {
        try{
            return m_data[index];
        }
        catch(...){
            std::cout << "Index out of Bounds!"<< std::endl;
        }
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::operator+(const Matrix4<T> &matrix) const {

        return Matrix4<T>(
                matrix[0][0] + (*this)[0][0],
                matrix[0][1] + (*this)[0][1],
                matrix[0][2] + (*this)[0][2],
                matrix[0][3] + (*this)[0][3],
                matrix[1][0] + (*this)[1][0],
                matrix[1][1] + (*this)[1][1],
                matrix[1][2] + (*this)[1][2],
                matrix[1][3] + (*this)[1][3],
                matrix[2][0] + (*this)[2][0],
                matrix[2][1] + (*this)[2][1],
                matrix[2][2] + (*this)[2][2],
                matrix[2][3] + (*this)[2][3],
                matrix[3][0] + (*this)[3][0],
                matrix[3][1] + (*this)[3][1],
                matrix[3][2] + (*this)[3][2],
                matrix[3][3] + (*this)[3][3]
        );
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::operator+(const T &value) const {
        return Matrix4<T>(
                (*this)[0][0] + value,
                (*this)[0][1] + value,
                (*this)[0][2] + value,
                (*this)[0][3] + value,
                (*this)[1][0] + value,
                (*this)[1][1] + value,
                (*this)[1][2] + value,
                (*this)[1][3] + value,
                (*this)[2][0] + value,
                (*this)[2][1] + value,
                (*this)[2][2] + value,
                (*this)[2][3] + value,
                (*this)[3][0] + value,
                (*this)[3][1] + value,
                (*this)[3][2] + value,
                (*this)[3][3] + value
        );
    }

    template<typename T>
    Matrix4<T> &Matrix4<T>::operator+=(const Matrix4<T> &matrix) {
        (*this)[0][0] += matrix[0][0];
        (*this)[0][1] += matrix[0][1];
        (*this)[0][2] += matrix[0][2];
        (*this)[0][3] += matrix[0][3];
        (*this)[1][0] += matrix[1][0];
        (*this)[1][1] += matrix[1][1];
        (*this)[1][2] += matrix[1][2];
        (*this)[1][3] += matrix[1][3];
        (*this)[2][0] += matrix[2][0];
        (*this)[2][1] += matrix[2][1];
        (*this)[2][2] += matrix[2][2];
        (*this)[2][3] += matrix[2][3];
        (*this)[3][0] += matrix[3][0];
        (*this)[3][1] += matrix[3][1];
        (*this)[3][2] += matrix[3][2];
        (*this)[3][3] += matrix[3][3];
        return *this;
    }

    template<typename T>
    Matrix4<T> &Matrix4<T>::operator+=(const T &value) {
        (*this)[0][0] += value,
        (*this)[0][1] += value;
        (*this)[0][2] += value;
        (*this)[0][3] += value;
        (*this)[1][0] += value;
        (*this)[1][1] += value;
        (*this)[1][2] += value;
        (*this)[1][3] += value;
        (*this)[2][0] += value;
        (*this)[2][1] += value;
        (*this)[2][2] += value;
        (*this)[2][3] += value;
        (*this)[3][0] += value;
        (*this)[3][1] += value;
        (*this)[3][2] += value;
        (*this)[3][3] += value;
        return *this;
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::operator-(const Matrix4<T> &matrix) const {
        return Matrix4<T>(
                (*this)[0][0] - matrix[0][0],
                (*this)[0][1] - matrix[0][1],
                (*this)[0][2] - matrix[0][2],
                (*this)[0][3] - matrix[0][3],
                (*this)[1][0] - matrix[1][0],
                (*this)[1][1] - matrix[1][1],
                (*this)[1][2] - matrix[1][2],
                (*this)[1][3] - matrix[1][3],
                (*this)[2][0] - matrix[2][0],
                (*this)[2][1] - matrix[2][1],
                (*this)[2][2] - matrix[2][2],
                (*this)[2][3] - matrix[2][3],
                (*this)[3][0] - matrix[3][0],
                (*this)[3][1] - matrix[3][1],
                (*this)[3][2] - matrix[3][2],
                (*this)[3][3] - matrix[3][3]
        );
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::operator-(const T &value) const {
        return Matrix4<T>(
                (*this)[0][0] - value,
                (*this)[0][1] - value,
                (*this)[0][2] - value,
                (*this)[0][3] - value,
                (*this)[1][0] - value,
                (*this)[1][1] - value,
                (*this)[1][2] - value,
                (*this)[1][3] - value,
                (*this)[2][0] - value,
                (*this)[2][1] - value,
                (*this)[2][2] - value,
                (*this)[2][3] - value,
                (*this)[3][0] - value,
                (*this)[3][1] - value,
                (*this)[3][2] - value,
                (*this)[3][3] - value
        );
    }

    template<typename T>
    Matrix4<T> &Matrix4<T>::operator-=(const Matrix4<T> &matrix) {
        (*this)[0][0] -= matrix[0][0];
        (*this)[0][1] -= matrix[0][1];
        (*this)[0][2] -= matrix[0][2];
        (*this)[0][3] -= matrix[0][3];
        (*this)[1][0] -= matrix[1][0];
        (*this)[1][1] -= matrix[1][1];
        (*this)[1][2] -= matrix[1][2];
        (*this)[1][3] -= matrix[1][3];
        (*this)[2][0] -= matrix[2][0];
        (*this)[2][1] -= matrix[2][1];
        (*this)[2][2] -= matrix[2][2];
        (*this)[2][3] -= matrix[2][3];
        (*this)[3][0] -= matrix[3][0];
        (*this)[3][1] -= matrix[3][1];
        (*this)[3][2] -= matrix[3][2];
        (*this)[3][3] -= matrix[3][3];
        return *this;
    }

    template<typename T>
    Matrix4<T> &Matrix4<T>::operator-=(const T &value) {
        (*this)[0][0] -= value,
        (*this)[0][1] -= value;
        (*this)[0][2] -= value;
        (*this)[0][3] -= value;
        (*this)[1][0] -= value;
        (*this)[1][1] -= value;
        (*this)[1][2] -= value;
        (*this)[1][3] -= value;
        (*this)[2][0] -= value;
        (*this)[2][1] -= value;
        (*this)[2][2] -= value;
        (*this)[2][3] -= value;
        (*this)[3][0] -= value;
        (*this)[3][1] -= value;
        (*this)[3][2] -= value;
        (*this)[3][3] -= value;
        return *this;
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::operator*(const T &value) const {
        return Matrix4<T>(
                (*this)[0][0] * value,
                (*this)[0][1] * value,
                (*this)[0][2] * value,
                (*this)[0][3] * value,
                (*this)[1][0] * value,
                (*this)[1][1] * value,
                (*this)[1][2] * value,
                (*this)[1][3] * value,
                (*this)[2][0] * value,
                (*this)[2][1] * value,
                (*this)[2][2] * value,
                (*this)[2][3] * value,
                (*this)[3][0] * value,
                (*this)[3][1] * value,
                (*this)[3][2] * value,
                (*this)[3][3] * value
        );
    }

    template<typename T>
    Matrix4<T> &Matrix4<T>::operator*=(const T &value) {
        (*this)[0][0] *= value;
        (*this)[0][1] *= value;
        (*this)[0][2] *= value;
        (*this)[0][3] *= value;
        (*this)[1][0] *= value;
        (*this)[1][1] *= value;
        (*this)[1][2] *= value;
        (*this)[1][3] *= value;
        (*this)[2][0] *= value;
        (*this)[2][1] *= value;
        (*this)[2][2] *= value;
        (*this)[2][3] *= value;
        (*this)[3][0] *= value;
        (*this)[3][1] *= value;
        (*this)[3][2] *= value;
        (*this)[3][3] *= value;
        return *this;
    }

    template<typename T>
    Vector4<T> Matrix4<T>::operator*(const Vector4<T> &vector) const {
        return Vector4<T>(
                ((*this)[0][0] * vector.x) + ((*this)[0][1] * vector.y) + ((*this)[0][2] * vector.z) + ((*this)[0][3] * vector.w),
                ((*this)[1][0] * vector.x) + ((*this)[1][1] * vector.y) + ((*this)[1][2] * vector.z) + ((*this)[1][3] * vector.w),
                ((*this)[2][0] * vector.x) + ((*this)[2][1] * vector.y) + ((*this)[2][2] * vector.z) + ((*this)[2][3] * vector.w),
                ((*this)[3][0] * vector.x) + ((*this)[3][1] * vector.y) + ((*this)[3][2] * vector.z) + ((*this)[3][3] * vector.w)
        );
    }


    template<typename T>
    Matrix4x2<T> Matrix4<T>::operator*(const Matrix4x2<T> &matrix) const {
        return Matrix4x2<T>(
                ((*this)[0][0] * matrix[0][0]) + ((*this)[0][1] * matrix[1][0]) + ((*this)[0][2] * matrix[2][0]) + ((*this)[0][3] * matrix[3][0]),
                ((*this)[0][0] * matrix[0][1]) + ((*this)[0][1] * matrix[1][1]) + ((*this)[0][2] * matrix[2][1]) + ((*this)[0][3] * matrix[3][1]),

                ((*this)[1][0] * matrix[0][0]) + ((*this)[1][1] * matrix[1][0]) + ((*this)[1][2] * matrix[2][0]) + ((*this)[1][3] * matrix[3][0]),
                ((*this)[1][0] * matrix[0][1]) + ((*this)[1][1] * matrix[1][1]) + ((*this)[1][2] * matrix[2][1]) + ((*this)[1][3] * matrix[3][1]),

                ((*this)[2][0] * matrix[0][0]) + ((*this)[2][1] * matrix[1][0]) + ((*this)[2][2] * matrix[2][0]) + ((*this)[2][3] * matrix[3][0]),
                ((*this)[2][0] * matrix[0][1]) + ((*this)[2][1] * matrix[1][1]) + ((*this)[2][2] * matrix[2][1]) + ((*this)[2][3] * matrix[3][1]),

                ((*this)[3][0] * matrix[0][0]) + ((*this)[3][1] * matrix[1][0]) + ((*this)[3][2] * matrix[2][0]) + ((*this)[3][3] * matrix[3][0]),
                ((*this)[3][0] * matrix[0][1]) + ((*this)[3][1] * matrix[1][1]) + ((*this)[3][2] * matrix[2][1]) + ((*this)[3][3] * matrix[3][1])
        );
    }


    template<typename T>
    Matrix4x3<T> Matrix4<T>::operator*(const Matrix4x3<T> &matrix) const {
        return Matrix4x3<T>(
                ((*this)[0][0] * matrix[0][0]) + ((*this)[0][1] * matrix[1][0]) + ((*this)[0][2] * matrix[2][0]) + ((*this)[0][3] * matrix[3][0]),
                ((*this)[0][0] * matrix[0][1]) + ((*this)[0][1] * matrix[1][1]) + ((*this)[0][2] * matrix[2][1]) + ((*this)[0][3] * matrix[3][1]),
                ((*this)[0][0] * matrix[0][2]) + ((*this)[0][1] * matrix[1][2]) + ((*this)[0][2] * matrix[2][2]) + ((*this)[0][3] * matrix[3][2]),

                ((*this)[1][0] * matrix[0][0]) + ((*this)[1][1] * matrix[1][0]) + ((*this)[1][2] * matrix[2][0]) + ((*this)[1][3] * matrix[3][0]),
                ((*this)[1][0] * matrix[0][1]) + ((*this)[1][1] * matrix[1][1]) + ((*this)[1][2] * matrix[2][1]) + ((*this)[1][3] * matrix[3][1]),
                ((*this)[1][0] * matrix[0][2]) + ((*this)[1][1] * matrix[1][2]) + ((*this)[1][2] * matrix[2][2]) + ((*this)[1][3] * matrix[3][2]),

                ((*this)[2][0] * matrix[0][0]) + ((*this)[2][1] * matrix[1][0]) + ((*this)[2][2] * matrix[2][0]) + ((*this)[2][3] * matrix[3][0]),
                ((*this)[2][0] * matrix[0][1]) + ((*this)[2][1] * matrix[1][1]) + ((*this)[2][2] * matrix[2][1]) + ((*this)[2][3] * matrix[3][1]),
                ((*this)[2][0] * matrix[0][2]) + ((*this)[2][1] * matrix[1][2]) + ((*this)[2][2] * matrix[2][2]) + ((*this)[2][3] * matrix[3][2]),

                ((*this)[3][0] * matrix[0][0]) + ((*this)[3][1] * matrix[1][0]) + ((*this)[3][2] * matrix[2][0]) + ((*this)[3][3] * matrix[3][0]),
                ((*this)[3][0] * matrix[0][1]) + ((*this)[3][1] * matrix[1][1]) + ((*this)[3][2] * matrix[2][1]) + ((*this)[3][3] * matrix[3][1]),
                ((*this)[3][0] * matrix[0][2]) + ((*this)[3][1] * matrix[1][2]) + ((*this)[3][2] * matrix[2][2]) + ((*this)[3][3] * matrix[3][2])
        );
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::operator*(const Matrix4<T> &matrix) const {
        return Matrix4<T>(
                ((*this)[0][0] * matrix[0][0]) + ((*this)[0][1] * matrix[1][0]) + ((*this)[0][2] * matrix[2][0]) + ((*this)[0][3] * matrix[3][0]),
                ((*this)[0][0] * matrix[0][1]) + ((*this)[0][1] * matrix[1][1]) + ((*this)[0][2] * matrix[2][1]) + ((*this)[0][3] * matrix[3][1]),
                ((*this)[0][0] * matrix[0][2]) + ((*this)[0][1] * matrix[1][2]) + ((*this)[0][2] * matrix[2][2]) + ((*this)[0][3] * matrix[3][2]),
                ((*this)[0][0] * matrix[0][3]) + ((*this)[0][1] * matrix[1][3]) + ((*this)[0][2] * matrix[2][3]) + ((*this)[0][3] * matrix[3][3]),

                ((*this)[1][0] * matrix[0][0]) + ((*this)[1][1] * matrix[1][0]) + ((*this)[1][2] * matrix[2][0]) + ((*this)[1][3] * matrix[3][0]),
                ((*this)[1][0] * matrix[0][1]) + ((*this)[1][1] * matrix[1][1]) + ((*this)[1][2] * matrix[2][1]) + ((*this)[1][3] * matrix[3][1]),
                ((*this)[1][0] * matrix[0][2]) + ((*this)[1][1] * matrix[1][2]) + ((*this)[1][2] * matrix[2][2]) + ((*this)[1][3] * matrix[3][2]),
                ((*this)[1][0] * matrix[0][3]) + ((*this)[1][1] * matrix[1][3]) + ((*this)[1][2] * matrix[2][3]) + ((*this)[1][3] * matrix[3][3]),

                ((*this)[2][0] * matrix[0][0]) + ((*this)[2][1] * matrix[1][0]) + ((*this)[2][2] * matrix[2][0]) + ((*this)[2][3] * matrix[3][0]),
                ((*this)[2][0] * matrix[0][1]) + ((*this)[2][1] * matrix[1][1]) + ((*this)[2][2] * matrix[2][1]) + ((*this)[2][3] * matrix[3][1]),
                ((*this)[2][0] * matrix[0][2]) + ((*this)[2][1] * matrix[1][2]) + ((*this)[2][2] * matrix[2][2]) + ((*this)[2][3] * matrix[3][2]),
                ((*this)[2][0] * matrix[0][3]) + ((*this)[2][1] * matrix[1][3]) + ((*this)[2][2] * matrix[2][3]) + ((*this)[2][3] * matrix[3][3]),

                ((*this)[3][0] * matrix[0][0]) + ((*this)[3][1] * matrix[1][0]) + ((*this)[3][2] * matrix[2][0]) + ((*this)[3][3] * matrix[3][0]),
                ((*this)[3][0] * matrix[0][1]) + ((*this)[3][1] * matrix[1][1]) + ((*this)[3][2] * matrix[2][1]) + ((*this)[3][3] * matrix[3][1]),
                ((*this)[3][0] * matrix[0][2]) + ((*this)[3][1] * matrix[1][2]) + ((*this)[3][2] * matrix[2][2]) + ((*this)[3][3] * matrix[3][2]),
                ((*this)[3][0] * matrix[0][3]) + ((*this)[3][1] * matrix[1][3]) + ((*this)[3][2] * matrix[2][3]) + ((*this)[3][3] * matrix[3][3])
        );
    }

    template<typename T>
    Matrix4<T> Matrix4<T>::operator/(const T &value) const {
        return Matrix4<T>(
                (*this)[0][0] / value,
                (*this)[0][1] / value,
                (*this)[0][2] / value,
                (*this)[0][3] / value,
                (*this)[1][0] / value,
                (*this)[1][1] / value,
                (*this)[1][2] / value,
                (*this)[1][3] / value,
                (*this)[2][0] / value,
                (*this)[2][1] / value,
                (*this)[2][2] / value,
                (*this)[2][3] / value,
                (*this)[3][0] / value,
                (*this)[3][1] / value,
                (*this)[3][2] / value,
                (*this)[3][3] / value
        );
    }

    template<typename T>
    Matrix4<T> &Matrix4<T>::operator/=(const T &value) {
        (*this)[0][0] /= value;
        (*this)[0][1] /= value;
        (*this)[0][2] /= value;
        (*this)[0][3] /= value;
        (*this)[1][0] /= value;
        (*this)[1][1] /= value;
        (*this)[1][2] /= value;
        (*this)[1][3] /= value;
        (*this)[2][0] /= value;
        (*this)[2][1] /= value;
        (*this)[2][2] /= value;
        (*this)[2][3] /= value;
        (*this)[3][0] /= value;
        (*this)[3][1] /= value;
        (*this)[3][2] /= value;
        (*this)[3][3] /= value;
        return *this;
    }
}
