public class TwoFourTree {
    private class Node {
        int[] values = new int[3];
        int valueCount = 0;
        boolean isLeaf = true;

        Node parent;
        Node[] children = new Node[4];

        public Node(int value) {
            values[0] = value;
            valueCount = 1;
        }

        public boolean isTwoNode() {
            return valueCount == 1;
        }

        public boolean isThreeNode() {
            return valueCount == 2;
        }

        public boolean isFourNode() {
            return valueCount == 3;
        }

        public boolean isRoot() {
            return parent == null;
        }

        public void addValue(int value) {
            values[valueCount++] = value;
            sortValues();
        }

        public void sortValues() {
            for (int i = 0; i < valueCount - 1; i++) {
                for (int j = i + 1; j < valueCount; j++) {
                    if (values[i] > values[j]) {
                        int temp = values[i];
                        values[i] = values[j];
                        values[j] = temp;
                    }
                }
            }
        }
    }

    private Node root;

    public boolean addValue(int value) {
        if (root == null) {
            root = new Node(value);
            return true;
        }
        return insert(root, value);
    }

    private boolean insert(Node node, int value) {
        if (node.isLeaf) {
            node.addValue(value);
            if (node.isFourNode()) {
                split(node);
            }
            return true;
        } else {
            int i = 0;
            while (i < node.valueCount && value > node.values[i]) {
                i++;
            }
            return insert(node.children[i], value);
        }
    }

    private void split(Node node) {
        int middleValue = node.values[1];
        Node leftChild = new Node(node.values[0]);
        Node rightChild = new Node(node.values[2]);

        leftChild.isLeaf = node.isLeaf;
        rightChild.isLeaf = node.isLeaf;

        if (!node.isLeaf) {
            for (int i = 0; i < 2; i++) {
                leftChild.children[i] = node.children[i];
                if (leftChild.children[i] != null) {
                    leftChild.children[i].parent = leftChild;
                }
            }
            for (int i = 2; i < 4; i++) {
                rightChild.children[i - 2] = node.children[i];
                if (rightChild.children[i - 2] != null) {
                    rightChild.children[i - 2].parent = rightChild;
                }
            }
        }

        if (node.isRoot()) {
            root = new Node(middleValue);
            root.isLeaf = false;
            root.children[0] = leftChild;
            root.children[1] = rightChild;
            leftChild.parent = root;
            rightChild.parent = root;
        } else {
            Node parent = node.parent;
            parent.addValue(middleValue);
            int index = findChildIndex(parent, node);
            parent.children[index] = leftChild;
            parent.children[index + 1] = rightChild;
            leftChild.parent = parent;
            rightChild.parent = parent;

            if (parent.isFourNode()) {
                split(parent);
            }
        }
    }

    private int findChildIndex(Node parent, Node child) {
        for (int i = 0; i < parent.children.length; i++) {
            if (parent.children[i] == child) {
                return i;
            }
        }
        return -1;
    }

    public boolean hasValue(int value) {
        return find(root, value);
    }

    private boolean find(Node node, int value) {
        if (node == null) {
            return false;
        }
        for (int i = 0; i < node.valueCount; i++) {
            if (node.values[i] == value) {
                return true;
            }
        }
        int i = 0;
        while (i < node.valueCount && value > node.values[i]) {
            i++;
        }
        return find(node.children[i], value);
    }

    public boolean deleteValue(int value) {
        return delete(root, value);
    }

    private boolean delete(Node node, int value) {
        if (node == null) {
            return false;
        }

        int index = findValueIndex(node, value);

        if (index != -1) {
            if (node.isLeaf) {
                removeFromLeaf(node, index);
            } else {
                Node predecessor = getPredecessor(node, index);
                node.values[index] = predecessor.values[predecessor.valueCount - 1];
                delete(predecessor, predecessor.values[predecessor.valueCount - 1]);
            }
            return true;
        }

        int i = 0;
        while (i < node.valueCount && value > node.values[i]) {
            i++;
        }
        boolean deleted = delete(node.children[i], value);

        if (node.children[i] != null && node.children[i].valueCount < 1) {
            rebalance(node, i);
        }

        return deleted;
    }

    private int findValueIndex(Node node, int value) {
        for (int i = 0; i < node.valueCount; i++) {
            if (node.values[i] == value) {
                return i;
            }
        }
        return -1;
    }

    private void removeFromLeaf(Node node, int index) {
        for (int i = index; i < node.valueCount - 1; i++) {
            node.values[i] = node.values[i + 1];
        }
        node.valueCount--;
    }

    private Node getPredecessor(Node node, int index) {
        Node current = node.children[index];
        while (!current.isLeaf) {
            current = current.children[current.valueCount];
        }
        return current;
    }

    private void rebalance(Node parent, int index) {
        Node child = parent.children[index];
        Node sibling = (index > 0) ? parent.children[index - 1] : parent.children[index + 1];

        if (sibling != null && sibling.valueCount > 1) {
            if (index > 0) {
                shiftLeft(parent, index);
            } else {
                shiftRight(parent, index);
            }
        } else {
            merge(parent, index);
        }
    }

    private void shiftLeft(Node parent, int index) {
        Node child = parent.children[index];
        Node sibling = parent.children[index - 1];

        for (int i = child.valueCount; i > 0; i--) {
            child.values[i] = child.values[i - 1];
        }
        child.values[0] = parent.values[index - 1];
        parent.values[index - 1] = sibling.values[sibling.valueCount - 1];
        sibling.valueCount--;
        child.valueCount++;
    }

    private void shiftRight(Node parent, int index) {
        Node child = parent.children[index];
        Node sibling = parent.children[index + 1];

        child.values[child.valueCount] = parent.values[index];
        parent.values[index] = sibling.values[0];
        sibling.valueCount--;
        child.valueCount++;

        for (int i = 0; i < sibling.valueCount; i++) {
            sibling.values[i] = sibling.values[i + 1];
        }
    }

    private void merge(Node parent, int index) {
        Node leftChild = parent.children[index];
        Node rightChild = parent.children[index + 1];
    
        // Merge the parent key with two child nodes
        leftChild.values[leftChild.valueCount] = parent.values[index];
        leftChild.valueCount++;
    
        for (int i = 0; i < rightChild.valueCount; i++) {
            leftChild.values[leftChild.valueCount++] = rightChild.values[i];
        }
    
        if (!leftChild.isLeaf) {
            for (int i = 0; i <= rightChild.valueCount; i++) {
                leftChild.children[leftChild.valueCount] = rightChild.children[i];
                if (leftChild.children[leftChild.valueCount] != null) {
                    leftChild.children[leftChild.valueCount].parent = leftChild;
                }
            }
        }
    
        // Shift parent's values and children
        for (int i = index; i < parent.valueCount - 1; i++) {
            parent.values[i] = parent.values[i + 1];
            parent.children[i + 1] = parent.children[i + 2];
        }
        parent.valueCount--;
    }
    

    public void printInOrder() {
        printInOrder(root);
    }

    private void printInOrder(Node node) {
        if (node == null) {
            return;
        }
        for (int i = 0; i < node.valueCount; i++) {
            printInOrder(node.children[i]);
            System.out.print(node.values[i] + " ");
        }
        printInOrder(node.children[node.valueCount]);
    }
}
