#include <iostream>
#include <vector>
#include <openssl/aes.h>

using namespace std;

// Function to encrypt a single block of plaintext using AES
// O(n) runtime: O(n) for resizing the ciphertext vector
void AES_encrypt(const vector<uint8_t>& plaintext, vector<uint8_t>& ciphertext, const vector<uint8_t>& key) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key.data(), 128, &encryptKey);

    // Ensure the ciphertext has the correct size
    ciphertext.resize(plaintext.size());

    AES_encrypt(plaintext.data(), ciphertext.data(), &encryptKey);
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
    // Example plaintext and key (both 16 bytes for AES-128)
    vector<uint8_t> plaintext = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    vector<uint8_t> key = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x12, 0x3c, 0xaf, 0xf5, 0x23, 0x7d};

    vector<uint8_t> ciphertext;

    // Encrypt the plaintext
    AES_encrypt(plaintext, ciphertext, key);

    // Print the results
    cout << "Plaintext: ";
    printBytes(plaintext);

    cout << "Ciphertext: ";
    printBytes(ciphertext);

    return 0;
}
