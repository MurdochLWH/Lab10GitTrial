#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <map>

template <class T, class U>
class Map{
private:
    /// Internal encapsulation of the standard library map
    std::map<T, U> data;
public:
    /// Default Constructor
    Map();
    /// Destructor
    ~Map();
    /// Copy Constructor
    Map(const Map& other);
    /// Copy assignment operator
    Map& operator=(const Map& other);
    /// Move constructor
    Map(Map&& other)noexcept;
    /// Move assignment operator
    Map& operator=(Map&& other)noexcept;

    /**@brief Inserts a new key-value pair or update the value if the key already exists.
     * @return bool - True -> new key inserted, False -> exisitng value updated
     */
    bool insert(const T& key, const U& value);

    /**@brief Retrieves the value with provided key.
     * @param key - const T&
     * @return const U& - const reference of U
     * @throws std::out_of_range if the key is not found.
     */
    const U& find(const T& key) const;

    /**@brief Checks if key exists in map.
     * @return bool - True -> key present, False -> key absent.
     */
    bool contains(const T& key) const;

    /**@brief Returns the number of key-value associations in the map.
     * @return size_t - The number of elements.
     */
    size_t size() const;
};

template <class T, class U>
Map<T, U>::Map():data() {}

template <class T, class U>
Map<T, U>::~Map() {}

template <class T, class U>
Map<T, U>::Map(const Map& other) {
    data(other.data);
}

template <class T, class U>
Map<T,U>& Map<T, U>::operator=(const Map& other){
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

template <class T, class U>
Map<T, U>::Map(Map&& other)noexcept : data(std::move(other.data)) {}

template <class T, class U>
Map<T,U>& Map<T, U>::operator=(Map&& other)noexcept {
    data = std::move(other.data);
    return *this;
}

template <class T, class U>
bool Map<T, U>::insert(const T& key, const U& value) {
    bool inserted = data.find(key) == data.end();
    data[key] = value;
    return inserted;
}

template <class T, class U>
const U& Map<T, U>::find(const T& key) const {
    auto it = data.find(key);
    if (it == data.end()) {
        throw std::out_of_range("Map::find() - Key not found.");
    }
    return it->second;
}

template <class T, class U>
bool Map<T, U>::contains(const T& key) const {
    return data.count(key) > 0;
}

template <class T, class U>
size_t Map<T, U>::size()const{
    return data.size();
}

#endif // MAP_H_INCLUDED
