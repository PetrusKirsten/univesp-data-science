#pragma once

#include <cstdint> // int64_t

class MeasurementAVL {

    public:
        struct RangeResult {
            std::int64_t count = 0;
            double       sum   = 0.0;
        };

        MeasurementAVL();
        ~MeasurementAVL();

        void        add(std::int64_t timestamp, double value);
        bool        remove(std::int64_t timestamp);
        RangeResult range(std::int64_t t1, std::int64_t t2) const;

    private:
        struct Node {
            std::int64_t ts;
            double       value;
            Node*        left;
            Node*        right;
            int          height;

            Node(std::int64_t t, double v) 
                : ts(t), value(v), left(nullptr), right(nullptr), height(0) {}
        };

        Node* root;
        
        // core ops
        static Node* insert(Node* node, std::int64_t ts, double value);
        static Node* removeNode(Node* node, std::int64_t ts, bool& removed);
        static Node* minValueNode(Node* node);

        // queries / cleanup
        static RangeResult rangeImpl(const Node*, std::int64_t t1, std::int64_t t2);  // return count and sum in the interval [t1, t2]
        static void destroy(Node* node);

        // AVL helpers
        static int height(const Node* node);
        static int balanceFactor(const Node* node);
        static Node* rotateRight(Node* y);
        static Node* rotateLeft(Node* x);

};
