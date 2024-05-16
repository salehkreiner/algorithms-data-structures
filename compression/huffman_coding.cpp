#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char character;
    int frequency;
    Node *left, *right;

    Node(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

// Comparator to order the nodes in the priority queue
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Function to generate the Huffman Codes
void generateCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If a leaf node is reached, store the code
    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman Tree and generate the codes
unordered_map<char, string> buildHuffmanTree(const string& text) {
    // Count frequency of each character
    unordered_map<char, int> frequency;
    for (char ch : text) {
        frequency[ch]++;
    }

    // Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate while the size of the heap doesn't become one
    while (pq.size() != 1) {
        // Extract the two nodes of the highest priority (lowest frequency)
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children and with frequency equal to the sum of the two nodes' frequencies
        int sum = left->frequency + right->frequency;
        Node* newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;

        // Add this node to the priority queue
        pq.push(newNode);
    }

    // The remaining node is the root of the Huffman Tree
    Node* root = pq.top();

    // Generate the Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    return huffmanCodes;
}

// Function to print the Huffman Codes
void printHuffmanCodes(const unordered_map<char, string>& huffmanCodes) {
    for (auto pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string text = "this is an example for huffman encoding";

    // Build Huffman Tree and generate codes
    // Time Complexity: O(n) for building the frequency map, where n is the length of the text
    //                  O(d log d) for building the priority queue, where d is the number of distinct characters (d <= n)
    //                  O(n log d) for building the Huffman Tree (extract-min and insert operations)
    // Overall Time Complexity: O(n log d), but typically simplified to O(n log n) in the worst case
    unordered_map<char, string> huffmanCodes = buildHuffmanTree(text);

    // Print the Huffman Codes
    printHuffmanCodes(huffmanCodes);

    return 0;
}
