#include <iostream>
#include <vector>
#include <cstring>
#include <openssl/sha.h>

using namespace std;

// Function to compute the SHA-256 hash of input data
// O(n) runtime: O(n) for hashing the input data
vector<uint8_t> computeSHA256(const vector<uint8_t>& data) {
    vector<uint8_t> hash(SHA256_DIGEST_LENGTH);
    SHA256(data.data(), data.size(), hash.data());
    return hash;
}

// Function to print bytes in hex format
// O(n) runtime: Iterates over each byte in the data vector
void printBytes(const vector<uint8_t>& data) {
    for (uint8_t byte : data) {
        printf("%02x ", byte);
    }
    printf("\n");
}

int main() {
    // Example plaintext
    vector<uint8_t> plaintext = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};

    // Compute the SHA-256 hash of the plaintext
    vector<uint8_t> hash = computeSHA256(plaintext);

    // Print the results
    cout << "Plaintext: ";
    for (char c : plaintext) {
        cout << c;
    }
    cout << endl;

    cout << "SHA-256 Hash: ";
    printBytes(hash);

    return 0;
}
