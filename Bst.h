#ifndef BST_H
#define BST_H
#include <iostream>


template <class T>
class Bst
{
	public:

	    using Action = void (*)(const T&);

	    /** @brief Default Constructor for Bst
        */
	    Bst();

	    /** @brief Constructor for Bst
       * @param val - T value for root Node
       */
		Bst(const T& val);

		/** @brief Copy Constructor for Bst
       * @param other - Bst&
       */
		Bst(const Bst& other);

		/** @brief Destructor for Bst
       */
		~Bst();

		/** @brief Copy Value from another Bst
       * @param other - Bst&
       * @return Bst&
       */
        Bst& operator=(const Bst& other);

        /** @brief Add value to Bst
       * @param obj - T&
       * @return void
       */
        void insert(const T& obj);

        /** @brief Search value from Bst, return true if found
       * @param obj - T&
       * @return bool
       */
        bool search(const T& obj)const;

        /** @brief Display value of Bst in order (L -> root -> R)
       * @return void
       */
        void inOrderTraversal() const;

        /** @brief Perform Action on Bst in order (L -> root -> R)
       * @return void
       */
        void inOrderTraversal(Action action) const;

        /** @brief Display value of Bst in pre order (root -> L -> R)
       * @return void
       */
        void preOrderTraversal() const;

        /** @brief Perform Action on Bst in pre order (root -> L -> R)
       * @return void
       */
        void preOrderTraversal(Action action) const;

        /** @brief Display value of Bst in post order (L -> R -> root)
       * @return void
       */
        void postOrderTraversal() const;

        /** @brief Perform Action on Bst in post order (L -> R -> root)
       * @return void
       */
        void postOrderTraversal(Action action) const;

        /** @brief Destroy and clear Bst
       * @return void
       */
        void destroyTree();

        /** @brief Check if the BST invariant property holds true, return true if tree is valid BST
       * @return bool
       */
        bool checkInvariant() const;

        /** @brief Check if the BST is empty, return true if BST is empty
       * @return bool
       */
        bool isEmpty() const { return root == nullptr; }


	private:
        struct Node {
            T data;
            Node* L;
            Node* R;

            Node(const T& val):data(val),L(nullptr),R(nullptr){}
        };
	    /// Root data of Bst
	    Node* root;

        /** @brief Helper function to insert value into Bst, returns updated current Node
       * @param node - Node*
       * @param val - T
       * @return Node*
       */
        Node* insertRecursive(Node* node, const T& val);

        /** @brief Helper function to search value in Bst, returns true if found
       * @param node - Node*
       * @param val - T
       * @return bool
       */
        bool searchRecursive(Node* node, const T& val)const;

        /** @brief Helper function to print value in order in Bst (L -> Node -> R)
       * @param node - Node*
       * @return void
       */
        void inOrderRecursive(Node* node)const;

        /** @brief Helper function to perform action in order in Bst (L -> Node -> R)
       * @param node - Node*
       * @return void
       */
        void inOrderRecursive(Node* node, Action action)const;

        /** @brief Helper function to print value in pre order in Bst (Node -> L -> R)
       * @param node - Node*
       * @return void
       */
        void preOrderRecursive(Node* node)const;

        /** @brief Helper function to perform action in pre order in Bst (Node -> L -> R)
       * @param node - Node*
       * @return void
       */
        void preOrderRecursive(Node* node, Action action)const;

        /** @brief Helper function to print value in post order in Bst (L -> R -> Node)
       * @param node - Node*
       * @return void
       */
        void postOrderRecursive(Node* node)const;

        /** @brief Helper function to perform action in post order in Bst (L -> R -> Node)
       * @param node - Node*
       * @return void
       */
        void postOrderRecursive(Node* node, Action action)const;

        /** @brief Helper function to delete value in Bst
       * @param node - Node*
       * @return void
       */
        void deleteRecursive(Node* node);

        /** @brief Helper function to copy value in Bst
       * @param node - Node*
       * @return Node*
       */
        Node* copyRecursive(const Node* node);

        /** @brief Helper function to check the BST invariant property, return true if invariant holds
       * @param node - Node*
       * @param minVal - T
       * @param maxVal - T
       * @return bool
       */
        bool checkRecursive(const Node* node,const T* minVal,const T* maxVal)const;
};

template<class T>
Bst<T>::Bst() {
    root=nullptr;
}

template<class T>
Bst<T>::Bst(const T& val){
    root= new Node(val);
}

template<class T>
Bst<T>::~Bst(){
    deleteRecursive(root);
}

template<class T>
Bst<T>::Bst(const Bst& other) {
    root= nullptr;
    root = copyRecursive(other.root);
}

template<class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other){
     if (this != &other) {
        // Destroy old resource
        destroyRecursive(root);
        root = nullptr;
        // Create new resource (deep copy)
        root = copyRecursive(other.root);
    }
    return *this;
}

template<class T>
void Bst<T>::insert(const T& val) {
    root = insertRecursive(root, val);
}

template<class T>
bool Bst<T>::search(const T& val)const {
    return searchRecursive(root, val);
}

template<class T>
void Bst<T>::inOrderTraversal() const {
    std::cout << "In-Order Traversal: ";
    inOrderRecursive(root);
    std::cout << std::endl;
}

template<class T>
void Bst<T>::inOrderTraversal(Action action) const {
    inOrderRecursive(root, action);
}

template<class T>
void Bst<T>::preOrderTraversal() const {
    std::cout << "Pre-Order Traversal: ";
    preOrderRecursive(root);
    std::cout << std::endl;
}

template<class T>
void Bst<T>::preOrderTraversal(Action action) const {
    preOrderRecursive(root, action);
}

template<class T>
void Bst<T>::postOrderTraversal() const {
    std::cout << "Post-Order Traversal: ";
    postOrderRecursive(root);
    std::cout << std::endl;
}

template<class T>
void Bst<T>::postOrderTraversal(Action action) const {
    postOrderRecursive(root, action);
}

template<class T>
void Bst<T>::destroyTree() {
    deleteRecursive(root);
    root = nullptr;
}

template<class T>
bool Bst<T>::checkInvariant() const {
    return checkRecursive(root, nullptr, nullptr);
}

template<class T>
typename Bst<T>::Node* Bst<T>::insertRecursive(Node* node, const T& val) {
    if (node == nullptr) {
        return new Bst<T>::Node(val);
    }
    if (node->data > val ) {
        node->L = insertRecursive(node->L, val);
    } else if (node->data < val) {
        node->R = insertRecursive(node->R, val);
    }
    // Duplicates are ignored.
    return node;
}

template<class T>
bool Bst<T>::searchRecursive(Node* node, const T& val) const {
    if (node == nullptr) {
        return false;
    }
    if (val == node->data) {
        return true;
    } else if (val < node->data) {
        return searchRecursive(node->L, val);
    } else {
        return searchRecursive(node->R, val);
    }
}

template<class T>
void Bst<T>::inOrderRecursive(Node* node) const {
    if (node != nullptr) {
        inOrderRecursive(node->L);
        std::cout << node->data << ",";
        inOrderRecursive(node->R);
    }
}

template<class T>
void Bst<T>::inOrderRecursive(Node* node, Action action) const {
    if (node != nullptr) {
        inOrderRecursive(node->L, action);
        action(node->data);
        inOrderRecursive(node->R, action);
    }
}

template<class T>
void Bst<T>::preOrderRecursive(Node* node) const {
    if (node != nullptr) {
        std::cout << node->data << ",";
        preOrderRecursive(node->L);
        preOrderRecursive(node->R);
    }
}

template<class T>
void Bst<T>::preOrderRecursive(Node* node, Action action) const {
    if (node != nullptr) {
        action(node->data);
        preOrderRecursive(node->L, action);
        preOrderRecursive(node->R, action);
    }
}

template<class T>
void Bst<T>::postOrderRecursive(Node* node) const {
    if (node != nullptr) {
        postOrderRecursive(node->L);
        postOrderRecursive(node->R);
        std::cout << node->data << ",";
    }
}

template<class T>
void Bst<T>::postOrderRecursive(Node* node, Action action) const {
    if (node != nullptr) {
        postOrderRecursive(node->L, action);
        postOrderRecursive(node->R, action);
        action(node->data);
    }
}

template<class T>
void Bst<T>::deleteRecursive(Node* node) {
    if (node != nullptr) {
        deleteRecursive(node->L);
        deleteRecursive(node->R);
        delete node;
    }
}

template<class T>
typename Bst<T>::Node* Bst<T>::copyRecursive(const Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    // Pre-order copy to build the structure
    Bst<T>::Node* newNode = new Bst<T>::Node(node->data);
    newNode->L = copyRecursive(node->L);
    newNode->R = copyRecursive(node->R);
    return newNode;
}

template<class T>
bool Bst<T>::checkRecursive(const Node* node, const T* minVal, const T* maxVal) const {
    if (node == nullptr) {
        return true;
    }
    // Check the current node against the valid range
    if ((minVal != nullptr && node->data <= *minVal) || (maxVal != nullptr && node->data >= *maxVal)) {
        std::cerr << "Invariant broken at node " << node->data << std::endl;
        return false;
    }
    // Check subtrees, tightening the bounds
    return checkRecursive(node->L, minVal, &(node->data)) &&
           checkRecursive(node->R, &(node->data), maxVal);
}


#endif
