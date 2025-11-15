#ifndef VECTOR_H
#define VECTOR_H
#include <vector>

// The class interface/declaration must have Doxygen comments – put these in
// Follow the style in modelfile.h

template <class T>
class Vector   // This is NOT the std::vector.
{
	public:
	    /** @brief Default Constructor for Vector
        */
	    Vector();

	    /** @brief Constructor for Vector
       *
       * @param n - number int
       *
       */
		Vector(int n); // done for you

		/** @brief Copy Constructor for Vector
       *
       * @param other - Vector&
       *
       */
		Vector(const Vector& other);

		/** @brief Destructor for Vector
       */
		~Vector();

        /** @brief Get size of Vector
       *
       * @return int
       *
       */
        int size() const;

        /** @brief Add to back of Vector
       *
       * @param obj - T&
       * @return void
       *
       */
        void push_back(const T& obj);

        /** @brief Get Value from Vector via Index
       *
       * @param n - Index number
       * @return T&
       *
       */
        T& operator[](int index);

        /** @brief Get Value from Vector via Index (const)
       *
       * @param n - Index number
       * @return T& (const)
       *
       */
       const T& operator[](int index) const;

        /** @brief Copy Value from another Vector
       *
       * @param vec - Vector&
       * @return Vector&
       *
       */
        Vector& operator=(const Vector& vec);

        /// Iterators
        typename std::vector<T>::iterator begin() { return data.begin(); }
        typename std::vector<T>::iterator end() { return data.end(); }

        /// Const iterators
        typename std::vector<T>::const_iterator begin() const { return data.cbegin(); }
        typename std::vector<T>::const_iterator end() const { return data.cend(); }
// you fill in the rest and include Doxygen comments
// Don’t forget rule of 3  given the requirements of this
// Vector. Violation means damaged Vector
// make sure only method declarations are here, otherwise
// no marks can be given.
// So do not clutter the class declaration and keep the class
// interface clean.
// operator[] is required/mandatory
	private:
	    /// Data type of vector
        std::vector<T> data;
		// the encapsulated dynamic array
		// fill in ..
};  // end of interface/declaration of the template class


// class implementation follows with normal comments
// you fill in the rest
// for template classes, the implementation is in .h below the interface/declaration shown above.
// Do not put the implementation in a .cpp file.
// The compiler can’t create an object file from an unbound type
// in a template implementation in a .cpp file
// Read the textbook for an explanation.

template<class T>
Vector<T>::Vector():data() {}

template<class T>
Vector<T>::Vector(int n):data(n) {}

template<class T>
Vector<T>::~Vector(){}

template<class T>
Vector<T>::Vector(const Vector& other): data(other.data) {}

template<class T>
int Vector<T>::size() const{
    return data.size();
}

template<class T>
void Vector<T>::push_back(const T& obj) {
    data.push_back(obj);
}

template<class T>
T& Vector<T>::operator[](int index) {
    return data[index];
}

template<class T>
const T& Vector<T>::operator[](int index) const{
    return data[index];
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec){
    if (this != &vec) {
        data = vec.data;
    }
    return *this;
}

#endif
