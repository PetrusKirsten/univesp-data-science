#include <algorithm>
#include "measurement_avl.h"


// ==========================
// class setup
// ==========================

MeasurementAVL::MeasurementAVL() : root(nullptr) {}

MeasurementAVL::~MeasurementAVL() {
    destroy(root);
    root = nullptr;
}

// ==========================
// public functions (API)
// ==========================

void MeasurementAVL::add(std::int64_t timestamp, double value) {
   root = insert(root, timestamp, value);
}

bool MeasurementAVL::remove(std::int64_t timestamp) {
    bool removed = false;
    root = removeNode(root, timestamp, removed);
    return removed;
}

MeasurementAVL::RangeResult MeasurementAVL::range(std::int64_t t1, std::int64_t t2) const {
    if (t1 > t2) return {};
    return rangeImpl(root, t1, t2);
}

// ==========================
// internal implementations
// ==========================

MeasurementAVL::Node* MeasurementAVL::insert(Node* node, std::int64_t ts, double value) {
    if (!node) {
        return new Node(ts, value);
    }

    if (ts < node->ts) {
        node->left = insert(node->left, ts, value);
    } else if (ts > node->ts) {
        node->right = insert(node->right, ts, value);
    } else {
        node->value = value;
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int bf = balanceFactor(node);

    // Left Left
    if (bf > 1 && ts < node->left->ts)
        return rotateRight(node);

    // Right Right
    if (bf < -1 && ts > node->right->ts)
        return rotateLeft(node);

    // Left Right
    if (bf > 1 && ts > node->left->ts) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left
    if (bf < -1 && ts < node->right->ts) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

MeasurementAVL::Node* MeasurementAVL::removeNode(Node* node, std::int64_t ts, bool& removed) {
    if (!node) return nullptr;

    if (ts < node->ts) {
        node->left = removeNode(node->left, ts, removed);
    } else if (ts > node->ts) {
        node->right = removeNode(node->right, ts, removed);
    } else {
        removed = true;

        // caso 0 ou 1 filho
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // caso 2 filhos
        Node* temp  = minValueNode(node->right);
        node->ts    = temp->ts;
        node->value = temp->value;
        node->right = removeNode(node->right, temp->ts, removed);
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int bf = balanceFactor(node);

    // Left heavy
    if (bf > 1) {
        if (balanceFactor(node->left) >= 0) {
            return rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    // Right heavy
    if (bf < -1) {
        if (balanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
    return node;
}

MeasurementAVL::Node* MeasurementAVL::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

MeasurementAVL::RangeResult MeasurementAVL::rangeImpl(const Node* node, std::int64_t t1, std::int64_t t2) {
    if (!node) return {};

    if (node->ts < t1) {
        return rangeImpl(node->right, t1, t2);
    }
    if (node->ts > t2) {
        return rangeImpl(node->left, t1, t2);
    }

    RangeResult res;
    auto leftRes  = rangeImpl(node->left, t1, t2);
    auto rightRes = rangeImpl(node->right, t1, t2);

    res.count = leftRes.count + rightRes.count + 1;
    res.sum   = leftRes.sum + rightRes.sum + node->value;
    
    return res;
}

void MeasurementAVL::destroy(Node* node) {
    if (!node) return;
    
    destroy(node->left);
    destroy(node->right);  

    delete node;
}

// ==========================
// helpers
// ==========================

int MeasurementAVL::height(const Node* node) {
    if (!node) return -1;
    return node->height;
}

int MeasurementAVL::balanceFactor(const Node* node) {
    return height(node->left) - height(node->right);
}

MeasurementAVL::Node* MeasurementAVL::rotateRight(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

MeasurementAVL::Node* MeasurementAVL::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return y;
}

