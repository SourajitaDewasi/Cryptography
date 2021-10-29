import hmac
import hashlib
import os
import struct
import binascii
def pbkdf2(digestmod, password: 'bytes', salt, count, dk_length) -> 'bytes':
    def pbkdf2_function(pw, salt, count, i):
        r = u = hmac.new(pw, salt + struct.pack(">i", i), digestmod).digest()
        for i in range(2, count + 1):
            u = hmac.new(pw, u, digestmod).digest()
            r = bytes(i ^ j for i, j in zip(r, u))
        return r
    dk, h_length = b'', digestmod().digest_size
    blocks = (dk_length // h_length) + (1 if dk_length % h_length else 0)
    for i in range(1, blocks + 1):
        dk += pbkdf2_function(password, salt, count, i)
    return dk[:dk_length]
password = "sourajita"
passwordSalt = os.urandom(16)
key = pbkdf2(hashlib.sha1,b"s3cr3t*c0d3", passwordSalt, 4096,16)
print('The AES Encryption key is:', binascii.hexlify(key))

