
public class TwoFourTree {
    private class TwoFourTreeItem {
        int values = 1;
        int value1;
        int value2;
        int value3;
        boolean isLeaf = true;

        TwoFourTreeItem parent;
        TwoFourTreeItem leftChild;
        TwoFourTreeItem centerChild;
        TwoFourTreeItem rightChild;
        TwoFourTreeItem centerLeftChild;
        TwoFourTreeItem centerRightChild;

        public TwoFourTreeItem(int value1) {
            this.value1 = value1;
            this.values = 1;
        }

        public TwoFourTreeItem(int value1, int value2) {
            this.value1 = value1;
            this.value2 = value2;
            this.values = 2;
        }

        public TwoFourTreeItem(int value1, int value2, int value3) {
            this.value1 = value1;
            this.value2 = value2;
            this.value3 = value3;
            this.values = 3;
        }

        public boolean isTwoNode() {
            return values == 1;
        }

        public boolean isThreeNode() {
            return values == 2;
        }

        public boolean isFourNode() {
            return values == 3;
        }

        public boolean isRoot() {
            return parent == null;
        }

        private void printIndents(int indent) {
            for (int i = 0; i < indent; i++) System.out.printf("  ");
        }

        public void printInOrder(int indent) {
            if (!isLeaf) leftChild.printInOrder(indent + 1);
            printIndents(indent);
            System.out.printf("%d\n", value1);
            if (isThreeNode()) {
                if (!isLeaf) centerChild.printInOrder(indent + 1);
                printIndents(indent);
                System.out.printf("%d\n", value2);
            } else if (isFourNode()) {
                if (!isLeaf) centerLeftChild.printInOrder(indent + 1);
                printIndents(indent);
                System.out.printf("%d\n", value2);
                if (!isLeaf) centerRightChild.printInOrder(indent + 1);
                printIndents(indent);
                System.out.printf("%d\n", value3);
            }
            if (!isLeaf) rightChild.printInOrder(indent + 1);
        }
    }

    TwoFourTreeItem root = null;

    public boolean addValue(int value) {
        if (root == null) {
            root = new TwoFourTreeItem(value);
            return true;
        }
        return insert(root, value);
    }

    private boolean insert(TwoFourTreeItem node, int value) {
        if (node.isLeaf) {
            if (node.isTwoNode()) {
                if (value < node.value1) {
                    node.value2 = node.value1;
                    node.value1 = value;
                } else {
                    node.value2 = value;
                }
                node.values++;
                return true;
            } else if (node.isThreeNode()) {
                if (value < node.value1) {
                    node.value3 = node.value2;
                    node.value2 = node.value1;
                    node.value1 = value;
                } else if (value < node.value2) {
                    node.value3 = node.value2;
                    node.value2 = value;
                } else {
                    node.value3 = value;
                }
                node.values++;
                splitNode(node);
                return true;
            }
        } else {
            if (value < node.value1) {
                return insert(node.leftChild, value);
            } else if (node.isThreeNode() && value < node.value2) {
                return insert(node.centerChild, value);
            } else {
                return insert(node.rightChild, value);
            }
        }
        return false;
    }

    private void splitNode(TwoFourTreeItem node) {
        int middleValue = node.value2;

        TwoFourTreeItem leftNode = new TwoFourTreeItem(node.value1);
        TwoFourTreeItem rightNode = new TwoFourTreeItem(node.value3);

        if (!node.isLeaf) {
            leftNode.isLeaf = false;
            leftNode.leftChild = node.leftChild;
            leftNode.rightChild = node.centerLeftChild;
            rightNode.isLeaf = false;
            rightNode.leftChild = node.centerRightChild;
            rightNode.rightChild = node.rightChild;

            if (leftNode.leftChild != null) leftNode.leftChild.parent = leftNode;
            if (leftNode.rightChild != null) leftNode.rightChild.parent = leftNode;
            if (rightNode.leftChild != null) rightNode.leftChild.parent = rightNode;
            if (rightNode.rightChild != null) rightNode.rightChild.parent = rightNode;
        }

        if (node.parent != null) {
            TwoFourTreeItem parent = node.parent;

            if (parent.isTwoNode()) {
                if (middleValue < parent.value1) {
                    parent.value2 = parent.value1;
                    parent.value1 = middleValue;
                    parent.centerChild = parent.leftChild;
                    parent.leftChild = leftNode;
                    parent.rightChild = rightNode;
                } else {
                    parent.value2 = middleValue;
                    parent.centerChild = rightNode;
                    parent.leftChild = leftNode;
                }
            } else if (parent.isThreeNode()) {
                if (middleValue < parent.value1) {
                    parent.value3 = parent.value2;
                    parent.value2 = parent.value1;
                    parent.value1 = middleValue;

                    parent.centerLeftChild = parent.leftChild;
                    parent.leftChild = leftNode;
                    parent.centerRightChild = rightNode;
                } else if (middleValue < parent.value2) {
                    parent.value3 = parent.value2;
                    parent.value2 = middleValue;

                    parent.centerLeftChild = leftNode;
                    parent.centerRightChild = rightNode;
                } else {
                    parent.value3 = middleValue;

                    parent.centerLeftChild = parent.centerChild;
                    parent.centerChild = leftNode;
                    parent.rightChild = rightNode;
                }

                splitNode(parent);
            }
        } else {
            root = new TwoFourTreeItem(middleValue);
            root.leftChild = leftNode;
            root.rightChild = rightNode;
            root.isLeaf = false;

            leftNode.parent = root;
            rightNode.parent = root;
        }

        leftNode.parent = node.parent;
        rightNode.parent = node.parent;
    }

    public boolean hasValue(int value) {
        return find(root, value);
    }

    private boolean find(TwoFourTreeItem node, int value) {
        if (node == null) return false;
        if (value == node.value1 || (node.isThreeNode() && value == node.value2)) return true;

        if (value < node.value1) {
            return find(node.leftChild, value);
        } else if (node.isThreeNode() && value < node.value2) {
            return find(node.centerChild, value);
        } else {
            return find(node.rightChild, value);
        }
    }

    public boolean deleteValue(int value) {
        return delete(root, value);
    }

    private boolean delete(TwoFourTreeItem node, int value) {
        if (node == null) return false;

        if (node.isLeaf) {
            // If the node is a leaf, simply remove the value.
            if (node.isTwoNode()) {
                if (node.value1 == value) {
                    node.values = 0; // Remove the value
                    return true;
                }
            } else if (node.isThreeNode()) {
                if (node.value1 == value) {
                    node.value1 = node.value2; // Promote the second value
                    node.value2 = 0; // Clear the second value
                    node.values--; // Decrement count of values
                    return true;
                } else if (node.value2 == value) {
                    node.value2 = node.value3; // Promote the third value
                    node.value3 = 0; // Clear the third value
                    node.values--; // Decrement count of values
                    return true;
                }
            }
            return false; // Value not found
        }

        // Search in the correct child based on value
        if (value < node.value1) {
            return delete(node.leftChild, value);
        } else if (node.isThreeNode() && value < node.value2) {
            return delete(node.centerChild, value);
        } else if (node.isThreeNode() && value == node.value2) {
            // Handle deletion of the second value from a three-node
            return deleteFromThreeNode(node, value);
        } else {
            return delete(node.rightChild, value);
        }
    }

    private boolean deleteFromThreeNode(TwoFourTreeItem node, int value) {
        if (value == node.value2) {
            node.value2 = node.value3; // Promote the third value
            node.value3 = 0; // Clear the third value
            node.values--; // Decrement count of values
            return true; // Deletion successful
        }
        return false; // Value not found
    }

    public void printInOrder() {
        if (root != null) root.printInOrder(0);
    }

    public TwoFourTree() {
        // Constructor
    }
}
