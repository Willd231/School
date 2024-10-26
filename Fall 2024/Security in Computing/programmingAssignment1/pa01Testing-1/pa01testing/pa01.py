#William Dellinger: CIS 3360 Programming assignment 1
import numpy as np
import sys


def read_keyfile(keyfile_path):
    #reads the key file
    with open(keyfile_path, "r") as keyfile:
        # get the key size
        n = int(keyfile.readline().strip())
        
        #make the empty matrix for the key
        key = np.zeros((n, n), dtype=int)  
        
        #read the values from the file into the matrix 
        for i in range(n):
            row = list(map(int, keyfile.readline().strip().split()))
            key[i] = row  
    return key, n

        

def read_plaintext(plaintext_path, n):
    with open(plaintext_path, "r") as plainfile:
        # read the plaintext file, remove non-letter characters and spaces, and convert to lowercase
        pt = ''.join(filter(str.isalpha, plainfile.read())).lower()

        # check if the plaintext length % n != 0, if so add 'x' to make it divisible by n
        filler = (n - len(pt) % n) % n 
        if filler != 0:
            pt += 'x' * filler
    return pt

#function that converts chars to ints
def convert_text_to_numbers(text):
    #since all of the letters increase in value starting with a we can just subtract the value of a to get the number correspondance from 0 - 25 
    return [ord(char) - ord('a') for char in text]


#function that converts ints to chars
def convert_numbers_to_text(numbers):
    #exactly opposite from the previous function this one adds on the value of a to get the numbers 
    return ''.join([chr(num + ord('a')) for num in numbers])




def hill_cipher_encrypt(pt, key, n):
    #convert all of the plaintext to numbers
    pt_numbers = convert_text_to_numbers(pt)
    #initialize an array for the encrypted text
    ciphertext = []

    # process the plain in chunks of n size to make sure the logic works correctly
    for i in range(0, len(pt_numbers), n):
        block = np.array(pt_numbers[i:i+n]).reshape(n, 1)
        
        # use numpy's dot function to multiply the current n numbers against the key to get the encrypted version 
        encrypted_block = np.dot(key, block) % 26
        
        # convert result back to letters
        encrypted_chars = convert_numbers_to_text(encrypted_block.flatten())
        ciphertext.extend(encrypted_chars)
    #combine all of the encrypted letters and return them
    
    return ''.join(ciphertext)



#main function
def main():
    #file paths are obtained through command line 
    keyfile_path = sys.argv[1]
    plaintext_path = sys.argv[2]
    
    #passing the variables
    key, n = read_keyfile(keyfile_path)
    plaintext = read_plaintext(plaintext_path, n)
    ciphertext = hill_cipher_encrypt(plaintext, key, n)
    
    #printing the results
    print("Key: ")
    print(key)
    print("Plaintext: ")
    for i in range(0, len(plaintext),80):
        print(plaintext[i:i+80])
    print("Ciphertext:")
    for j in range(0, len(ciphertext),80):
        print(ciphertext[j:j+80])


main()
