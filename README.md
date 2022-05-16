# [Cryptography](https://github.com/SourajitaDewasi/Cryptography)
Algorithms studied/completed during the Cryptography Course
# C/C++/Python Implementation of Cryptography Programs 
1.  Caesar Cipher
2.  Multiplicative Cipher
3.  Affine Cipher
4.  Diffie-Hellmen Cipher
5.  Keyless Cipher
6.  Initial and Final Permutation of DES
7.  Round 1 of DES Key Generation
8.  Round 1 to 16 of DES Key Generation
9.  S-Box of DES Algorithm
10. Encryption in DES ALgorithm
11. Hill Cipher
12. Key Generation in AES Algorithm
13. RSA Cipher
14. Elgamal Cipher 
15. ECC Cipher

## Caesar Cipher
The Caesar Cipher is one of the earliest encryption methods. It's a substitution cypher, in which each letter of a given text is substituted by a letter located a certain number of positions down the alphabet. With a shift of one, for example, A would be replaced by B, B by C, and so on. To encrypt a given text, we need an integer value called shift, which tells how far down each letter of the text has been shifted. 

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/Additive%20Cipher.c)

[Definition Reference Link](https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/)

## Multiplicative Cipher
Encrypting and decrypting symbols with the Caesar cypher technique entails transforming the values into integers using a simple addition or subtraction procedure. A wrap-around situation occurs when multiplication is employed to convert to encrypted text. A multiplicative cypher has the advantage of being able to work with very big keys. A computer would take a long time to brute-force its way through a majority of nine million keys.

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/Affine%20Cipher.cpp)

[Definition Reference Link](https://www.tutorialspoint.com/cryptography_with_python/cryptography_with_python_multiplicative_cipher.htm)

## Affine Cipher
Affine Cipher is a form of Monoalphabetic Substituiton cypher that uses a mathematical encryption approach. The entire procedure is based on working modulo m (the length of the alphabet used). The letters of an alphabet of size m are first mapped to integers in the range 0... m-1 in the affine cypher. The Affine cipher key is made up of two numbers, which we'll refer to as a and b. It follows assumes a 26-character alphabet (m = 26). a should be chosen to be close to m in terms of primness (i.e. a should have no factors in common with m). 

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/Affine%20Cipher.cpp)

## Diffie-Hellmen Cipher
Diffie Hellmen Cipher is an exponential key cipher. It is a method of digital encryption. In this case the end users Alice and Bob agree on using positive whole numbers p and q, such that p is a prime number and q is a generator of p, while communicating through a channel they know is private. When raised to positive whole-number powers less than p, the generator q never generates the same result for any two such whole numbers. lthough the value of p can be rather large, the value of q is usually quite low. Alice and Bob choose positive whole-number personal keys a and b, both less than the prime-number modulus p, after privately agreeing on p and q. Neither user shares their personal key with anyone; they should memorise these numbers rather than writing them down or storing them anyplace. Then, using the formulas, Alice and Bob compute public keys a* and b* based on their personal keys. 

a* = qa mod p and b* = qb mod p

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/Diffie%20Hellmen%20Cipher.cpp)

## Keyless Cipher
The keyless transportation cipher is a type of encryption. The text is written into a table column by column and then row by row in the first technique. The text is written row by row into the table and then transferred column by column in the second manner. 

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/Keyless%20Cipher.cpp)

[Definition Reference Link](https://www.ques10.com/p/3454/what-is-keyless-transposition-cipher-give-an-exa-1/)

## DES Algorithm
The Data Encryption Standard (DES) is a block cypher technique that converts plain text in 64-bit blocks to ciphertext using 48-bit keys. It's a symmetric key algorithm, which means it encrypts and decrypts data with the same key. The 16 48-bit keys' sequence is reversed, so key 16 becomes key 1, and so forth. The encryption processes are then applied to the ciphertext. 

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/DES_Encryption_Complete.cpp)

## Hill Cipher
Hill cypher is a polygraphic substitution cypher. A number modulo 26 is assigned to each letter. The basic scheme A = 0, B = 1,..., Z = 25 is frequently employed, but it is not a requirement of the encryption. Each block of n letters (considered an n-component vector) is multiplied by an invertible nxn matrix against modulus 26 to encrypt a message. Each block is multiplied by the inverse of the encryption matrix to decrypt the message. 

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/Hill%20Cipher.cpp)

## AES Algorithm
Despite being more difficult to build, AES is frequently used today because it is substantially stronger than DES and triple DES. The AES cypher is a block cipher just like DES. The key can be 128/192/256 bits in length. Data is encrypted in 128-bit blocks. It accepts 128 bits as input and outputs 128 bits of encrypted cypher text. AES is based on the substitution-permutation network principle, which involves replacing and shuffling the input data through a series of connected processes. 

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/AES_Key_Generation.py)

[Reference Link](https://www.geeksforgeeks.org/advanced-encryption-standard-aes/)

## RSA Cipher

It was devised by three scientists Rivest, Shamir and Adleman. It is based on Factorization Problem where number of bits must be atleast 1024 for a secured RSA.
In the solution there has been the use of a small prime integer.

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/RSA%20Cipher.cpp)

## Elgamal Cipher
ElGamal cryptosystem is a cryptography algorithm that secures communication between two systems by utilising public and private key principles. It's an asymmetric algorithm in which public and private keys are used to encrypt and decrypt information. The client uses the public key to encrypt the message, and the message may be decrypted using the private key on the server end.
Because the keys are incredibly difficult to guess, this is considered an efficient approach for encryption and decryption. 

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/ELgamal%20Crypto%20System.cpp)

[Code Reference Link](https://github.com/DhruvDixitDD/ElGamal-based-Elliptic-Curve-Cryptography/blob/master/ElgamalEllipticCurve.cpp)

## ECC Cipher
Elliptic Curve Cryptography (ECC) is a key-based data encryption technology. For decryption and encryption of web traffic, ECC focuses on pairs of public and private keys.
It uses elliptic curve mathematics to generate security between key pairs for public key encryption. ECC's approach to public key cryptography is based on the algebraic structure of elliptic curves over finite fields. As a result, ECC generates keys that are mathematically more difficult to crack. It is regarded as the next generation of public key cryptography technology. 

[Code Link](https://github.com/SourajitaDewasi/Cryptography/blob/main/ECC_Cipher.c)

[Code Reference Link](https://avinetworks.com/glossary/elliptic-curve-cryptography/)
