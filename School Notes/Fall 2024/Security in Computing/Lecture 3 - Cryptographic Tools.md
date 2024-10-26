
 Overview:
 - Confidentiality with symmetric encryption 
 - Message Authentication and Hash functions
 - Public Key Encryption 
 - Digital Signatures and Key Management 
 - Random and Pseudorandom numbers 


Symmetric Encryption:
- also called single key encryption
- same key is used by sender and receiver 

Components:
- plaintext 
- encryption algorithm 
- secret key
- ciphertext 
- decryption algorithm 

Strong encryption algorithm:
- even if the opponent has the algorithm and the ciphertext, they still cannot decipher the ciphertext or figure out the key

Brute force:
- on average half of the possible keys must be tried

	Block Cipher:
- processes plaintext input into fixed size blocks   

Stream Cipher:
- processes input elements continuously 
- produces one element at a time 
- can be a byte or bigger than a byte 

Encryption = ensures confidentiality 

Message/data authentication assures data integrity

contents have not been altered 
MAC - message authentication code 
an authentication technique that uses a shared key and a MAC algorithm 
MAC is appended onto the message before transmission 
MAC is the last 16 or 32 bits of the encrypted message  


S